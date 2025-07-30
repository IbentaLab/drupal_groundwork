
# Card Utilities

Groundwork provides flexible, accessible card components using the `.card` base class and a rich set of optional modifiers. Cards are commonly used for grouping related content with visual emphasis, consistent padding, and optional elevation.

Like other Groundwork layout utilities, card styles can be applied using the **Groundwork lock Styles UI** — no code required. You can also apply them **atomically** in your own markup.

## Overview

| Class                    | Description                                    |
| ------------------------ | ---------------------------------------------- |
| `.card`                | Base card styling with padding and shadow      |
| `.card--*`             | Visual variants (e.g.,`--primary`,`--red`) |
| `.card--1`/`2`/`3` | Elevation levels (low to high)                 |
| `.card--hover`         | Adds elevation on hover                        |

> 💡  **Note** : All `.card--*` modifiers must be used together with the `.card` base class.

---

## Base Card

```html
<div class="card">
  <p>This is a standard card.</p>
</div>
```

Provides default padding, subtle shadow, and a white background.

---

## Color Variants

```html
<div class="card card--blue">
  <p>This card has a blue background.</p>
</div>
```

Supported color modifiers:

* `.card--primary`
* `.card--inverse`
* `.card--outline`
* `.card--blue`, `.card--indigo`, `.card--deep-purple`, `.card--purple`
* `.card--pink`, `.card--red`, `.card--orange`, `.card--amber`, `.card--yellow`, `.card--lime`
* `.card--green`, `.card--teal`, `.card--cyan`, `.card--brown`, `.card--blue-gray`, `.card--gray`

Most color variants remove the border for a cleaner look.

---

## Elevation

Use elevation modifiers to increase depth:

```html
<div class="card card--2">
  <p>This card has medium elevation.</p>
</div>
```

* `.card--1`: low elevation
* `.card--2`: medium elevation
* `.card--3`: high elevation

You can also add `.card--hover` to elevate the card on hover:

```html
<div class="card card--hover">
  <p>This card lifts on hover.</p>
</div>
```

---

## Accessibility Notes

* Text colors use `--text-on-dark` or `--text-on-light` for WCAG contrast compliance.
* Use `.card--outline` for transparent or minimal designs.

---

## Summary

Groundwork cards offer:

* A clean, modern UI foundation
* Optional color and elevation variants
* Reusable, atomic class combinations
* Accessible color contrast by default

Customize cards by combining base `.card` with any number of supported modifiers.
