# Hybrid Style Components (HSC)

Hybrid Style Components (HSCs) apply **both layout behavior and visual styles** to Drupal blocks. These components are designed to work with Groundwork's Block Styles UI and follow the `.block` + `.block-style-target` pattern.

They are particularly useful for:
- Structuring flex or grid layouts within blocks
- Applying spacing, alignment, and other container behaviors
- Enhancing layout without needing SDC markup or overrides

---

## 📁 Location

```text
css/hybrid-style-components/
```

---

## ⚠️ Guidelines

- Do **not** combine HSCs with `.is-*` grid width classes (e.g. `.is-4--s`, `.is-half`)
- Avoid using `.grid--equal` with HSCs, as alignment may conflict
- Best applied to **full-width blocks** or blocks in isolated regions

---

## ✅ Available HSCs

| Component Name       | Description                            |
|----------------------|----------------------------------------|
| [`layout-flex-row`](layout-flex-row.md) | Flexbox layout for horizontal content |
