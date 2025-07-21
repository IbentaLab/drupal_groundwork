<?php

/**
 * @file
 * Groundwork Theme Settings form (vertical tabs, AI providers, pro styling).
 *
 * @ingroup groundwork
 */

use Drupal\Core\Form\FormStateInterface;

// Include the init file to make sure AJAX callbacks are available.
include_once __DIR__ . '/init.inc';

function groundwork_form_system_theme_settings_alter(&$form, FormStateInterface $form_state)
{
  // ----- Branded header -----
  $logo_path = groundwork_theme_path() . '/images/groundwork-logo.svg';
  $form['gw_intro'] = [
    '#type' => 'item',
    '#markup' => '
      <div class="gw-settings-header">
        <img src="' . $logo_path . '" alt="Groundwork Logo" class="gw-settings-logo" />
        <h2 class="gw-settings-title">Groundwork Theme Settings</h2>
        <div class="gw-settings-lead">
          Modern, accessible, and AI-powered for Drupal 11+.<br>
          <small>
            Docs: <a href="https://groundwork.ibenta.no/docs" target="_blank">View online</a> &nbsp;|&nbsp;
            <a href="mailto:support@ibenta.no">Contact support</a>
          </small>
        </div>
      </div>
    ',
    '#weight' => -100,
  ];

  // ----- Vertical tabs -----
  $form['gw_settings_tabs'] = [
    '#type' => 'vertical_tabs',
    '#title' => t('Groundwork Theme Settings'),
    '#weight' => -90,
  ];

  // ----- Design & Branding tab -----
  $form['design'] = [
    '#type' => 'details',
    '#title' => t('Design & Branding'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 10,
  ];
  $form['design']['gw_color_scheme'] = [
    '#type' => 'radios',
    '#title' => t('Color scheme'),
    '#default_value' => theme_get_setting('gw_color_scheme'),
    '#options' => [
      'auto' => t('Follow OS setting'),
      'light' => t('Light'),
      'dark' => t('Dark'),
    ],
    '#description' => t('Switch between light and dark mode, or follow the user’s operating system preference.'),
  ];
  $form['design']['gw_custom_css'] = [
  '#type' => 'textarea',
  '#title' => t('Custom CSS'),
  '#description' => t('Add custom CSS for quick tweaks or experiments. Only valid CSS will be rendered. For security reasons, HTML tags (such as &lt;div&gt;, &lt;script&gt;) or JavaScript code are not allowed—if your CSS includes &lt; or &gt;, it will be rejected.'),
  '#default_value' => theme_get_setting('gw_custom_css'),
  '#element_validate' => ['groundwork_validate_custom_css'],
];

  // ----- AI-powered Tools tab -----
  $form['ai_tools'] = [
    '#type' => 'details',
    '#title' => t('AI-powered Tools'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 20,
    '#description' => t('Try the AI-powered color palette generator! Gemini offers 1,000 free requests/month.'),
  ];

  // AI provider dropdown (models in parentheses)
  $form['ai_tools']['ai_provider'] = [
    '#type' => 'select',
    '#title' => t('AI Provider'),
    '#options' => [
      ''            => t('Choose provider...'),
      'gemini'      => t('Google Gemini (Gemini Pro – recommended, free tier)'),
      'openai'      => t('OpenAI (ChatGPT, GPT-4o, GPT-3.5 Turbo)'),
      'openrouter'  => t('OpenRouter (DeepSeek, Llama-3, Mixtral, GPT-4o, etc.)'),
      'huggingface' => t('HuggingFace (DeepSeek, Llama, Mistral, open source)'),
      'azure'       => t('Azure AI (GPT-4, GPT-3.5, vision, enterprise)'),
      'aws'         => t('AWS Bedrock (Anthropic, Amazon Titan, Llama)'),
      'perplexity'  => t('Perplexity AI (PPLX-70B, web-powered Q&A, paid only)'),
      'simulate'    => t('Simulate AI (demo only, no real AI)'),
    ],
    '#default_value' => theme_get_setting('ai_provider') ?: '',
    '#description' => t('Choose your AI provider. Gemini is free for most users. OpenRouter gives you access to DeepSeek, Llama, and many others.'),
  ];
  // Provider-specific API keys
  $form['ai_tools']['ai_gemini_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('Google Gemini API Key'),
    '#description' => t('Get your free API key at <a href="https://ai.google.dev/gemini-api/docs/pricing" target="_blank">Gemini API</a>.'),
    '#default_value' => theme_get_setting('ai_gemini_api_key'),
    '#states' => [
      'visible' => [
        ':input[name="ai_provider"]' => ['value' => 'gemini'],
      ],
    ],
    '#element_validate' => ['groundwork_validate_api_key'],
  ];
  $form['ai_tools']['ai_openai_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('OpenAI API Key'),
    '#description' => t('Get your API key at <a href="https://platform.openai.com/" target="_blank">OpenAI</a>.'),
    '#default_value' => theme_get_setting('ai_openai_api_key'),
    '#states' => [
      'visible' => [
        ':input[name="ai_provider"]' => ['value' => 'openai'],
      ],
    ],
    '#element_validate' => ['groundwork_validate_api_key'],
  ];
  $form['ai_tools']['ai_openrouter_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('OpenRouter API Key'),
    '#description' => t('Get your API key at <a href="https://openrouter.ai/" target="_blank">OpenRouter.ai</a>. Choose your model (DeepSeek, Llama, etc.) in your OpenRouter dashboard.'),
    '#default_value' => theme_get_setting('ai_openrouter_api_key'),
    '#states' => [
      'visible' => [
        ':input[name="ai_provider"]' => ['value' => 'openrouter'],
      ],
    ],
  ];
  $form['ai_tools']['ai_huggingface_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('HuggingFace API Key'),
    '#description' => t('Get your API token at <a href="https://huggingface.co/settings/tokens" target="_blank">HuggingFace</a>. Choose DeepSeek or other open models.'),
    '#default_value' => theme_get_setting('ai_huggingface_api_key'),
    '#states' => [
      'visible' => [
        ':input[name="ai_provider"]' => ['value' => 'huggingface'],
      ],
    ],
  ];
  $form['ai_tools']['ai_azure_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('Azure AI API Key'),
    '#description' => t('Get your API key at <a href="https://portal.azure.com/" target="_blank">Azure Portal</a>.'),
    '#default_value' => theme_get_setting('ai_azure_api_key'),
    '#states' => [
      'visible' => [
        ':input[name="ai_provider"]' => ['value' => 'azure'],
      ],
    ],
  ];
  $form['ai_tools']['ai_aws_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('AWS Bedrock API Key'),
    '#description' => t('Get your API key at <a href="https://console.aws.amazon.com/" target="_blank">AWS Console</a>.'),
    '#default_value' => theme_get_setting('ai_aws_api_key'),
    '#states' => [
      'visible' => [
        ':input[name="ai_provider"]' => ['value' => 'aws'],
      ],
    ],
  ];
  $form['ai_tools']['ai_perplexity_api_key'] = [
    '#type' => 'textfield',
    '#title' => t('Perplexity API Key'),
    '#description' => t('Sign up for a Perplexity API key at <a href="https://docs.perplexity.ai/" target="_blank">Perplexity docs</a>. No free tier.'),
    '#default_value' => theme_get_setting('ai_perplexity_api_key'),
    '#states' => [
      'visible' => [
        ':input[name="ai_provider"]' => ['value' => 'perplexity'],
      ],
    ],
  ];
  // Simulate AI: no API key, just a note
  $form['ai_tools']['ai_simulate_note'] = [
    '#type' => 'container',
    '#states' => [
      'visible' => [
        ':input[name="ai_provider"]' => ['value' => 'simulate'],
      ],
    ],
  ];
  $form['ai_tools']['ai_simulate_note']['markup'] = [
    '#type' => 'markup',
    '#markup' => '<div class="gw-pro-feature-disabled"><strong>Simulate AI:</strong> This is a demo result for testing and development. No real AI is used.</div>',
  ];

  // Image upload for palette suggestion
  $form['ai_tools']['ai_palette_logo'] = [
    '#type' => 'managed_file',
    '#title' => t('Upload logo or image for color palette suggestion'),
    '#upload_location' => 'public://ai_palette/',
    '#default_value' => theme_get_setting('ai_palette_logo'),
    '#description' => t('Upload a logo or image for AI-powered color palette suggestions.'),
  ];
  // Suggestion button (AJAX submit, not fully implemented here)
  $form['ai_tools']['ai_suggest_palette'] = [
    '#type' => 'submit',
    '#value' => t('Suggest Color Palette (AI-powered)'),
    '#ajax' => [
      'callback' => 'groundwork_ai_palette_callback',
      'wrapper' => 'ai-palette-result-wrapper',
      'effect' => 'fade',
    ],
  ];
  $form['ai_tools']['ai_palette_result'] = [
    '#type' => 'markup',
    '#markup' => '<div id="ai-palette-result-wrapper"></div>',
    '#allowed_tags' => ['div', 'span', 'strong'],
  ];

  // ----- Social Links tab -----
$form['social'] = [
  '#type' => 'details',
  '#title' => t('Social Links Bar'),
  '#group' => 'gw_settings_tabs',
  '#weight' => 25, // This places it before the Footer tab
];

// Location Setting
$form['social']['gw_social_bar_location'] = [
  '#type' => 'radios',
  '#title' => t('Location'),
  '#options' => [
    'none' => t('None (Hide the bar)'),
    'header' => t('Above the main site header'),
    'footer' => t('In the footer (above the legal bar)'),
  ],
  '#default_value' => theme_get_setting('gw_social_bar_location') ?: 'footer',
  '#description' => t('Choose where to display the full-width social links bar.'),
];

// Alignment Setting
$form['social']['gw_social_bar_alignment'] = [
  '#type' => 'radios',
  '#title' => t('Link Alignment'),
  '#options' => [
    'left' => t('Left'),
    'center' => t('Center'),
    'right' => t('Right'),
    'distributed' => t('Distributed (Justify)'),
  ],
  '#default_value' => theme_get_setting('gw_social_bar_alignment') ?: 'center',
  '#description' => t('Align the links within the social bar.'),
  // Use #states to hide this if the location is 'none'.
  '#states' => [
    'visible' => [
      ':input[name="gw_social_bar_location"]' => ['!value' => 'none'],
    ],
  ],
];

// Social Network Fields
$form['social']['gw_social_links_intro'] = [
   '#type' => 'markup',
   '#markup' => '<p><strong>' . t('Enter the full URLs for your social media profiles. The bar will only appear if at least one link is entered.') . '</strong></p>',
   '#states' => [ // Also hide this if location is 'none'
     'visible' => [
       ':input[name="gw_social_bar_location"]' => ['!value' => 'none'],
     ],
   ],
];

$social_networks = [
   'twitter'   => t('X (formerly Twitter)'),
   'facebook'  => t('Facebook'),
   'linkedin'  => t('LinkedIn'),
   'instagram' => t('Instagram'),
   'youtube'   => t('YouTube'),
];

foreach ($social_networks as $key => $title) {
   $form['social']['gw_social_' . $key] = [
       '#type' => 'url', // Use 'url' type for better validation
       '#title' => $title,
       '#default_value' => theme_get_setting('gw_social_' . $key),
       '#states' => [ // Also hide these if location is 'none'
         'visible' => [
           ':input[name="gw_social_bar_location"]' => ['!value' => 'none'],
         ],
       ],
   ];
}

  // ----- Footer & Attribution tab -----
  $form['footer'] = [
    '#type' => 'details',
    '#title' => t('Footer & Attribution'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 30,
  ];
  $form['footer']['gw_footer_attribution'] = [
    '#type' => 'checkbox',
    '#title' => t('Show “Powered by Groundwork Theme Framework” in the footer'),
    '#default_value' => 1,
    '#description' => t('This attribution helps support ongoing development. <strong>Removal is available with a <a href=":pro_url" target="_blank">Groundwork Pro license</a>.</strong>', [':pro_url' => 'https://groundwork.ibenta.no/pro']),
    '#attributes' => [
      'disabled' => 'disabled',
    ],
  ];  
  $form['footer']['gw_footer_copyright_enable'] = [
    '#type' => 'checkbox',
    '#title' => t('Show copyright text in the footer'),
    '#default_value' => 1,
    '#description' => t('Uncheck to hide the copyright line from the footer.'),
    '#attributes' => [
      'disabled' => 'disabled',
    ],
  ];
  $site_name = \Drupal::config('system.site')->get('name');
  $default_copyright = t('&copy; {year} @site_name. All rights reserved.', [
    '@site_name' => $site_name,
  ]);
  $form['footer']['gw_footer_copyright'] = [
    '#type' => 'textfield',
    '#title' => t('Footer copyright text'),
    '#description' => t('Supports tokens like {year}, {site_name}. Example: &copy; {year} My Company.<br><strong>Removal is available with a <a href=":pro_url" target="_blank">Groundwork Pro license</a>.</strong>', [':pro_url' => 'https://groundwork.ibenta.no/pro']),
    '#default_value' => theme_get_setting('gw_footer_copyright') ?: $default_copyright,
    '#states' => [
      'visible' => [
        ':input[name="gw_footer_copyright_enable"]' => ['checked' => TRUE],
      ],
    ],
  ];

  // ----- Collapse core Drupal theme settings in their own fieldset -----
  $core_settings = [
    'theme_settings',
    'logo',
    'favicon',
    // Add more as needed.
  ];
  $form['core_settings'] = [
    '#type' => 'details',
    '#title' => t('Drupal Core Theme Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 100,
  ];
  foreach ($core_settings as $key) {
    if (isset($form[$key])) {
      $form['core_settings'][$key] = $form[$key];
      unset($form[$key]);
    }
  }

  // Attach admin CSS for settings page styling.
  $form['#attached']['library'][] = 'groundwork/theme-settings';
}

/**
 * Validation for the custom CSS field.
 */
function groundwork_validate_custom_css($element, FormStateInterface $form_state, $form) {
  $css = $form_state->getValue('gw_custom_css');
  if (preg_match('/[<>]/', $css)) {
    $form_state->setError($element, t('HTML tags are not allowed in custom CSS.'));
  }
}

// Add validation for API keys
function groundwork_validate_api_key($element, FormStateInterface $form_state, $form) {
  $api_key = $form_state->getValue($element['#name']);
  $provider = $form_state->getValue('ai_provider');
  
  // Skip validation if no provider is selected or simulate mode is used
  if (empty($provider) || $provider === 'simulate') {
    return;
  }
  
  if (empty($api_key)) {
    $form_state->setError($element, t('The API key cannot be empty.'));
  }
}
