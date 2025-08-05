<?php

/**
 * @file
 * SEO and meta settings for Groundwork theme.
 */

// ----- SEO & Meta tab -----
$form['seo'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('SEO & Meta'),
  '#group' => 'gw_settings_tabs',
  '#weight' => 40,
];

// ----- Meta Tags -----
$form['seo']['gw_meta'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Meta Tags'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
];

$form['seo']['gw_meta']['gw_meta_description'] = [
  '#type' => 'textarea',
  '#title' => \Drupal::translation()->translate('Default Meta Description'),
  '#default_value' => $config->get('gw_meta_description') ?? '',
  '#description' => \Drupal::translation()->translate('Default meta description for pages without specific descriptions.'),
  '#rows' => 3,
  '#maxlength' => 160,
];

$form['seo']['gw_meta']['gw_meta_keywords'] = [
  '#type' => 'textfield',
  '#title' => \Drupal::translation()->translate('Default Meta Keywords'),
  '#default_value' => $config->get('gw_meta_keywords') ?? '',
  '#description' => \Drupal::translation()->translate('Comma-separated keywords (mostly ignored by search engines).'),
];

// ----- Open Graph -----
$form['seo']['gw_opengraph'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Open Graph / Social Media'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['seo']['gw_opengraph']['gw_og_enable'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Enable Open Graph meta tags'),
  '#default_value' => $config->get('gw_og_enable') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Add Open Graph tags for better social media sharing.'),
];

$form['seo']['gw_opengraph']['gw_og_image'] = [
  '#type' => 'managed_file',
  '#title' => \Drupal::translation()->translate('Default Open Graph Image'),
  '#description' => \Drupal::translation()->translate('Default image for social media sharing (1200x630px recommended).'),
  '#default_value' => $config->get('gw_og_image'),
  '#upload_location' => 'public://og_images/',
  '#upload_validators' => [
    'FileIsImage' => [],
    'FileExtension' => ['extensions' => 'jpg jpeg png'],
  ],
  '#states' => [
    'visible' => [
      ':input[name="gw_og_enable"]' => ['checked' => TRUE],
    ],
  ],
];

$form['seo']['gw_opengraph']['gw_twitter_cards'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Enable Twitter Card meta tags'),
  '#default_value' => $config->get('gw_twitter_cards') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Add Twitter Card tags for better Twitter sharing.'),
  '#states' => [
    'visible' => [
      ':input[name="gw_og_enable"]' => ['checked' => TRUE],
    ],
  ],
];

// ----- Structured Data -----
$form['seo']['gw_schema'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Structured Data'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['seo']['gw_schema']['gw_schema_org'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Enable Schema.org markup'),
  '#default_value' => $config->get('gw_schema_org') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Add structured data markup for search engines.'),
];

$form['seo']['gw_schema']['gw_schema_organization'] = [
  '#type' => 'textfield',
  '#title' => \Drupal::translation()->translate('Organization Name'),
  '#default_value' => $config->get('gw_schema_organization') ?? '',
  '#description' => \Drupal::translation()->translate('Your organization name for Schema.org markup.'),
  '#states' => [
    'visible' => [
      ':input[name="gw_schema_org"]' => ['checked' => TRUE],
    ],
  ],
];

// ----- Breadcrumbs -----
$form['seo']['gw_breadcrumbs'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Breadcrumbs'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['seo']['gw_breadcrumbs']['gw_breadcrumbs_enable'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Show breadcrumbs'),
  '#default_value' => $config->get('gw_breadcrumbs_enable') ?? TRUE,
  '#description' => \Drupal::translation()->translate('Display breadcrumb navigation for better SEO and UX.'),
];

$form['seo']['gw_breadcrumbs']['gw_breadcrumbs_home'] = [
  '#type' => 'textfield',
  '#title' => \Drupal::translation()->translate('Home breadcrumb text'),
  '#default_value' => $config->get('gw_breadcrumbs_home') ?? 'Home',
  '#description' => \Drupal::translation()->translate('Text for the home link in breadcrumbs.'),
  '#states' => [
    'visible' => [
      ':input[name="gw_breadcrumbs_enable"]' => ['checked' => TRUE],
    ],
  ],
];
