<?php

declare(strict_types=1);

/**
 * @file
 * Page-attachment hooks for the Groundwork theme.
 *
 * • Add new libraries / assets to every page.
 * • Alter or remove assets that Core or modules attached.
 */

use Drupal\Core\Render\Markup;

/**
 * Implements hook_page_attachments().
 *
 * This hook is used to attach assets (like CSS, JS, meta tags, etc.) to the page.
 * In this theme, it's specifically used to inject the global SVG icon sprite
 * directly into the HTML head, making it available for <use> tags across the site.
 *
 * @param array $attachments
 * A renderable array of page attachments.
 */
function groundwork_page_attachments(array &$attachments): void
{
  // Load the global SVG icon sprite into the HTML head.
  // The sprite is co-located with the gwicons Twig partial and CSS for better encapsulation.
  $sprite_path = \Drupal::theme()->getActiveTheme()->getPath(). '/framework-partials/gwicons/gwicons.svg';

  // Check if the SVG sprite file exists and is readable before attempting to load it.
  if (is_readable($sprite_path)) {
    $attachments['#attached']['html_head'][] = [
      [
        '#type'   => 'markup',
        '#markup' => file_get_contents($sprite_path),
      ],
      // A unique key for this attachment to prevent duplicates if the hook is called multiple times.
      'groundwork-icon-sprite',
    ];
  }
}

/**
 * Implements hook_page_attachments_alter().
 *
 * Use this hook to remove or modify assets that other modules or core
 * attached. Delete the body if unused.
 *
 * @param array $attachments
 *   A render array of attachments already assembled for the page.
 */
function groundwork_page_attachments_alter(array &$attachments): void
{
  // Example: remove Core’s dialog CSS if you don't use it.
  // unset($attachments['#attached']['library']['core/drupal.dialog']);
}
