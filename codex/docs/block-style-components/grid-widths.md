# Grid Widths

The Groundwork theme supports a **12-column responsive grid** system. You can assign width-based utility classes to blocks using the **Block Styles UI** or by adding them manually.

These classes work together with `.grid` or `.grid--with-gutter` containers and require the `.grid-cell` class (which is applied automatically).

---

## 📏 How It Works

Each `.grid-cell` block can be sized using these responsive classes:

```text
.is-[1-12]--s   → Small screens (mobile)
.is-[1-12]      → Medium screens (tablet and up)
.is-[1-12]--l   → Large screens (desktop and up)
```

Also available:
```text
.is-half, .is-quarter, .is-third, .is-two-thirds, etc.
```

These control the **flex-basis** of the block inside a flex `.grid` container.

---

## ✍️ Example

```html
<div class="grid grid--with-gutter">
  <div class="block is-6">
    <div class="block-style-target">Left</div>
  </div>
  <div class="block is-6">
    <div class="block-style-target">Right</div>
  </div>
</div>
```

---

## ⚠️ Compatibility Warning

Do **not** use `.is-*` grid width classes on the same block as:

- Hybrid Style Components (HSCs) like `.layout-flex-row`
- Layout-driven classes like `.flex-row`, `.flex-col`, `.grid--equal`

These conflict in layout model (grid cell vs. layout container).

---

## ✅ Best Practices

- Use width classes **only inside** a `.grid` or `.grid--with-gutter` container
- Apply widths to `.block`, not the `.block-style-target`
- Mix freely with BSCs like `.p`, `.text-sm`, `.shadow`, etc.
- For layout-driven blocks, use HSCs instead of `.is-*`

---

## 🗂 Related

- [`grid`](../layout/grid.md)
- [`layout-flex-row`](../hybrid-style-components/layout-flex-row.md)
