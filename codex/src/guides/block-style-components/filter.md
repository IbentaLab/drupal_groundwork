
# CSS Filter Utilities

Groundwork offers CSS filter utilities for visual effects such as blur, brightness, contrast, and grayscale. These can be applied using the **Groundwork Block Styles** module (included in the Groundwork Helpers meta module) — or used atomically.

## Overview

| Class                  | Description                                      |
| ---------------------- | ------------------------------------------------ |
| `.filter`            | Enables filter utilities (required parent class) |
| `.blur-sm`           | Applies a subtle blur (4px)                      |
| `.grayscale`         | Converts content to grayscale (black and white)  |
| `.brightness-75`     | Reduces brightness to 75%                        |
| `.contrast-125`      | Increases contrast to 125%                       |
| `.filter-none`       | Resets all applied filter effects                |
| `.hover-grayscale-0` | Removes grayscale effect on hover                |

---

## Example

```html
<div class="filter grayscale blur-sm">
  <img src="example.jpg" alt="Filtered image">
</div>
```

---

## Design Notes

* All filters are powered by CSS custom properties (e.g., `--filter-blur`, `--filter-brightness`)
* `.filter` must be used to enable filter application — it combines all active variables
* Hover utilities enhance interactivity and reveal underlying visuals

---

## Accessibility Notes

* Avoid overuse of filters that reduce clarity (e.g. blur or low contrast)
* Ensure alt text and semantics still provide meaning when visuals are filtered

---

## Summary

The CSS filter utilities allow visual enhancement and effects for block content. Use via the **Groundwork Block Styles** module or apply directly in markup to:

* Apply subtle or dramatic visual treatments
* Create interactive hover reveals
* Add visual depth without additional images or markup
