# Badge Component

## Overview
Badges are small elements that represent status, counts, or labels. They're commonly used to display notification counts, highlight new items, or indicate status.

## Basic Usage

```html
<!-- Basic badge -->
<span class="badge">New</span>

<!-- Count badge -->
<span class="badge badge--primary badge--pill">5</span>

<!-- Status badge -->
<span class="badge badge--success">Active</span>

<!-- Notification badge -->
<div class="badge-container">
  <button>Notifications</button>
  <span class="badge badge--danger badge--stacked">12</span>
</div>

<!-- Dot badge -->
<span class="badge badge--success badge--dot"></span>
```

## Variants

### Color Variants
- Default - Uses primary color
- `badge--primary` - Primary theme color
- `badge--secondary` - Secondary theme color
- `badge--info` - Information theme color
- `badge--notice` - Notice theme color
- `badge--success` - Success/confirmation theme color
- `badge--danger` - Error/danger theme color
- `badge--warning` - Warning theme color
- `badge--muted` - Subtle theme color

### Size Variants
- `badge--xs` - Extra small badge
- `badge--sm` - Small badge
- `badge--md` (default) - Medium badge
- `badge--lg` - Large badge
- `badge--xl` - Extra large badge

### Shape Variants
- Default - Standard border radius
- `badge--rounded` - More rounded corners
- `badge--square` - No border radius
- `badge--pill` - Fully rounded (pill shape)

### Type Variants
- Default (solid) - Filled background with contrasting text
- `badge--outline` - Outlined style with transparent background
- `badge--soft` - Soft/pastel background with matching text color
- `badge--dot` - Simple dot indicator (no text)

### Layout Variants
- `badge--inline` - For inline text (adds margin)
- `badge--stacked` - For positioning on top of other elements

## Best Practices

1. Keep badge text brief, ideally a single word or number
2. Use consistent badge types for similar information across your application
3. Choose colors that convey meaning (e.g., red for errors, green for success)
4. Ensure sufficient contrast between badge text and background
5. For notification counts over a threshold (e.g., 99), consider using "99+" format

## Accessibility Considerations

- Badges that convey important information should be accessible to screen readers
- For purely decorative badges, use `aria-hidden="true"`
- For notification badges, consider using `aria-label` to provide context (e.g., "5 unread messages")

## Implementation Notes

- Badges have a minimum width to maintain a circular appearance with single digits
- When using stacked badges, ensure the container element has `position: relative`
- Dot badges have no text content and are sized appropriately for status indicators