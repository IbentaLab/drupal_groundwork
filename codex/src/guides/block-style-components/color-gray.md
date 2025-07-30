# Gray Color Utilities

Groundwork includes a complete range of gray color utilities for styling text, backgrounds, and borders. These can be applied via the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module) — or used atomically in any HTML element.

## Overview

| Class                                | Description                                      |
| ------------------------------------ | ------------------------------------------------ |
| `.gray`                            | Gray background with black text                  |
| `.gray-inverted`                   | White background with gray text                  |
| `.gray--light5`→`.gray--light1` | Lighter grays with `--text-on-light`text color |
| `.gray--dark1`→`.gray--dark5`   | Darker grays with `--text-on-dark`text color   |
| `.gray-text`                       | Applies gray to text only                        |
| `.gray-border`                     | Applies gray to border only                      |
| `.gray-hover`                      | Gray background on hover with black text         |
| `.gray-hover-text`                 | Gray text color on hover                         |
| `.gray-hover-border`               | Gray border color on hover                       |

---

## Example

```html
<div class="gray--light4 gray-border gray-text">
  Gray-themed content block
</div>
```

---

## Design Notes

* Uses CSS custom properties like `--gray`, `--gray-light4`, `--gray-dark2`
* Text contrast is automatically adjusted using `--text-on-light` or `--text-on-dark`
* Backgrounds are accessible by default; hover states enhance interactivity

---

## Accessibility Notes

* Light and dark gray variants maintain legibility and meet contrast guidelines
* Hover states reinforce interaction without compromising readability
* Suitable for neutral backgrounds, muted UI, or subdued emphasis

---

## Summary

The gray utility set allows you to:

* Apply a wide range of accessible grays
* Style text, borders, and backgrounds
* Use color effectively without overwhelming the layout

Available via the **Groundwork Block Styles** module or applied atomically.
