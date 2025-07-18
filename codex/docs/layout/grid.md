# Grid System

Groundwork’s grid system provides a flexible 12-column layout that enables responsive block placement and consistent spacing across breakpoints. It is mobile-first and compatible with both utility-based styling and Layout Builder.

---

## 🧱 Core Concepts

### `.grid`
A flexbox container that wraps any number of `.grid-cell` children.

```html
<div class="grid">
  <div class="grid-cell">A</div>
  <div class="grid-cell">B</div>
</div>
```

---

### `.grid-cell`
A class added to all blocks via the Groundwork theme. This enables grid behaviors to work universally, including responsive widths, gutters, and alignment modifiers.

> ⚠️ While `.grid-cell` is safe to keep, avoid combining it with Hybrid Style Components that alter layout (like `layout-flex-row`).

---

## 📐 Gutter Variants

### `.grid--with-gutter`
Applies inner padding to `.grid-cell` and negative outer margin to the grid container, simulating a gutter-based layout.

```html
<div class="grid grid--with-gutter">
  <div class="grid-cell">Block</div>
  <div class="grid-cell">Block</div>
</div>
```

### `.grid--gap`
Applies `gap` using native CSS — simpler and less hacky but requires modern browser support.

---

## 🎛 Modifiers

| Class              | Description                               |
|-------------------|-------------------------------------------|
| `.grid--centered` | Center-align cells horizontally           |
| `.grid--between`  | Distribute cells with space-between        |
| `.grid--middle`   | Vertically center-align all cells         |
| `.grid--stretch`  | Stretch children to fill full height      |
| `.grid--reverse`  | Reverses the horizontal order             |
| `.grid--stacked`  | Stacks cells vertically                   |
| `.grid--equal`    | Forces equal height on all grid cells     |

---

## ⚠️ Compatibility Notes

### ❌ Do Not Use With:
- `.is-*` width classes + HSCs like `layout-flex-row` on the same block
- `.grid--equal` in combination with HSCs (they may override each other’s vertical alignment)

### ✅ Safe To Combine:
- `.grid`, `.grid--gap`, `.grid--with-gutter` — on containers only
- `.grid-cell` — always safe (by default on all blocks)

---

## 🗂 Related

- [`grid-widths`](../block-style-components/grid-widths.md)
- [`layout-flex-row`](../hybrid-style-components/layout-flex-row.md)
