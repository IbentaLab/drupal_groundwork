# Theme Utility: Blue

Groundwork ships with a default utility pack for the blue token, defined in `theme-utility-blue.css`. This file extends the `--blue` token from `tokens.css` into a full set of utility classes that can be used in markup, templates, or the Block Styles UI.

These classes are ideal for editors, site builders, or developers who want to apply consistent visual styles without writing custom CSS.

---

## 🎨 Blue Token Source

All classes in this file are based on:

```css
--blue: hsl(202 94% 40%); /* #067cc6 */
```

Variants are generated using `hsl(from var(--blue) ...)` syntax to create lighter and darker shades programmatically.

---

## 📦 Class Naming Convention

```css
.blue                 /* Default blue background */
.blue--light1         /* Slightly lighter background */
.blue--light2         /* Lighter */
.blue--light3         /* Even lighter */
.blue--dark1          /* Slightly darker */
.blue--dark2          /* Darker */
.blue--dark3          /* Even darker */

.blue-text            /* Text color */
.blue-hover-text      /* Text color on hover */
.blue-border          /* Border color */
.blue-hover-border    /* Border color on hover */
```

These are available as atomic classes and can be used directly in templates, WYSIWYG editors, or custom block templates.

---

## ✅ Use Cases

* Styling hero sections, call-to-actions, or blocks with brand accent color
* Building Block Style Components for visual variants
* Adding hover or focus states using prebuilt tokens

---

## 📐 Best Practices

* Use `.blue-*` utilities in markup or when building UI controls (like the Block Styles UI)
* For CSS stylesheets in `core/` and `patterns/`, prefer `--color-primary` or `--blue` tokens
* Avoid mixing semantic and utility tokens within the same CSS rule

---

Next up: [Theme Utility: Gray](theme-utility-gray.md) →
