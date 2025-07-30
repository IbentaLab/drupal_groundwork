
# Blockquote Utility

Groundwork provides a simple, accessible `.blockquote` utility class for styling quoted text with visual clarity and distinction.

As with all Groundwork utilities, the `.blockquote` class can be applied via the **Groundwork Block Styles** module — or atomically in your own markup. The Groundwork Block Styles module is part of the meta module Groundwork Helpers.

## Overview

| Class           | Description                                    |
| --------------- | ---------------------------------------------- |
| `.blockquote` | Styles block-level quotes with border and tone |

---

## Example

```html
<blockquote class="blockquote">
  "We do not inherit the earth from our ancestors; we borrow it from our children."
</blockquote>
```

This adds:

* Padding and spacing for readability
* A thick left border for visual emphasis
* A contrasting background tone
* Italicized text for a traditional quote look

---

## Visual Features

* Uses `--color-border` for the left border (customizable)
* Applies `--color-surface-contrast` as background
* Rounded corners via `--radius-sm`
* Soft, neutral styling that adapts to light/dark themes

---

## Accessibility Notes

* The background contrast is optimized for readability
* Borders and spacing aid content scanning
* Does not rely solely on color for meaning

---

## Summary

The `.blockquote` class is a foundational typographic utility ideal for:

* Quoting external sources
* Highlighting key statements
* Styling testimonials or citations

Use it through the **Groundwork Block Styles** module or directly in markup — no extra configuration required.
