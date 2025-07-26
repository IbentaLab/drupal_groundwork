# Optional Utility Packs

Groundwork includes additional utility packs based on the full set of raw color tokens in `tokens.css`. These packs are  **not loaded by default** , but they are available for developers and site builders to enable as needed.

Each pack extends a single base token (like `--red`, `--green`, `--purple`) and outputs a consistent set of utility classes for background, text, border, and hover colors.

---

## 🚫 Not Loaded by Default

To keep the base theme lean and performant, Groundwork only loads `theme-utility-blue.css` and `theme-utility-gray.css` by default.

All other utility packs must be explicitly enabled in `THEME.libraries.yml` or via theme settings:

```yaml
optional-color-utilities:
  css:
    theme:
      theme/theme-utility-red.css: {}
      theme/theme-utility-green.css: {}
      theme/theme-utility-gold.css: {}
      theme/theme-utility-purple.css: {}
```

---

## 🧩 Available Utility Packs

| Token        | File                         |
| ------------ | ---------------------------- |
| `--red`    | `theme-utility-red.css`    |
| `--green`  | `theme-utility-green.css`  |
| `--gold`   | `theme-utility-gold.css`   |
| `--purple` | `theme-utility-purple.css` |
| `--orange` | `theme-utility-orange.css` |
| `--pink`   | `theme-utility-pink.css`   |
| `--teal`   | `theme-utility-teal.css`   |
| `--lime`   | `theme-utility-lime.css`   |
| `--brown`  | `theme-utility-brown.css`  |
| `--silver` | `theme-utility-silver.css` |

Each file follows the same class naming pattern:

```css
.red--light2,
.red-border,
.red-text,
.red-hover-text,
.red-hover-border
```

---

## ✅ When to Enable

Enable additional packs only when:

* More color variety is needed in site content or layout
* Editors require color-coded UI controls in Block Styles UI
* A brand or visual language includes additional accent tones

---

## 📐 Best Practices

* Load only the color packs in use to avoid unnecessary CSS weight
* Avoid enabling all packs unless you're building a UI kit or design playground
* Let semantic tokens handle theming—use utilities for quick styling only

---

Return to: [Tokens Overview](index.md) →
