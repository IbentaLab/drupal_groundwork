<?php

/**
 * @file
 * Provides the AI Tools tab and its functionality for the Groundwork theme.
 *
 * This file is included by settings-form.inc and adds the form elements
 * for the various AI-powered tools, along with their corresponding helper
 * functions and AJAX callbacks.
 */

declare(strict_types=1);

use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\StringTranslation\TranslatableMarkup;
use Drupal\file\Entity\File;
use GuzzleHttp\Client;

// --- AI Tools Vertical Tab ---
$form['ai_tools'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('AI Tools'),
  '#group' => 'gw_settings_tabs',
  '#weight' => 1, // Adjust weight as needed
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
];

// --- API Key Settings ---
$form['ai_tools']['api_settings'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('API Configuration'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
];

$form['ai_tools']['api_settings']['gemini_api_key'] = [
  '#type' => 'textfield',
  '#title' => \Drupal::translation()->translate('Google Gemini API Key'),
  '#default_value' => theme_get_setting('gemini_api_key'),
  '#description' => \Drupal::translation()->translate('Enter your Google Gemini API key. You can get a key from <a href="https://aistudio.google.com/app/apikey" target="_blank">Google AI Studio</a>. For production sites, it is highly recommended to use the <a href="https://www.drupal.org/project/key" target="_blank">Key module</a> to store this securely.'),
  '#size' => 60,
  '#maxlength' => 128,
];

// --- Build the form for each AI tool ---
$form['ai_tools']['color_palette_generator'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('AI Color Palette Generator'),
  '#description' => \Drupal::translation()->translate('Generate a color palette for your site based on a text prompt or a logo.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];
$form['ai_tools']['color_palette_generator'] += groundwork_ai_color_palette_generator_form();

$form['ai_tools']['layout_builder_ai'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('AI Layout & Component Builder'),
  '#description' => \Drupal::translation()->translate('Translates natural language descriptions into Groundwork layout and component "recipes".'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];
$form['ai_tools']['layout_builder_ai'] += groundwork_ai_layout_builder_form();

$form['ai_tools']['content_copilot'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('AI Content Copilot'),
  '#description' => \Drupal::translation()->translate('Tools to assist with content creation, such as generating placeholder text, summaries, and meta tags.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];
$form['ai_tools']['content_copilot'] += groundwork_ai_content_copilot_form();

$form['ai_tools']['accessibility_auditor'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('AI Accessibility Auditor'),
  '#description' => \Drupal::translation()->translate('Provides real-time feedback on content to help improve compliance with WCAG 2.1 AA standards.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];
$form['ai_tools']['accessibility_auditor'] += groundwork_ai_accessibility_auditor_form();

$form['ai_tools']['component_generator_ai'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('AI Component Generator & Linter'),
  '#description' => \Drupal::translation()->translate('Helps developers create and validate new Groundwork components according to framework standards.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];
$form['ai_tools']['component_generator_ai'] += groundwork_ai_component_generator_form();

/**
 * Loads a system prompt template from the /agent directory.
 *
 * @param string $prompt_name
 * The name of the prompt file (without the .md extension).
 *
 * @return string
 * The content of the prompt file.
 */
function _groundwork_ai_load_prompt(string $prompt_name): string {
  $path = __DIR__ . '/agent/' . $prompt_name . '.md';
  if (file_exists($path)) {
    return file_get_contents($path);
  }
  return '';
}

/**
 * Helper function to make API calls to the Google Gemini service.
 *
 * @param string $api_key
 * The Google Gemini API key.
 * @param array $payload
 * The payload to send to the API, including contents and generation config.
 *
 * @return array
 * The decoded JSON response from the API as an associative array.
 *
 * @throws \GuzzleHttp\Exception\GuzzleException
 * Thrown if the HTTP request fails.
 */
function _groundwork_ai_call_gemini(string $api_key, array $payload): array {
  $client = new Client();
  $response = $client->post('https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=' . $api_key, [
    'json' => $payload,
  ]);
  return json_decode((string) $response->getBody(), TRUE);
}

/**
 * Builds the form elements for the AI Color Palette Generator tool.
 *
 * @return array
 * A render array containing the form elements for the tool.
 */
function groundwork_ai_color_palette_generator_form(): array {
  $form['color_prompt'] = [
    '#type' => 'textarea',
    '#title' => \Drupal::translation()->translate('Describe your desired color palette'),
    '#description' => \Drupal::translation()->translate('Use the text description OR upload a logo below.'),
  ];
  $form['logo_upload'] = [
    '#type' => 'managed_file',
    '#title' => \Drupal::translation()->translate('Or upload a logo'),
    '#upload_location' => 'public://groundwork-ai-uploads/',
    '#upload_validators' => [
      'file_validate_extensions' => ['png jpg jpeg gif'],
    ],
  ];
  $form['generate_button'] = [
    '#type' => 'button',
    '#value' => \Drupal::translation()->translate('Generate Palette'),
    '#ajax' => [
      'callback' => 'groundwork_ai_generate_palette_callback',
      'wrapper' => 'palette-result-wrapper',
    ],
  ];
  $form['palette_result'] = [
    '#type' => 'container',
    '#attributes' => ['id' => 'palette-result-wrapper'],
  ];
  return $form;
}

/**
 * Handles the AJAX callback for the Color Palette Generator.
 *
 * @param array $form
 * An associative array containing the structure of the form.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 * The current state of the form.
 *
 * @return array
 * A render array containing the generated palette or an error message.
 */
function groundwork_ai_generate_palette_callback(array &$form, FormStateInterface $form_state): array {
  $api_key = theme_get_setting('gemini_api_key');
  if (empty($api_key)) {
    return [
      '#markup' => new TranslatableMarkup('<div class="messages messages--error">Please enter your Gemini API key in the API Configuration tab.</div>'),
    ];
  }

  $prompt_text = $form_state->getValue('color_prompt');
  $file_ids = $form_state->getValue(['logo_upload', 0]);
  if (empty($prompt_text) && empty($file_ids)) {
    return [
      '#markup' => new TranslatableMarkup('<div class="messages messages--warning">Please enter a description or upload a logo.</div>'),
    ];
  }

  $payload_parts = [];
  $prompt_instruction = _groundwork_ai_load_prompt('color_palette_generator');

  if (!empty($file_ids) && ($file = File::load($file_ids[0]))) {
    /** @var \Drupal\file\FileInterface $file */
    $payload_parts[] = [
      'inlineData' => [
        'mimeType' => $file->getMimeType(),
        'data' => base64_encode(file_get_contents($file->getFileUri())),
      ],
    ];
    $prompt_instruction .= ' The user has uploaded the attached logo for color reference.';
    $file->setTemporary();
    $file->save();
  }

  $prompt_instruction = str_replace('{{user_prompt}}', htmlspecialchars($prompt_text, ENT_QUOTES, 'UTF-8'), $prompt_instruction);
  $payload_parts[] = ['text' => $prompt_instruction];

  try {
    $payload = [
      'contents' => [['parts' => $payload_parts]],
      'generationConfig' => ['responseMimeType' => 'application/json'],
    ];
    $body = _groundwork_ai_call_gemini($api_key, $payload);
    $palette_json = $body['candidates'][0]['content']['parts'][0]['text'] ?? '{}';
    $palette = json_decode($palette_json, TRUE);

    if (json_last_error() !== JSON_ERROR_NONE || empty($palette)) {
      throw new \Exception('Could not parse a valid palette from the API response.');
    }

    $css_vars = '';
    $visual_preview_items = '';
    foreach ($palette as $name => $hex) {
      if (preg_match('/^#([a-fA-F0-9]{6}|[a-fA-F0-9]{3})$/', $hex)) {
        $clean_name = htmlspecialchars($name, ENT_QUOTES, 'UTF-8');
        $clean_hex = htmlspecialchars($hex, ENT_QUOTES, 'UTF-8');
        $css_vars .= "  --color-{$clean_name}: {$clean_hex};\n";
        $visual_preview_items .= "<div style='text-align: center;'><div style='width: 100px; height: 100px; background-color: {$clean_hex}; border: 1px solid #ccc; border-radius: 4px;'></div><div>--color-{$clean_name}</div><div>{$clean_hex}</div></div>";
      }
    }

    $markup = new TranslatableMarkup(
      '<h4>Generated Color Palette</h4><p>Copy these CSS variables into your <code>groundwork-tokens.css</code> file.</p><pre><code>:root {\n@css_vars}</code></pre><h4>Visual Preview</h4><div style="display: flex; flex-wrap: wrap; gap: 10px;">@visual_preview</div>',
      [
        '@css_vars' => $css_vars,
        '@visual_preview' => $visual_preview_items,
      ]
    );
    return ['#markup' => $markup];
  }
  catch (\Exception $e) {
    \Drupal::logger('groundwork_ai')->error($e->getMessage());
    $markup = new TranslatableMarkup('<div class="messages messages--error">An error occurred: @error</div>', ['@error' => $e->getMessage()]);
    return ['#markup' => $markup];
  }
}

/**
 * Builds the form elements for the AI Layout & Component Builder tool.
 *
 * @return array
 * A render array containing the form elements for the tool.
 */
function groundwork_ai_layout_builder_form(): array {
  $form['layout_prompt'] = [
    '#type' => 'textarea',
    '#title' => \Drupal::translation()->translate('Describe the layout or section you want to build'),
  ];
  $form['generate_layout_button'] = [
    '#type' => 'button',
    '#value' => \Drupal::translation()->translate('Generate Layout Recipe'),
    '#ajax' => [
      'callback' => 'groundwork_ai_generate_layout_callback',
      'wrapper' => 'layout-result-wrapper',
    ],
  ];
  $form['layout_result'] = [
    '#type' => 'container',
    '#attributes' => ['id' => 'layout-result-wrapper'],
  ];
  return $form;
}

/**
 * Handles the AJAX callback for the Layout & Component Builder.
 *
 * @param array $form
 * An associative array containing the structure of the form.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 * The current state of the form.
 *
 * @return array
 * A render array containing the generated layout recipe or an error message.
 */
function groundwork_ai_generate_layout_callback(array &$form, FormStateInterface $form_state): array {
  $api_key = theme_get_setting('gemini_api_key');
  if (empty($api_key)) {
    return ['#markup' => new TranslatableMarkup('<div class="messages messages--error">Please enter your Gemini API key.</div>')];
  }
  $prompt_text = $form_state->getValue('layout_prompt');
  if (empty($prompt_text)) {
    return ['#markup' => new TranslatableMarkup('<div class="messages messages--warning">Please describe the layout.</div>')];
  }
  $template = _groundwork_ai_load_prompt('layout_builder');
  $system_prompt = str_replace('{{user_prompt}}', htmlspecialchars($prompt_text, ENT_QUOTES, 'UTF-8'), $template);

  try {
    $payload = ['contents' => [['parts' => [['text' => $system_prompt]]]]];
    $body = _groundwork_ai_call_gemini($api_key, $payload);
    $recipe_text = $body['candidates'][0]['content']['parts'][0]['text'] ?? '';
    $markup = new TranslatableMarkup(
      '<h4>Your Layout Recipe</h4><div class="layout-recipe">@recipe</div>',
      ['@recipe' => nl2br(htmlspecialchars($recipe_text))]
    );
    return ['#markup' => $markup];
  }
  catch (\Exception $e) {
    \Drupal::logger('groundwork_ai')->error($e->getMessage());
    $markup = new TranslatableMarkup('<div class="messages messages--error">An error occurred: @error</div>', ['@error' => $e->getMessage()]);
    return ['#markup' => $markup];
  }
}

/**
 * Builds the form elements for the AI Content Copilot tool.
 *
 * @return array
 * A render array containing the form elements for the tool.
 */
function groundwork_ai_content_copilot_form(): array {
  $form['copilot_action'] = [
    '#type' => 'select',
    '#title' => \Drupal::translation()->translate('Action'),
    '#options' => [
      'summarize' => \Drupal::translation()->translate('Summarize Text'),
      'meta_tags' => \Drupal::translation()->translate('Suggest SEO Meta Tags'),
      'placeholder' => \Drupal::translation()->translate('Generate Placeholder Content'),
    ],
  ];
  $form['copilot_page_path'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('Page Path'),
    '#description' => \Drupal::translation()->translate('Optional: Enter an internal path (e.g., /node/1) to analyze its content instead of using the text area below.'),
    '#size' => 60,
  ];
  $form['copilot_prompt'] = [
    '#type' => 'textarea',
    '#title' => \Drupal::translation()->translate('Input Text or Description'),
    '#description' => \Drupal::translation()->translate('For Summarize/Meta Tags, paste your content. For Placeholders, describe what you need (e.g., "a short bio for a fictional graphic designer"). This is ignored if a Page Path is provided.'),
  ];
  $form['generate_copilot_button'] = [
    '#type' => 'button',
    '#value' => \Drupal::translation()->translate('Generate Content'),
    '#ajax' => [
      'callback' => 'groundwork_ai_generate_copilot_callback',
      'wrapper' => 'copilot-result-wrapper',
    ],
  ];
  $form['copilot_result'] = [
    '#type' => 'container',
    '#attributes' => ['id' => 'copilot-result-wrapper'],
  ];
  return $form;
}

/**
 * Handles the AJAX callback for the AI Content Copilot.
 *
 * @param array $form
 * An associative array containing the structure of the form.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 * The current state of the form.
 *
 * @return array
 * A render array containing the generated content or an error message.
 */
function groundwork_ai_generate_copilot_callback(array &$form, FormStateInterface $form_state): array {
  $api_key = theme_get_setting('gemini_api_key');
  if (empty($api_key)) {
    return ['#markup' => new TranslatableMarkup('<div class="messages messages--error">Please enter your Gemini API key.</div>')];
  }

  $prompt_text = $form_state->getValue('copilot_prompt');
  $page_path = $form_state->getValue('copilot_page_path');
  $action = $form_state->getValue('copilot_action');

  if (!empty($page_path)) {
    try {
      $base_url = \Drupal::request()->getSchemeAndHttpHost();
      $http_client = \Drupal::httpClient();
      $response = $http_client->get($base_url . $page_path);
      $html = (string) $response->getBody();

      if (!empty($html)) {
        libxml_use_internal_errors(TRUE);
        $dom = new \DOMDocument();
        $dom->loadHTML($html);
        libxml_clear_errors();
        $xpath = new \DOMXPath($dom);
        $main_content = $xpath->query('//main')->item(0);
        if ($main_content) {
          $prompt_text = strip_tags($main_content->nodeValue);
        }
        else {
          $prompt_text = strip_tags($html);
        }
      }
    }
    catch (\Exception $e) {
      \Drupal::logger('groundwork_ai')->error($e->getMessage());
      return ['#markup' => new TranslatableMarkup('<div class="messages messages--error">Could not fetch content from path @path: @error</div>', ['@path' => $page_path, '@error' => $e->getMessage()])];
    }
  }

  if (empty($prompt_text)) {
    return ['#markup' => new TranslatableMarkup('<div class="messages messages--warning">Please provide input text, a description, or a valid page path.</div>')];
  }

  $template = _groundwork_ai_load_prompt('content_copilot_' . $action);
  $system_prompt = str_replace('{{user_prompt}}', $prompt_text, $template);

  try {
    $payload = ['contents' => [['parts' => [['text' => $system_prompt]]]]];
    $body = _groundwork_ai_call_gemini($api_key, $payload);
    $result_text = $body['candidates'][0]['content']['parts'][0]['text'] ?? '';
    $markup = new TranslatableMarkup(
      '<h4>Generated Content</h4><pre style="white-space: pre-wrap; word-wrap: break-word;">@result</pre>',
      ['@result' => htmlspecialchars($result_text)]
    );
    return ['#markup' => $markup];
  }
  catch (\Exception $e) {
    \Drupal::logger('groundwork_ai')->error($e->getMessage());
    $markup = new TranslatableMarkup('<div class="messages messages--error">An error occurred: @error</div>', ['@error' => $e->getMessage()]);
    return ['#markup' => $markup];
  }
}

/**
 * Builds the form elements for the AI Accessibility Auditor tool.
 *
 * @return array
 * A render array containing the form elements for the tool.
 */
function groundwork_ai_accessibility_auditor_form(): array {
  $form['accessibility_page_path'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('Page Path'),
    '#description' => \Drupal::translation()->translate('Optional: Enter an internal path (e.g., /node/1) to analyze its content instead of using the text area below.'),
    '#size' => 60,
  ];
  $form['accessibility_prompt'] = [
    '#type' => 'textarea',
    '#title' => \Drupal::translation()->translate('Content to Audit'),
    '#description' => \Drupal::translation()->translate('Paste your text or HTML snippet here to check for common accessibility issues. This is ignored if a Page Path is provided.'),
  ];
  $form['generate_audit_button'] = [
    '#type' => 'button',
    '#value' => \Drupal::translation()->translate('Audit Content'),
    '#ajax' => [
      'callback' => 'groundwork_ai_generate_audit_callback',
      'wrapper' => 'audit-result-wrapper',
    ],
  ];
  $form['audit_result'] = [
    '#type' => 'container',
    '#attributes' => ['id' => 'audit-result-wrapper'],
  ];
  return $form;
}

/**
 * Handles the AJAX callback for the AI Accessibility Auditor.
 *
 * @param array $form
 * An associative array containing the structure of the form.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 * The current state of the form.
 *
 * @return array
 * A render array containing the audit results or an error message.
 */
function groundwork_ai_generate_audit_callback(array &$form, FormStateInterface $form_state): array {
  $api_key = theme_get_setting('gemini_api_key');
  if (empty($api_key)) {
    return ['#markup' => new TranslatableMarkup('<div class="messages messages--error">Please enter your Gemini API key.</div>')];
  }

  $prompt_text = $form_state->getValue('accessibility_prompt');
  $page_path = $form_state->getValue('accessibility_page_path');

  if (!empty($page_path)) {
    try {
      $base_url = \Drupal::request()->getSchemeAndHttpHost();
      $http_client = \Drupal::httpClient();
      $response = $http_client->get($base_url . $page_path);
      $html = (string) $response->getBody();

      if (!empty($html)) {
        libxml_use_internal_errors(TRUE);
        $dom = new \DOMDocument();
        $dom->loadHTML($html);
        libxml_clear_errors();
        $xpath = new \DOMXPath($dom);
        $main_content = $xpath->query('//main')->item(0);
        if ($main_content) {
          // Send the raw HTML of the main content area.
          $prompt_text = $dom->saveHTML($main_content);
        }
        else {
          $prompt_text = $html;
        }
      }
    }
    catch (\Exception $e) {
      \Drupal::logger('groundwork_ai')->error($e->getMessage());
      return ['#markup' => new TranslatableMarkup('<div class="messages messages--error">Could not fetch content from path @path: @error</div>', ['@path' => $page_path, '@error' => $e->getMessage()])];
    }
  }

  if (empty($prompt_text)) {
    return ['#markup' => new TranslatableMarkup('<div class="messages messages--warning">Please provide content to audit or a valid page path.</div>')];
  }

  $template = _groundwork_ai_load_prompt('accessibility_auditor');
  $system_prompt = str_replace('{{user_prompt}}', $prompt_text, $template);

  try {
    $payload = ['contents' => [['parts' => [['text' => $system_prompt]]]]];
    $body = _groundwork_ai_call_gemini($api_key, $payload);
    $result_text = $body['candidates'][0]['content']['parts'][0]['text'] ?? '';
    $markup = new TranslatableMarkup(
      '<h4>Accessibility Audit Results</h4><div class="audit-results">@results</div>',
      ['@results' => nl2br(htmlspecialchars($result_text))]
    );
    return ['#markup' => $markup];
  }
  catch (\Exception $e) {
    \Drupal::logger('groundwork_ai')->error($e->getMessage());
    $markup = new TranslatableMarkup('<div class="messages messages--error">An error occurred: @error</div>', ['@error' => $e->getMessage()]);
    return ['#markup' => $markup];
  }
}

/**
 * Builds the form elements for the AI Component Generator & Linter tool.
 *
 * @return array
 * A render array containing the form elements for the tool.
 */
function groundwork_ai_component_generator_form(): array {
  $form['component_prompt'] = [
    '#type' => 'textarea',
    '#title' => \Drupal::translation()->translate('Describe the component you want to create'),
    '#description' => \Drupal::translation()->translate('For example: "A dismissible alert banner with a title and message content. It should support the standard color variants like success and warning."'),
  ];
  $form['generate_component_button'] = [
    '#type' => 'button',
    '#value' => \Drupal::translation()->translate('Generate SDC Boilerplate'),
    '#ajax' => [
      'callback' => 'groundwork_ai_generate_component_callback',
      'wrapper' => 'component-result-wrapper',
    ],
  ];
  $form['component_result'] = [
    '#type' => 'container',
    '#attributes' => ['id' => 'component-result-wrapper'],
  ];
  return $form;
}

/**
 * Handles the AJAX callback for the AI Component Generator.
 *
 * @param array $form
 * An associative array containing the structure of the form.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 * The current state of the form.
 *
 * @return array
 * A render array containing the generated SDC boilerplate or an error message.
 */
function groundwork_ai_generate_component_callback(array &$form, FormStateInterface $form_state): array {
  $api_key = theme_get_setting('gemini_api_key');
  if (empty($api_key)) {
    return ['#markup' => new TranslatableMarkup('<div class="messages messages--error">Please enter your Gemini API key.</div>')];
  }
  $prompt_text = $form_state->getValue('component_prompt');
  if (empty($prompt_text)) {
    return ['#markup' => new TranslatableMarkup('<div class="messages messages--warning">Please describe the component.</div>')];
  }
  $template = _groundwork_ai_load_prompt('component_generator');
  $system_prompt = str_replace('{{user_prompt}}', htmlspecialchars($prompt_text, ENT_QUOTES, 'UTF-8'), $template);

  try {
    $payload = ['contents' => [['parts' => [['text' => $system_prompt]]]]];
    $body = _groundwork_ai_call_gemini($api_key, $payload);
    $result_text = $body['candidates'][0]['content']['parts'][0]['text'] ?? '';
    $markup = new TranslatableMarkup(
      '<h4>Generated SDC Boilerplate</h4><pre style="white-space: pre-wrap; word-wrap: break-word;">@result</pre>',
      ['@result' => htmlspecialchars($result_text)]
    );
    return ['#markup' => $markup];
  }
  catch (\Exception $e) {
    \Drupal::logger('groundwork_ai')->error($e->getMessage());
    $markup = new TranslatableMarkup('<div class="messages messages--error">An error occurred: @error</div>', ['@error' => $e->getMessage()]);
    return ['#markup' => $markup];
  }
}
