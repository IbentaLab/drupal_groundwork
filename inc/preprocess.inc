<?php
/**
 * @file
 * Preprocess functions for Groundwork theme.
 * Exposes theme settings to Twig for page/footer rendering.
 *
 * @ingroup groundwork
 */

function groundwork_preprocess_html(array &$variables) {
  if (\Drupal::routeMatch()->getRouteName() === 'block.admin_demo') {
    $variables['attributes']['class'][] = 'page-block-demo';
  }

  $color_scheme = theme_get_setting('gw_color_scheme') ?? 'auto';
  if ($color_scheme === 'dark') {
    $variables['html_attributes']['data-theme'] = 'dark';
  }
  elseif ($color_scheme === 'light') {
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

function groundwork_preprocess_page(array &$variables) {
  $variables['theme_settings'] = [
    'gw_color_scheme' => theme_get_setting('gw_color_scheme'),
    // Only what you actually need for Twig here!
  ];

  if (file_exists(__DIR__ . '/inc/init.inc')) {
    include_once __DIR__ . '/inc/init.inc';
    groundwork_postprocess_footer($variables);
  }
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
function groundwork_preprocess_image_widget(array &$variables): void {
  $data = &$variables['data'];

  if (isset($data['preview']['#access']) && $data['preview']['#access'] === FALSE) {
    unset($data['preview']);
  }
}
