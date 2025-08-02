<?php

/**
 * @file
 * Preprocess functions for the Groundwork theme.
 *
 * This file contains preprocess functions that modify variables before they
 * are passed to the theme layer for rendering.
 *
 * @ingroup groundwork
 */

declare(strict_types=1);

use Drupal\file\Entity\File;

/**
 * Implements hook_preprocess_page().
 *
 * Adjusts page variables before rendering, including footer processing,
 * social media bar integration, and brand color injection.
 *
 * @param array $variables
 *   The variables array for the page template.
 */
function groundwork_preprocess_page(array &$variables): void {
  $config = \Drupal::config('groundwork.settings');

  // Process footer elements.
  groundwork_postprocess_footer($variables);

  // Process social media bar.
  groundwork_process_social_bar($variables, $config);

  // Process brand colors - inject as CSS custom properties.
  groundwork_inject_brand_colors($variables, $config);

  // Process accessibility features.
  groundwork_process_accessibility_features($variables, $config);

  // Process SEO features.
  groundwork_process_seo_features($variables, $config);
}

/**
 * Implements hook_preprocess_region().
 *
 * Adds background colors, images, brand colors, and layout classes to regions.
 *
 * @param array $variables
 *   The variables array for the region template.
 */
function groundwork_preprocess_region(array &$variables): void {
  $config = \Drupal::config('groundwork.settings');
  $region = $variables['elements']['#region'] ?? '';

  if (empty($region)) {
    return;
  }

  // Define regions that support background customization.
  $regions_with_backgrounds = [
    'billboard',
    'header',
    'hero',
    'supplement',
    'extra',
    'rider',
    'footer',
  ];

  // Define regions that support layout customization.
  $regions_with_layout = [
    'header',
    'hero',
    'preface',
    'content',
    'appendix',
    'sidebar_first',
    'sidebar_second',
    'supplement',
    'extra',
    'rider',
    'footer',
  ];

  // Apply brand color scheme to colorable regions.
  if (in_array($region, $regions_with_backgrounds)) {
    groundwork_apply_region_color_scheme($variables, $region, $config);
    groundwork_apply_region_background_color($variables, $region, $config);
    groundwork_apply_region_background_image($variables, $region, $config);
  }

  // Apply layout classes to regions with layout support.
  if (in_array($region, $regions_with_layout)) {
    groundwork_apply_region_layout_classes($variables, $region, $config);
  }

  // Add accessibility classes.
  groundwork_apply_region_accessibility_classes($variables, $region, $config);
}

/**
 * Implements hook_preprocess_block().
 *
 * Adds responsive grid classes and accessibility improvements to blocks.
 *
 * @param array $variables
 *   The variables array for the block template.
 */
function groundwork_preprocess_block(array &$variables): void {
  $plugin_id = $variables['plugin_id'] ?? '';
  $region = $variables['elements']['#region'] ?? '';

  // Use responsive grid classes for header blocks.
  if ($region === 'header') {
    if ($plugin_id === 'system_branding_block') {
      $variables['attributes']['class'][] = 'is-12--s';
      $variables['attributes']['class'][] = 'is-4';
    }
    elseif ($plugin_id === 'system_menu_block:main') {
      $variables['attributes']['class'][] = 'is-12--s';
      $variables['attributes']['class'][] = 'is-8';
    }
  }

  // Add accessibility improvements.
  groundwork_apply_block_accessibility($variables);
}

/**
 * Implements hook_preprocess_node().
 *
 * Adds custom processing for node templates.
 *
 * @param array $variables
 *   The variables array for the node template.
 */
function groundwork_preprocess_node(array &$variables): void {
  // Add node bundle as a CSS class for styling.
  if (!empty($variables['elements']['#node'])) {
    $node = $variables['elements']['#node'];
    if (method_exists($node, 'bundle')) {
      $bundle = $node->bundle();
      if (!empty($bundle)) {
        $variables['attributes']['class'][] = 'gw-node--' . str_replace('_', '-', $bundle);
      }
    }
  }

  // Add SEO enhancements.
  groundwork_process_node_seo($variables);
}

