<?php

/**
 * @file
 * Design and branding settings for Groundwork theme.
 *
 * @ingroup groundwork
 */

// ----- Design & Branding tab -----
$form['design'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Design & Branding'),
  '#group' => 'gw_settings_tabs',
  '#weight' => 10,
];

// ----- Brand Colors -----
$form['design']['gw_brand_colors'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Brand Colors'),
  '#description' => \Drupal::translation()->translate('Define your primary brand colors for consistent theming across all regions.'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
];

$form['design']['gw_brand_colors']['gw_brand_primary'] = [
  '#type' => 'color',
  '#title' => \Drupal::translation()->translate('Primary Brand Color'),
  '#default_value' => $config->get('gw_brand_primary') ?? '#2196f3',
  '#description' => \Drupal::translation()->translate('Your main brand color (buttons, links, highlights).'),
];

$form['design']['gw_brand_colors']['gw_brand_secondary'] = [
  '#type' => 'color',
  '#title' => \Drupal::translation()->translate('Secondary Brand Color'),
  '#default_value' => $config->get('gw_brand_secondary') ?? '#4caf50',
  '#description' => \Drupal::translation()->translate('Supporting brand color for accents and secondary elements.'),
];

$form['design']['gw_brand_colors']['gw_brand_accent'] = [
  '#type' => 'color',
  '#title' => \Drupal::translation()->translate('Accent Color'),
  '#default_value' => $config->get('gw_brand_accent') ?? '#ff9800',
  '#description' => \Drupal::translation()->translate('Accent color for highlights and call-to-action elements.'),
];

// ----- Color Scheme -----
$form['design']['gw_color_scheme'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Color Scheme'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['design']['gw_color_scheme']['gw_theme_mode'] = [
  '#type' => 'radios',
  '#title' => \Drupal::translation()->translate('Theme Mode'),
  '#default_value' => $config->get('gw_theme_mode') ?? 'auto',
  '#options' => [
    'auto' => \Drupal::translation()->translate('Auto (Follow OS setting)'),
    'light' => \Drupal::translation()->translate('Light Mode'),
    'dark' => \Drupal::translation()->translate('Dark Mode'),
  ],
  '#description' => \Drupal::translation()->translate('Choose the color theme for your site.'),
];

$form['design']['gw_color_scheme']['gw_color_utilities'] = [
  '#type' => 'checkboxes',
  '#title' => \Drupal::translation()->translate('Enable Color Utility Palettes'),
  '#description' => \Drupal::translation()->translate('Select additional color utility stylesheets to load.'),
  '#options' => [
    'amber' => \Drupal::translation()->translate('Amber'),
    'blue-gray' => \Drupal::translation()->translate('Blue Gray'),
    'brown' => \Drupal::translation()->translate('Brown'),
    'cyan' => \Drupal::translation()->translate('Cyan'),
    'deep-purple' => \Drupal::translation()->translate('Deep Purple'),
    'green' => \Drupal::translation()->translate('Green'),
    'indigo' => \Drupal::translation()->translate('Indigo'),
    'lime' => \Drupal::translation()->translate('Lime'),
    'orange' => \Drupal::translation()->translate('Orange'),
    'pink' => \Drupal::translation()->translate('Pink'),
    'purple' => \Drupal::translation()->translate('Purple'),
    'red' => \Drupal::translation()->translate('Red'),
    'teal' => \Drupal::translation()->translate('Teal'),
    'yellow' => \Drupal::translation()->translate('Yellow'),
  ],
  '#default_value' => $config->get('gw_color_utilities') ?? [],
];

// ----- Custom CSS -----
$form['design']['gw_custom_css'] = [
  '#type' => 'textarea',
  '#title' => \Drupal::translation()->translate('Custom CSS'),
  '#description' => \Drupal::translation()->translate('Add custom CSS for quick tweaks. HTML tags are not allowed for security.'),
  '#default_value' => $config->get('gw_custom_css'),
  '#element_validate' => ['groundwork_validate_custom_css'],
  '#rows' => 6,
];
