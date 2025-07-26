# Installing Groundwork

Groundwork is designed to be fast and easy to install. There are no build tools, no Sass compilers, and no JavaScript frameworks. You just drop it into your Drupal site and start building with Layout Builder or the Block UI.

This guide walks you through:

* Installing the Groundwork theme with Composer
* Setting it as your default theme
* Enabling optional modules (like Layout Builder and Groundwork Helpers)

Let’s get started.

---

## 🧩 Prerequisites

Before installing Groundwork, make sure you have:

* A working Drupal 10.1+ or 11 site
* Composer installed
* Drush (recommended)

> 💡 Groundwork is compatible with both Drupal 10.1+ and Drupal 11.

---

## 📦 Step 1: Install the Theme with Composer

In your terminal, run:

```bash
composer require drupal/groundwork
```

This will download the Groundwork theme into your `themes/contrib/` directory.

---

## ✅ Step 2: Enable the Theme

You can enable it using Drush:

```bash
drush theme:enable groundwork
```

Or via the Drupal admin UI:

1. Go to **Appearance**
2. Click **Install and set as default** next to **Groundwork**

---

## 🎯 Step 3: Set as Default Theme

If you used Drush:

```bash
drush config-set system.theme default groundwork
```

Or via the admin UI under **Appearance** →  **Set as default** .

---

## 🚀 Step 4: Clear the Cache

Groundwork uses Single Directory Components (SDCs), so make sure to rebuild the cache:

```bash
drush cr
```

Or via the UI: **Configuration** → **Performance** →  **Clear all caches** .

---

## 🧱 Step 5: (Optional but Recommended) Enable Layout Builder

Layout Builder allows you to visually build pages using drag-and-drop blocks.

To enable it:

1. Go to **Structure** → **Content types** → Choose a type (e.g. "Page") → **Manage display**
2. Check **Use Layout Builder** and optionally **Allow each content item to have its layout customized**
3. Save

You can now use Layout Builder to place SDCs, blocks, and apply styles.

---

## 🧰 Step 6: (Optional) Install Groundwork Helpers Module

This module enhances the Groundwork experience with UI tools:

* Block Styles UI (visual class-based styling)
* Icon Picker (Gwicons)
* Layout Patterns and responsive image handling

Install it with:

```bash
composer require drupal/groundwork_helpers
```

Enable modules:

```bash
drush en groundwork_helpers groundwork_helpers_block_styles groundwork_helpers_gwicons
```

> You can also enable them via the admin UI at  **Extend** .

---

## 🔍 What’s Next?

✅ You’ve installed Groundwork! Now:

* Start building pages with Layout Builder or Block UI
* Apply styles visually using the Block Styles UI
* Explore [Block Style Components (BSCs)](../guides/block-style-components.md)

> **Groundwork is now active. You’re ready to build fast, accessible, flexible layouts — without a single line of CSS.**
>
