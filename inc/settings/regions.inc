<?php

// ----- Regions Tab -----
$form['gw_regions'] = [
  '#type' => 'details',
  '#title' => t('Regions'),
  '#group' => 'gw_settings_tabs',
  '#weight' => 12, // Adjust weight as needed
  '#description' => t('Configure settings for specific theme regions, such as sidebars, headers, and footers.'),
];

// ----- Billboard Settings -----
$form['gw_regions']['gw_billboard'] = [
  '#type' => 'details',
  '#title' => t('Billboard'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_billboard']['gw_billboard_background'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Background'),
  '#description' => \Drupal::translation()->translate('Configure the background image and color for this region.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_billboard']['gw_billboard_background']['gw_background_billboard_color'] = [
  '#type' => 'select',
  '#title' => t('Background Color'),
  '#description' => t("Choose a pre-defined background color for the billboard region. This is overridden if a background image is set."),
  '#options' => [
    '' => t('- Default -'),
    'blue' => t('Blue'),
    'indigo' => t('Indigo'),
    'deep-purple' => t('Deep Purple'),
    'purple' => t('Purple'),
    'pink' => t('Pink'),
    'red' => t('Red'),
    'orange' => t('Orange'),
    'amber' => t('Amber'),
    'yellow' => t('Yellow'),
    'lime' => t('Lime'),
    'green' => t('Green'),
    'teal' => t('Teal'),
    'cyan' => t('Cyan'),
    'brown' => t('Brown'),
    'blue-gray' => t('Blue Gray'),
    'gray' => t('Gray'),
  ],
  '#default_value' => $config->get('gw_background_billboard_color') ?? '',
];

$form['gw_regions']['gw_billboard']['gw_billboard_background']['gw_background_billboard_use_default'] = [
  '#type' => 'checkbox',
  '#title' => t("Uncheck to define your custom background image"),
  '#default_value' => $config->get('gw_background_billboard_use_default') ?? 1,
];

$form['gw_regions']['gw_billboard']['gw_billboard_background']['gw_custom_background_wrapper'] = [
  '#type' => 'container',
  '#states' => [
    'invisible' => [
      ':input[name="gw_background_billboard_use_default"]' => ['checked' => TRUE],
    ],
  ],
];

$form['gw_regions']['gw_billboard']['gw_billboard_background']['gw_custom_background_wrapper']['gw_background_billboard_path'] = [
  '#type' => 'textfield',
  '#title' => t('Path to custom billboard background image'),
  '#default_value' => $config->get('gw_background_billboard_path'),
  '#description' => t('Examples: background.jpg, public://background.jpg, or themes/custom/groundwork/images/background.jpg.'),
];

$form['gw_regions']['gw_billboard']['gw_billboard_background']['gw_custom_background_wrapper']['gw_background_billboard_upload'] = [
  '#type' => 'managed_file',
  '#title' => t('Upload billboard background image'),
  '#description' => t("If you don't have direct file access, use this field to upload your background image."),
  '#default_value' => $config->get('gw_background_billboard_upload'),
  '#upload_location' => 'public://theme_backgrounds/billboard/',
  '#upload_validators' => [
    'FileIsImage' => [],
    'FileExtension' => ['extensions' => 'jpg jpeg png gif svg webp avif'],
  ],
];

// ----- Header Settings -----
$form['gw_regions']['gw_header'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Header'),
  '#description' => \Drupal::translation()->translate('Configure header background and layout options.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_header']['gw_header_background'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Background'),
  '#description' => \Drupal::translation()->translate('Configure the background image and color for this region.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_header']['gw_header_background']['gw_background_header_color'] = [
  '#type' => 'select',
  '#title' => t('Background Color'),
  '#description' => t("Choose a pre-defined background color for the header region. This is overridden if a background image is set."),
  '#options' => [
    '' => t('- Default -'),
    'blue' => t('Blue'),
    'indigo' => t('Indigo'),
    'deep-purple' => t('Deep Purple'),
    'purple' => t('Purple'),
    'pink' => t('Pink'),
    'red' => t('Red'),
    'orange' => t('Orange'),
    'amber' => t('Amber'),
    'yellow' => t('Yellow'),
    'lime' => t('Lime'),
    'green' => t('Green'),
    'teal' => t('Teal'),
    'cyan' => t('Cyan'),
    'brown' => t('Brown'),
    'blue-gray' => t('Blue Gray'),
    'gray' => t('Gray'),
  ],
  '#default_value' => $config->get('gw_background_header_color') ?? 'blue',
];

$form['gw_regions']['gw_header']['gw_header_background']['gw_background_header_use_default'] = [
  '#type' => 'checkbox',
  '#title' => t("Uncheck to define your custom background image"),
  '#default_value' => $config->get('gw_background_header_use_default') ?? 1,
];

$form['gw_regions']['gw_header']['gw_header_background']['gw_custom_background_wrapper'] = [
  '#type' => 'container',
  '#states' => [
    'invisible' => [
      ':input[name="gw_background_header_use_default"]' => ['checked' => TRUE],
    ],
  ],
];

$form['gw_regions']['gw_header']['gw_header_background']['gw_custom_background_wrapper']['gw_background_header_path'] = [
  '#type' => 'textfield',
  '#title' => t('Path to custom header background image'),
  '#default_value' => $config->get('gw_background_header_path'),
  '#description' => t('Examples: background.jpg, public://background.jpg, or themes/custom/groundwork/images/background.jpg.'),
];

$form['gw_regions']['gw_header']['gw_header_background']['gw_custom_background_wrapper']['gw_background_header_upload'] = [
  '#type' => 'managed_file',
  '#title' => t('Upload header background image'),
  '#description' => t("If you don't have direct file access, use this field to upload your background image."),
  '#default_value' => $config->get('gw_background_header_upload'),
  '#upload_location' => 'public://theme_backgrounds/header/',
  '#upload_validators' => [
    'FileIsImage' => [],
    'FileExtension' => ['extensions' => 'jpg jpeg png gif svg webp avif'],
  ],
];

// ----- Hero Settings -----
$form['gw_regions']['gw_hero'] = [
  '#type' => 'details',
  '#title' => t('Hero'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_hero']['gw_hero_background'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Background'),
  '#description' => \Drupal::translation()->translate('Configure the background image and color for this region.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_hero']['gw_hero_background']['gw_background_hero_color'] = [
  '#type' => 'select',
  '#title' => t('Background Color'),
  '#description' => t("Choose a pre-defined background color for the hero region. This is overridden if a background image is set."),
  '#options' => [
    '' => t('- Default -'),
    'blue' => t('Blue'),
    'indigo' => t('Indigo'),
    'deep-purple' => t('Deep Purple'),
    'purple' => t('Purple'),
    'pink' => t('Pink'),
    'red' => t('Red'),
    'orange' => t('Orange'),
    'amber' => t('Amber'),
    'yellow' => t('Yellow'),
    'lime' => t('Lime'),
    'green' => t('Green'),
    'teal' => t('Teal'),
    'cyan' => t('Cyan'),
    'brown' => t('Brown'),
    'blue-gray' => t('Blue Gray'),
    'gray' => t('Gray'),
  ],
  '#default_value' => $config->get('gw_background_hero_color') ?? '',
];

$form['gw_regions']['gw_hero']['gw_hero_background']['gw_background_hero_use_default'] = [
  '#type' => 'checkbox',
  '#title' => t("Uncheck to define your custom background image"),
  '#default_value' => $config->get('gw_background_hero_use_default') ?? 1,
];

$form['gw_regions']['gw_hero']['gw_hero_background']['gw_custom_background_wrapper'] = [
  '#type' => 'container',
  '#states' => [
    'invisible' => [
      ':input[name="gw_background_hero_use_default"]' => ['checked' => TRUE],
    ],
  ],
];

$form['gw_regions']['gw_hero']['gw_hero_background']['gw_custom_background_wrapper']['gw_background_hero_path'] = [
  '#type' => 'textfield',
  '#title' => t('Path to custom hero background image'),
  '#default_value' => $config->get('gw_background_hero_path'),
  '#description' => t('Examples: background.jpg, public://background.jpg, or themes/custom/groundwork/images/background.jpg.'),
];

$form['gw_regions']['gw_hero']['gw_hero_background']['gw_custom_background_wrapper']['gw_background_hero_upload'] = [
  '#type' => 'managed_file',
  '#title' => t('Upload hero background image'),
  '#description' => t("If you don't have direct file access, use this field to upload your background image."),
  '#default_value' => $config->get('gw_background_hero_upload'),
  '#upload_location' => 'public://theme_backgrounds/hero/',
  '#upload_validators' => [
    'FileIsImage' => [],
    'FileExtension' => ['extensions' => 'jpg jpeg png gif svg webp avif'],
  ],
];

// ----- Sidebar Settings -----
$form['gw_regions']['gw_sidebars'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Sidebars'),
  '#description' => \Drupal::translation()->translate('Set the widths for the sidebars at different breakpoints.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

// Sidebar First fieldset
$form['gw_regions']['gw_sidebars']['gw_sidebar_first'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Sidebar First Grid Widths'),
  '#description' => \Drupal::translation()->translate('Choose how many grid cells Sidebar First should occupy on each breakpoint. Default layout is 4 on desktop and 3 on wide.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];
$form['gw_regions']['gw_sidebars']['gw_sidebar_first']['gw_sidebar_first_cells_s'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Mobile (S)'),
  '#options' => array_combine(range(1, 12), range(1, 12)),
  '#default_value' => $config->get('gw_sidebar_first_cells_s') ?? 12,
];
$form['gw_regions']['gw_sidebars']['gw_sidebar_first']['gw_sidebar_first_cells_m'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Desktop (M)'),
  '#options' => array_combine(range(1, 12), range(1, 12)),
  '#default_value' => $config->get('gw_sidebar_first_cells_m') ?? 4,
];
$form['gw_regions']['gw_sidebars']['gw_sidebar_first']['gw_sidebar_first_cells_l'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Wide (L)'),
  '#options' => array_combine(range(1, 12), range(1, 12)),
  '#default_value' => $config->get('gw_sidebar_first_cells_l') ?? 3,
];

// Sidebar Second fieldset
$form['gw_regions']['gw_sidebars']['gw_sidebar_second'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Sidebar Second Grid Widths'),
  '#description' => \Drupal::translation()->translate('Choose how many grid cells Sidebar Second should occupy on each breakpoint. Default layout is 2 on desktop and wide.'),
  '#attributes' => ['class' => ['gw-sidebar-settings', 'gw-horizontal-selects']],
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];
$form['gw_regions']['gw_sidebars']['gw_sidebar_second']['gw_sidebar_second_cells_s'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Mobile (S)'),
  '#options' => array_combine(range(1, 12), range(1, 12)),
  '#default_value' => $config->get('gw_sidebar_second_cells_s') ?? 12,
];
$form['gw_regions']['gw_sidebars']['gw_sidebar_second']['gw_sidebar_second_cells_m'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Desktop (M)'),
  '#options' => array_combine(range(1, 12), range(1, 12)),
  '#default_value' => $config->get('gw_sidebar_second_cells_m') ?? 2,
];
$form['gw_regions']['gw_sidebars']['gw_sidebar_second']['gw_sidebar_second_cells_l'] = [
  '#type' => 'select',
  '#title' => \Drupal::translation()->translate('Wide (L)'),
  '#options' => array_combine(range(1, 12), range(1, 12)),
  '#default_value' => $config->get('gw_sidebar_second_cells_l') ?? 2,
];

// ----- Extra Settings -----
$form['gw_regions']['gw_extra'] = [
  '#type' => 'details',
  '#title' => t('Extra'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_extra']['gw_extra_background'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Background'),
  '#description' => \Drupal::translation()->translate('Configure the background image and color for this region.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_extra']['gw_extra_background']['gw_background_extra_color'] = [
  '#type' => 'select',
  '#title' => t('Background Color'),
  '#description' => t("Choose a pre-defined background color for the extra region. This is overridden if a background image is set."),
  '#options' => [
    '' => t('- Default -'),
    'blue' => t('Blue'),
    'indigo' => t('Indigo'),
    'deep-purple' => t('Deep Purple'),
    'purple' => t('Purple'),
    'pink' => t('Pink'),
    'red' => t('Red'),
    'orange' => t('Orange'),
    'amber' => t('Amber'),
    'yellow' => t('Yellow'),
    'lime' => t('Lime'),
    'green' => t('Green'),
    'teal' => t('Teal'),
    'cyan' => t('Cyan'),
    'brown' => t('Brown'),
    'blue-gray' => t('Blue Gray'),
    'gray' => t('Gray'),
  ],
  '#default_value' => $config->get('gw_background_extra_color') ?? '',
];

$form['gw_regions']['gw_extra']['gw_extra_background']['gw_background_extra_use_default'] = [
  '#type' => 'checkbox',
  '#title' => t("Uncheck to define your custom background image"),
  '#default_value' => $config->get('gw_background_extra_use_default') ?? 1,
];

$form['gw_regions']['gw_extra']['gw_extra_background']['gw_custom_background_wrapper'] = [
  '#type' => 'container',
  '#states' => [
    'invisible' => [
      ':input[name="gw_background_extra_use_default"]' => ['checked' => TRUE],
    ],
  ],
];

$form['gw_regions']['gw_extra']['gw_extra_background']['gw_custom_background_wrapper']['gw_background_extra_path'] = [
  '#type' => 'textfield',
  '#title' => t('Path to custom extra background image'),
  '#default_value' => $config->get('gw_background_extra_path'),
  '#description' => t('Examples: background.jpg, public://background.jpg, or themes/custom/groundwork/images/background.jpg.'),
];

$form['gw_regions']['gw_extra']['gw_extra_background']['gw_custom_background_wrapper']['gw_background_extra_upload'] = [
  '#type' => 'managed_file',
  '#title' => t('Upload extra background image'),
  '#description' => t("If you don't have direct file access, use this field to upload your background image."),
  '#default_value' => $config->get('gw_background_extra_upload'),
  '#upload_location' => 'public://theme_backgrounds/extra/',
  '#upload_validators' => [
    'FileIsImage' => [],
    'FileExtension' => ['extensions' => 'jpg jpeg png gif svg webp avif'],
  ],
];

// ----- Supplement Settings -----
$form['gw_regions']['gw_supplement'] = [
  '#type' => 'details',
  '#title' => t('Supplement'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_supplement']['gw_supplement_background'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Background'),
  '#description' => \Drupal::translation()->translate('Configure the background image and color for this region.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_supplement']['gw_supplement_background']['gw_background_supplement_color'] = [
  '#type' => 'select',
  '#title' => t('Background Color'),
  '#description' => t("Choose a pre-defined background color for the supplement region. This is overridden if a background image is set."),
  '#options' => [
    '' => t('- Default -'),
    'blue' => t('Blue'),
    'indigo' => t('Indigo'),
    'deep-purple' => t('Deep Purple'),
    'purple' => t('Purple'),
    'pink' => t('Pink'),
    'red' => t('Red'),
    'orange' => t('Orange'),
    'amber' => t('Amber'),
    'yellow' => t('Yellow'),
    'lime' => t('Lime'),
    'green' => t('Green'),
    'teal' => t('Teal'),
    'cyan' => t('Cyan'),
    'brown' => t('Brown'),
    'blue-gray' => t('Blue Gray'),
    'gray' => t('Gray'),
  ],
  '#default_value' => $config->get('gw_background_supplement_color') ?? '',
];

$form['gw_regions']['gw_supplement']['gw_supplement_background']['gw_background_supplement_use_default'] = [
  '#type' => 'checkbox',
  '#title' => t("Uncheck to define your custom background image"),
  '#default_value' => $config->get('gw_background_supplement_use_default') ?? 1,
];

$form['gw_regions']['gw_supplement']['gw_supplement_background']['gw_custom_background_wrapper'] = [
  '#type' => 'container',
  '#states' => [
    'invisible' => [
      ':input[name="gw_background_supplement_use_default"]' => ['checked' => TRUE],
    ],
  ],
];

$form['gw_regions']['gw_supplement']['gw_supplement_background']['gw_custom_background_wrapper']['gw_background_supplement_path'] = [
  '#type' => 'textfield',
  '#title' => t('Path to custom supplement background image'),
  '#default_value' => $config->get('gw_background_supplement_path'),
  '#description' => t('Examples: background.jpg, public://background.jpg, or themes/custom/groundwork/images/background.jpg.'),
];

$form['gw_regions']['gw_supplement']['gw_supplement_background']['gw_custom_background_wrapper']['gw_background_supplement_upload'] = [
  '#type' => 'managed_file',
  '#title' => t('Upload supplement background image'),
  '#description' => t("If you don't have direct file access, use this field to upload your background image."),
  '#default_value' => $config->get('gw_background_supplement_upload'),
  '#upload_location' => 'public://theme_backgrounds/supplement/',
  '#upload_validators' => [
    'FileIsImage' => [],
    'FileExtension' => ['extensions' => 'jpg jpeg png gif svg webp avif'],
  ],
];

// ----- Rider Settings -----
$form['gw_regions']['gw_rider'] = [
  '#type' => 'details',
  '#title' => t('Rider'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_rider']['gw_rider_background'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Background'),
  '#description' => \Drupal::translation()->translate('Configure the background image and color for this region.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_rider']['gw_rider_background']['gw_background_rider_color'] = [
  '#type' => 'select',
  '#title' => t('Background Color'),
  '#description' => t("Choose a pre-defined background color for the rider region. This is overridden if a background image is set."),
  '#options' => [
    '' => t('- Default -'),
    'blue' => t('Blue'),
    'indigo' => t('Indigo'),
    'deep-purple' => t('Deep Purple'),
    'purple' => t('Purple'),
    'pink' => t('Pink'),
    'red' => t('Red'),
    'orange' => t('Orange'),
    'amber' => t('Amber'),
    'yellow' => t('Yellow'),
    'lime' => t('Lime'),
    'green' => t('Green'),
    'teal' => t('Teal'),
    'cyan' => t('Cyan'),
    'brown' => t('Brown'),
    'blue-gray' => t('Blue Gray'),
    'gray' => t('Gray'),
  ],
  '#default_value' => $config->get('gw_background_rider_color') ?? '',
];

$form['gw_regions']['gw_rider']['gw_rider_background']['gw_background_rider_use_default'] = [
  '#type' => 'checkbox',
  '#title' => t("Uncheck to define your custom background image"),
  '#default_value' => $config->get('gw_background_rider_use_default') ?? 1,
];

$form['gw_regions']['gw_rider']['gw_rider_background']['gw_custom_background_wrapper'] = [
  '#type' => 'container',
  '#states' => [
    'invisible' => [
      ':input[name="gw_background_rider_use_default"]' => ['checked' => TRUE],
    ],
  ],
];

$form['gw_regions']['gw_rider']['gw_rider_background']['gw_custom_background_wrapper']['gw_background_rider_path'] = [
  '#type' => 'textfield',
  '#title' => t('Path to custom rider background image'),
  '#default_value' => $config->get('gw_background_rider_path'),
  '#description' => t('Examples: background.jpg, public://background.jpg, or themes/custom/groundwork/images/background.jpg.'),
];

$form['gw_regions']['gw_rider']['gw_rider_background']['gw_custom_background_wrapper']['gw_background_rider_upload'] = [
  '#type' => 'managed_file',
  '#title' => t('Upload rider background image'),
  '#description' => t("If you don't have direct file access, use this field to upload your background image."),
  '#default_value' => $config->get('gw_background_rider_upload'),
  '#upload_location' => 'public://theme_backgrounds/rider/',
  '#upload_validators' => [
    'FileIsImage' => [],
    'FileExtension' => ['extensions' => 'jpg jpeg png gif svg webp avif'],
  ],
];

// ----- Footer Settings -----
$form['gw_regions']['gw_footer'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Footer'),
  '#description' => \Drupal::translation()->translate('Configure footer background and layout options.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_footer']['gw_footer_background'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Background'),
  '#description' => \Drupal::translation()->translate('Configure the background image and color for this region.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_footer']['gw_footer_background']['gw_background_footer_color'] = [
  '#type' => 'select',
  '#title' => t('Background Color'),
  '#description' => t("Choose a pre-defined background color for the footer region. This is overridden if a background image is set."),
  '#options' => [
    '' => t('- Default -'),
    'blue' => t('Blue'),
    'indigo' => t('Indigo'),
    'deep-purple' => t('Deep Purple'),
    'purple' => t('Purple'),
    'pink' => t('Pink'),
    'red' => t('Red'),
    'orange' => t('Orange'),
    'amber' => t('Amber'),
    'yellow' => t('Yellow'),
    'lime' => t('Lime'),
    'green' => t('Green'),
    'teal' => t('Teal'),
    'cyan' => t('Cyan'),
    'brown' => t('Brown'),
    'blue-gray' => t('Blue Gray'),
    'gray' => t('Gray'),
  ],
  '#default_value' => $config->get('gw_background_footer_color') ?? '',
];

$form['gw_regions']['gw_footer']['gw_footer_background']['gw_background_footer_use_default'] = [
  '#type' => 'checkbox',
  '#title' => t("Uncheck to define your custom background image"),
  '#default_value' => $config->get('gw_background_footer_use_default') ?? 1,
];

$form['gw_regions']['gw_footer']['gw_footer_background']['gw_custom_background_wrapper'] = [
  '#type' => 'container',
  '#states' => [
    'invisible' => [
      ':input[name="gw_background_footer_use_default"]' => ['checked' => TRUE],
    ],
  ],
];

$form['gw_regions']['gw_footer']['gw_footer_background']['gw_custom_background_wrapper']['gw_background_footer_path'] = [
  '#type' => 'textfield',
  '#title' => t('Path to custom footer background image'),
  '#default_value' => $config->get('gw_background_footer_path'),
  '#description' => t('Examples: background.jpg, public://background.jpg, or themes/custom/groundwork/images/background.jpg.'),
];

$form['gw_regions']['gw_footer']['gw_footer_background']['gw_custom_background_wrapper']['gw_background_footer_upload'] = [
  '#type' => 'managed_file',
  '#title' => t('Upload footer background image'),
  '#description' => t("If you don't have direct file access, use this field to upload your background image."),
  '#default_value' => $config->get('gw_background_footer_upload'),
  '#upload_location' => 'public://theme_backgrounds/footer/',
  '#upload_validators' => [
    'FileIsImage' => [],
    'FileExtension' => ['extensions' => 'jpg jpeg png gif svg webp avif'],
  ],
];
// --- BACKGROUND SETTINGS END ---

$form['gw_regions']['gw_footer']['gw_footer_copyright'] = [
  '#type' => 'details',
  '#title' => \Drupal::translation()->translate('Copyright'),
  '#description' => \Drupal::translation()->translate('Configure the copyright text for this region.'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
];

$form['gw_regions']['gw_footer']['gw_footer_copyright']['gw_footer_copyright_text'] = [
  '#type' => 'textfield',
  '#title' => \Drupal::translation()->translate('Footer copyright text'),
  '#description' => \Drupal::translation()->translate('Supports tokens like {year}, {site_name}. Example: &copy; {year} My Company. All rights reserved.'),
  '#default_value' => $config->get('gw_footer_copyright') ?: $default_copyright,
  '#states' => ['visible' => [':input[name="gw_footer_copyright_enable"]' => ['checked' => TRUE]]],
];

$form['gw_regions']['gw_footer']['gw_footer_copyright']['gw_footer_copyright_enable'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Show copyright text in the footer'),
  '#default_value' => 1,
  '#description' => \Drupal::translation()->translate('Uncheck to hide the copyright line from the footer. <strong>Removal is available with a <a href=":pro_url" target="_blank">Groundwork Pro license</a>.</strong>', [':pro_url' => 'https://groundwork.ibenta.no/pro']),
  '#attributes' => ['disabled' => 'disabled'],
];
$site_name = \Drupal::config('system.site')->get('name');
$default_copyright = \Drupal::translation()->translate('&copy; {year} @site_name. All rights reserved.', ['@site_name' => $site_name]);

$form['gw_regions']['gw_footer']['gw_footer_copyright']['gw_footer_attribution'] = [
  '#type' => 'checkbox',
  '#title' => \Drupal::translation()->translate('Show “Powered by Groundwork Theme Framework” in the footer'),
  '#default_value' => 1,
  '#description' => \Drupal::translation()->translate('This attribution helps support ongoing development. <strong>Removal is available with a <a href=":pro_url" target="_blank">Groundwork Pro license</a>.</strong>', [':pro_url' => 'https://groundwork.ibenta.no/pro']),
  '#attributes' => ['disabled' => 'disabled'],
];



