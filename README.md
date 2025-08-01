<br>

<div align="center">
  <table>
    <tr>
      <td align="center" bgcolor="#dc3545">
        <h1>⚠️ NOT PRODUCTION READY ⚠️</h1>
        <h3>This repository is under heavy development</h3>
        <p>Features may be incomplete, theme structure may change without notice, and breaking changes are expected.</p>
      </td>
    </tr>
  </table>
</div>

<br>

## 🚀 What Is Groundwork Theme Framework?

**The fast, accessible, atomic foundation for block-based Drupal.**

<br>

<div align="center">
<img src="images/drupal-11+--blue.svg" alt="Drupal 11+" height="24">
<img src="images/no-build-tools-100-percent-vanilla--brightgreen.svg" alt="No Build Tools" height="24">
<img src="images/accessibility-wcag_2.1_aa _norwegian-law--blueviolet.svg" alt="WCAG 2.1 AA & Norwegian Law" height="24">
<img src="images/performance-first-informational.svg" alt="Performance First" height="24">
</div>

**Groundwork Theme Framework** is a next-generation frontend framework built specifically for  **Drupal** . Engineered for ⚡ speed, ♿ accessibility, and 💡 developer joy, it empowers developers, designers, and site builders to build modern, flexible websites using pure Drupal features and vanilla web technologies— **no build tools required** .

<br>

> Built with Blocks, Layout Builder, Single Directory Components (SDCs), and vanilla Twig, CSS, and JavaScript. No SCSS, no Webpack, no Node dependencies.

#### The Groundwork has been laid. Now, let's build something great.

## 🎯 Why Groundwork?

* ♿ **Accessibility-first** – Built to meet WCAG 2.1 AA and Norwegian digital accessibility laws
* ⚡ **Performance-first** – Every line of code is designed for speed and efficiency
* 🧱 **Structure-first** – Logical, maintainable architecture with consistent file and CSS structure
* 🧰 **No-code-friendly** – Editors and content creators can style pages without touching code
* 🎨 **Utility-first** – Use composable, reusable CSS classes across any part of the site
* 🚫 **Build-free** – No compiling, no build step — just native Drupal and vanilla tech

Groundwork isn't just a theme you install and forget—it's a frontend **philosophy** that helps your entire team build better, faster, and more accessibly.

## 🚀 Quick Start

#### **This next-generation Groundwork, compatible with Drupal 11+, will be officially released on drupal.org *upon reaching stable status*.**

```
composer require drupal/groundwork

```

