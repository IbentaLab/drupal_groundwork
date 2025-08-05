<?php

/**
 * @file
 * Accessibility settings for Groundwork theme.
 *
 * @ingroup groundwork
 */

// ----- Accessibility tab -----
$form['accessibility'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Accessibility'),
  '#group' => 'gw_settings_tabs',
  '#weight' => 30,
  '#description' => \Drupal::translation()->translate('Configure accessibility features to meet WCAG 2.1 AA standards.'),
];

// ----- Navigation Accessibility -----
$form['accessibility']['gw_nav_accessibility'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Navigation Accessibility'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
];

$form['accessibility']['gw_nav_accessibility']['gw_skip_links'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Enable Skip Links'),
  '#default_value' => $config->get('gw_skip_links') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Add "Skip to main content" links for keyboard navigation.'),
];

$form['accessibility']['gw_nav_accessibility']['gw_focus_outlines'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Enhanced Focus Outlines'),
  '#default_value' => $config->get('gw_focus_outlines') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Provide high-contrast focus indicators for keyboard users.'),
];

$form['accessibility']['gw_nav_accessibility']['gw_keyboard_navigation'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Enhanced Keyboard Navigation'),
  '#default_value' => $config->get('gw_keyboard_navigation') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Improve keyboard navigation with arrow key support in menus.'),
];

// ----- Motion & Animation -----
$form['accessibility']['gw_motion'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Motion & Animation'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['accessibility']['gw_motion']['gw_respect_motion'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Respect Reduced Motion Preference'),
  '#default_value' => $config->get('gw_respect_motion') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Disable animations for users who prefer reduced motion (prefers-reduced-motion).'),
];

$form['accessibility']['gw_motion']['gw_animation_duration'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Default Animation Duration'),
  '#options' => [
    'fast' => \Drupal::translation()->translate('Fast (0.15s)'),
    'normal' => \Drupal::translation()->translate('Normal (0.3s)'),
    'slow' => \Drupal::translation()->translate('Slow (0.5s)'),
  ],
  '#default_value' => $config->get('gw_animation_duration') ?? 'normal',
  '#description' => \Drupal::translation()->translate('Default duration for theme animations and transitions.'),
];

// ----- Color & Contrast -----
$form['accessibility']['gw_contrast'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Color & Contrast'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['accessibility']['gw_contrast']['gw_contrast_mode'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Contrast Target'),
  '#options' => [
    'aa' => \Drupal::translation()->translate('WCAG AA (Standard - 4.5:1)'),
    'aaa' => \Drupal::translation()->translate('WCAG AAA (Enhanced - 7:1)'),
  ],
  '#default_value' => $config->get('gw_contrast_mode') ?? 'aa',
  '#description' => \Drupal::translation()->translate('Target contrast level for text and background combinations.'),
];

$form['accessibility']['gw_contrast']['gw_link_underlines'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Link Underlines'),
  '#options' => [
    'none' => \Drupal::translation()->translate('None (color only)'),
    'hover' => \Drupal::translation()->translate('On hover/focus'),
    'always' => \Drupal::translation()->translate('Always visible'),
  ],
  '#default_value' => $config->get('gw_link_underlines') ?? 'hover',
  '#description' => \Drupal::translation()->translate('Ensure links are distinguishable for users who cannot perceive color.'),
];

// ----- Screen Reader Support -----
$form['accessibility']['gw_screen_reader'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Screen Reader Support'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['accessibility']['gw_screen_reader']['gw_screen_reader_text'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Enhanced Screen Reader Support'),
  '#default_value' => $config->get('gw_screen_reader_text') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Add additional context and labels for screen readers.'),
];

$form['accessibility']['gw_screen_reader']['gw_landmark_roles'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Enhanced Landmark Roles'),
  '#default_value' => $config->get('gw_landmark_roles') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Add comprehensive ARIA landmark roles for better navigation.'),
];

$form['accessibility']['gw_screen_reader']['gw_live_regions'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('ARIA Live Regions'),
  '#default_value' => $config->get('gw_live_regions') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Announce dynamic content changes to screen readers.'),
];
