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
function groundwork_preprocess_html(array &$variables)
{
  if (\Drupal::routeMatch()->getRouteName() === 'block.admin_demo') {
    $variables['attributes']['class'][] = 'page-block-demo';
  }

  $color_scheme = theme_get_setting('gw_color_scheme') ?? 'auto';
  if ($color_scheme === 'dark') {
    $variables['html_attributes']['data-theme'] = 'dark';
  } elseif ($color_scheme === 'light') {
    $variables['html_attributes']['data-theme'] = 'light';
  }

  if ($gw_custom_css = theme_get_setting('gw_custom_css') ?? '') {
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

  // Verify the theme's signature.
  if (function_exists($groundwork_signature_function) && $groundwork_signature_function()) {

    // Get the unique, private hash salt for this specific Drupal site.
    $site_salt = \Drupal\Component\Utility\Crypt::getHashSalt();

    // Generate a dynamic class name unique to this site.
    $groundwork_signature_class = '.gw-auth-' . substr(md5($groundwork_signature_function . $site_salt), 0, 12);

    // Add the unique class to the <html> element.
    $variables['html_attributes']['class'][] = ltrim($groundwork_signature_class, '.');

    // Define a dynamic CSS variable to hold the unique signature class.
    $groundwork_signature_css_variable = "
      :root {
        --groundwork-signature-scope: {$groundwork_signature_class};
      }
    ";

    // Attach the dynamic CSS variable definition to the page header.
    $variables['#attached']['html_head'][] = [
      [
        '#tag' => 'style',
        '#value' => $groundwork_signature_css_variable,
        '#attributes' => ['id' => 'groundwork-signature-scope'],
      ],
      'groundwork-signature-scope'
    ];

    // Add a generator meta tag for identification.
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
function groundwork_preprocess_page(array &$variables)
{
  $variables['theme_settings'] = [
    'gw_color_scheme' => theme_get_setting('gw_color_scheme'),
    // Only what you actually need for Twig here!
  ];

  groundwork_postprocess_footer($variables);

  if (\Drupal::routeMatch()->getRouteName() === 'block.admin_demo') {
    $variables['#attached']['library'][] = 'groundwork/block-demo';
  }

  // Pass pro status to all templates. We'll use this later.
  $variables['is_pro'] = function_exists('groundwork_is_pro') && groundwork_is_pro();

  // --- Prepare the Social Bar SDC ---
  $location = theme_get_setting('gw_social_bar_location');

  // Stop if the bar is disabled.
  if ($location === 'none') {
    return;
  }

  // Get social links from settings.
  $social_networks = ['twitter', 'facebook', 'linkedin', 'instagram', 'youtube'];

  // Create a mapping for proper brand names.
  $social_network_names = [
    'twitter' => 'Twitter',
    'facebook' => 'Facebook',
    'linkedin' => 'LinkedIn',
    'instagram' => 'Instagram',
    'youtube' => 'YouTube',
  ];

  $links = [];
  foreach ($social_networks as $key) {
    if ($url = theme_get_setting('gw_social_' . $key)) {
      $links[] = [
        'url' => $url,
        // Use the mapping, with a fallback to the old behavior.
        'name' => $social_network_names[$key] ?? ucfirst($key),
      ];
    }
  }

  // Stop if there are no links to show.
  if (empty($links)) {
    return;
  }

  // Build the render array for the SDC.
  $social_bar_sdc = [
    '#type' => 'component',
    '#component' => 'groundwork:social-bar',
    '#props' => [
      'links' => $links,
      'alignment' => theme_get_setting('gw_social_bar_alignment'),
    ],
  ];

  // Put the SDC into the correct variable based on the location setting.
  if ($location === 'header') {
    $variables['page']['social_bar_header'] = $social_bar_sdc;
  } elseif ($location === 'footer') {
    // Look at your screenshot, this should go above the grey legal bar.
    $variables['page']['social_bar_footer'] = $social_bar_sdc;
  }

}

/**
 * Implements hook_preprocess_image_widget().
 *
 * Prevents image widget templates from rendering the preview container
 * to users without permission to access previews.
 *
 * @todo Revisit in https://drupal.org/node/953034 and https://drupal.org/node/3114318
 */
function groundwork_preprocess_image_widget(array &$variables): void
{
  $data = &$variables['data'];

  if (isset($data['preview']['#access']) && $data['preview']['#access'] === FALSE) {
    unset($data['preview']);
  }
}

/**
 * Implements hook_preprocess_node().
 *
 * Alter variables before a node is rendered.
 *
 * @param array $variables
 *   The variables array for the node template.
 */
function groundwork_preprocess_node(array &$variables): void
{
  // Example: Add a field value as a CSS class.
  // if (!empty($variables['elements']['#node']->bundle())) {
  //   $variables['attributes']['class'][] = 'gw-' . $variables['elements']['#node']->bundle();
  // }
}

/**
 * Implements hook_preprocess_block().
 *
 * @param array $variables
 * An associative array containing:
 * - elements: An array of elements for this block.
 * - attributes: An array of HTML attributes for the block wrapper.
 * - configuration: An array of configuration values for this block.
 * - plugin_id: The ID of the block plugin.
 */
function groundwork_preprocess_block(array &$variables): void {
  $plugin_id = $variables['plugin_id'] ?? '';
  $is_system_menu_block = str_starts_with($plugin_id, 'system_menu_block:');

  if ($is_system_menu_block) {
    $menu_name = substr($plugin_id, strlen('system_menu_block:'));
    $is_horizontal_main = (theme_get_setting('gw_menu_main_horizontal') ?? 1) && $menu_name === 'main';
    $is_horizontal_secondary = (theme_get_setting('gw_menu_secondary_horizontal') ?? 0) && $menu_name === 'secondary';

    if ($is_horizontal_main || $is_horizontal_secondary) {
      $variables['attributes']['class'][] = 'menu--horizontal';
      // Pass the #is_horizontal flag to the menu's render array.
      $variables['content']['#is_horizontal'] = TRUE;

      if ($is_horizontal_main && (theme_get_setting('gw_menu_main_transparent') ?? 0)) {
        $variables['attributes']['class'][] = 'menu--transparent';
      }
    }
  }

  if (($variables['elements']['#region'] ?? '') === 'header') {
    if ($plugin_id === 'system_branding_block') {
      $variables['attributes']['class'][] = 'is-4';
    }
    elseif ($plugin_id === 'system_menu_block:main') {
      $variables['attributes']['class'][] = 'is-8';
    }
  }
}

/**
 * Implements hook_preprocess_menu().
 *
 * This function acts as a bridge, passing the #is_horizontal flag from the
 * block's content render array into the menu.html.twig template's scope.
 * THIS IS THE KEY FIX for the mobile menu.
 */
function groundwork_preprocess_menu(array &$variables): void {
  if (isset($variables['#is_horizontal'])) {
    $variables['is_horizontal'] = $variables['#is_horizontal'];
  }
}

/**
 * Example: Custom preprocess function for a custom template.
 *
 * This would be auto-called as groundwork_preprocess_MY_TEMPLATE().
 *
 * @param array $variables
 *   The variables array for the custom template.
 */
function groundwork_preprocess_my_custom_template(array &$variables): void
{
  // Custom logic for my-custom-template.html.twig.
}
