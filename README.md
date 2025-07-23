<br>

<div style="font-size: 24px; color: #ffffff; font-weight: bold; text-align: center; background-color: #dc3545; border: 3px solid #7e0a14ff; padding: 20px; border-radius: 10px; margin: 20px 0;">
⚠️ NOT PRODUCTION READY ⚠️<br>
<span style="font-size: 16px;">This repository is under heavy development</span>
</div>

<br>

# 🚀 What Is Groundwork Theme Framework?

**The fast, accessible, atomic foundation for block-based Drupal.**

<br>

<div align="center">
<img src="images/drupal-11+--blue.svg" alt="Drupal 11+" height="24">
<img src="images/no-build-tools-100-percent-vanilla--brightgreen.svg" alt="No Build Tools" height="24">
<img src="images/accessibility-wcag_2.1_aa _norwegian-law--blueviolet.svg" alt="WCAG 2.1 AA & Norwegian Law" height="24">
<img src="images/performance-first-informational.svg" alt="Performance First" height="24">
</div>

---

**Groundwork Theme Framework** is a next-generation frontend framework built specifically for **Drupal**. Engineered for ⚡ speed, ♿ accessibility, and 💡 developer joy, it empowers developers, designers, and site builders to build modern, flexible websites using pure Drupal features and vanilla web technologies—**no build tools required**.

<br>

> Built with Blocks, Layout Builder, Single Directory Components (SDCs), and vanilla Twig, CSS, and JavaScript. No SCSS, no Webpack, no Node dependencies.

#### The Groundwork has been laid. Now, let's build something great.

## 🎯 Why Groundwork?

- ♿ **Accessibility-first** – Built to meet WCAG 2.1 AA and Norwegian digital accessibility laws
- ⚡ **Performance-first** – Every line of code is designed for speed and efficiency
- 🧱 **Structure-first** – Logical, maintainable architecture with consistent file and CSS structure
- 🧰 **No-code-friendly** – Editors and content creators can style pages without touching code
- 🎨 **Utility-first** – Use composable, reusable CSS classes across any part of the site
- 🚫 **Build-free** – No compiling, no build step — just native Drupal and vanilla tech

Groundwork isn't just a theme you install and forget—it's a frontend **philosophy** that helps your entire team build better, faster, and more accessibly.

---

## 🚀 Quick Start

**This next-generation Groundwork, compatible with Drupal 11+, will be officially released on drupal.org upon reaching stable status.**

```sh
composer require drupal/groundwork
```

