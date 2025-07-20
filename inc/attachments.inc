<?php

declare(strict_types = 1);

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
 * Inlines the `gwicons.svg` sprite (478 symbols) once per request so any
 * template can render an icon with:
 *   <svg class="gw-icon"><use href="#gw-bars" /></svg>
 *
 * @param array $attachments
 *   A render array of assets already attached to the page.
 */
function groundwork_page_attachments(array &$attachments): void {
  $sprite = drupal_get_path('theme', 'groundwork') . '/gwicons/gwicons.svg';

  if (is_readable($sprite)) {
    $attachments['#attached']['html_head'][] = [
      [
        '#type'   => 'markup',
        '#markup' => file_get_contents($sprite),
      ],
      'gwicons.sprite',
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
function groundwork_page_attachments_alter(array &$attachments): void {
  // Example: remove Core’s dialog CSS if you don't use it.
  // unset($attachments['#attached']['library']['core/drupal.dialog']);
}
