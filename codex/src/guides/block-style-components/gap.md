
# Gap Utilities

Groundwork provides gap utilities to manage spacing between items inside a flex (`.d-flex`) or grid (`.d-grid`) container. These classes can be applied through the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module) — or used atomically in your markup.

## Overview

| Class         | Description                             |
| ------------- | --------------------------------------- |
| `.gap-xs`   | Extra-small gap between items           |
| `.gap-sm`   | Small gap between items                 |
| `.gap-md`   | Medium gap between items                |
| `.gap-lg`   | Large gap between items                 |
| `.gap-xl`   | Extra-large gap between items           |
| `.gap-xxl`  | 2x extra-large gap between items        |
| `.gap-x-md` | Medium horizontal gap only (column-gap) |
| `.gap-y-md` | Medium vertical gap only (row-gap)      |

---

## Example

```html
<div class="d-flex gap-md">
  <div>Item 1</div>
  <div>Item 2</div>
</div>
```

---

## Design Notes

* Effective only on flex or grid containers
* Gaps use CSS variables (e.g., `--space-2`) with sensible fallbacks
* Supports both uniform and axis-specific spacing

---

## Accessibility Notes

* Gaps help maintain whitespace for clarity and scannability
* Improves tap target separation in mobile views
* Consistent gaps enhance visual rhythm and usability

---

## Summary

Gap utilities give you layout control for both Flexbox and Grid systems. Use them via the **Groundwork Block Styles** module or directly in your markup to:

* Apply consistent spacing between layout items
* Customize spacing without custom CSS
* Improve layout structure and responsiveness
