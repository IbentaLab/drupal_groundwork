# Groundwork Theme: Layout Architecture

## 1. Core Philosophy

The layout architecture of the Groundwork theme is built on two core principles:

1. **Separation of Concerns:** The system clearly distinguishes between different layers of layout control.
   * **Page Structure:** High-level wrappers that define the main sections of the page.
   * **Macro Layout:** A grid system for positioning blocks *within* page regions.
   * **Micro Layout:** Utilities for controlling the layout of content *inside* individual blocks.
2. **Mobile-First Design:** All layouts are designed for mobile screens by default and then progressively enhanced for larger screens using `md` and `lg` breakpoints.

## 2. Page Structure

The foundational structure is defined in `page.html.twig`.

### The Page Wrapper (`.page-wrapper`)

The entire page is enclosed in a single `<div class="page-wrapper">`. This element uses Flexbox to create a "sticky footer" layout, ensuring the footer stays at the bottom of the viewport on pages with short content.

```
.page-wrapper {
  display: flex;
  flex-direction: column;
  min-height: calc(100vh - var(--drupal-displace-offset-top, 0px));
}

.layout-main {
  flex-grow: 1; /* Allows the main content to expand */
}

```

### Top-Level Layout Regions (`.layout-*`)

The direct children of `.page-wrapper` are the main structural sections of the page. These are the only elements that receive a `.layout-*` class name (e.g., `.layout-header`, `.layout-main`, `.layout-footer`).

* These wrappers are typically full-width, allowing for full-bleed backgrounds or borders.
* The content inside them is then constrained by a `.region.grid` element, which can be set to a maximum width (e.g., `1024px`).

## 3. The Groundwork Grid System (Macro Layout)

This system is defined in `grid.css` and is used for positioning blocks within regions.

* **Container (`.grid`):** Any region is a grid container. It establishes an independent, 12-column grid.
* **Item (`.grid-cell`):** Any block placed in a region is a grid item. By default, it spans the full 12 columns.
* **Utilities:** A comprehensive set of mobile-first utility classes allows for precise control over a block's position and size. The format is `property-value-breakpoint`.
  * **Width:** `.w-1` to `.w-12`
  * **Height:** `.h-1` to `.h-12`
  * **Offsets:** `.w-start-1` to `.w-start-12`
  * **Ordering:** `.order-1` to `.order-12`
* **Responsiveness:** All utilities have responsive variants using `-md` (768px) and `-lg` (1024px) suffixes (e.g., `.w-6-md`, `.order-1-lg`).

## 4. Dynamic Main Content Area

The layout for the main content area and its sidebars is defined in `page.css`. It uses the Groundwork Grid System but with a dynamic approach powered by CSS Custom Properties (Variables).

* The `.main__container` div acts as the 12-column grid container for the content and sidebars.
* **Theme Settings Control:** Sidebar widths are not hardcoded. Instead, they are controlled by CSS variables (`--sf-width-md`, `--sc-width-lg`) which are set via an inline style attribute in `page.html.twig`.
* **Automatic Content Width:** The `.main__content` column uses `calc()` functions to automatically fill the space that is left over between the two sidebars. This creates a flexible and powerful layout that adapts to user configuration.

```
/* Example of the dynamic calculation */
.main__content {
  grid-column: calc(1 + var(--sf-cols, 0)) / calc(13 - var(--sc-cols, 0));
}

```

## 5. Block-Level Layouts (Micro Layout)

Groundwork provides a separate set of utility classes, prefixed with `d-` (for "display"), to control the layout of content *inside* a block.

* **`.d-grid` / `.d-flex`:** These classes can be applied to a block via the "Block Styles" module to turn the block's inner content area into a grid or flexbox container.
* **Purpose:** This creates a clear separation. The `.grid` system positions the block on the page, while the `.d-grid` utilities arrange the elements within that block. This prevents CSS conflicts and makes the system's intent clear.

This two-level system provides maximum flexibility, allowing a site builder to position a block on the page grid and then create a completely independent layout for the content inside it.
