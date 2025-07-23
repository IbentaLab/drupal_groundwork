<?php

declare(strict_types = 1);

/**
 * @file
 * Render-array and suggestion alter hooks for the Groundwork theme.
 *
 * Place hook_*_alter() implementations here (except page-attachments,
 * which live in attachments.inc).
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Example stub: tweak the core search block. Replace or remove.
 *
 * @param array $form
 *   The form render array.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 *   Current form state.
 * @param string $form_id
 *   Unique form ID.
 */
function groundwork_form_search_block_form_alter(
  array &$form,
  \Drupal\Core\Form\FormStateInterface $form_state,
  string $form_id
): void {
  // Example: add placeholder.
  // $form['keys']['#attributes']['placeholder'] = t('Search …');
}

/**
 * Implements hook_theme_suggestions_node_alter().
 *
 * Example stub: add `node--article--teaser.html.twig` for article teasers.
 * Delete or customise.
 *
 * @param array $suggestions
 *   Theme hook suggestions.
 * @param array $variables
 *   Variables available to the node template.
 */
function groundwork_theme_suggestions_node_alter(
  array &$suggestions,
  array $variables
): void {
  // if ($variables['view_mode'] === 'teaser'
  //   && $variables['node']->bundle() === 'article') {
  //   $suggestions[] = 'node__article__teaser';
  // }
}
