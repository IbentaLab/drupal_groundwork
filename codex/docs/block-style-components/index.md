# Block Style Components (BSC)

Block Style Components are reusable, **pure-CSS utility classes** that apply specific visual styles to blocks in Drupal. These classes are compatible with Groundwork’s Block Styles UI and scoped to affect only the `.block` and `.block-style-target` elements.

BSCs are ideal for:
- Padding, margin, border, background, text styles
- Rapid visual changes without custom components
- Composable utility-first styling

---

## 📁 Location

```text
css/block-style-components/
```

---

## 💡 Key Features

- Fully compatible with Block Styles UI
- Modular, composable, and predictable
- No layout behavior — pure visual changes
- Fully composable — Safe to combine with other BSCs

---

## 🧹 Usage Example

To style a block as a blue card with padding and shadow:

```html
<div class="block card blue shadow">
  <div class="block-style-target">
    <h3>Title</h3>
    <p>Content</p>
  </div>
</div>
```

Apply classes manually or via the **Groundwork Block Styles UI module**.

---

## ✅ Available BSCs

| Component           | Description                  |
|---------------------|------------------------------|
| `padding.css`       | Utility padding classes       |
| `margin.css`        | Utility margin classes        |
| `text.css`          | Text sizes, fonts, and alignment |
| `border.css`        | Border sides and none         |
| `shadow.css`        | Shadow depth utilities        |
| `rounded.css`       | Border-radius utilities       |
| `hover.css`         | Hover styles for effects      |
