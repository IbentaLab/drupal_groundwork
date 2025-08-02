# 🧭 Groundwork Contributor Onboarding Guide

Welcome, and thank you for your interest in contributing to the **Groundwork Theme Framework** — a fast, accessible, block-based, and component-driven Drupal 11+ frontend system.

This guide will walk you through:

* What Groundwork is
* How it’s structured
* Contribution rules
* Where to find things
* How to get started — today.

---

## 🚀 What is Groundwork?

Groundwork is a **modern, utility-first theme framework for Drupal 11+** designed to work out of the box with  **Layout Builder** ,  **Single Directory Components (SDCs)** , and **visual block styling tools** — all without needing build steps, JS frameworks, or external dependencies.

> It is built for accessibility (WCAG 2.1 AA + Norwegian laws), performance, and dev-friendly collaboration.

---

## 🧱 Groundwork Architecture

Groundwork is powered by three foundational CSS/component layers:

| Type                                        | Description                                                                  | Folder                          |
| ------------------------------------------- | ---------------------------------------------------------------------------- | ------------------------------- |
| **BSC**– Block Style Components      | Atomic utility classes for visual block styling. Used via UI or class names. | `css/block-style-components/` |
| **SDC**– Single Directory Components | Fully encapsulated UI components. Twig + YAML + CSS + JS in one folder.      | `components/`                 |
| **AP**– Atomic Partials              | Tiny, reusable atomic UI patterns (icons, ribbons, badges).                  | `css/partials/`               |

> HSCs (Hybrid Style Components) were deprecated as of 2025-08-01. Use BSCs + FPs + SDCs instead.

---

## 🌐 Groundwork Ecosystem

Groundwork is more than just a theme — it's an ecosystem made up of:

### ✅ 1. The Theme

Found in the `/themes/custom/groundwork/` folder.

Includes:

* All base CSS (`theme/`, `atomic-partials/`, `block-style-components/`, `layout/`)
* Design tokens (`groundwork-tokens.css`)
* Layout utilities
* Component folders (`/components`) with SDCs

### ✅ 2. The Groundwork Helpers Module

Custom Drupal module that extends the theme’s UI tools:

* **Block Styles UI** — checkboxes in block forms to apply classes (categorized and grouped from BSC docblocks)
* **Components** — provide blocks for Groundwork components
* **Dev tools** ,  **responsive images** , **and more are planned**

Module lives in: `modules/custom/groundwork_helpers/`

---

## 🖐 Rules & Guidelines

### ♻️ Use design tokens from `groundwork-tokens.css`

All spacing, sizing, color, radius, shadow, and typography must reference tokens.

Example:

```css
padding: var(--space-sm);
color: var(--color-text);
font-size: var(--ms-sm);
```

### ⚠️ Build all styles with **light/dark theme support**

Avoid hardcoded values. Use `--color-*` tokens that respond to theme context.

---

## 🎨 Semantic Color Variants — ✅ REQUIRED

These are the **required supported color variants** in all partials and color-capable BSCs:

* `--primary`
* `--secondary`
* `--info`
* `--notice`
* `--success`
* `--warning`
* `--danger`
* `--muted`

Each must:

* Use `--color-*` tokens only
* Provide appropriate text contrast (light/dark)
* Work in both themes (use `color-mix()` or background-aware pairs)

Example:

```css
.badge--primary {
  background-color: var(--color-primary);
  color: var(--color-text-inverse);
}

.badge--danger {
  background-color: var(--color-danger);
  color: var(--color-text-inverse);
}
```

---

## 🧹 Single Directory Components  (SDC) — ✅ REQUIRED

* Live in `components/`
* Must include:

  * `{name}.component.yml`
  * `{name}.twig`
  * Optional: `{name}.css`, `{name}.js`
* `component.yml` must define:

  * `props` (typed, optionally required)
  * `slots` (for flexible content)
  * Optional metadata: `group`, `status`, `description`
