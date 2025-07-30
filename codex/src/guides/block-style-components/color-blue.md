# Blue Color Utilities

Groundwork offers a flexible set of blue color utilities, allowing you to apply consistent theme-aware styles to backgrounds, text, and borders. These can be applied through the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module) — or used atomically in your markup.

## Overview

| Class                                | Description                                             |
| ------------------------------------ | ------------------------------------------------------- |
| `.blue`                            | Blue background with readable text                      |
| `.blue-inverted`                   | White background with blue text (inverted look)         |
| `.blue--light5`→`.blue--light1` | Lighter blue backgrounds with appropriate text contrast |
| `.blue--dark1`→`.blue--dark5`   | Darker blue backgrounds with accessible light text      |
| `.blue-text`                       | Applies blue to text only                               |
| `.blue-border`                     | Applies blue to border only                             |
| `.blue-hover`                      | Applies blue background on hover                        |
| `.blue-hover-text`                 | Applies blue text color on hover                        |
| `.blue-hover-border`               | Applies blue border color on hover                      |

---

## Example

```html
<div class="blue--light3 blue-border blue-text">
  Blue-themed content block
</div>
```

---

## Design Notes

* Blue shades use CSS variables like `--blue-light3`, `--blue-dark2`, and `--text-on-light`
* Light shades ensure readable text on bright backgrounds
* Darker shades use `--text-on-dark` for accessibility
* Hover utilities allow smooth interactive effects

---

## Accessibility Notes

* Text color is automatically set for sufficient contrast
* `--light2` is WCAG AA compliant only for large text (18pt+)
* Always use hover states that retain legibility

---

## Summary

Blue utilities allow theme-consistent styling with minimal effort. Use them to:

* Set background and text tones
* Create emphasis or branding sections
* Apply interactive hover states

Available through the **Groundwork Block Styles** module or directly in your markup using class names.
