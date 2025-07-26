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
# Theme Utility: Gray

Groundwork provides a default utility pack for the gray token, defined in `theme-utility-gray.css`. This file extends the `--gray` token from `tokens.css` into a set of utility classes for text, backgrounds, borders, and hover states.

These utilities are useful for building accessible UIs, creating muted interface elements, and enabling quick styling in markup or block configuration.

---

## 🎨 Gray Token Source

All utility classes are based on:

```css
--gray: hsl(0 0% 50%); /* #808080 */
```

Shades are derived using `hsl(from var(--gray) ...)` syntax to ensure consistency and maintainability.

---

## 📦 Class Naming Convention

```css
.gray                  /* Default gray background */
.gray--light1          /* Lighter */
.gray--light2          /* Lighter still */
.gray--light3          /* Very light */
.gray--dark1           /* Slightly darker */
.gray--dark2           /* Darker */
.gray--dark3           /* Even darker */

.gray-text             /* Text color */
.gray-hover-text       /* Text color on hover */
.gray-border           /* Border color */
.gray-hover-border     /* Border color on hover */
```

---

## ✅ Use Cases

* Muted headings, subtitles, captions, and timestamps
* Low-emphasis backgrounds or dividers
* Color-based layout or UI differentiation
* Reusable styling through Block Styles UI or atomic classes

---

## 📐 Best Practices

* Use `.gray-*` utilities in markup, templates, or site-builder tools
* Use token references like `--gray` or `--color-text` in stylesheets for `core/` and `patterns/`
* Don’t override `theme-utility-gray.css` directly — extend it via class composition or variables

---

Next up: [Optional Utility Packs](theme-utility-packs.md) →

```

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

Next up: [Theme Utility: Gray](https://chatgpt.com/g/g-p-6847e31f43d08191a965bb28943bccc9-groundwork/c/theme-utility-gray.md) →
