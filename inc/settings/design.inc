<?php

// ----- Design & Branding tab -----
  $form['design'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Colors and Design'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 10,
  ];

  // ----- Colors -----
  $form['design']['gw_colors'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Colors'),
    '#description' => \Drupal::translation()->translate('Customize the color palette for the theme.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];
  $form['design']['gw_colors']['gw_color_scheme'] = [
    '#type' => 'radios',
    '#title' => \Drupal::translation()->translate('Color scheme'),
    '#default_value' => $config->get('gw_color_scheme'),
    '#options' => [
      'auto' => \Drupal::translation()->translate('Follow OS setting'),
      'light' => \Drupal::translation()->translate('Light'),
      'dark' => \Drupal::translation()->translate('Dark'),
    ],
    '#description' => \Drupal::translation()->translate('Switch between light and dark mode, or follow the user’s operating system preference.'),
  ];
  $form['design']['gw_colors']['gw_color_utilities'] = [
    '#type' => 'checkboxes',
    '#title' => \Drupal::translation()->translate('Enable Color Utility Palettes'),
    '#description' => \Drupal::translation()->translate('Select which color utility stylesheets to load. Each enabled color provides a set of utility classes (e.g., .red, .red--dark1).'),
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

  $form['design']['gw_custom_css'] = [
    '#type' => 'textarea',
    '#title' => \Drupal::translation()->translate('Custom CSS'),
    '#description' => \Drupal::translation()->translate('Add custom CSS for quick tweaks or experiments. Only valid CSS will be rendered. For security reasons, HTML tags (such as &lt;div&gt;, &lt;script&gt;) or JavaScript code are not allowed—if your CSS includes &lt; or &gt;, it will be rejected.'),
    '#default_value' => $config->get('gw_custom_css'),
    '#element_validate' => ['groundwork_validate_custom_css'],
  ];

