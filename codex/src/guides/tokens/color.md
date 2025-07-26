# Color Tokens

Groundwork defines a structured color system in `tokens.css`, starting with a small set of carefully chosen  **raw color tokens** . These are the base HSL values used throughout the theme. They are not tied to meaning or usage — they are just named colors.

These tokens act as the foundation for all visual color decisions in Groundwork. Other token layers (like semantic tokens and utility classes) build on top of this base.

---

## 🎨 Raw Color Tokens

Defined in `tokens.css`:

```css
--blue:   hsl(202 94% 40%);  /* #067cc6 */
--red:    hsl(7 94% 40%);    /* #c61c06 */
--green:  hsl(122 51% 49%);  /* #40ba44 */
--orange: hsl(34 100% 50%);  /* #ff8c00 */
--purple: hsl(277 94% 40%);  /* #8906c6 */
--pink:   hsl(330 94% 40%);  /* #c60666 */
--gold:   hsl(45 94% 40%);   /* #c69c06 */
--brown:  hsl(26 94% 40%);   /* #c65c06 */
--gray:   hsl(0 0% 50%);     /* #808080 */
--teal:   hsl(174 100% 29%); /* #009688 */
--lime:   hsl(62 63% 44%);   /* #afb42b */
--silver: hsl(0 0% 62%);     /* #9e9e9e */
```

These are the core color values that Groundwork and its utility packs use as input. They are **not meant to be used directly in CSS** unless styling highly generic or brand-related elements.

---

## 🧱 Use Cases

* Base palette for utility classes (like `.blue--light2`, `.gray-border`, etc.)
* Input source for semantic tokens (`--color-primary`, `--color-link`, etc.)
* Mapping for theme-based utilities and Block Styles UI options

---

## 🚫 Avoid Direct Use

Do not use `--blue`, `--gray`, `--red`, etc. directly in component or layout CSS.

Instead:

* Use semantic tokens (see: [Semantic Tokens](semantic-colors.md))
* Use utility classes from `theme-utility-blue.css` and `theme-utility-gray.css`

This helps Groundwork stay maintainable and customizable.

---

Next up: [Semantic Tokens](semantic-colors.md) →
