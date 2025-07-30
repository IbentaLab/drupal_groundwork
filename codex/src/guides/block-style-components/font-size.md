# Font Size Utilities

Groundwork provides a modular, scalable typography system for managing font sizes. These utilities can be applied through the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module) — or used atomically in your markup.

## Overview

| Class          | Description                              |
| -------------- | ---------------------------------------- |
| `.text-xs`   | Extra small text (`var(--ms-xs)`)      |
| `.text-sm`   | Small text (`var(--ms-sm)`)            |
| `.text-md`   | Medium / base text (`var(--ms-md)`)    |
| `.text-lg`   | Large text (`var(--ms-lg)`)            |
| `.text-xl`   | Extra-large text (`var(--ms-xl)`)      |
| `.text-xxl`  | 2x extra-large text (`var(--ms-xxl)`)  |
| `.text-xxxl` | 3x extra-large text (`var(--ms-xxxl)`) |

---

## Example

```html
<h2 class="text-xl">Section Heading</h2>
<p class="text-md">This is body text using the medium size.</p>
```

---

## Design Notes

* Sizes follow a modular scale for visual harmony
* Values use CSS variables like `--ms-sm`, `--ms-lg`, etc.
* Defaults are designed for accessibility and responsiveness

---

## Accessibility Notes

* Sizes support readability and clear hierarchy
* Larger text enhances scannability and inclusive design
* Text scale can be customized via design tokens if needed

---

## Summary

Font size utilities provide a flexible, consistent typographic system for Groundwork. Apply them via the **Groundwork Block Styles** module or directly in your HTML to:

* Define clear typographic hierarchy
* Maintain visual rhythm across content
* Adapt to different display contexts with ease
