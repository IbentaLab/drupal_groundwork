<?php

/**
 * @file
 * Groundwork Theme Settings form (vertical tabs, AI providers pro styling).
 */

use Drupal\Core\Form\FormStateInterface;
use Drupal\file\Entity\File;
use Drupal\Core\StringTranslation\TranslatableMarkup;

// Include the init file to make sure AJAX callbacks are available.
if (file_exists(__DIR__ . '/init.inc')) {
  include_once __DIR__ . '/init.inc';
}

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function groundwork_form_system_theme_settings_alter(&$form, FormStateInterface $form_state) {
  // Load the theme's configuration object to get settings.
  $config = \Drupal::config('groundwork.settings');

  // Define reusable options arrays.
  $padding_options = [
    'none' => \Drupal::translation()->translate('None'),
    'xs' => \Drupal::translation()->translate('Extra Small'),
    'sm' => \Drupal::translation()->translate('Small'),
    'md' => \Drupal::translation()->translate('Medium'),
    'lg' => \Drupal::translation()->translate('Large'),
    'xl' => \Drupal::translation()->translate('Extra Large'),
    'xxl' => \Drupal::translation()->translate('Extra Extra Large'),
  ];

  $container_options = [
    'contained' => \Drupal::translation()->translate('Contained (Centered with max-width)'),
    'full-width' => \Drupal::translation()->translate('Full Width (Spans entire browser width)'),
  ];

  $color_options = [
    '' => \Drupal::translation()->translate('Default'),
    'primary' => \Drupal::translation()->translate('Primary'),
    'secondary' => \Drupal::translation()->translate('Secondary'),
    'success' => \Drupal::translation()->translate('Success'),
    'warning' => \Drupal::translation()->translate('Warning'),
    'danger' => \Drupal::translation()->translate('Danger'),
    'info' => \Drupal::translation()->translate('Info'),
    'light' => \Drupal::translation()->translate('Light'),
    'dark' => \Drupal::translation()->translate('Dark'),
  ];

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
            Docs: <a href="https://groundwork.ibenta.no/docs" target="_blank">View online</a>
            &nbsp;|&nbsp;
            <a href="mailto:support@ibenta.no">Contact support</a>
          </small>
        </div>
      </div>
    ',
    '#weight' => -100,
  ];

  $form['#attributes']['enctype'] = 'multipart/form-data';

  // ----- Vertical tabs -----
  $form['gw_settings_tabs'] = [
    '#type' => 'vertical_tabs',
    '#title' => \Drupal::translation()->translate('Groundwork Theme Settings'),
    '#weight' => -90,
  ];

  // Include the settings files for each tab.
  // Variables ($config, $padding_options, etc.) are in scope.
  $settings_files = [
    'design.inc',
    'layout.inc',
    'accessibility.inc',
    'ai-tools.inc',
    'social.inc',
    'seo.inc',
  ];

  foreach ($settings_files as $file) {
    $file_path = __DIR__ . '/settings/' . $file;
    if (file_exists($file_path)) {
      include $file_path;
    }
  }

  // ----- Collapse core Drupal theme settings -----
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

  // Attach the custom submit handler and CSS.
  $form['#submit'][] = 'groundwork_theme_settings_submit';
  $form['#attached']['library'][] = 'groundwork/theme-settings';
}

/**
 * Validation callback for the custom CSS field.
 *
 * @param array $element
 *   The form element being validated.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 *   The form state object.
 * @param array $form
 *   The complete form array.
 */
function groundwork_validate_custom_css($element, FormStateInterface $form_state, $form) {
  $css = $form_state->getValue('gw_custom_css');
  if (preg_match('/[<>]/', $css)) {
    $form_state->setError($element, \Drupal::translation()->translate('HTML tags are not allowed in custom CSS.'));
  }
}

/**
 * Validation callback for API keys.
 *
 * @param array $element
 *   The form element being validated.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 *   The form state object.
 * @param array $form
 *   The complete form array.
 */
function groundwork_validate_api_key($element, FormStateInterface $form_state, $form) {
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
 *
 * @param array $form
 *   The form array.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 *   The form state object.
 */
function groundwork_theme_settings_submit(&$form, FormStateInterface $form_state) {
  // Load the editable configuration object to save values.
  $config = \Drupal::configFactory()->getEditable('groundwork.settings');

  // --- Process Region Backgrounds ---
  $regions_with_backgrounds = [
    'billboard',
    'header',
    'hero',
    'supplement',
    'extra',
    'rider',
    'footer',
  ];

  foreach ($regions_with_backgrounds as $region) {
    groundwork_process_region_background_files($region, $form_state, $config);
  }

  // --- Save All Other Configuration Values ---
  foreach ($form_state->getValues() as $key => $value) {
    if (strpos($key, 'gw_') === 0 || strpos($key, 'ai_') === 0) {
      $config->set($key, $value);
    }
  }

  // Save all changes to the theme's configuration file.
  $config->save();

  // Clear theme registry to apply any new settings.
  \Drupal::service('theme.registry')->reset();

  // Show success message.
  \Drupal::messenger()->addMessage(
    \Drupal::translation()->translate('Groundwork theme settings have been saved successfully.')
  );
}

/**
 * Process background file uploads for a region.
 *
 * @param string $region
 *   The region name.
 * @param \Drupal\Core\Form\FormStateInterface $form_state
 *   The form state object.
 * @param \Drupal\Core\Config\Config $config
 *   The editable configuration object.
 */
function groundwork_process_region_background_files(string $region, FormStateInterface $form_state, $config): void {
  $use_default_key = 'gw_background_' . $region . '_use_default';
  $path_key = 'gw_background_' . $region . '_path';
  $upload_key = 'gw_background_' . $region . '_upload';

  // Save the "use default" checkbox value.
  $config->set($use_default_key, $form_state->getValue($use_default_key));

  // Check if a new file was uploaded for this region.
  $upload_fids = $form_state->getValue($upload_key);
  if (!empty($upload_fids[0])) {
    // A new file was uploaded. Process it.
    try {
      $file = File::load($upload_fids[0]);
      if ($file && !$file->isPermanent()) {
        $file->setPermanent();
        $file->save();
      }
      // Save the new file's FID and clear the path field to avoid conflicts.
      $config->set($upload_key, $upload_fids);
      $config->set($path_key, '');
    }
    catch (\Exception $e) {
      \Drupal::logger('groundwork')->error('Error processing background file for @region: @message', [
        '@region' => $region,
        '@message' => $e->getMessage(),
      ]);
    }
  }
  else {
    // No new file was uploaded, so save the value from the path field.
    // Also save the upload FID, which will be empty if the user removed a file.
    $config->set($path_key, $form_state->getValue($path_key));
    $config->set($upload_key, []);
  }
}
