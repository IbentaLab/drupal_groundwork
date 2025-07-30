<?php

// ----- Navigation & Menus tab -----
  $form['gw_navigation'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Navigation & Menus'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 15,
    '#description' => \Drupal::translation()->translate('Configure display options for the site header and menus.'),
  ];

  $form['gw_navigation']['gw_menu_main_horizontal'] = [
    '#type' => 'checkbox',
    '#title' => \Drupal::translation()->translate('Display Main menu as a horizontal, responsive menu'),
    '#default_value' => $config->get('gw_menu_main_horizontal') ?? 1,
    '#description' => \Drupal::translation()->translate('When checked, this setting adds the "horizontal-menu" class to the Main Menu block, which renders it using the responsive Horizontal Menu component. This can be overridden in the Block Layout UI.'),
  ];

  $form['gw_navigation']['gw_menu_secondary_horizontal'] = [
    '#type' => 'checkbox',
    '#title' => \Drupal::translation()->translate('Display Secondary menu as a horizontal, responsive menu'),
    '#default_value' => $config->get('gw_menu_secondary_horizontal') ?? 0,
    '#description' => \Drupal::translation()->translate('When checked, this setting adds the "horizontal-menu" class to the Secondary Menu block. This can be overridden in the Block Layout UI.'),
  ];

  $form['gw_navigation']['gw_menu_main_transparent'] = [
    '#type' => 'checkbox',
    '#title' => \Drupal::translation()->translate('Make the horizontal main menu background transparent'),
    '#default_value' => $config->get('gw_menu_main_transparent') ?? 0,
    '#description' => \Drupal::translation()->translate('This only applies if the main menu is set to display horizontally. The menu will inherit the background of its parent region.'),
    '#states' => [
      'visible' => [
        ':input[name="gw_menu_main_horizontal"]' => ['checked' => TRUE],
      ],
    ],
  ];
