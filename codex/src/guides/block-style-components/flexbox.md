
# Flexbox Utilities

Groundwork’s `flexbox.css` provides a set of utility classes for creating flexible, responsive layouts using the **CSS Flexbox** model.

Flexbox helps you **align, distribute, and reorder items** inside a container — all without writing custom CSS. It's perfect for common layout tasks like:

* Stacking elements vertically
* Aligning content side-by-side
* Centering things in both directions

In Groundwork, Flexbox utilities apply to the block’s **content container** (`.field--name-body`) when used via the **Groundwork Block Styles UI** — but you can also use them **atomically** in your own markup.

---

## ✅ What Is Flexbox?

Flexbox (short for  *Flexible Box Layout* ) is a CSS layout system designed to make it easier to:

* Lay out items in **rows or columns**
* **Control spacing** between items
* **Align** items along horizontal or vertical axes
* Handle **responsive behavior** automatically

Groundwork makes Flexbox beginner-friendly with clear utility classes you can apply through the Block Styles UI or directly in your HTML.

---

## 🧱 Understanding Flexbox Axes

Flexbox works on two axes:

* The **main axis** — defined by the direction you choose (`row` or `column`)
* The **cross axis** — perpendicular to the main axis

| `flex-direction` | Main Axis     | Cross Axis    |
| ------------------ | ------------- | ------------- |
| `row`(default)   | left → right | top ↕ bottom |
| `column`         | top ↓ bottom | left ↔ right |

This is important because:

* `justify-content` aligns items on the **main axis**
* `align-items` aligns items on the **cross axis**

---

## 🧱 Utility Class Overview

You can apply these classes via the  **Block Styles UI** , or directly in your HTML with atomic classes:

| Class                       | Description                                                                    |
| --------------------------- | ------------------------------------------------------------------------------ |
| `.d-flex`                 | Turns the block content into a Flexbox container                               |
| `.d-flex-row`             | Aligns items horizontally (default direction)                                  |
| `.d-flex-col`             | Aligns items vertically (great for stacking content)                           |
| `.d-flex-items-start`     | Aligns items to the top or left (cross-axis)                                   |
| `.d-flex-items-center`    | Aligns items in the center vertically or horizontally (depending on direction) |
| `.d-flex-items-end`       | Aligns items to the bottom or right (cross-axis)                               |
| `.d-flex-justify-start`   | Pushes items to the start of the container (main axis)                         |
| `.d-flex-justify-center`  | Centers items along the main axis                                              |
| `.d-flex-justify-end`     | Pushes items to the end of the container (main axis)                           |
| `.d-flex-justify-between` | Distributes items with space between them                                      |
| `.d-flex-wrap`            | Allows items to wrap to multiple lines if there’s not enough space            |
| `.d-flex-nowrap`          | Prevents wrapping (default behavior in most browsers)                          |

---

## 💡 When to Use Flexbox

Use Flexbox when you want to:

* Stack things vertically or horizontally with ease
* Build  **centered hero sections** ,  **icon+text layouts** , or **button groups**
* Control layout without writing custom CSS
* Quickly respond to different screen sizes

For layout patterns with **rows and columns** of content, see the [Grid Utilities](css-grid.md) instead.

---

## 💻 Usage Example

Here’s how to vertically stack and center content inside a block:

```html
<div class="block d-flex d-flex-col d-flex-items-center d-flex-justify-center">
  <h2 class="title">Welcome</h2>
  <p class="subtitle">We're glad you're here</p>
</div>
```

And here’s a horizontal layout with space between items:

```html
<div class="block d-flex d-flex-row d-flex-justify-between d-flex-items-center">
  <span class="label">Name:</span>
  <input type="text" class="input" />
</div>
```

---

## 🔒 Accessibility & Best Practices

* All Groundwork utilities work **without build tools** and use clean, readable class names.
* Layouts adapt based on writing direction (LTR/RTL) and follow **WCAG and ARIA** best practices when used properly.
* Avoid relying solely on alignment for meaning — use semantic HTML and landmarks.

---

## 📦 Related Utilities

* [Gap Utilities](gap.md) — Add spacing between flex or grid items
* [Grid Utilities](css-grid.md) — For column-based layouts

---

## 🎓 Want to Learn More?

* [CSS Tricks: A Complete Guide to Flexbox](https://css-tricks.com/snippets/css/a-guide-to-flexbox/)
* [MDN Flexbox Reference](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_flexible_box_layout/Basic_Concepts_of_Flexbox)

---

With just a few classes, Groundwork's Flexbox utilities help you build clean, responsive layouts — even if you're just getting started.
