<?php

// ----- Social Links tab -----
  $form['social'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Social Links Bar'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 25,
  ];
  $form['social']['gw_social_bar_location'] = [
    '#type' => 'radios',
    '#title' => \Drupal::translation()->translate('Location'),
    '#options' => [
      'none' => \Drupal::translation()->translate('None (Hide the bar)'),
      'header' => \Drupal::translation()->translate('Above the main site header'),
      'footer' => \Drupal::translation()->translate('In the footer (above the legal bar)'),
    ],
    '#default_value' => $config->get('gw_social_bar_location') ?: 'footer',
    '#description' => \Drupal::translation()->translate('Choose where to display the full-width social links bar.'),
  ];
  $form['social']['gw_social_bar_alignment'] = [
    '#type' => 'radios',
    '#title' => \Drupal::translation()->translate('Link Alignment'),
    '#options' => [
      'left' => \Drupal::translation()->translate('Left'),
      'center' => \Drupal::translation()->translate('Center'),
      'right' => \Drupal::translation()->translate('Right'),
      'distributed' => \Drupal::translation()->translate('Distributed (Justify)'),
    ],
    '#default_value' => $config->get('gw_social_bar_alignment') ?: 'center',
    '#description' => \Drupal::translation()->translate('Align the links within the social bar.'),
    '#states' => ['visible' => [':input[name="gw_social_bar_location"]' => ['!value' => 'none']]],
  ];
  $form['social']['gw_social_links_intro'] = [
    '#type' => 'markup',
    '#markup' => '<p><strong>' . \Drupal::translation()->translate('Enter the full URLs for your social media profiles. The bar will only appear if at least one link is entered.') . '</strong></p>',
    '#states' => ['visible' => [':input[name="gw_social_bar_location"]' => ['!value' => 'none']]],
  ];
  $social_networks = [
    'twitter' => \Drupal::translation()->translate('X (formerly Twitter)'),
    'facebook' => \Drupal::translation()->translate('Facebook'),
    'linkedin' => \Drupal::translation()->translate('LinkedIn'),
    'instagram' => \Drupal::translation()->translate('Instagram'),
    'youtube' => \Drupal::translation()->translate('YouTube'),
  ];
  foreach ($social_networks as $key => $title) {
    $form['social']['gw_social_' . $key] = [
      '#type' => 'url',
      '#title' => $title,
      '#default_value' => $config->get('gw_social_' . $key),
      '#states' => ['visible' => [':input[name="gw_social_bar_location"]' => ['!value' => 'none']]],
    ];
  }