* JS must use `Drupal.behaviors`

Twig file must:

* Use semantic markup with ARIA support
* Output classes with `{{ attributes.addClass(classes) }}`

---

## 🗱 Atomic Partials (AP) — ✅ REQUIRED

* Live in `css/atomic-partials/`
* Must:

  * Use only tokenized values (no hardcoded hex, px, etc.)
  * Include variants:

    * Size: `--xs`, `--sm`, `--md`, `--lg`, `--xl`, `--xxl`
    * Color: all **eight semantic color variants** listed above
    * Component-specific: e.g. `--rounded`, `--pill`, `--dismissable`
* Must include this docblock:

```css
/*
 * Variants supported:
 *  - 🔏 Size: xs, sm, md, lg, xl, xxl
 *  - 🎨 Color: primary, secondary, info, notice, success, warning, danger, muted
 *  - 🧠 Component: pill, square, dismissable
 */
```

---

## 🎨 Block Style Components (BSC) — ✅ REQUIRED

* Live in `css/block-style-components/`
* Required top docblock:

```css
/**
 * @category 🎨 Visual Styles
 * @description Provides utility classes for card components, padding, borders, and background.
 * @order 1
 */
```

* Each class must have:

```css
/**
 * @name .card
 * @description A padded, bordered content block with background support.
 * @blockStyleComponent true
 */
```

* Use tokens only, no raw hex/px
* Must support semantic color variants (same list as above)
* Must be tested in Block Styles UI

---

## ✅ JavaScript

* Vanilla JS only — no jQuery
* Scoped per component
* Use `Drupal.behaviors` pattern
* Must enhance progressively and degrade gracefully

---

## ✅ PHP

All PHP contributions must follow the [Drupal PHP Coding Standards](https://www.drupal.org/docs/develop/standards/php/php-coding-standards). Key rules include:

* Use **PSR-12** formatting style
* Use full PHP opening tags `<?php` only
* Indent with **2 spaces** (no tabs)
* One class per file
* Follow proper **namespace and use** declarations
* Include **type hints** for all parameters and return values
* Use `declare(strict_types=1);` at the top of every file
* Avoid long inline functions and complex logic in templates
* Use `@file` docblocks and inline comments where helpful
* All module code should be inside `groundwork_helpers` or relevant submodules

Example:

```php
<?php

declare(strict_types=1);

namespace Drupal\groundwork_helpers\Plugin\Block;

use Drupal\Core\Block\BlockBase;

/**
 * Provides a custom example block.
 *
 * @Block(
 *   id = "example_block",
 *   admin_label = @Translation("Example block"),
 * )
 */
class ExampleBlock extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function build(): array {
    return [
      '#markup' => $this->t('Hello from Groundwork!'),
    ];
  }

}
```

---

## 🛠 Where to Add Your Work

| Type               | Directory                              |
| ------------------ | -------------------------------------- |
| New visual utility | `css/block-style-components/`        |
| New component      | `components/[name]/`                 |
| Reusable snippet   | `css/partials/`                      |
| Design token       | `theme/groundwork-tokens.css`        |
| Layout helper      | `css/layout/`                        |
| Module/feature     | `modules/custom/groundwork_helpers/` |

---

## 🧪 Before Submitting

* ✅ Run `drush cr`
* ✅ Test in light + dark mode
* ✅ Validate YAML, CSS, JS, PHP syntax
* ✅ Confirm color contrast and ARIA/keyboard support
* ✅ Include all required docblocks and variants

---

## 📬 Ready to Contribute?

1. Fork the Groundwork repo (GitHub)
2. Clone to local + set up with DDEV or Drupal quick-start
3. Explore `css/`, `components/`, and `modules/custom/groundwork_helpers/`
4. Pick an issue or propose a new BSC, FP, or SDC
5. Follow all `✅ REQUIRED` guidelines above
6. Open a PR and tag a maintainer

🎉 Welcome aboard! Let’s build the future of Drupal theming — together.
