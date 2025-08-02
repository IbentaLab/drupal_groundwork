<?php

declare(strict_types = 1);

/**
 * @file
 * Theme suggestion hooks for the Groundwork theme.
 *
 * Place all hook_theme_suggestions_*_alter() implementations here.
 */

/**
 * Implements hook_theme_suggestions_region_alter().
 *
 * Adds a shared template suggestion (`region--custom.html.twig`) for a
 * curated set of regions.
 *
 * @param array $suggestions
 *   Existing template suggestions for the region.
 * @param array $variables
 *   Theme variables passed to the region template.
 */

/*
function groundwork_theme_suggestions_region_alter(
  array &$suggestions,
  array $variables
): void {
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

  $region_name = $variables['elements']['#region'] ?? '';
  if (in_array($region_name, $target_regions, TRUE)) {
    $suggestions[] = 'region__custom';
  }
}*/
