# Font Weight and Style Utilities

Groundwork provides a robust set of utilities for adjusting text weight and style — from ultra-thin to black, or italic to normal. These classes can be applied through the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module) — or used atomically in any element.

## Overview

| Class              | Description                      |
| ------------------ | -------------------------------- |
| `.font-thin`     | Ultra-thin font weight (100)     |
| `.font-light`    | Light font weight (300)          |
| `.font-normal`   | Regular font weight (400)        |
| `.font-medium`   | Medium font weight (500)         |
| `.font-semibold` | Semi-bold font weight (600)      |
| `.font-bold`     | Bold font weight (700)           |
| `.font-black`    | Heavyest font weight (900)       |
| `.italic`        | Applies italic styling           |
| `.not-italic`    | Reverts italic styling to normal |

---

## Example

```html
<p class="font-light italic">
  This is a light and italic paragraph.
</p>
```

---

## Design Notes

* Groundwork's weight scale follows common typographic conventions
* Useful for headings, emphasis, UI labels, or semantic text contrast
* These styles map directly to CSS `font-weight` and `font-style` properties

---

## Accessibility Notes

* Use bold and italic for semantic emphasis, not just visual flair
* Consider screen reader compatibility (e.g., `em`, `strong`) if styling semantic content

---

## Summary

Font weight and style utilities give you quick control over typographic emphasis. Use them via the **Groundwork Block Styles** module or directly in your markup to:

* Control visual hierarchy
* Improve scannability and contrast
* Enhance clarity and expressiveness in UI copy