/**
 * Apply brand color scheme to region.
 *
 * @param array $variables
 *   The variables array for the region template.
 * @param string $region
 *   The region name.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_apply_region_color_scheme(array &$variables, string $region, $config): void {
  $color_scheme = $config->get('gw_' . $region . '_color_scheme');

  if (empty($color_scheme)) {
    return;
  }

  // Apply brand color classes.
  switch ($color_scheme) {
    case 'brand-primary':
      $variables['attributes']['class'][] = 'gw-brand-primary';
      $variables['attributes']['data-color-scheme'] = 'brand-primary';
      break;

    case 'brand-secondary':
      $variables['attributes']['class'][] = 'gw-brand-secondary';
      $variables['attributes']['data-color-scheme'] = 'brand-secondary';
      break;

    case 'brand-accent':
      $variables['attributes']['class'][] = 'gw-brand-accent';
      $variables['attributes']['data-color-scheme'] = 'brand-accent';
      break;

    case 'custom':
      $custom_color = $config->get('gw_' . $region . '_custom_color');
      if (!empty($custom_color)) {
        $variables['attributes']['class'][] = 'gw-custom-color';
        $variables['attributes']['style'][] = '--region-custom-color: ' . $custom_color . ';';
        $variables['attributes']['data-color-scheme'] = 'custom';
      }
      break;
  }
}

/**
 * Apply background color class to region.
 *
 * @param array $variables
 *   The variables array for the region template.
 * @param string $region
 *   The region name.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_apply_region_background_color(array &$variables, string $region, $config): void {
  $color = $config->get('gw_background_' . $region . '_color');
  if (!empty($color)) {
    $variables['attributes']['class'][] = 'bg--' . $color;
  }
}

/**
 * Apply background image to region.
 *
 * @param array $variables
 *   The variables array for the region template.
 * @param string $region
 *   The region name.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_apply_region_background_image(array &$variables, string $region, $config): void {
  // Only apply if NOT using default background.
  if ($config->get('gw_background_' . $region . '_use_default')) {
    return;
  }

  $background_image_url = groundwork_get_region_background_url($region, $config);

  if (!empty($background_image_url)) {
    $safe_url = htmlspecialchars($background_image_url, ENT_QUOTES, 'UTF-8');
    $variables['attributes']['style'][] = "background-image: url('" . $safe_url . "');";
    $variables['attributes']['class'][] = 'has-background-image';
  }
}

/**
 * Apply layout and padding classes to region.
 *
 * @param array $variables
 *   The variables array for the region template.
 * @param string $region
 *   The region name.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_apply_region_layout_classes(array &$variables, string $region, $config): void {
  // Container mode.
  $container_mode = $config->get('gw_' . $region . '_container_mode');
  if (!empty($container_mode)) {
    $variables['attributes']['class'][] = 'container--' . $container_mode;
  }

  // Grid columns (for specific regions).
  $columns = $config->get('gw_' . $region . '_columns');
  if (!empty($columns)) {
    $variables['attributes']['class'][] = 'grid-columns--' . $columns;
  }

  // Padding classes.
  $padding_positions = ['top', 'bottom', 'left', 'right'];
  foreach ($padding_positions as $position) {
    $padding = $config->get('gw_' . $region . '_padding_' . $position);
    if (!empty($padding)) {
      $variables['attributes']['class'][] = 'padding-' . $position . '--' . $padding;
    }
  }
}

/**
 * Apply accessibility classes to region.
 *
 * @param array $variables
 *   The variables array for the region template.
 * @param string $region
 *   The region name.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_apply_region_accessibility_classes(array &$variables, string $region, $config): void {
  // Enhanced focus outlines.
  if ($config->get('gw_focus_outlines')) {
    $variables['attributes']['class'][] = 'gw-enhanced-focus';
  }

  // Keyboard navigation support.
  if ($config->get('gw_keyboard_navigation')) {
    $variables['attributes']['class'][] = 'gw-keyboard-nav';
  }

  // Add landmark roles for better screen reader navigation.
  if ($config->get('gw_landmark_roles')) {
    $landmark_roles = [
      'header' => 'banner',
      'footer' => 'contentinfo',
      'content' => 'main',
      'sidebar_first' => 'complementary',
      'sidebar_second' => 'complementary',
    ];

    if (isset($landmark_roles[$region])) {
      $variables['attributes']['role'] = $landmark_roles[$region];
    }
  }
}

/**
 * Apply accessibility improvements to blocks.
 *
 * @param array $variables
 *   The variables array for the block template.
 */
function groundwork_apply_block_accessibility(array &$variables): void {
  $config = \Drupal::config('groundwork.settings');

  // Add skip link targets for important blocks.
  $plugin_id = $variables['plugin_id'] ?? '';
  if ($plugin_id === 'system_main_block') {
    $variables['attributes']['id'] = 'main-content';
  }
}

