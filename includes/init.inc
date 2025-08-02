<?php

declare(strict_types = 1);

use Drupal\Core\Form\FormStateInterface;

/**
 * @file
 * Initialisation and utility helpers for the Groundwork theme.
 *
 * - Define theme constants and functions needed site-wide.
 * - Add system-level postprocessors or AJAX callbacks.
 * - This file is included first from groundwork.theme.
 */

/**
 * AJAX callback for AI-powered color palette suggestion.
 *
 * @param array $form
 * The form render array.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 * The current state of the form.
 *
 * @return array
 * A render array representing the AJAX response.
 */
function groundwork_ai_palette_callback(array &$form, FormStateInterface $form_state) {
  $provider = $form_state->getValue('ai_provider') ?? 'simulate';

  // Handle "Simulate AI" provider.
  if ($provider === 'simulate') {
    return [
      '#type' => 'markup',
      '#markup' => '
        <div class="gw-ai-palette-demo">
          <strong>Simulated Color Palette:</strong><br>
          <span style="display:inline-block;width:32px;height:32px;background:#067cc6 !important;border-radius:4px;margin-right:6px;border:1px solid #ccd;"></span>
          <span style="display:inline-block;width:32px;height:32px;background:#ff8c00 !important;border-radius:4px;margin-right:6px;border:1px solid #ccd;"></span>
          <span style="display:inline-block;width:32px;height:32px;background:#f8fafc !important;border-radius:4px;margin-right:6px;border:1px solid #ccd;"></span>
          <div style="margin-top:0.5em;color:#777;font-size:0.97em;">
            This is a demo result for testing and development.<br>No real AI is used.
          </div>
        </div>
      ',
    ];
  }

  // Handle "Gemini" AI provider.
  if ($provider === 'gemini') {
    $palette = groundwork_fetch_gemini_palette();
    if ($palette) {
      return [
        '#type' => 'markup',
        '#markup' => groundwork_render_palette($palette),
      ];
    }
    else {
      return [
        '#type' => 'markup',
        '#markup' => '<div class="gw-ai-palette-error">Failed to fetch the color palette from Gemini. Please check your API key or try again later.</div>',
      ];
    }
  }

  // Handle "OpenAI" AI provider.
  if ($provider === 'openai') {
    $palette = groundwork_fetch_openai_palette();
    if ($palette) {
      return [
        '#type' => 'markup',
        '#markup' => groundwork_render_palette($palette),
      ];
    }
    else {
      return [
        '#type' => 'markup',
        '#markup' => '<div class="gw-ai-palette-error">Failed to fetch the color palette from OpenAI. Please check your API key or try again later.</div>',
      ];
    }
  }

  // Handle "Azure" AI provider.
  if ($provider === 'azure') {
    $palette = groundwork_fetch_azure_palette();
    if ($palette) {
      return [
        '#type' => 'markup',
        '#markup' => groundwork_render_palette($palette),
      ];
    }
    else {
      return [
        '#type' => 'markup',
        '#markup' => '<div class="gw-ai-palette-error">Failed to fetch the color palette from Azure. Please check your API key or try again later.</div>',
      ];
    }
  }

  // Handle "CustomAPI" provider.
  if ($provider === 'customapi') {
    $palette = groundwork_fetch_customapi_palette();
    if ($palette) {
      return [
        '#type' => 'markup',
        '#markup' => groundwork_render_palette($palette),
      ];
    }
    else {
      return [
        '#type' => 'markup',
        '#markup' => '<div class="gw-ai-palette-error">Failed to fetch the color palette from CustomAPI. Please check your API key or try again later.</div>',
      ];
    }
  }

  // Fallback: show an error for unsupported providers.
  return [
    '#type' => 'markup',
    '#markup' => '<div class="gw-ai-palette-error">The selected AI provider is not supported or not implemented.</div>',
  ];
}

/**
 * Fetches a color palette from the Gemini API.
 *
 * @return array|null
 * An array of color hex codes, or NULL on failure.
 */
function groundwork_fetch_gemini_palette() {
  try {
    // UPDATED: Use the config service to get the theme setting.
    $config = \Drupal::config('groundwork.settings');
    $api_key = $config->get('ai_gemini_api_key') ?? '';

    $response = \Drupal::httpClient()->get('https://api.gemini.com/palette', [
      'headers' => [
        'Authorization' => 'Bearer ' . $api_key,
      ],
    ]);

    if ($response->getStatusCode() === 200) {
      $data = json_decode((string) $response->getBody(), TRUE);
      return $data['palette'] ?? NULL;
    }
  }
  catch (\Exception $e) {
    \Drupal::logger('groundwork')->error('Gemini API error: @message', ['@message' => $e->getMessage()]);
  }

  return NULL;
}

/**
 * Fetches a color palette from the OpenAI API.
 *
 * @return array|null
 * An array of color hex codes, or NULL on failure.
 */
function groundwork_fetch_openai_palette() {
  try {
    // UPDATED: Use the config service to get the theme setting.
    $config = \Drupal::config('groundwork.settings');
    $api_key = $config->get('ai_openai_api_key') ?? '';

    $response = \Drupal::httpClient()->post('https://api.openai.com/v1/palette', [
      'headers' => [
        'Authorization' => 'Bearer ' . $api_key,
        'Content-Type' => 'application/json',
      ],
      'json' => [
        'prompt' => 'Generate a color palette based on the uploaded image.',
      ],
    ]);

    if ($response->getStatusCode() === 200) {
      $data = json_decode((string) $response->getBody(), TRUE);
      return $data['palette'] ?? NULL;
    }
  }
  catch (\Exception $e) {
    \Drupal::logger('groundwork')->error('OpenAI API error: @message', ['@message' => $e->getMessage()]);
  }

  return NULL;
}

