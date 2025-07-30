
# Alert Utilities

Groundwork includes a flexible set of contextual alert styles using the `.alert` base class and accompanying color-coded variants for different message types.

As with other Groundwork utilities, you can apply alert styles via the **Groundwork Block Styles UI** — no code needed — or use them atomically in your own markup. The Groundwork Block Styles module is included with the meta module Groundwork Helpers.

## Overview

| Class              | Description                   |
| ------------------ | ----------------------------- |
| `.alert`         | Base styling for all alerts   |
| `.alert-info`    | Informational messages        |
| `.alert-success` | Success confirmation messages |
| `.alert-warning` | Warnings or cautions          |
| `.alert-danger`  | Errors or critical alerts     |

> 💡  **Note** : Color variants should be combined with the `.alert` base class.

---

## Base Alert

```html
<div class="alert">
  <p>This is a generic alert box.</p>
</div>
```

This sets up the padding, border-radius, and left border appearance. To style the alert fully, use a contextual modifier like `.alert-info`.

---

## Contextual Variants

Each variant adds color-specific background, border, and text styling:

```html
<div class="alert alert-info">
  <p>This is an informational message.</p>
</div>
```

### Available Variants

* `.alert-info`: Informational messages (uses primary theme color)
* `.alert-success`: Success messages (e.g., form submission)
* `.alert-warning`: Warnings or potential issues
* `.alert-danger`: Critical errors or failures

Each variant uses `hsl(from ...)` syntax to derive accessible colors with soft backgrounds and readable text.

---

## Accessibility Notes

* Text color is tuned for contrast against each background.
* Alerts use large left borders and ample padding to aid visual scanning.
* Background hues are softened with high lightness for readability.

---

## Summary

Alert utilities offer:

* Clear, color-coded messaging for user feedback
* Full support in the **Groundwork Block Styles UI** or atomic usage
* Accessible contrast by default

Easily drop in alerts for success, errors, or general information using the `.alert` base and appropriate modifier class.