/**
 * Inject brand colors as CSS custom properties.
 *
 * @param array $variables
 *   The variables array for the page template.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_inject_brand_colors(array &$variables, $config): void {
  $brand_primary = $config->get('gw_brand_primary');
  $brand_secondary = $config->get('gw_brand_secondary');
  $brand_accent = $config->get('gw_brand_accent');

  if (!empty($brand_primary) || !empty($brand_secondary) || !empty($brand_accent)) {
    $css_vars = [];

    if (!empty($brand_primary)) {
      $css_vars[] = '--gw-brand-primary: ' . $brand_primary;
    }
    if (!empty($brand_secondary)) {
      $css_vars[] = '--gw-brand-secondary: ' . $brand_secondary;
    }
    if (!empty($brand_accent)) {
      $css_vars[] = '--gw-brand-accent: ' . $brand_accent;
    }

    if (!empty($css_vars)) {
      $variables['#attached']['html_head'][] = [
        [
          '#type' => 'html_tag',
          '#tag' => 'style',
          '#value' => ':root { ' . implode('; ', $css_vars) . '; }',
        ],
        'groundwork_brand_colors',
      ];
    }
  }
}

/**
 * Process accessibility features for the page.
 *
 * @param array $variables
 *   The variables array for the page template.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_process_accessibility_features(array &$variables, $config): void {
  // Add skip links.
  if ($config->get('gw_skip_links')) {
    $variables['page']['skip_links'] = [
      '#type' => 'markup',
      '#markup' => '<a href="#main-content" class="visually-hidden focusable skip-link">' .
      \Drupal::translation()->translate('Skip to main content') . '</a>',
      '#weight' => -1000,
    ];
  }

  // Add motion preferences CSS class.
  if ($config->get('gw_respect_motion')) {
    $variables['attributes']['class'][] = 'gw-respect-motion';
  }

  // Add contrast mode class.
  $contrast_mode = $config->get('gw_contrast_mode');
  if (!empty($contrast_mode)) {
    $variables['attributes']['class'][] = 'gw-contrast--' . $contrast_mode;
  }
}

/**
 * Process SEO features for the page.
 *
 * @param array $variables
 *   The variables array for the page template.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_process_seo_features(array &$variables, $config): void {
  // Add Open Graph meta tags.
  if ($config->get('gw_og_enable')) {
    groundwork_add_open_graph_tags($variables, $config);
  }

  // Add Schema.org markup.
  if ($config->get('gw_schema_org')) {
    groundwork_add_schema_markup($variables, $config);
  }

  // Add breadcrumbs.
  if ($config->get('gw_breadcrumbs_enable')) {
    groundwork_add_breadcrumbs($variables, $config);
  }
}

/**
 * Add Open Graph meta tags.
 *
 * @param array $variables
 *   The variables array for the page template.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_add_open_graph_tags(array &$variables, $config): void {
  $site_name = \Drupal::config('system.site')->get('name');
  $current_url = \Drupal::request()->getSchemeAndHttpHost() . \Drupal::request()->getRequestUri();

  // Basic Open Graph tags.
  $og_tags = [
    'og:site_name' => $site_name,
    'og:url' => $current_url,
    'og:type' => 'website',
  ];

  // Add default OG image if configured.
  $og_image_fids = $config->get('gw_og_image');
  if (!empty($og_image_fids[0])) {
    try {
      $file = File::load($og_image_fids[0]);
      if ($file) {
        $og_tags['og:image'] = \Drupal::service('file_url_generator')->generateAbsoluteString($file->getFileUri());
      }
    }
    catch (\Exception $e) {
      \Drupal::logger('groundwork')->error('Error loading OG image: @message', ['@message' => $e->getMessage()]);
    }
  }

  // Add Twitter Card tags if enabled.
  if ($config->get('gw_twitter_cards')) {
    $og_tags['twitter:card'] = 'summary_large_image';
  }

  // Attach meta tags.
  foreach ($og_tags as $property => $content) {
    $variables['#attached']['html_head'][] = [
      [
        '#tag' => 'meta',
        '#attributes' => [
          'property' => $property,
          'content' => $content,
        ],
      ],
      'groundwork_og_' . str_replace(':', '_', $property),
    ];
  }
}

/**
 * Add Schema.org markup.
 *
 * @param array $variables
 *   The variables array for the page template.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_add_schema_markup(array &$variables, $config): void {
  $organization_name = $config->get('gw_schema_organization');
  if (!empty($organization_name)) {
    $schema = [
      '@context' => 'https://schema.org',
      '@type' => 'Organization',
      'name' => $organization_name,
      'url' => \Drupal::request()->getSchemeAndHttpHost(),
    ];

    $variables['#attached']['html_head'][] = [
      [
        '#tag' => 'script',
        '#attributes' => ['type' => 'application/ld+json'],
        '#value' => json_encode($schema),
      ],
      'groundwork_schema_organization',
    ];
  }
}

/**
 * Add breadcrumbs to the page.
 *
 * @param array $variables
 *   The variables array for the page template.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_add_breadcrumbs(array &$variables, $config): void {
  // This would integrate with Drupal's breadcrumb system.
  // Implementation depends on your specific breadcrumb requirements.
}

/**
 * Process social media bar.
 *
 * @param array $variables
 *   The variables array for the page template.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration.
 */
