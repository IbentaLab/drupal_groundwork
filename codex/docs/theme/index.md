# 🎨 Theme System Overview

Groundwork uses a design-token-based theming system built on CSS custom properties (`--var`) to provide consistent, flexible, and accessible visual styling.

---

## 🧱 File Structure

- `colors.css`: Base named colors (e.g. `--blue`, `--red`) and semantic aliases (e.g. `--color-primary`)
- `variables.css`: Modular scale, spacing, and shadow presets
- `theme-tokens.css`: Light/Dark mode-aware tokens for background, text, borders, and surfaces

---

## 🌗 Dark Mode Support

Groundwork supports two dark mode strategies:
- Automatic via `@media (prefers-color-scheme: dark)`
- Manual toggle using `data-theme="dark"` and localStorage

```html
<!-- Auto via OS setting -->
@media (prefers-color-scheme: dark) { ... }

<!-- Manual override -->
<html data-theme="dark">
```

JavaScript to toggle:
```js
document.documentElement.setAttribute('data-theme', 'dark');
```

See [Theme Tokens](theme-tokens.md) for implementation.

---

## 📚 Related Docs

- [Theme Tokens](theme-tokens.md)
- [Colors](colors.md)
- [Variables](variables.md)
- 