Or download from [drupal.org/project/groundwork](https://www.drupal.org/project/groundwork "null").

```
drush theme:enable groundwork
drush config-set system.theme default groundwork

```

1. **Compose pages using either:**
   * **Layout Builder** for visual, drag-and-drop page building, **or**
   * **Drupal's core Block UI** for familiar block placement.
2. **Apply Block Style Components (BSC)** to blocks using the **Block Styles UI** (from the Groundwork Helpers module) to control layout, spacing, colors, and more.
3. **Build with Single Directory Components (SDC)** for modular, reusable custom elements like accordions or modals.

<br>

# 🧱 Core Architecture

Groundwork is built around a powerful, layered frontend architecture:

| **Type**                              | **Folder**                | **Purpose**                                                              |
| ------------------------------------------- | ------------------------------- | ------------------------------------------------------------------------------ |
| **Page Layout Grid**                  | `css/layout/`                 | The primary Flexbox grid for arranging**blocks**in **regions** .   |
| **BSC**– Block Style Components      | `css/block-style-components/` | A comprehensive library of utility classes for styling blocks and content.     |
| **SDC**– Single Directory Components | `components/`                 | Fully reusable, self-contained UI components with their own Twig, CSS, and JS. |
| **FP**– Framework Partials           | `css/partials/`               | Small, reusable UI fragments (like buttons) used across templates.             |

## 🧮 The Dual Grid System

Groundwork features two distinct grid systems, each designed for a specific purpose.

### 1. Page Layout Grid (Flexbox)

This is the foundational 12-column Flexbox grid that controls the main structure of your site. It is designed to arrange **blocks** (`.grid-cell`) within your theme's **regions** (`.grid`).

**Use this grid for:**

* Creating complex, multi-block layouts inside a single region.
* Defining the width of blocks in a region.
* Reordering blocks visually.

**Example:**

```
<!-- A region is automatically a .grid container -->
<div class="region grid">
  <!-- This block takes up 2/3 of the width -->
  <div class="block grid-cell is-8"> ... </div>
  <!-- This block takes up 1/3 of the width -->
  <div class="block grid-cell is-4"> ... </div>
</div>

```

📁 Located in: `css/layout/`

### 2. Content Layout Grid (CSS Grid)

This is an optional but powerful **CSS Grid** system that you can apply to any block to arrange the  **content inside it** .

**Use this grid for:**

* Creating a multi-column list of features inside a single block.
* Building complex, card-like layouts with images and text.
* Aligning items in a two-dimensional grid.

**Example:**

```
<!-- A single block with the .d-grid BSC applied -->
<div class="block grid-cell d-grid d-grid-cols-3 gap-4">
  <div class="block-style-target">
    <!-- The content inside is now arranged on a 3-column grid -->
    <div>Item 1</div>
    <div>Item 2</div>
    <div class="col-span-2">Item 3 (spans 2 columns)</div>
  </div>
</div>

```

📁 Located in: `css/block-style-components/d-grid.css`

## 🎨 Block Style Components (BSC)

BSCs are dual-purpose utility classes for styling blocks and content. They are the primary tool for customizing the look and feel of your site without writing custom CSS.

### What can you do with BSCs?

* **Layout:** Create complex internal layouts with Flexbox (`.d-flex`) or CSS Grid (`.d-grid`).
* **Spacing:** Control internal and external space with a full suite of `padding`, `margin`, and `gap` utilities.
* **Appearance:** Apply pre-styled components like `.card` and `.alert`, or compose your own with `.border`, `.rounded`, and `.shadow`.
* **Typography:** Control every aspect of text with a comprehensive `typography.css` file.
* **Interactivity:** Add polished user feedback with `.hover-*`, `.cursor-*`, and `.transition-all`.

### How are they used?

* 💻 Developers can apply them anywhere.
* 🧑‍🎨 Editors can apply them visually to blocks using the  **Block Styles UI** .
* 🎯 You can stack them freely — e.g. `.card .p-4 .shadow-lg .hover-raise .transition-all`

📁 Located in: `css/block-style-components/`

## 🧩 Single Directory Components (SDC)

SDCs are a Drupal core feature for creating  **self-contained, reusable components** . Each SDC has its own Twig, CSS, JS, and metadata.

### Use SDCs for:

* Accordions, Tabs, and Modals
* Complex hero sections with multiple fields
* Sliders or Carousels
* Any component with its own unique structure and behavior.

📁 Located in: `components/`

## ✂️ Framework Partials (FP)

Framework Partials are **tiny UI fragments** you use inside templates or SDCs to avoid repeating the same markup everywhere.

### Examples:

* A reusable `<svg>` icon
* A “New!” ribbon
* A visual divider

These aren’t full components — they’re  **helpers** .

📁 Located in: `framework-partials/`

## 🧰 Groundwork Helpers (Optional Module)

This is a **modular companion module** that extends Groundwork’s capabilities with powerful UI tools.

| **Feature**         | **Description**                                                       |
| ------------------------- | --------------------------------------------------------------------------- |
| **Block Styles UI** | An interactive design tool for applying BSCs to blocks with a live preview. |
| **Gwicons**         | An SVG icon picker and management system.                                   |
| **Layout Patterns** | Pre-built layout sections ready for use in Layout Builder.                  |

📦 Install once, enable only what you need.

## 📚 Documentation: The Groundwork Codex

The **Groundwork Codex** is the comprehensive documentation hub for the framework.

[https://IbentaLab.github.io/drupal_groundwork/](https://ibentalab.github.io/drupal_groundwork/ "null")

## 💡 Demo Site

A live demo site showcases Groundwork's visual components and layout patterns in action. **This demo site is built using Groundwork itself, demonstrating its capabilities in a real-world application.**

[https://www.ibenta.no/projects/groundwork](https://www.ibenta.no/projects/groundwork "null")

## 🧠 Why Groundwork Wins

* ✨ **Faster theming, fewer bugs**
* 🧼 **Clean, modular architecture** (BSC, HSC, SDC, FP)
* ⚡ **No builds, no dependencies**
* 🌍 **Accessibility built-in**
* 🧩 **Truly block-based Drupal theming** — without compromise

<br>