function groundwork_process_social_bar(array &$variables, $config): void {
  $location = $config->get('gw_social_bar_location');
  if (empty($location) || $location === 'none') {
    return;
  }

  $social_networks = ['twitter', 'facebook', 'linkedin', 'instagram', 'youtube'];
  $social_network_names = [
    'twitter' => 'Twitter',
    'facebook' => 'Facebook',
    'linkedin' => 'LinkedIn',
    'instagram' => 'Instagram',
    'youtube' => 'YouTube',
  ];

  $links = [];
  foreach ($social_networks as $key) {
    $url = $config->get('gw_social_' . $key);
    if (!empty($url) && filter_var($url, FILTER_VALIDATE_URL)) {
      $links[] = [
        'url' => $url,
        'name' => $social_network_names[$key] ?? ucfirst($key),
      ];
    }
  }

  if (empty($links)) {
    return;
  }

  $social_bar_sdc = [
    '#type' => 'component',
    '#component' => 'groundwork:social-bar',
    '#props' => [
      'links' => $links,
      'alignment' => $config->get('gw_social_bar_alignment') ?: 'center',
    ],
  ];

  if ($location === 'header') {
    $variables['page']['social_bar_header'] = $social_bar_sdc;
  }
  elseif ($location === 'footer') {
    $variables['page']['social_bar_footer'] = $social_bar_sdc;
  }
}

/**
 * Process SEO features for nodes.
 *
 * @param array $variables
 *   The variables array for the node template.
 */
function groundwork_process_node_seo(array &$variables): void {
  // Add article Schema.org markup for content types.
  if (!empty($variables['node'])) {
    $node = $variables['node'];
    if ($node->bundle() === 'article') {
      $schema = [
        '@context' => 'https://schema.org',
        '@type' => 'Article',
        'headline' => $node->getTitle(),
        'datePublished' => date('c', $node->getCreatedTime()),
        'dateModified' => date('c', $node->getChangedTime()),
      ];

      $variables['#attached']['html_head'][] = [
        [
          '#tag' => 'script',
          '#attributes' => ['type' => 'application/ld+json'],
          '#value' => json_encode($schema),
        ],
        'groundwork_schema_article_' . $node->id(),
      ];
    }
  }
}

/**
 * Helper function to get background image URL for a region.
 *
 * @param string $region
 *   The region name.
 * @param \Drupal\Core\Config\ImmutableConfig $config
 *   The theme configuration object.
 *
 * @return string
 *   The background image URL, or empty string if none found.
 */
function groundwork_get_region_background_url(string $region, $config): string {
  $background_image_url = '';

  // Check for uploaded file first.
  $upload_fids = $config->get('gw_background_' . $region . '_upload');
  if (!empty($upload_fids[0])) {
    try {
      $file = File::load($upload_fids[0]);
      if ($file && $file->access('view')) {
        $file_uri = $file->getFileUri();
        if (!empty($file_uri)) {
          $background_image_url = \Drupal::service('file_url_generator')->generateAbsoluteString($file_uri);
        }
      }
    }
    catch (\Exception $e) {
      \Drupal::logger('groundwork')->error('Error loading background image file for @region: @message', [
        '@region' => $region,
        '@message' => $e->getMessage(),
      ]);
    }
  }

  // Fall back to path if no uploaded file.
  if (empty($background_image_url)) {
    $path = $config->get('gw_background_' . $region . '_path');
    if (!empty($path)) {
      try {
        $background_image_url = \Drupal::service('file_url_generator')->generateAbsoluteString($path);
      }
      catch (\Exception $e) {
        \Drupal::logger('groundwork')->error('Error generating background image URL from path for @region: @message', [
          '@region' => $region,
          '@message' => $e->getMessage(),
        ]);
      }
    }
  }

  return $background_image_url;
}
