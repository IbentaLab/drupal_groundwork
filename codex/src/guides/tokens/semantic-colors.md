# Semantic Tokens

Groundwork uses semantic tokens to describe the intent or meaning of a color—not the actual color value. These tokens are aliases that map to raw color tokens defined in `tokens.css`, like `--blue` or `--gray`.

This abstraction lets a color's purpose drive its naming, making the design system easier to theme, maintain, and extend.

---

## 🎯 What Are Semantic Tokens?

Instead of writing:

```css
color: var(--blue);
```

Use:

```css
color: var(--color-link);
```

This way, the link color can be changed from blue to teal, or something else entirely, without rewriting every reference in the codebase.

---

## ✳️ Common Semantic Tokens

Defined in `tokens.css`:

```css
--color-primary: var(--blue);
--color-brand: var(--blue);
--color-link: var(--blue);
--color-link-hover: var(--blue-dark2);
--color-heading: var(--gray-dark4);
--color-text: var(--gray-dark3);
--color-border: var(--gray);
--color-background: white;
--color-muted: var(--gray-light3);
```

> Note: These values can be changed to use other base tokens (like `--teal`, `--green`, etc.) if needed.

---

## 🔁 Remapping Semantics

Theme developers can easily swap token mappings to rebrand or restyle a Groundwork-based site:

```css
--color-primary: var(--teal);
--color-link: var(--teal);
--color-link-hover: var(--teal-dark2);
```

No utility classes or component styles need to change—just the token mapping.

---

## ✅ Where to Use Semantic Tokens

* In `core/` stylesheets (buttons, forms, messages, menus, etc.)
* In `patterns/` and base layout styles
* For accessible contrast-aware text and background pairings

Avoid using semantic tokens in utility classes. Those are based on raw palette tokens.

---

Next up: [Theme Utility: Blue](theme-utility-blue.md) →