/**
 * Fetches a color palette from the Azure API.
 *
 * @return array|null
 * An array of color hex codes, or NULL on failure.
 */
function groundwork_fetch_azure_palette() {
  try {
    // UPDATED: Use the config service to get the theme setting.
    $config = \Drupal::config('groundwork.settings');
    $api_key = $config->get('ai_azure_api_key') ?? '';

    $response = \Drupal::httpClient()->post('https://api.azure.com/v1/palette', [
      'headers' => [
        'Authorization' => 'Bearer ' . $api_key,
        'Content-Type' => 'application/json',
      ],
      'json' => [
        'prompt' => 'Generate a color palette based on the uploaded image.',
      ],
    ]);

    if ($response->getStatusCode() === 200) {
      $data = json_decode((string) $response->getBody(), TRUE);
      return $data['palette'] ?? NULL;
    }
  }
  catch (\Exception $e) {
    \Drupal::logger('groundwork')->error('Azure API error: @message', ['@message' => $e->getMessage()]);
  }

  return NULL;
}

/**
 * Fetches a color palette from a Custom API.
 *
 * @return array|null
 * An array of color hex codes, or NULL on failure.
 */
function groundwork_fetch_customapi_palette() {
  try {
    // UPDATED: Use the config service to get the theme setting.
    $config = \Drupal::config('groundwork.settings');
    $api_key = $config->get('ai_customapi_api_key') ?? '';

    $response = \Drupal::httpClient()->post('https://api.customapi.com/palette', [
      'headers' => [
        'Authorization' => 'Bearer ' . $api_key,
        'Content-Type' => 'application/json',
      ],
      'json' => [
        'prompt' => 'Generate a color palette based on the uploaded image.',
      ],
    ]);

    if ($response->getStatusCode() === 200) {
      $data = json_decode((string) $response->getBody(), TRUE);
      return $data['palette'] ?? NULL;
    }
  }
  catch (\Exception $e) {
    \Drupal::logger('groundwork')->error('CustomAPI error: @message', ['@message' => $e->getMessage()]);
  }

  return NULL;
}

/**
 * Renders a color palette as HTML.
 *
 * @param array $palette
 * An array of color hex codes.
 *
 * @return string
 * Rendered HTML for the color palette.
 */
function groundwork_render_palette(array $palette): string {
  $output = '<div class="gw-ai-palette-demo"><strong>AI-Generated Color Palette:</strong><br>';
  foreach ($palette as $color) {
    $output .= '<span style="display:inline-block;width:32px;height:32px;background:' . \Drupal\Component\Utility\Html::escape($color) . ';border-radius:4px;margin-right:6px;border:1px solid #ccd;"></span>';
  }
  $output .= '</div>';
  return $output;
}

/**
 * Adds Groundwork's system utility to the footer region.
 * (Core theme integration — do not remove or modify.)
 *
 * @internal
 *
 * @param array $variables
 * The page variables array passed by reference.
 */
function groundwork_postprocess_footer(array &$variables): void {
  // --- Always show attribution and copyright for GPL (free) users ---
  // For now, force both on for GPL version:
  $show_attribution = 1;
  $copyright_enabled = 1;

  // UPDATED: Use the config service to get the theme setting.
  $config = \Drupal::config('groundwork.settings');
  $copyright_text = trim($config->get('gw_footer_copyright') ?? '');

  $site_name = \Drupal::config('system.site')->get('name') ?? 'Drupal powered by Groundwork';
  // Use the string_translation service, as global t() is removed in Drupal 11.
  $default_copyright = \Drupal::translation()->translate('&copy; {year} @site_name. All rights reserved.', [
    '@site_name' => $site_name,
  ]);
  $year = date('Y');

  $footer_utility = '';
  if ($show_attribution) {
    // Use the string_translation service here as well.
    $footer_utility .= \Drupal::translation()->translate('Site powered by') . ' <a href="https://groundwork.ibenta.no" rel="nofollow">Groundwork Theme Framework</a>.';
  }
  if ($show_attribution && $copyright_enabled) {
    $footer_utility .= ' <span aria-hidden="true">|</span> ';
  }
  if ($copyright_enabled) {
    $output_copyright = $copyright_text ?: $default_copyright;
    // Cast the variable to a string before using it in str_replace.
    $output_copyright = str_replace(['{year}', '{site_name}'], [$year, $site_name], (string) $output_copyright);
    $footer_utility .= $output_copyright;
  }

  // This correctly adds the legal text as a renderable element to the footer region.
  $variables['page']['footer']['groundwork_footer_system_utility'] = [
    '#type' => 'markup',
    '#markup' => '<div class="site-footer__legal">' . $footer_utility . '</div>',
    '#allowed_tags' => ['a', 'span', 'div'],
    '#weight' => 10000,
  ];
}

/**
 * Example: Define a theme constant.
 */
// define('GROUNDWORK_VERSION', '1.0.0');

/**
 * Example: Custom bootstrap logic (runs on every page).
 */
// function groundwork_init_custom() {
//   // Add custom logic here.
// }

