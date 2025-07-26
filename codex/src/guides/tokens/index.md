# Tokens

Groundwork is a token-first design system. Every visual decision—from color to spacing, typography, and layout—is powered by reusable, centralized variables defined in `tokens.css` and extended via utility packs like `theme-utility-blue.css` and `theme-utility-gray.css`.

Tokens ensure design consistency, themeability, and maintainability across the theme. Instead of hardcoding colors, font sizes, or spacing values, semantic and scale-based tokens are used to reflect Groundwork's design language.

---

## What's Included in the Tokens Layer

### ✅ Core Tokens (`tokens.css`)

These are the design primitives that define the theme's foundation:

* **Color Palette Tokens** : `--blue`, `--gray`, `--teal`, `--red`, etc.
* **Semantic Color Aliases** : `--color-primary`, `--color-link`, `--color-brand`
* **Spacing Scale** : `--space-1` to `--space-6` (used for margin, padding, gap)
* **Radius & Borders** : `--radius`, `--radius-lg`, `--border-width`, etc.
* **Typography** : `--font-sm`, `--font-lg`, `--leading-tight`, `--font-weight-bold`
* **Layout Tokens** : `--max-content-width`, `--grid-gap`, `--container-padding`
* **Transitions** : `--transition-fast`, `--transition-smooth`

These tokens are available globally to all CSS, components, and utilities in Groundwork.

---

## Utility Color Packs

To make colors more usable in markup and block UI, Groundwork provides  **utility packs** :

### ✅ Default Loaded

Always included in the base theme:

* **`theme-utility-blue.css`** : Provides `.blue--light2`, `.blue-border`, `.blue-text`, etc.
* **`theme-utility-gray.css`** : Provides `.gray--dark1`, `.gray-bg`, `.gray-hover-text`, etc.

### 🟡 Optional (Opt-in)

These are **not loaded by default** but can be added via `libraries.yml` or theme settings:

* `theme-utility-red.css`
* `theme-utility-green.css`
* `theme-utility-gold.css`
* `theme-utility-purple.css`
* ... and more

These optional packs allow site builders and developers to enable more color utility classes only when needed, keeping the base theme clean.

---

## Best Practices

* Use **semantic tokens** (`--color-primary`, `--space-2`, `--font-sm`) in `core/` and `patterns/` CSS.
* Use **utility classes** from `theme-utility-blue.css` and `theme-utility-gray.css` in markup and Block Styles UI.
* Avoid hardcoded values (like `#000`, `1em`, `12px`) unless absolutely necessary.
* Let `tokens.css` be the single source of truth for design decisions.

---

Continue exploring:

* [Color Tokens](color.md)
* [Semantic Tokens](semantic-colors.md)
* [Theme Utility: Blue](theme-utility-blue.md)
* [Theme Utility: Gray](theme-utility-gray.md)
* [Optional Utility Packs](theme-utility-packs.md)
