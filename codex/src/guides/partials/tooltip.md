# Tooltip Component

## Overview
Tooltips provide additional context or information about an element when a user hovers over or focuses on it. They appear temporarily and are non-disruptive.

## Basic Usage

```html
<!-- Simple tooltip -->
<div class="tooltip tooltip--top">
  <button>Hover me</button>
  <div class="tooltip__content">This is a tooltip</div>
</div>

<!-- Colored tooltip with rich content -->
<div class="tooltip tooltip--bottom tooltip--info">
  <button>Help</button>
  <div class="tooltip__content tooltip--rich-content">
    <h4>Need assistance?</h4>
    <p>Click here to contact support.</p>
  </div>
</div>
```

## Variants

### Position Variants
- `tooltip--top` (default) - Appears above the element
- `tooltip--right` - Appears to the right of the element
- `tooltip--bottom` - Appears below the element
- `tooltip--left` - Appears to the left of the element

### Color Variants
- Default (no class) - Uses `--color-surface-dark`
- `tooltip--primary` - Primary theme color
- `tooltip--secondary` - Secondary theme color
- `tooltip--info` - Information theme color
- `tooltip--notice` - Notice theme color
- `tooltip--success` - Success/confirmation theme color
- `tooltip--danger` - Error/danger theme color
- `tooltip--warning` - Warning theme color
- `tooltip--muted` - Subtle theme color

### Size Variants
- `tooltip--xs` - Extra small tooltip
- `tooltip--sm` - Small tooltip
- `tooltip--md` (default) - Medium tooltip
- `tooltip--lg` - Large tooltip
- `tooltip--xl` - Extra large tooltip

### Shape Variants
- Default - Default border radius
- `tooltip--rounded` - More rounded corners
- `tooltip--square` - No border radius

### Type Variants
- Default - Simple text content
- `tooltip--rich-content` - For complex content with headings, paragraphs, etc.

### Animation Variants
- Default - Slide animation
- `tooltip--fade` - Fade in/out animation
- `tooltip--scale` - Scale in/out animation

## Accessibility Considerations

- Tooltips are automatically revealed on both hover and keyboard focus
- For complex tooltips, consider using `aria-describedby` to associate the tooltip with its target
- Tooltips should supplement UI, not hide essential information

## Implementation Notes

- Tooltips position themselves automatically, but may need adjustment on smaller screens
- The arrow adapts to match the tooltip position
- Avoid using tooltips for essential information that users need to complete a task