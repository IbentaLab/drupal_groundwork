<?php

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
    '#upload_validators' => [
      'FileIsImage' => [],
      'FileExtension' => [
        'extensions' => 'jpg jpeg png gif svg webp avif',
      ],
    ],
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
