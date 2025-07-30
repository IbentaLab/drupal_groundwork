# Font Family Utilities

Groundwork provides font family utilities to quickly switch between common typeface categories. These utilities can be applied through the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module) — or used atomically.

## Overview

| Class           | Description                       |
| --------------- | --------------------------------- |
| `.font-sans`  | Applies the sans-serif font stack |
| `.font-serif` | Applies the serif font stack      |
| `.font-mono`  | Applies the monospace font stack  |

---

## Example

```html
<div class="font-serif">
  This text uses a serif font.
</div>
```

---

## Design Notes

* Font stacks are defined using CSS variables like `--font-family-sans`, `--font-family-serif`, etc.
* Defaults fallback to system-friendly fonts (e.g., Ubuntu, Segoe UI, Georgia)
* Useful for quick prototyping or ensuring typographic consistency

---

## Accessibility Notes

* These utilities help align font choice with content purpose
* Monospace is useful for code or structured content
* Serif and sans-serif distinctions support readability for different audiences

---

## Summary

Font family utilities let you:

* Swap typography categories without writing custom CSS
* Ensure fallback safety and readable defaults
* Use via the **Groundwork Block Styles** module or atomically in markup
