<?php

/**
 * @file
 * Layout and grid settings for Groundwork theme.
 *
 * @ingroup groundwork
 */

// ----- Layout & Grid tab -----
$form['layout'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Layout & Grid'),
  '#group' => 'gw_settings_tabs',
  '#weight' => 15,
];

// ----- Global Layout -----
$form['layout']['gw_global_layout'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Global Layout'),
  '#description' => \Drupal::translation()->translate('Site-wide layout and container settings.'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
];

$form['layout']['gw_global_layout']['gw_container_max_width'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Default Container Max Width'),
  '#options' => [
    '960px' => \Drupal::translation()->translate('960px (Compact)'),
    '1140px' => \Drupal::translation()->translate('1140px (Standard)'),
    '1200px' => \Drupal::translation()->translate('1200px (Wide)'),
    '1320px' => \Drupal::translation()->translate('1320px (Extra Wide)'),
    '1400px' => \Drupal::translation()->translate('1400px (Ultra Wide)'),
  ],
  '#default_value' => $config->get('gw_container_max_width') ?? '1140px',
  '#description' => \Drupal::translation()->translate('Default maximum width for contained layouts.'),
];

$form['layout']['gw_global_layout']['gw_grid_gutter'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Grid Gutter Size'),
  '#options' => [
    'xs' => \Drupal::translation()->translate('Extra Small'),
    'sm' => \Drupal::translation()->translate('Small'),
    'md' => \Drupal::translation()->translate('Medium'),
    'lg' => \Drupal::translation()->translate('Large'),
    'xl' => \Drupal::translation()->translate('Extra Large'),
  ],
  '#default_value' => $config->get('gw_grid_gutter') ?? 'sm',
  '#description' => \Drupal::translation()->translate('Default spacing between grid columns.'),
];

// ----- Region-Specific Layout -----
$form['layout']['gw_region_layout'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Region-Specific Layout'),
  '#description' => \Drupal::translation()->translate('Configure layout for individual regions.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

// Define regions that support layout customization.
$layout_regions = [
  'header' => \Drupal::translation()->translate('Header'),
  'hero' => \Drupal::translation()->translate('Hero'),
  'preface' => \Drupal::translation()->translate('Preface'),
  'content' => \Drupal::translation()->translate('Main Content'),
  'appendix' => \Drupal::translation()->translate('Appendix'),
  'sidebar_first' => \Drupal::translation()->translate('Sidebar First'),
  'sidebar_second' => \Drupal::translation()->translate('Sidebar Second'),
  'supplement' => \Drupal::translation()->translate('Supplement'),
  'extra' => \Drupal::translation()->translate('Extra'),
  'rider' => \Drupal::translation()->translate('Rider'),
  'footer' => \Drupal::translation()->translate('Footer'),
];

foreach ($layout_regions as $region_key => $region_label) {
  $form['layout']['gw_region_layout']['gw_' . $region_key . '_layout'] = [
    '#type' => 'details',
    '#title' => $region_label . ' ' . \Drupal::translation()->translate('Layout'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];

  // Container mode.
  $form['layout']['gw_region_layout']['gw_' . $region_key . '_layout']['gw_' . $region_key . '_container_mode'] = [
    '#type' => 'select',
    '#title' => \Drupal::translation()->translate('Container Mode'),
    '#options' => $container_options,
    '#default_value' => $config->get('gw_' . $region_key . '_container_mode') ?? 'contained',
    '#description' => \Drupal::translation()->translate('How the content should be contained within this region.'),
  ];

  // Grid columns (for specific regions)
  if (in_array($region_key, ['header', 'footer', 'preface', 'appendix'])) {
    $form['layout']['gw_region_layout']['gw_' . $region_key . '_layout']['gw_' . $region_key . '_columns'] = [
      '#type' => 'select',
      '#title' => \Drupal::translation()->translate('Grid Columns'),
      '#options' => array_combine(range(1, 12), range(1, 12)),
      '#default_value' => $config->get('gw_' . $region_key . '_columns') ?? 12,
      '#description' => \Drupal::translation()->translate('Number of grid columns for this region.'),
    ];
  }

  // Padding controls.
  $padding_positions = ['top', 'bottom', 'left', 'right'];
  foreach ($padding_positions as $position) {
    $form['layout']['gw_region_layout']['gw_' . $region_key . '_layout']['gw_' . $region_key . '_padding_' . $position] = [
      '#type' => 'select',
      '#title' => \Drupal::translation()->translate('Padding @position', ['@position' => ucfirst($position)]),
      '#options' => $padding_options,
      '#default_value' => $config->get('gw_' . $region_key . '_padding_' . $position) ?? 'md',
    ];
  }
}
