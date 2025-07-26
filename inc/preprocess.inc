<?php

declare(strict_types=1);

use Drupal\block\BlockInterface;

/**
 * @file
 * Preprocess hooks for the Groundwork theme.
 *
 * Place all hook_preprocess_*() implementations here to keep
 * groundwork.theme minimal and maintainable.
 */

/**
 * Implements hook_preprocess_html().
 *
 * Modify global HTML variables before the page is rendered.
 *
 * @param array $variables
 *   The variables for the HTML template.
 */
function groundwork_preprocess_html(array &$variables): void {
  $config = \Drupal::config('groundwork.settings');

  // Add a data-theme attribute for the selected color scheme.
  $color_scheme = $config->get('gw_color_scheme') ?? 'auto';
  if (in_array($color_scheme, ['dark', 'light'])) {
    $variables['html_attributes']['data-theme'] = $color_scheme;
  }

  // Add a class for the block demo page for specific styling.
  $route = \Drupal::routeMatch()->getRouteName();
  if ($route === 'block.admin_demo') {
    $variables['attributes']['class'][] = 'page-block-demo';
    $variables['#attached']['library'][] = 'groundwork/admin-styles';
  }

  // Attach custom CSS from theme settings.
  if ($gw_custom_css = $config->get('gw_custom_css') ?? '') {
    $variables['#attached']['html_head'][] = [
      [
        '#tag' => 'style',
        '#value' => $gw_custom_css,
      ],
      'groundwork-custom-css',
    ];
  }

  // Set the name of the theme's signature validation function.
  $groundwork_signature_function = 'groundwork_signature_check';

  // Verify the theme's signature (for Pro version).
  if (function_exists($groundwork_signature_function) && $groundwork_signature_function()) {
    $site_salt = \Drupal::service('settings')->get('hash_salt');
    $groundwork_signature_class = 'gw-auth-' . substr(md5($groundwork_signature_function . $site_salt), 0, 12);
    $variables['html_attributes']['class'][] = $groundwork_signature_class;

    $groundwork_signature_css_variable = ":root { --groundwork-signature-scope: .{$groundwork_signature_class}; }";
    $variables['#attached']['html_head'][] = [
      [
        '#tag' => 'style',
        '#value' => $groundwork_signature_css_variable,
        '#attributes' => ['id' => 'groundwork-signature-scope'],
      ],
      'groundwork-signature-scope'
    ];

    $variables['#attached']['html_head'][] = [
      [
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => [
          'name' => 'generator',
          'content' => 'This site is built with Groundwork Pro!',
        ],
      ],
      'groundwork-signature-generator-tag'
    ];
  }
}

/**
 * Implements hook_preprocess_page().
 *
 * Adjusts page variables before rendering.
 *
 * @param array $variables
 *   The variables array for the page template.
 */
function groundwork_preprocess_page(array &$variables): void {
  $config = \Drupal::config('groundwork.settings');

  // Process footer elements.
  groundwork_postprocess_footer($variables);

  // Process social media bar.
  $location = $config->get('gw_social_bar_location');
  if ($location === 'none' || !$location) {
    return;
  }

  $social_networks = ['twitter', 'facebook', 'linkedin', 'instagram', 'youtube'];
  $social_network_names = [
    'twitter' => 'Twitter',
    'facebook' => 'Facebook',
    'linkedin' => 'LinkedIn',
    'instagram' => 'Instagram',
    'youtube' => 'YouTube',
  ];

  $links = [];
  foreach ($social_networks as $key) {
    if ($url = $config->get('gw_social_' . $key)) {
      $links[] = [
        'url' => $url,
        'name' => $social_network_names[$key] ?? ucfirst($key),
      ];
    }
  }

  if (empty($links)) {
    return;
  }

  $social_bar_sdc = [
    '#type' => 'component',
    '#component' => 'groundwork:social-bar',
    '#props' => [
      'links' => $links,
      'alignment' => $config->get('gw_social_bar_alignment') ?? 'center',
    ],
  ];

  if ($location === 'header') {
    $variables['page']['social_bar_header'] = $social_bar_sdc;
  }
  elseif ($location === 'footer') {
    $variables['page']['social_bar_footer'] = $social_bar_sdc;
  }
}

/**
 * Implements hook_preprocess_region().
 */
function groundwork_preprocess_region(array &$variables): void {
  if ($variables['region'] === 'header') {
    $header_layout = \Drupal::config('groundwork.settings')->get('gw_header_layout') ?? 'header--brand-left';
    $variables['attributes']['class'][] = $header_layout;
  }
}

/**
 * Implements hook_preprocess_image_widget().
 */
function groundwork_preprocess_image_widget(array &$variables): void {
  $data = &$variables['data'];
  if (isset($data['preview']['#access']) && $data['preview']['#access'] === FALSE) {
    unset($data['preview']);
  }
}

/**
 * Implements hook_preprocess_node().
 */
function groundwork_preprocess_node(array &$variables): void {
  // Example: Add a field value as a CSS class.
  // if (!empty($variables['elements']['#node']->bundle())) {
  //   $variables['attributes']['class'][] = 'gw-' . $variables['elements']['#node']->bundle();
  // }
}

/**
 * Implements hook_preprocess_block().
 */
function groundwork_preprocess_block(array &$variables): void {
  $config = \Drupal::config('groundwork.settings');
  $plugin_id = $variables['plugin_id'] ?? '';

  // Add horizontal menu classes and pass a flag to the menu template.
  if (str_starts_with($plugin_id, 'system_menu_block:')) {
    $menu_name = str_replace('system_menu_block:', '', $plugin_id);
    $is_horizontal_main = ($config->get('gw_menu_main_horizontal') ?? TRUE) && $menu_name === 'main';
    $is_horizontal_secondary = ($config->get('gw_menu_secondary_horizontal') ?? FALSE) && $menu_name === 'secondary';

    if ($is_horizontal_main || $is_horizontal_secondary) {
      $variables['attributes']['class'][] = 'menu--horizontal';
      $variables['content']['#is_horizontal'] = TRUE;
      if ($is_horizontal_main && ($config->get('gw_menu_main_transparent') ?? FALSE)) {
        $variables['attributes']['class'][] = 'menu--transparent';
      }
    }
  }

  // Use responsive grid classes for header blocks.
  if (($variables['elements']['#region'] ?? '') === 'header') {
    if ($plugin_id === 'system_branding_block') {
      $variables['attributes']['class'][] = 'is-12--s';
      $variables['attributes']['class'][] = 'is-4';
    }
    elseif ($plugin_id === 'system_menu_block:main') {
      $variables['attributes']['class'][] = 'is-12--s';
      $variables['attributes']['class'][] = 'is-8';
    }
  }
}

/**
 * Implements hook_preprocess_menu().
 */
function groundwork_preprocess_menu(array &$variables): void {
  if (isset($variables['#is_horizontal'])) {
    $variables['is_horizontal'] = $variables['#is_horizontal'];
  }
}

/**
 * Example: Custom preprocess function for a custom template.
 */
function groundwork_preprocess_my_custom_template(array &$variables): void {
  // Custom logic for my-custom-template.html.twig.
}
