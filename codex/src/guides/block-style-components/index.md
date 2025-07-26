# Block Style Components (BSCs)

Welcome to the Block Style Component (BSC) documentation for the Groundwork framework. BSCs are a powerful set of dual-purpose utility classes that allow you to style blocks and content with maximum flexibility.

## Core Concept

BSCs are designed to be  **composable** . This means you can mix and match different classes to create unique and complex designs without writing a single line of custom CSS. The framework contains a mix of dual-purpose BSCs and single-purpose atomic utilities.

* **Dual-Purpose BSCs:** The majority of utilities are dual-purpose. They can be applied directly to any HTML element for a specific style (atomic use) or applied to a Drupal block to style its entire content area (BSC use).
* **Atomic Utilities:** Some classes, like those for grid items (`.col-span-2`) or accessibility (`.sr-only`), are purely atomic and are designed to be used on specific elements inside your content.

## Component Library

Below is a categorized list of all available Block Style Components. Click on any component to view its detailed documentation, class reference, and usage examples.

### Pre-Styled Components

Ready-to-use components that can be applied to any block or element to give it a specific appearance and meaning.

* [**Card Component**](card.md) (`card.css`)
  * A versatile component for grouping content into an elevated container.
* [**Alert Component**](alerts.md) (`alerts.css`)
  * For displaying contextual feedback messages (e.g., success, warning, error).
* [**Blockquote Component**](blockquote.md) (`blockquote.css`)
  * For visually distinguishing quoted text.
* [**Well / Aside Component**](well.md) (`well.css`)
  * For subtly highlighting content in an inset container.

### Layout & Display

A suite of dual-purpose utilities for controlling the layout, positioning, and visibility of blocks or individual elements.

* [**Display Utilities**](display.md) (`display.css`)
  * Control the `display` property. Essential for enabling Flexbox (`.d-flex`) and CSS Grid (`.d-grid`) content layouts.
* [**Content Layout Grid**](d-grid.md) (`d-grid.css`)
  * A powerful CSS Grid system for arranging content *inside* a block or element.
* [**Flexbox Utilities**](flexbox.md) (`flexbox.css`)
  * A complete suite of tools for aligning, justifying, and ordering items within a flex container.
* [**Overflow Utilities**](overflow.md) (`overflow.css`)
  * Manage what happens when content overflows its container.
* [**Sizing Utilities**](sizing.md) (`sizing.css`)
  * Set explicit widths and heights, including viewport-relative sizes and max-width constraints.

### Spacing

A comprehensive suite of dual-purpose utilities for controlling the space inside and around your components, whether applied to a block or an element.

* [**Margin Utilities**](margin.md) (`margin.css`)
  * Control the "external space" around a block or element, including negative margins and auto-centering.
* [**Padding Utilities**](padding.md) (`padding.css`)
  * Control the "internal space" within a block or element.
* [**Gap Utilities**](gap.md) (`gap.css`)
  * The modern way to add space between items in a grid or flex container.

### Borders & Effects

Dual-purpose utilities for styling the edges and surfaces of your components, from entire blocks to individual elements.

* [**Border Utilities**](border.md) (`border.css`)
  * A composable system for adding borders with control over width, style, and color.
* [**Rounded Corner Utilities**](rounded.md) (`rounded.css`)
  * A flexible system for rounding all corners, specific sides, or individual corners.
* [**Shadow & Elevation Utilities**](shadow.md) (`shadow.css`)
  * Apply token-driven box shadows to create depth and lift components off the page.

### Interactivity & Effects

Dual-purpose utilities for providing user feedback and creating dynamic, polished interfaces on blocks or specific elements.

* [**Cursor Utilities**](cursor.md) (`cursor.css`)
  * Change the mouse cursor to indicate interactivity.
* [**Filter Utilities**](filter.md) (`filters.css`)
  * Apply graphical effects like blur, grayscale, and contrast.
* [**Hover Utilities**](hover.md) (`hover.css`)
  * Apply styles that only appear when a user hovers over a block or element.
* [**Transitions**](transitions.md) (`transitions.css`)
  * Control the timing and animation of style changes to create smooth effects.
* [**Transforms**](transforms.md) (`transforms.css`)
  * Apply static 2D transformations like scale and rotate.
* [**User Selection Utilities**](user-select.md) (`user-select.css`)
  * Control whether the text inside a block or element can be highlighted.

### Typography & Content

Utilities for styling text and other content elements like lists and icons. These can be applied atomically to any element or to an entire block to style all of its content.

* [**Typography Utilities**](typography.md) (`typography.css`)
  * The complete system for styling text, including font family, size, weight, alignment, and decoration.
* [**List Style Utilities**](lists.md) (`lists.css`)
  * Control the appearance and position of list markers (bullets and numbers).
* [**SVG Styling Utilities**](svg.md) (`svg.css`)
  * Effortlessly style inline SVG icons with dynamic or static colors.
