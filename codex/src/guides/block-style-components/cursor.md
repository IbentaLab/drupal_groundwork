
# Cursor Utilities

Groundwork provides cursor utilities to indicate different user interaction states. These classes can be applied through the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module) — or used atomically in any element.

## Overview

| Class                   | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| `.cursor-pointer`     | Shows a pointer (hand), indicating an interactive element    |
| `.cursor-not-allowed` | Shows a no-entry icon, indicating the action is blocked      |
| `.cursor-wait`        | Shows a spinner or hourglass, indicating background activity |
| `.cursor-default`     | Shows the default arrow cursor                               |

---

## Example

```html
<div class="cursor-pointer">
  Click me
</div>
```

---

## Design Notes

* Cursor classes only affect the cursor’s appearance
* These utilities are helpful for buttons, links, disabled elements, or loading states

---

## Accessibility Notes

* Cursor styles reinforce user expectations
* Use in combination with `aria-disabled`, `aria-busy`, or proper HTML semantics

---

## Summary

Cursor utilities enhance interactivity and affordance without adding complexity. Use them via the **Groundwork Block Styles** module or directly in markup to:

* Signal clickable or disabled elements
* Indicate loading states
* Restore default cursor appearance
