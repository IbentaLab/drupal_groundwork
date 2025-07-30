<?php

/**
 * @file
 * Groundwork Theme Settings form (vertical tabs, AI providers, pro styling).
 *
 * @ingroup groundwork
 */

use Drupal\file\Entity\File;
use Drupal\Core\Form\FormStateInterface;

// Include the init file to make sure AJAX callbacks are available.
include_once __DIR__ . '/init.inc';

function groundwork_form_system_theme_settings_alter(&$form, FormStateInterface $form_state)
{
  // Load the theme's configuration object to get settings.
  $config = \Drupal::config('groundwork.settings');

  // ----- Branded header -----
  $logo_path = \Drupal::theme()->getActiveTheme()->getPath() . '/logo/groundwork-logo-70.svg';
  $form['gw_intro'] = [
    '#type' => 'item',
    '#markup' => '
      <div class="gw-settings-header">
        <img src="/' . $logo_path . '" alt="Groundwork Logo" class="gw-settings-logo" />
        <h2 class="gw-settings-title">Groundwork Theme Settings</h2>
        <div class="gw-settings-lead">
          Modern, accessible, and AI-powered for Drupal 11+.<br>
          <small>
            Docs: <a href="https://groundwork.ibenta.no/docs" target="_blank">View online</a> &nbsp;|&nbsp;
            <a href="mailto:support@ibenta.no">Contact support</a>
          </small>
        </div>
      </div>
    ',
    '#weight' => -100,
  ];

  // ----- Vertical tabs -----
  $form['gw_settings_tabs'] = [
    '#type' => 'vertical_tabs',
    '#title' => \Drupal::translation()->translate('Groundwork Theme Settings'),
    '#weight' => -90,
  ];

  // Include the settings files for each tab
  include __DIR__ . '/settings/design.inc';
  include __DIR__ . '/settings/regions.inc';
  include __DIR__ . '/settings/navigation.inc';
  include __DIR__ . '/settings/ai-tools.inc';
  include __DIR__ . '/settings/social.inc';

  // ----- Collapse core Drupal theme settings in their own fieldset -----
  $core_settings = ['theme_settings', 'logo', 'favicon'];
  $form['core_settings'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Drupal Core Theme Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];
  foreach ($core_settings as $key) {
    if (isset($form[$key])) {
      $form['core_settings'][$key] = $form[$key];
      unset($form[$key]);
    }
  }

  // Attach the custom submit handler to save managed files.
  $form['#submit'][] = 'groundwork_theme_settings_submit';

  // Attach admin CSS for settings page styling.
  $form['#attached']['library'][] = 'groundwork/theme-settings';
}

/**
 * Validation for the custom CSS field.
 */
function groundwork_validate_custom_css($element, FormStateInterface $form_state, $form)
{
  $css = $form_state->getValue('gw_custom_css');
  if (preg_match('/[<>]/', $css)) {
    $form_state->setError($element, \Drupal::translation()->translate('HTML tags are not allowed in custom CSS.'));
  }
}

/**
 * Validation for API keys.
 */
function groundwork_validate_api_key($element, FormStateInterface $form_state, $form)
{
  $provider = $form_state->getValue('ai_provider');
  $api_key = $form_state->getValue($element['#name']);

  if (empty($provider) || $provider === 'simulate') {
    return;
  }

  if (empty($api_key)) {
    $form_state->setError($element, \Drupal::translation()->translate('The API key cannot be empty.'));
  }
}

/**
 * Custom submit handler for the theme settings form.
 *
 * This handler is responsible for processing form values, marking uploaded files
 * as permanent, and saving them to the theme configuration.
 */
function groundwork_theme_settings_submit(&$form, FormStateInterface $form_state) {
  // Load the editable configuration object to save values.
  $config = \Drupal::configFactory()->getEditable('groundwork.settings');

  // --- Process Region Backgrounds ---
  $regions = [
    'billboard', 'header', 'hero', 'supplement', 'extra', 'rider', 'footer',
  ];

  foreach ($regions as $region) {
    $use_default_key = 'gw_background_' . $region . '_use_default';
    $path_key = 'gw_background_' . $region . '_path';
    $upload_key = 'gw_background_' . $region . '_upload';

    // Save the "use default" checkbox value.
    $config->set($use_default_key, $form_state->getValue($use_default_key));

    // Check if a new file was uploaded for this region.
    $upload_fids = $form_state->getValue($upload_key);
    if (!empty($upload_fids[0])) {
      // A new file was uploaded. Process it.
      $file = File::load($upload_fids[0]);
      if ($file && !$file->isPermanent()) {
        $file->setPermanent();
        $file->save();
      }
      // Save the new file's FID and clear the path field to avoid conflicts.
      $config->set($upload_key, $upload_fids);
      $config->set($path_key, '');
    }
    else {
      // No new file was uploaded, so save the value from the path field.
      // Also save the upload FID, which will be empty if the user removed a file.
      $config->set($path_key, $form_state->getValue($path_key));
      $config->set($upload_key, $upload_fids);
    }
  }

  // --- Process AI Palette Logo ---
  $ai_logo_fids = $form_state->getValue('ai_palette_logo');
  $config->set('ai_palette_logo', $ai_logo_fids);
  if (!empty($ai_logo_fids[0])) {
    $file = File::load($ai_logo_fids[0]);
    if ($file && !$file->isPermanent()) {
      $file->setPermanent();
      $file->save();
    }
  }

  // Finally, save all changes to the theme's configuration file.
  $config->save();
}

