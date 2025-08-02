<?php

/**
 * @file
 * Standardized background settings template for regions.
 *
 * This file is included for each region that supports backgrounds.
 *
 * Variables available:
 * - $region_key: The region machine name (e.g., 'header', 'footer')
 * - $region_label: The human-readable region name
 * - $config: The theme configuration object
 * - $color_options: Array of color options.
 *
 * @ingroup groundwork
 */

$form['regions']['gw_region_backgrounds']['gw_' . $region_key . '_background'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('@region Background', ['@region' => $region_label]),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

// Background color (legacy support)
$form['regions']['gw_region_backgrounds']['gw_' . $region_key . '_background']['gw_background_' . $region_key . '_color'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Background Color (Legacy)'),
  '#description' => \Drupal::translation()->translate('Pre-defined background color. Use Color Schemes above for brand colors.'),
  '#options' => $color_options,
  '#default_value' => $config->get('gw_background_' . $region_key . '_color') ?? '',
];

// Use default background toggle.
$form['regions']['gw_region_backgrounds']['gw_' . $region_key . '_background']['gw_background_' . $region_key . '_use_default'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Use default background (uncheck to set custom background image)'),
  '#default_value' => $config->get('gw_background_' . $region_key . '_use_default') ?? 1,
];

// Custom background wrapper.
$form['regions']['gw_region_backgrounds']['gw_' . $region_key . '_background']['gw_custom_background_wrapper'] = [
  '#type' => 'container',
  '#states' => [
    'invisible' => [
      ':input[name="gw_background_' . $region_key . '_use_default"]' => ['checked' => TRUE],
    ],
  ],
];

// Background image path.
$form['regions']['gw_region_backgrounds']['gw_' . $region_key . '_background']['gw_custom_background_wrapper']['gw_background_' . $region_key . '_path'] = [
  '#type' => 'textfield',
  '#title' => \Drupal::translation()->translate('Background image path'),
  '#default_value' => $config->get('gw_background_' . $region_key . '_path'),
  '#description' => \Drupal::translation()->translate('Examples: background.jpg, public://background.jpg, or themes/custom/groundwork/images/background.jpg'),
];

// Background image upload.
$form['regions']['gw_region_backgrounds']['gw_' . $region_key . '_background']['gw_custom_background_wrapper']['gw_background_' . $region_key . '_upload'] = [
  '#type' => 'managed_file',
  '#title' => \Drupal::translation()->translate('Upload background image'),
  '#description' => \Drupal::translation()->translate('Upload a background image for this region.'),
  '#default_value' => $config->get('gw_background_' . $region_key . '_upload'),
  '#upload_location' => 'public://theme_backgrounds/' . $region_key . '/',
  '#upload_validators' => [
    'FileIsImage' => [],
    'FileExtension' => ['extensions' => 'jpg jpeg png gif svg webp avif'],
  ],
];
