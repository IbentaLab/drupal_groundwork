# 🖌️ Block Style Components (BSC)

**BSCs** are reusable CSS classes applied to Drupal blocks to enhance appearance **without new markup**.

- Location: `css/block-style-components/`
- Scope: styles `.block-style-target` inside the block.
- Usage: via Block Styles UI or class attribute.

## Dual Role
| Role | Example |
|------|---------|
| **Atomic utility** | `.p-4`, `.bg-primary`, `.text-center` |
| **Block preset**   | `.card`, `.alert--warning`, `.shadow-lg` |

## Guidelines
- Composable & accessible.
- Use tokens (`var(--color-primary)` etc.), never hard‑code values.
- Reuse before creating new utilities.
