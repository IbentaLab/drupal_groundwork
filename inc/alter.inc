<?php
/**
 * @file
 * Functions to support theming in the Groundwork theme.
 */

/**
 * Implements hook_theme_suggestions_region_alter().
 */
function groundwork_theme_suggestions_region_alter(array &$suggestions, array $variables) {
  // Define the list of regions that will use the custom template.
  $target_regions = [
    'billboard',
    'header',
    'preface',
    'content',
    'appendix',
    'sidebar_first',
    'sidebar_second',
    'footer',
  ];

  // Get the current region name from the render array.
  $region_name = $variables['elements']['#region'];

  // If the current region is in our target list, add a new template suggestion.
  if (in_array($region_name, $target_regions)) {
    $suggestions[] = 'region__custom';
  }
}
