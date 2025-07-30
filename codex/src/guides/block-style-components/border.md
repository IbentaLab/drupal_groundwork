
# Border Utilities

Groundwork includes utility classes to apply consistent borders around block content. You can apply these via the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module) — or use them atomically in your own markup.

## Overview

| Class              | Description                          |
| ------------------ | ------------------------------------ |
| `.border`        | Adds a 1px solid border on all sides |
| `.border-t`      | Adds a top border                    |
| `.border-b`      | Adds a bottom border                 |
| `.border-l`      | Adds a left border                   |
| `.border-r`      | Adds a right border                  |
| `.border-solid`  | Sets border style to solid           |
| `.border-dashed` | Sets border style to dashed          |
| `.border-dotted` | Sets border style to dotted          |
| `.border-none`   | Removes all borders                  |

---

## Example

```html
<div class="border border-dashed border-t">
  This block has a dashed top border.
</div>
```

---

## Design Notes

* All borders use the `--color-border` variable, customizable via tokens.css
* Each side-specific class can be used independently or combined
* Combine style utilities (e.g. `.border-dotted`) with directionals (e.g. `.border-r`) to control appearance

---

## Accessibility Notes

* Borders help separate and distinguish sections of content
* They do not convey meaning on their own, ensuring semantic neutrality
* Use sparingly to avoid visual clutter

---

## Summary

Border utilities give you easy control over:

* Which sides display a border
* What style the border has
* Whether a border is visible or removed

These are available in the **Groundwork Block Styles** interface or can be used atomically in any HTML element.
