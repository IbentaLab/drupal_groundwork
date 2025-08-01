
# ✅ Groundwork Partial CSS Guidelines

Groundwork partials are **tiny, reusable UI fragments** that act as atomic building blocks for creating consistent and themeable design systems. These guidelines ensure every partial is:

- **Theme-safe:** Works across light and dark modes.
- **Consistent:** Matches the Groundwork design tokens and principles.
- **Flexible:** Adaptable for various use cases.
- **Accessible:** Built with accessibility as a priority.

---

## 1. 🎨 Use Groundwork Tokens

All values must use variables from `groundwork-tokens.css`.
This includes **colors, spacing, font sizes, borders, radii, and shadows.**

```css
/* ✅ Correct */
color: var(--color-text);
font-size: var(--ms-sm);
padding: var(--space-sm) var(--space-md);
```

---

## 2. 🌗 Light/Dark Theme Safety

Ensure all styles adapt seamlessly between **light** and **dark themes**.
Use **tokenized `--color-*` variables** instead of hardcoded values.

```css
/* ✅ Correct */
background-color: var(--color-bg);
color: var(--color-text);

/* 🚫 Avoid */
background-color: #ffffff; /* Hardcoded value */
```

---

## 3. 📏 Must Include Size Variants

Every partial must support the following size variants:

- `--xs`, `--sm`, `--md`, `--lg`, `--xl`, `--xxl`.

These sizes affect **font size**, **padding**, and sometimes **dimensions**.

```css
/* Example: Badge size variants */
.badge--sm {
  font-size: var(--ms-sm);
  padding: var(--space-xs) var(--space-sm);
}

.badge--lg {
  font-size: var(--ms-lg);
  padding: var(--space-md) var(--space-lg);
}
```

---

## 4. 🎨 Must Include Color Variants

Partials must support these **color states**:

- `--primary`, `--secondary`, `--info`, `--notice`, `--success`, `--warning`, `--danger`, `--muted`.

These are used for **borders**, **icons**, or **fills**.

```css
/* Example: Badge color variants */
.badge--primary {
  background-color: var(--color-primary);
  color: var(--color-text-inverse);
}

.badge--success {
  background-color: var(--color-success);
  color: var(--color-text-inverse);
}
```

---

## 5. 🧠 Add Component-Specific Variants

Add variants that are **appropriate** for your partial.
These are optional and tailored to the component’s purpose.

| **Component** | **Possible Variants**                  |
| ------------------- | -------------------------------------------- |
| `form-checkbox`   | `--switch`, `--compact`                  |
| `tags/chips`      | `--dismissable`, `--rounded`, `--pill` |

---

## 6. 💬 Document Supported Variants in the Docblock

Each partial must include a **docblock** that lists all supported variants.
Use emojis to make it clear and organized.

```css
/*
 * Variants supported:
 *  - 🎨 Color: primary, secondary, etc.
 *  - 📏 Size: xs, sm, md, etc.
 *  - ✳️ State: is-invalid, is-disabled
 *  - 🧠 Layout: inline, stacked
 *  - ⬜ Shape: pill, square (if applicable)
 */
```

---

## 7. 🧪 Use `.is-*` Utility States When Needed

Include globally recognized utility states like:

- `.is-invalid` — for error states.
- `.is-disabled` — for disabled interactions.
- Other states that may be commonly applied.

```css
/* Example: Invalid badge */
.badge.is-invalid {
  border-color: var(--color-danger);
  color: var(--color-danger-dark);
}
```

---

## Why These Guidelines Matter

By following these guidelines, Groundwork partials remain:

- **Powerful:** Flexible for different use cases.
- **Consistent:** Aligned with the design system.
- **Themeable:** Usable in both light and dark modes.
- **Accessible:** Built for inclusivity and usability.

Groundwork partials are the foundation for creating UI fragments that are predictable, reusable, and easy to integrate into larger systems.
