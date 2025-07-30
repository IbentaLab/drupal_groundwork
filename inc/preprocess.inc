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

  // Attach color utilities based on theme settings.
  $enabled_utilities = array_filter($config->get('gw_color_utilities') ?? []);
  foreach ($enabled_utilities as $utility) {
    $variables['#attached']['library'][] = "groundwork/util-{$utility}";
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
  $config = \Drupal::config('groundwork.settings');
  $region = $variables['elements']['#region'];

  // A list of regions that have background settings.
  $regions_with_backgrounds = [
    'billboard', 'header', 'hero', 'supplement', 'extra', 'rider', 'footer',
  ];

  if (in_array($region, $regions_with_backgrounds)) {
    // Stop if "Use default" is checked for this region.
    if ($config->get('gw_background_' . $region . '_use_default')) {
      return;
    }

    // 1. Set Background Color Class
    $color = $config->get('gw_background_' . $region . '_color');
    if ($color) {
      $variables['attributes']['class'][] = 'bg--' . $color;
    }

    // 2. Set Background Image Style
    $background_image_url = '';
    $upload_fids = $config->get('gw_background_' . $region . '_upload');
    $path = $config->get('gw_background_' . $region . '_path');

    if (!empty($upload_fids[0])) {
      // Priority 1: Use the uploaded file.
      $file = \Drupal\file\Entity\File::load($upload_fids[0]);
      if ($file) {
        $background_image_url = \Drupal::service('file_url_generator')->generateAbsoluteString($file->getFileUri());
      }
    }
    elseif (!empty($path)) {
      // Priority 2: Use the path field.
      // We use file_url_generator to handle paths like 'public://' correctly.
      $background_image_url = \Drupal::service('file_url_generator')->generateAbsoluteString($path);
    }

    if ($background_image_url) {
      // Add the inline style to the region's attributes.
      $variables['attributes']['style'][] = "background-image: url('" . $background_image_url . "');";
    }
  }

  // ------ Header Layout -----
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
  $content = $variables['content'] ?? [];

  // Get the primary theme hook, handling cases where it's an array of suggestions.
  $theme_hook = $content['#theme'] ?? NULL;
  if (is_array($theme_hook)) {
    $theme_hook = reset($theme_hook);
  }

  // Only proceed if this is a menu block with items.
  if (is_string($theme_hook) && str_starts_with($theme_hook, 'menu') && !empty($content['#items'])) {

    // --- Theme Settings Logic ---
    // Check if theme settings should make this menu horizontal by default.
    $menu_name = str_replace('system_menu_block:', '', $plugin_id);
    $is_horizontal_main = ($config->get('gw_menu_main_horizontal') ?? TRUE) && $menu_name === 'main';
    $is_horizontal_secondary = ($config->get('gw_menu_secondary_horizontal') ?? FALSE) && $menu_name === 'secondary';

    if ($is_horizontal_main || $is_horizontal_secondary) {
      $variables['attributes']['class'][] = 'horizontal-menu';
    }
    if ($is_horizontal_main && ($config->get('gw_menu_main_transparent') ?? FALSE)) {
      $variables['attributes']['class'][] = 'menu--transparent';
    }

    // --- SDC Transformation Logic ---
    // Now, check if the .horizontal-menu class exists on the block, either from
    // theme settings or the Block UI.
    $attributes = $variables['attributes']['class'] ?? [];
    if (in_array('horizontal-menu', $attributes)) {
      // Transform the menu items into the structure our SDC expects.
      $sdc_items = _groundwork_build_sdc_menu_items($content['#items']);

      // Replace the original render array with one that calls our SDC.
      $variables['content'] = [
        '#type' => 'component',
        '#component' => 'groundwork:horizontal-menu',
        '#props' => [
          'items' => $sdc_items,
        ],
      ];

      // Debug: Log that we've replaced the content
      \Drupal::logger('groundwork')->notice('Replaced menu content with SDC. Items count: @count', [
        '@count' => count($sdc_items)
      ]);
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
 * Example: Custom preprocess function for a custom template.
 */
function groundwork_preprocess_my_custom_template(array &$variables): void {
  // Custom logic for my-custom-template.html.twig.
}

/**
 * Helper function to recursively transform a Drupal menu array into an SDC-compatible array.
 */
function _groundwork_build_sdc_menu_items(array $menu_items): array {
  $sdc_items = [];

  foreach ($menu_items as $item) {
    // Skip items that don't have the required data
    if (empty($item['title']) || empty($item['url'])) {
      continue;
    }

    $sdc_item = [
      'title' => (string) $item['title'],
      'url' => $item['url']->toString(),
      'is_active' => $item['in_active_trail'] ?? FALSE,
      'children' => !empty($item['below']) ? _groundwork_build_sdc_menu_items($item['below']) : [],
    ];

    $sdc_items[] = $sdc_item;
  }

  return $sdc_items;
}
