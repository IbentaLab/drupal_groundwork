<?php

/**
 * @file
 * Groundwork Theme Settings form (vertical tabs, AI providers, pro styling).
 *
 * @ingroup groundwork
 */

use Drupal\Core\Form\FormStateInterface;

// Include the init file to make sure AJAX callbacks are available.
include_once __DIR__ . '/init.inc';

function groundwork_form_system_theme_settings_alter(&$form, FormStateInterface $form_state)
{
  // Load the theme's configuration object to get settings.
  $config = \Drupal::config('groundwork.settings');

  // ----- Branded header -----
  $logo_path = \Drupal::theme()->getActiveTheme()->getPath() . '/images/groundwork-logo.svg';
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

  // ----- Design & Branding tab -----
  $form['design'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Design & Branding'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 10,
  ];
  $form['design']['gw_color_scheme'] = [
    '#type' => 'radios',
    '#title' => \Drupal::translation()->translate('Color scheme'),
    '#default_value' => $config->get('gw_color_scheme'),
    '#options' => [
      'auto' => \Drupal::translation()->translate('Follow OS setting'),
      'light' => \Drupal::translation()->translate('Light'),
      'dark' => \Drupal::translation()->translate('Dark'),
    ],
    '#description' => \Drupal::translation()->translate('Switch between light and dark mode, or follow the user’s operating system preference.'),
  ];
  $form['design']['gw_color_utilities'] = [
    '#type' => 'checkboxes',
    '#title' => \Drupal::translation()->translate('Enable Color Utility Palettes'),
    '#description' => \Drupal::translation()->translate('Select which color utility stylesheets to load. Each enabled color provides a set of utility classes (e.g., .red, .red--dark1).'),
    '#options' => [
      'amber' => \Drupal::translation()->translate('Amber'),
      'blue-gray' => \Drupal::translation()->translate('Blue Gray'),
      'brown' => \Drupal::translation()->translate('Brown'),
      'cyan' => \Drupal::translation()->translate('Cyan'),
      'deep-purple' => \Drupal::translation()->translate('Deep Purple'),
      'green' => \Drupal::translation()->translate('Green'),
      'indigo' => \Drupal::translation()->translate('Indigo'),
      'lime' => \Drupal::translation()->translate('Lime'),
      'orange' => \Drupal::translation()->translate('Orange'),
      'pink' => \Drupal::translation()->translate('Pink'),
      'purple' => \Drupal::translation()->translate('Purple'),
      'red' => \Drupal::translation()->translate('Red'),
      'teal' => \Drupal::translation()->translate('Teal'),
      'yellow' => \Drupal::translation()->translate('Yellow'),
    ],
    '#default_value' => $config->get('gw_color_utilities') ?? [],
  ];
  $form['design']['gw_custom_css'] = [
    '#type' => 'textarea',
    '#title' => \Drupal::translation()->translate('Custom CSS'),
    '#description' => \Drupal::translation()->translate('Add custom CSS for quick tweaks or experiments. Only valid CSS will be rendered. For security reasons, HTML tags (such as &lt;div&gt;, &lt;script&gt;) or JavaScript code are not allowed—if your CSS includes &lt; or &gt;, it will be rejected.'),
    '#default_value' => $config->get('gw_custom_css'),
    '#element_validate' => ['groundwork_validate_custom_css'],
  ];

  // Sidebar First fieldset
  $form['design']['gw_sidebar_first'] = [
    '#type' => 'fieldset',
    '#title' => \Drupal::translation()->translate('Sidebar First Grid Widths'),
    '#description' => \Drupal::translation()->translate('Choose how many grid cells Sidebar First should occupy on each breakpoint. Default layout is 4 on desktop and 3 on wide.'),
    '#attributes' => ['class' => ['gw-sidebar-settings', 'gw-horizontal-selects']],
  ];
  $form['design']['gw_sidebar_first']['gw_sidebar_first_cells_s'] = [
    '#type' => 'select',
    '#title' => \Drupal::translation()->translate('Mobile (S)'),
    '#options' => array_combine(range(1, 12), range(1, 12)),
    '#default_value' => $config->get('gw_sidebar_first_cells_s') ?? 12,
  ];
  $form['design']['gw_sidebar_first']['gw_sidebar_first_cells_m'] = [
    '#type' => 'select',
    '#title' => \Drupal::translation()->translate('Desktop (M)'),
    '#options' => array_combine(range(1, 12), range(1, 12)),
    '#default_value' => $config->get('gw_sidebar_first_cells_m') ?? 4,
  ];
  $form['design']['gw_sidebar_first']['gw_sidebar_first_cells_l'] = [
    '#type' => 'select',
    '#title' => \Drupal::translation()->translate('Wide (L)'),
    '#options' => array_combine(range(1, 12), range(1, 12)),
    '#default_value' => $config->get('gw_sidebar_first_cells_l') ?? 3,
  ];

  // Sidebar Second fieldset
  $form['design']['gw_sidebar_second'] = [
    '#type' => 'fieldset',
    '#title' => \Drupal::translation()->translate('Sidebar Second Grid Widths'),
    '#description' => \Drupal::translation()->translate('Choose how many grid cells Sidebar Second should occupy on each breakpoint. Default layout is 2 on desktop and wide.'),
    '#attributes' => ['class' => ['gw-sidebar-settings', 'gw-horizontal-selects']],
  ];
  $form['design']['gw_sidebar_second']['gw_sidebar_second_cells_s'] = [
    '#type' => 'select',
    '#title' => \Drupal::translation()->translate('Mobile (S)'),
    '#options' => array_combine(range(1, 12), range(1, 12)),
    '#default_value' => $config->get('gw_sidebar_second_cells_s') ?? 12,
  ];
  $form['design']['gw_sidebar_second']['gw_sidebar_second_cells_m'] = [
    '#type' => 'select',
    '#title' => \Drupal::translation()->translate('Desktop (M)'),
    '#options' => array_combine(range(1, 12), range(1, 12)),
    '#default_value' => $config->get('gw_sidebar_second_cells_m') ?? 2,
  ];
  $form['design']['gw_sidebar_second']['gw_sidebar_second_cells_l'] = [
    '#type' => 'select',
    '#title' => \Drupal::translation()->translate('Wide (L)'),
    '#options' => array_combine(range(1, 12), range(1, 12)),
    '#default_value' => $config->get('gw_sidebar_second_cells_l') ?? 2,
  ];


  // ----- Navigation & Menus tab -----
  $form['gw_navigation'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Navigation & Menus'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 15,
    '#description' => \Drupal::translation()->translate('Configure display options for the site header and menus.'),
  ];

  $form['gw_navigation']['gw_header_layout'] = [
    '#type'          => 'radios',
    '#title'         => \Drupal::translation()->translate('Header Layout'),
    '#default_value' => $config->get('gw_header_layout') ?: 'header--brand-left',
    '#options'       => [
      'header--brand-left'  => \Drupal::translation()->translate('Brand Left (Default)'),
      'header--brand-center' => \Drupal::translation()->translate('Brand Center'),
      'header--brand-stacked' => \Drupal::translation()->translate('Stacked'),
    ],
    '#description'   => \Drupal::translation()->translate('Select the layout for the site header. This applies a CSS class to the <body> tag.'),
  ];

  $form['gw_navigation']['gw_menu_main_horizontal'] = [
    '#type' => 'checkbox',
    '#title' => \Drupal::translation()->translate('Display Main menu as a horizontal, responsive menu'),
    '#default_value' => $config->get('gw_menu_main_horizontal') ?? 1,
    '#description' => \Drupal::translation()->translate('When checked, the main menu will be styled as a horizontal bar with dropdowns on desktop, and a collapsible accordion on mobile. Best used in the Header or Primary Menu regions.'),
  ];

  $form['gw_navigation']['gw_menu_secondary_horizontal'] = [
    '#type' => 'checkbox',
    '#title' => \Drupal::translation()->translate('Display Secondary menu as a horizontal, responsive menu'),
    '#default_value' => $config->get('gw_menu_secondary_horizontal') ?? 0,
    '#description' => \Drupal::translation()->translate('When checked, the secondary menu will be styled as a horizontal bar.'),
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

  // ----- AI-powered Tools tab -----
  $form['ai_tools'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('AI-powered Tools'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 20,
    '#description' => \Drupal::translation()->translate('Try the AI-powered color palette generator! Gemini offers 1,000 free requests/month.'),
  ];

  $form['ai_tools']['ai_provider'] = [
    '#type' => 'select',
    '#title' => \Drupal::translation()->translate('AI Provider'),
    '#options' => [
      '' => \Drupal::translation()->translate('Choose provider...'),
      'gemini' => \Drupal::translation()->translate('Google Gemini (Gemini Pro – recommended, free tier)'),
      'openai' => \Drupal::translation()->translate('OpenAI (ChatGPT, GPT-4o, GPT-3.5 Turbo)'),
      'openrouter' => \Drupal::translation()->translate('OpenRouter (DeepSeek, Llama-3, Mixtral, GPT-4o, etc.)'),
      'huggingface' => \Drupal::translation()->translate('HuggingFace (DeepSeek, Llama, Mistral, open source)'),
      'azure' => \Drupal::translation()->translate('Azure AI (GPT-4, GPT-3.5, vision, enterprise)'),
      'aws' => \Drupal::translation()->translate('AWS Bedrock (Anthropic, Amazon Titan, Llama)'),
      'perplexity' => \Drupal::translation()->translate('Perplexity AI (PPLX-70B, web-powered Q&A, paid only)'),
      'simulate' => \Drupal::translation()->translate('Simulate AI (demo only, no real AI)'),
    ],
    '#default_value' => $config->get('ai_provider') ?: '',
    '#description' => \Drupal::translation()->translate('Choose your AI provider. Gemini is free for most users. OpenRouter gives you access to DeepSeek, Llama, and many others.'),
  ];
  $form['ai_tools']['ai_gemini_api_key'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('Google Gemini API Key'),
    '#description' => \Drupal::translation()->translate('Get your free API key at <a href="https://ai.google.dev/gemini-api/docs/pricing" target="_blank">Gemini API</a>.'),
    '#default_value' => $config->get('ai_gemini_api_key'),
    '#states' => ['visible' => [':input[name="ai_provider"]' => ['value' => 'gemini']]],
    '#element_validate' => ['groundwork_validate_api_key'],
  ];
  $form['ai_tools']['ai_openai_api_key'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('OpenAI API Key'),
    '#description' => \Drupal::translation()->translate('Get your API key at <a href="https://platform.openai.com/" target="_blank">OpenAI</a>.'),
    '#default_value' => $config->get('ai_openai_api_key'),
    '#states' => ['visible' => [':input[name="ai_provider"]' => ['value' => 'openai']]],
    '#element_validate' => ['groundwork_validate_api_key'],
  ];
  $form['ai_tools']['ai_openrouter_api_key'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('OpenRouter API Key'),
    '#description' => \Drupal::translation()->translate('Get your API key at <a href="https://openrouter.ai/" target="_blank">OpenRouter.ai</a>. Choose your model (DeepSeek, Llama, etc.) in your OpenRouter dashboard.'),
    '#default_value' => $config->get('ai_openrouter_api_key'),
    '#states' => ['visible' => [':input[name="ai_provider"]' => ['value' => 'openrouter']]],
  ];
  $form['ai_tools']['ai_huggingface_api_key'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('HuggingFace API Key'),
    '#description' => \Drupal::translation()->translate('Get your API token at <a href="https://huggingface.co/settings/tokens" target="_blank">HuggingFace</a>. Choose DeepSeek or other open models.'),
    '#default_value' => $config->get('ai_huggingface_api_key'),
    '#states' => ['visible' => [':input[name="ai_provider"]' => ['value' => 'huggingface']]],
  ];
  $form['ai_tools']['ai_azure_api_key'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('Azure AI API Key'),
    '#description' => \Drupal::translation()->translate('Get your API key at <a href="https://portal.azure.com/" target="_blank">Azure Portal</a>.'),
    '#default_value' => $config->get('ai_azure_api_key'),
    '#states' => ['visible' => [':input[name="ai_provider"]' => ['value' => 'azure']]],
  ];
  $form['ai_tools']['ai_aws_api_key'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('AWS Bedrock API Key'),
    '#description' => \Drupal::translation()->translate('Get your API key at <a href="https://console.aws.amazon.com/" target="_blank">AWS Console</a>.'),
    '#default_value' => $config->get('ai_aws_api_key'),
    '#states' => ['visible' => [':input[name="ai_provider"]' => ['value' => 'aws']]],
  ];
  $form['ai_tools']['ai_perplexity_api_key'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('Perplexity API Key'),
    '#description' => \Drupal::translation()->translate('Sign up for a Perplexity API key at <a href="https://docs.perplexity.ai/" target="_blank">Perplexity docs</a>. No free tier.'),
    '#default_value' => $config->get('ai_perplexity_api_key'),
    '#states' => ['visible' => [':input[name="ai_provider"]' => ['value' => 'perplexity']]],
  ];
  $form['ai_tools']['ai_simulate_note'] = [
    '#type' => 'container',
    '#states' => ['visible' => [':input[name="ai_provider"]' => ['value' => 'simulate']]],
    '#markup' => '<div class="gw-pro-feature-disabled"><strong>' . \Drupal::translation()->translate('Simulate AI:') . '</strong> ' . \Drupal::translation()->translate('This is a demo result for testing and development. No real AI is used.') . '</div>',
  ];
  $form['ai_tools']['ai_palette_logo'] = [
    '#type' => 'managed_file',
    '#title' => \Drupal::translation()->translate('Upload logo or image for color palette suggestion'),
    '#upload_location' => 'public://ai_palette/',
    '#default_value' => $config->get('ai_palette_logo'),
    '#description' => \Drupal::translation()->translate('Upload a logo or image for AI-powered color palette suggestions.'),
  ];
  $form['ai_tools']['ai_suggest_palette'] = [
    '#type' => 'submit',
    '#value' => \Drupal::translation()->translate('Suggest Color Palette (AI-powered)'),
    '#ajax' => [
      'callback' => 'groundwork_ai_palette_callback',
      'wrapper' => 'ai-palette-result-wrapper',
      'effect' => 'fade',
    ],
  ];
  $form['ai_tools']['ai_palette_result'] = [
    '#type' => 'markup',
    '#markup' => '<div id="ai-palette-result-wrapper"></div>',
    '#allowed_tags' => ['div', 'span', 'strong'],
  ];

  // ----- Social Links tab -----
  $form['social'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Social Links Bar'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 25,
  ];
  $form['social']['gw_social_bar_location'] = [
    '#type' => 'radios',
    '#title' => \Drupal::translation()->translate('Location'),
    '#options' => [
      'none' => \Drupal::translation()->translate('None (Hide the bar)'),
      'header' => \Drupal::translation()->translate('Above the main site header'),
      'footer' => \Drupal::translation()->translate('In the footer (above the legal bar)'),
    ],
    '#default_value' => $config->get('gw_social_bar_location') ?: 'footer',
    '#description' => \Drupal::translation()->translate('Choose where to display the full-width social links bar.'),
  ];
  $form['social']['gw_social_bar_alignment'] = [
    '#type' => 'radios',
    '#title' => \Drupal::translation()->translate('Link Alignment'),
    '#options' => [
      'left' => \Drupal::translation()->translate('Left'),
      'center' => \Drupal::translation()->translate('Center'),
      'right' => \Drupal::translation()->translate('Right'),
      'distributed' => \Drupal::translation()->translate('Distributed (Justify)'),
    ],
    '#default_value' => $config->get('gw_social_bar_alignment') ?: 'center',
    '#description' => \Drupal::translation()->translate('Align the links within the social bar.'),
    '#states' => ['visible' => [':input[name="gw_social_bar_location"]' => ['!value' => 'none']]],
  ];
  $form['social']['gw_social_links_intro'] = [
    '#type' => 'markup',
    '#markup' => '<p><strong>' . \Drupal::translation()->translate('Enter the full URLs for your social media profiles. The bar will only appear if at least one link is entered.') . '</strong></p>',
    '#states' => ['visible' => [':input[name="gw_social_bar_location"]' => ['!value' => 'none']]],
  ];
  $social_networks = [
    'twitter' => \Drupal::translation()->translate('X (formerly Twitter)'),
    'facebook' => \Drupal::translation()->translate('Facebook'),
    'linkedin' => \Drupal::translation()->translate('LinkedIn'),
    'instagram' => \Drupal::translation()->translate('Instagram'),
    'youtube' => \Drupal::translation()->translate('YouTube'),
  ];
  foreach ($social_networks as $key => $title) {
    $form['social']['gw_social_' . $key] = [
      '#type' => 'url',
      '#title' => $title,
      '#default_value' => $config->get('gw_social_' . $key),
      '#states' => ['visible' => [':input[name="gw_social_bar_location"]' => ['!value' => 'none']]],
    ];
  }

  // ----- Footer & Attribution tab -----
  $form['footer'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Footer & Attribution'),
    '#group' => 'gw_settings_tabs',
    '#weight' => 30,
  ];
  $form['footer']['gw_footer_attribution'] = [
    '#type' => 'checkbox',
    '#title' => \Drupal::translation()->translate('Show “Powered by Groundwork Theme Framework” in the footer'),
    '#default_value' => 1,
    '#description' => \Drupal::translation()->translate('This attribution helps support ongoing development. <strong>Removal is available with a <a href=":pro_url" target="_blank">Groundwork Pro license</a>.</strong>', [':pro_url' => 'https://groundwork.ibenta.no/pro']),
    '#attributes' => ['disabled' => 'disabled'],
  ];
  $form['footer']['gw_footer_copyright_enable'] = [
    '#type' => 'checkbox',
    '#title' => \Drupal::translation()->translate('Show copyright text in the footer'),
    '#default_value' => 1,
    '#description' => \Drupal::translation()->translate('Uncheck to hide the copyright line from the footer.'),
    '#attributes' => ['disabled' => 'disabled'],
  ];
  $site_name = \Drupal::config('system.site')->get('name');
  $default_copyright = \Drupal::translation()->translate('&copy; {year} @site_name. All rights reserved.', ['@site_name' => $site_name]);
  $form['footer']['gw_footer_copyright'] = [
    '#type' => 'textfield',
    '#title' => \Drupal::translation()->translate('Footer copyright text'),
    '#description' => \Drupal::translation()->translate('Supports tokens like {year}, {site_name}. Example: &copy; {year} My Company.<br><strong>Removal is available with a <a href=":pro_url" target="_blank">Groundwork Pro license</a>.</strong>', [':pro_url' => 'https://groundwork.ibenta.no/pro']),
    '#default_value' => $config->get('gw_footer_copyright') ?: $default_copyright,
    '#states' => ['visible' => [':input[name="gw_footer_copyright_enable"]' => ['checked' => TRUE]]],
  ];

  // ----- Collapse core Drupal theme settings in their own fieldset -----
  $core_settings = ['theme_settings', 'logo', 'favicon'];
  $form['core_settings'] = [
    '#type' => 'details',
    '#title' => \Drupal::translation()->translate('Drupal Core Theme Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 100,
  ];
  foreach ($core_settings as $key) {
    if (isset($form[$key])) {
      $form['core_settings'][$key] = $form[$key];
      unset($form[$key]);
    }
  }

  // Attach admin CSS for settings page styling.
  $form['#attached']['library'][] = 'groundwork/theme-settings';
}

/**
 * Validation for the custom CSS field.
 */
function groundwork_validate_custom_css($element, FormStateInterface $form_state, $form) {
  $css = $form_state->getValue('gw_custom_css');
  if (preg_match('/[<>]/', $css)) {
    $form_state->setError($element, \Drupal::translation()->translate('HTML tags are not allowed in custom CSS.'));
  }
}

/**
 * Validation for API keys.
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