Or download from [drupal.org/project/groundwork](https://www.drupal.org/project/groundwork).

```sh
drush theme:enable groundwork
drush config-set system.theme default groundwork
```

1. **Compose pages using either:**
   - **Layout Builder** for visual, drag-and-drop page building (optional but fully supported), **or**
   - **Drupal's core Block UI** for familiar block placement.
2. **Apply Block Style Components (BSC) atomic classes** or block presets via the “Groundwork Block Styles” UI (see below) or class field.
3. **Use Hybrid Style Components (HSC)** for complex internal layouts.
4. **Build with Single Directory Components (SDC)** for modular, reusable custom elements.

<br>

---

# 🧱 Core Architecture

Groundwork is built around **six powerful frontend building blocks**, each serving a different purpose:

| Type                                         | Folder                           | Purpose                                              |
| -------------------------------------------- | -------------------------------- | ---------------------------------------------------- |
| **BSC** – Block Style Components      | `css/block-style-components/`  | Atomic utility classes for styling blocks and fields |
| **HSC** – Hybrid Style Components     | `css/hybrid-style-components/` | Layout + style combinations for flexible sections    |
| **SDC** – Single Directory Components | `components/`                  | Fully reusable, self-contained UI components         |
| **FP** – Framework Partials           | `framework-partials/`          | Small chunks of reusable UI used across templates    |
| **Grid System**                        | `css/layout/`                  | Responsive, class-based 12-column layout system      |
| **Layout Builder**                     | Core Drupal                      | Visual content composition with drag-and-drop tools  |

## 🎨 Block Style Components (BSC)

BSCs are dual-purpose. They are **atomic utility classes** — small, single-purpose CSS classes you can apply directly to any element or to style blocks to change their appearance.

### Example:

```html
<div class="card p-4 shadow text-center">
  I’m styled with BSCs!
</div>
```

### What can you do with BSCs?

- Add spacing (`.p-4`, `.mt-2`)
- Control alignment (`.text-center`, `.text-right`)
- Apply colors (`.bg-primary`, `.text-light`)
- Add visual effects (`.shadow`, `.border`, `.card`, `.alert--warning`)

### How are they used?

- 💻 Developers can apply them anywhere.
- 🧑‍🎨 Editors can apply them visually in blocks using the **Block Styles UI**
- 🎯 You can stack them freely — e.g. `.card.bg-light.p-4.shadow-lg`

📁 Located in: `css/block-style-components/`

## ⚗️ Hybrid Style Components (HSC)

HSCs are **ready-made layout + style patterns**. They’re more than simple utilities but not full components. Think of them as reusable building blocks for structuring a section of your site.

### Use HSCs when you need:

- A **media + text** layout that works on all screen sizes
- A **card grid** with consistent spacing and alignment
- A **two-column hero section** or feature band

### What makes them useful?

- They’re consistent: once you define an HSC layout, it works across the entire site
- They’re flexible: you can combine them with BSCs for even more control
- They require no JS or Twig: just apply the right classes

📁 Located in: `css/hybrid-style-components/`

## 🧩 Single Directory Components (SDC)

SDCs are very muc supported and utilized in Groundwork. An SDC is a Drupal core feature that is **self-contained**. It includes everything a component needs to work:

```
components/
  └── hero/
      ├── hero.twig
      ├── hero.css
      ├── hero.js
      └── hero.component.yml
```

### Why SDCs rock:

- ✅ They’re lazy-loaded — only load when the component is rendered
- ✅ They’re native to Drupal 11 — no custom module needed
- ✅ They’re reusable — add them via Layout Builder, blocks, or templates

### Use cases:

- Hero sections
- Accordions
- Tabs
- Modals
- Call-to-action blocks

📁 Located in: `components/`

## ✂️ Framework Partials (FP)

Framework Partials are **tiny UI fragments** you use inside templates or SDCs to avoid repeating the same markup everywhere.

### Examples:

- A reusable `<svg>` icon
- A “New!” ribbon
- A visual divider
- A simple tagline block

These aren’t full components — they’re **helpers**. Think of them like includes or macros that help you keep things DRY.

📁 Located in: `framework-partials/`

## 🧮 Grid System

Groundwork features a comprehensive *12-column Flexbox grid* system, built with semantic, class-based utilities that provide exceptional flexibility and ease of use.

With its highly configurable grid settings, Groundwork offers unlimited layout possibilities. The framework makes it simple to customize websites with specific layout requirements, enabling developers to create virtually any block layout configuration through its robust grid system.

Whether you're building simple layouts or complex responsive designs, Groundwork's grid system adapts to meet your project's unique needs.

### Example:

```html
<div class="grid grid--with-gutter">
  <div class="grid-cell is-4">One third</div>
  <div class="grid-cell is-8">Two thirds</div>
</div>
```

### Features:

- `.grid`, `.grid-cell`, `.grid--with-gutter`
- Width utilities: `.is-6`, `.is-third`, `.is-quarter`, etc.
- Fully responsive
- Works with Layout Builder, SDCs, plain Twig markup, and even in blocks.

📁 Located in: `css/layout/`

## 🧰 Layout Builder

Groundwork is built to work **seamlessly with Layout Builder**.

- Drop in blocks or SDCs
- Apply Block Style Components via the UI
- Use Layout Patterns from Groundwork Helpers (see below)
- No extra configuration — it just works

## ✅ Accessibility & Performance Standards

- ✅ WCAG 2.1 AA compliant by default
- ✅ Supports Norwegian digital accessibility laws
- ✅ Mobile-first, responsive, and semantic HTML
- ✅ Uses CSS custom properties (`var(--token)`) for consistency
- ✅ Fast-loading, minimal CSS/JS footprint

## 🧰 Groundwork Helpers (Optional Module)

This is a **modular companion module** that extends Groundwork’s capabilities with powerful UI tools — great for both devs and editors.

| Feature                     | Description                                   |
| --------------------------- | --------------------------------------------- |
| **Block Styles UI**   | Drag-and-drop block styling with live preview |
| **Gwicons**           | SVG icon picker with sprite management        |
| **Responsive Images** | Automatic `<picture>` tags for perf & a11y  |
| **Layout Patterns**   | Prebuilt layout sections ready for use        |
| **Dev & A11y Tools**  | Debug tools, contrast checker, markup audit   |

📦 Install once, enable only what you need.

## 📚 Documentation: The Groundwork Codex

The **Groundwork Codex** serves as the comprehensive documentation hub for the Groundwork Theme Framework, which is managed directly on GitHub for easy access and version control alongside the project's codebase.

You can access the full documentation site at:

https://IbentaLab.github.io/drupal_groundwork/

The Codex provides detailed guides and references across various aspects of the framework, including:

* **Getting Started:**
  * `/getting-started/` – An introduction to the framework.
  * `/getting-started/installation/` – Step-by-step instructions for setting up Groundwork.
* **Guides:**
  * `/guides/accessibility/` – Information on Groundwork's built-in accessibility features.
  * `/guides/block-style-components/` – Deep dive into Block Style Components (BSCs).
  * `/guides/core-architecture/` – Understanding the foundational structure of Groundwork.
  * `/guides/framework-partials/` – Details on using Framework Partials (FPs).
  * `/guides/grid-system/` – Comprehensive guide to the responsive 12-column Flexbox grid.
  * `/guides/hybrid-style-components/` – Explanation of Hybrid Style Components (HSCs).
  * `/guides/single-directory-components/` – How to leverage Single Directory Components (SDCs).
* **Contributing:**
  * `/contributing/` – Guidelines for contributing to the Groundwork project.
  * `/contributing/code-standards/` – Specific code standards for CSS, JavaScript, PHP, Twig, and YAML.

## 💡 Demo Site

Beyond the documentation, a live demo site showcases Groundwork's visual components and layout patterns in action. **This demo site is built using Groundwork itself, demonstrating its capabilities in a real-world application.** This allows you to see how various elements and structures render, providing a practical demonstration of the framework's flexibility and design capabilities.

Explore the demo site at:

https://www.ibenta.no/projects/groundwork

The demo site features:

* `/demos/homepage/` – An example of a homepage built with Groundwork.
* `/demos/landing-page/` – A demonstration of a landing page.
* `/demos/components/` – Live previews of individual components in various contexts.

For a more extensive demonstration of Groundwork's capabilities, we invite you to explore the entire Ibenta.no website, which is also powered by this framework.

## 🧠 Why Groundwork Wins

- ✨ **Faster theming, fewer bugs**
- 🧼 **Clean, modular architecture** (BSC, HSC, SDC, FP)
- ⚡ **No builds, no dependencies**
- 🌍 **Accessibility built-in**
- 🧩 **Truly block-based Drupal theming** — without compromise

<br>
