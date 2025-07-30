
# Hover Effects Utilities

Groundwork includes a flexible set of hover utilities for adding interactive visual effects. These classes can be applied via the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module), or used atomically in any element.

## Overview

| Class               | Description                                        |
| ------------------- | -------------------------------------------------- |
| `.hover-shadow`   | Applies a soft shadow on hover                     |
| `.hover-opacity`  | Reduces opacity to 80% on hover                    |
| `.hover-raise`    | Lifts the block slightly upward on hover           |
| `.hover-scale`    | Slight zoom-in effect on hover (3% scale)          |
| `.hover-bg-light` | Adds a light contrasting background on hover       |
| `.hover-none`     | Removes all hover styles (use to override effects) |

---

## Example

```html
<div class="block hover-shadow hover-scale">
  Hover me
</div>
```

---

## Design Notes

* Effects are subtle by default to prevent visual overload
* Can be combined for compound behaviors (e.g., `hover-shadow` + `hover-scale`)
* Effects enhance perceived interactivity and responsiveness

---

## Accessibility Notes

* Avoid using hover as the sole indicator of interaction
* Complement hover effects with visible focus styles for keyboard users
* Avoid hover effects on non-interactive content to reduce confusion

---

## Summary

Hover utilities provide quick and reusable enhancements for interactive states. Use them through the **Groundwork Block Styles** module or atomically in your markup to:

* Add depth, motion, and interactivity
* Improve UI feedback and responsiveness
* Encourage user engagement with subtle, accessible effects
