# Avatar Component

## Overview
Avatars are visual representations of users, typically displaying profile pictures or initials when images are unavailable.

## Basic Usage

```html
<!-- Image avatar -->
<div class="avatar">
  <img class="avatar__image" src="/path/to/profile.jpg" alt="User Name">
</div>

<!-- Text avatar (initials) -->
<div class="avatar avatar--primary">
  JD
</div>

<!-- Avatar with status -->
<div class="avatar avatar--with-status avatar--status-online">
  <img class="avatar__image" src="/path/to/profile.jpg" alt="User Name">
</div>

<!-- Avatar group -->
<div class="avatar-group">
  <div class="avatar"><img class="avatar__image" src="/path/to/user1.jpg" alt="User 1"></div>
  <div class="avatar"><img class="avatar__image" src="/path/to/user2.jpg" alt="User 2"></div>
  <div class="avatar"><img class="avatar__image" src="/path/to/user3.jpg" alt="User 3"></div>
</div>
```

## Variants

### Color Variants
- `avatar--primary` - Primary theme color background
- `avatar--secondary` - Secondary theme color background
- `avatar--info` - Information theme color background
- `avatar--notice` - Notice theme color background
- `avatar--success` - Success theme color background
- `avatar--danger` - Danger theme color background
- `avatar--warning` - Warning theme color background
- `avatar--muted` (default) - Muted theme color background

### Size Variants
- `avatar--xs` - Extra small avatar
- `avatar--sm` - Small avatar
- `avatar--md` (default) - Medium avatar
- `avatar--lg` - Large avatar
- `avatar--xl` - Extra large avatar
- `avatar--xxl` - Extra extra large avatar

### Shape Variants
- Default (circle) - Circular avatar
- `avatar--square` - Square avatar
- `avatar--rounded` - Rounded square avatar

### Type Variants
- Image - With an `img` element (default when image present)
- Text - Text content for initials (default when no image)
- `avatar--icon` - For icon avatars

### Layout Variants
- `avatar--with-status` - Shows online status indicator
  - `avatar--status-online` - Green status indicator
  - `avatar--status-away` - Yellow status indicator
  - `avatar--status-busy` - Red status indicator
  - `avatar--status-offline` - Gray status indicator
- `avatar--with-badge` - Shows a badge on the avatar
- `avatar-group` - Groups multiple avatars with overlap
- `avatar-stacked` - Avatar with name and additional info

## Best Practices

1. **Fallback Strategy**: Always provide a text fallback for when images fail to load
2. **Accessibility**: Include appropriate alt text for image avatars
3. **Size Consistency**: Use the same size avatars within a specific UI context
4. **Contrast**: Ensure good contrast between avatar text and background colors

## Implementation Notes

- Avatar text is automatically centered
- The component handles image scaling and cropping
- Group avatars have a slight overlap and are automatically layered
- Status indicators appear in the bottom right by default