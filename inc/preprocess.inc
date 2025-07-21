<?php

declare(strict_types=1);

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
 *   The variables array for the block template.
 */
function groundwork_preprocess_block(array &$variables): void
{
  // Example: Add block ID as a class.
  // if (!empty($variables['elements']['#id'])) {
  //   $variables['attributes']['class'][] = 'block-id-' . $variables['elements']['#id'];
  // }
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
