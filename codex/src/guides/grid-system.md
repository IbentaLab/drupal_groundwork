# Groundwork Grid Layout System

> **Version:** Groundwork 3.0 (BSC-based, mobile-first, modern CSS)

## Overview

Groundwork’s Grid Layout system is a **Block Style Component (BSC)** that enables responsive, 12-column, flexbox-based layouts. It is designed to be:

* 🔁  **Dual-purpose** : works as an **atomic utility** *and* a **region-block layout system**
* 💡 Highly intuitive: readable, reusable class names like `.is-4`, `.grid--centered`
* 🧱 Configurable: tweak gutters, breakpoints, and more via tokens
* 🪶 Lightweight: no dependencies, no JavaScript
* 🌍 Fully responsive: mobile-first design with breakpoint modifiers

> ✅ All regions are `.grid`. All blocks are `.grid-cell`. You are always in control.

---

## 🔁 Dual Purpose: Atomic + Layout Component

The Groundwork grid system isn’t just a utility—it’s also a layout powerhouse.

* **Atomic** : Use `.grid`, `.grid-cell`, `.is-*`, `.grid--*` in markup directly.
* **Block Layout** : Every region is a `.grid`, every block a `.grid-cell`. Perfect harmony.

```html
<!-- Footer with 3 equal blocks -->
<div class="region-footer grid">
  <div class="block grid-cell is-4">Block 1</div>
  <div class="block grid-cell is-4">Block 2</div>
  <div class="block grid-cell is-4">Block 3</div>
</div>
```

This dual nature is why the Groundwork Grid is not “just another grid.” It’s a layout language for your content.

---

## Base Architecture

### Grid Container Classes

* `.grid`: Basic flex wrapper
* `.grid--with-gutter`: Adds internal padding to columns using `--grid-gutter`

```css
.grid,
.grid--with-gutter {
  display: flex;
  flex-direction: row;
  flex-wrap: wrap;
}

.grid--with-gutter > .grid-cell {
  padding: var(--grid-gutter);
}
```

---

### Grid Cell Class

All blocks use `.grid-cell`, and every region uses `.grid`. This structure allows BSCs to style individual cells and grids independently.

```css
.grid > .grid-cell,
.grid--with-gutter > .grid-cell {
  flex: 0 0 100%;
}

.grid > .grid-cell.col-auto,
.grid--with-gutter > .grid-cell.col-auto {
  flex-basis: auto;
}
```

---

## Responsive Columns

The grid supports 12-column layouts across three breakpoints:

* **Small** (`--s`): `max-width: var(--breakpoint-small-screen)`
* **Medium** (default): `min-width: var(--breakpoint-medium-screen)`
* **Large** (`--l`): `min-width: var(--breakpoint-large-screen)`

### Example

```html
<!-- 50% width on mobile, 33.33% on desktop -->
<div class="grid">
  <div class="grid-cell is-6--s is-4">Column</div>
</div>
```

### Column Width Class List

* `is-1--s` to `is-12--s`
* `is-1` to `is-12`
* `is-1--l` to `is-12--l`
* `col-auto`

Each maps to its corresponding `flex-basis` percentage (e.g., `is-6` = 50%).

---

## 🍱 Common Layout Recipes

| Use Case                        | Classes                          |
| ------------------------------- | -------------------------------- |
| 2 equal columns                 | `.is-6`                        |
| 3 equal columns                 | `.is-4`                        |
| 4 equal columns                 | `.is-3`                        |
| 2 col (mobile), 3 col (desktop) | `.is-6--s is-4--l`             |
| Sidebar + Main Content          | `.is-4`,`.is-8`              |
| Equal height columns            | Add `.grid--equal`to `.grid` |

---

## Layout Modifiers

These affect how the grid container behaves:

```css
.grid--centered    { justify-content: center; }
.grid--between     { justify-content: space-between; }
.grid--middle      { align-items: center; }
.grid--stretch     { align-items: stretch; }
.grid--reverse     { flex-direction: row-reverse; }
.grid--stacked     { flex-direction: column; }
.grid--gap         { gap: var(--grid-gutter); }
.grid--equal .grid-cell { align-self: stretch; }
```

### Usage

```html
<div class="grid grid--centered grid--gap">
  <div class="grid-cell is-6">Half</div>
  <div class="grid-cell is-6">Half</div>
</div>
```

---

## 🧪 Advanced (Experimental CSS Features)

We support parent-based targeting using `:has()` to apply styles to the grid based on the presence of certain children:

```css
:root var(--groundwork-signature-scope) .grid:has(> .grid-cell.grid--centered) {
  justify-content: center;
}
```

> ⚠️ Supported in all modern browsers except IE and Opera Mini.

---

## BSC Best Practices

* Apply `.grid` to **regions** (e.g. `.region-sidebar`) only
* Apply `.grid-cell` to **blocks** (e.g. `.block`) only
* Combine grid with other BSCs freely
* Prefer `.grid--with-gutter` for spacing

---

## Directory Placement

Place this CSS file in:

```
/css/block-style-components/_grid-layout.css
```

---

## Status

✅ Complete and integrated. No dependencies. Fully atomic. Follows Groundwork standards.

---

## 🚧 Coming Enhancements

* RTL compatibility
* Stack/gap combos
* Grid overlays for debugging (opt-in only)

---

## 📸 For Visual Examples

View the Grid section in the Groundwork Codex demo site.

---

## 💬 Why Groundwork Grid Wins

> "The layout options available are endless, which makes Groundwork extremely versatile. Customizing a site layout is now a breeze."

* Configure block widths at will using the Block Styles UI or pure markup
* Every block can be resized individually at any breakpoint
* Create 2, 3, 4+ column layouts in *any* region—footer, sidebar, even main
* Groundwork Grid is not a rigid system—it’s a creative tool.

Let your layout imagination run wild. With Groundwork, it’s not just possible—it’s built in.
