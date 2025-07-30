# CSS Grid Utilities

Groundwork’s `css-grid.css` provides a powerful set of utility classes for building **flexible, responsive, column-based layouts** using the CSS Grid layout model.

Grid is ideal when you need to:

* Create layouts with multiple columns or rows
* Control how space is distributed across a layout
* Align and position items in two dimensions (horizontal and vertical)

In Groundwork, Grid utilities apply to the block’s **content container** (`.field--name-body`) when used via the **Groundwork Block Styles UI** — but you can also use them **atomically** in your own markup.

---

## ✅ What Is CSS Grid?

CSS Grid is a two-dimensional layout system designed to let you place content into rows and columns with precision.

It gives you control over spacing, alignment, and layout logic — even when elements wrap or resize responsively.

Use Grid when Flexbox isn't enough, especially when:

* You need a layout with **both rows and columns**
* Content must align across multiple rows
* You want predictable spacing and auto-resizing

---

## 🧱 Grid Terminology & Concepts

Grid works by turning a container into a "grid" and placing child items into defined columns and rows.

| Term                      | Meaning                                                       |
| ------------------------- | ------------------------------------------------------------- |
| `grid-template-columns` | Defines how many columns the grid has and how wide they are   |
| `grid-template-rows`    | Defines rows (optional unless needed)                         |
| `grid-auto-flow`        | Controls whether items fill by row or column                  |
| `justify-content`       | Aligns content**horizontally**inside the grid container |
| `align-items`           | Aligns items**vertically**inside their grid areas       |

---

## 🧱 Utility Class Overview

These utilities are available via the **Block Styles UI** or directly in your markup:

| Class                 | Description                                        |
| --------------------- | -------------------------------------------------- |
| `.d-grid`           | Enables grid layout on the block content container |
| `.d-grid-cols-[n]`  | Creates equal-width columns (2, 3, 4, 6, 12)       |
| `.d-grid-rows-[n]`  | Creates equal-height rows (2, 3, 4)                |
| `.d-grid-flow-row`  | Fills items by row (default)                       |
| `.d-grid-flow-col`  | Fills items by column                              |
| `.d-grid-justify-*` | Aligns grid content horizontally                   |
| `.d-grid-align-*`   | Aligns grid items vertically                       |

---

## 💡 When to Use CSS Grid

Use CSS Grid when:

* You want **equal-width columns** that wrap automatically
* You need **multi-row layouts** with alignment across rows
* You want to build responsive card grids, pricing tables, or dashboard layouts

If you only need a one-direction layout (row **or** column), Flexbox might be simpler. For two-dimensional layout logic, use Grid.

---

## 💻 Usage Example

Here’s a simple 3-column layout:

```html
<div class="d-grid d-grid-cols-3 d-grid-gap-4">
  <div class="item">Item 1</div>
  <div class="item">Item 2</div>
  <div class="item">Item 3</div>
</div>
```

And a more advanced example with alignment:

```html
<div class="d-grid d-grid-cols-4 d-grid-align-center d-grid-justify-between">
  <div class="card">Card A</div>
  <div class="card">Card B</div>
  <div class="card">Card C</div>
  <div class="card">Card D</div>
</div>
```

---

## 🔒 Accessibility & Best Practices

* Grid-based layouts should still use semantic HTML (e.g. `<section>`, `<article>`, `<ul>`) where appropriate.
* Always check how grid behaves at different screen sizes and directions (LTR/RTL).
* Avoid using grid purely for visual positioning of unrelated content — preserve meaning and hierarchy.

---

## 📦 Related Utilities

* [Flexbox Utilities](https://chatgpt.com/c/flexbox.md) — For simpler one-dimensional layouts
* [Gap Utilities](https://chatgpt.com/c/gap.md) — Add spacing between grid or flex items

---

## 🎓 Want to Learn More?

* [CSS Tricks: A Complete Guide to Grid](https://css-tricks.com/snippets/css/complete-guide-grid/)
* [MDN Grid Reference](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_grid_layout)

---

Groundwork’s CSS Grid utilities let you build advanced layouts quickly and accessibly — all without touching custom CSS.
