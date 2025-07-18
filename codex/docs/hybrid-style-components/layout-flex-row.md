# layout-flex-row

A **Hybrid Block Component (HBC)** that applies a horizontal flex layout to a block, enabling side-by-side alignment of its inner content with consistent spacing.

---

## 📌 Usage

Apply via the **Groundwork Block Styles UI**, or manually by adding:

```html
<div class="block layout-flex-row">
  <div class="block-style-target">
    <!-- child elements -->
  </div>
</div>
```

---

## 💡 What It Does

| Target              | Effect                                  |
|---------------------|------------------------------------------|
| `.block`            | `display: flex`, `flex-direction: row`   |
| `.block-style-target` | `width: 100%`, `display: contents`    |

- Aligns children in a horizontal row
- Adds `gap` spacing between them
- Ensures full width on both parent and content area

---

## ⚠️ Warnings

- ❌ **Do not combine with grid width classes** like `.is-6--s`, `.is-quarter`, etc.
- ❌ **Do not use with `.grid--equal`** — it conflicts with flex alignment.
- ❌ Not compatible with `.grid-cell` layouts using `.is-*`
- ✅ Best used on **full-width blocks** or in standalone regions

---

## ✅ Ideal For

- Image + text side-by-side
- CTA button groups
- Icon + description blocks
- Nested horizontal cards

---

## 📁 File Location

```text
css/hybrid-style-components/layout-flex-row.css
```

---

## 🏷 Related

- [`grid-widths`](../block-style-components/grid-widths.md)
- [`grid`](../layout/grid.md)
