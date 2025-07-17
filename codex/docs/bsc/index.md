# 🎨 Block Style Components (BSC)

**Block Style Components (BSCs)** are reusable CSS classes that allow you to style blocks in a flexible, no-code-friendly way — right from the Drupal admin UI.

They are designed to work seamlessly with the Groundwork theme and Drupal’s block system, giving site builders and developers powerful design control without needing to touch templates.

---

## 💡 Key Features

* ⚡ Apply via the **Block Style field** (using the Groundwork Block Styles module)
* 🎯 Scoped to `.block-style-target` to avoid affecting outer wrappers
* 🧱 Fully composable — combine multiple BSCs like `.card`, `.blue`, `.shadow`
* ♿ Designed to meet accessibility and responsive best practices

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

---

## 📚 Available BSCs

* [`.card`](card.md)
* [`.alert--info`](alert--info.md)
* [`.ribbon`](ribbon.md)
* *(add more as they are created)*

---

## ✍️ Adding New BSCs

To create a new Block Style Component:

1. Add its CSS rule to the theme (typically in `/css/components/` or `/css/theme/`)
2. Scope it to `.block-style-target` using a safe pattern:

```css
.blue:not(.block),
.blue.block .block-style-target {
  background-color: #067cc6;
  color: #fff;
}
```

3. Register it in the Block Styles module (optional)

---

> BSCs give Groundwork the flexibility of a design system — without requiring a component framework or build tools.
