# Toast Component

## Overview
Toast notifications are brief, non-disruptive messages that appear temporarily to provide quick feedback to the user. They typically appear at the edges of the interface and automatically dismiss after a few seconds.

## Basic Usage

```html
<!-- Basic toast -->
<div class="toast-container toast-container--top-right">
  <div class="toast">
    <div class="toast__content">
      <p class="toast__message">Your changes have been saved.</p>
    </div>
    <button class="toast__close" aria-label="Close notification">×</button>
  </div>
</div>

<!-- Toast with icon and title -->
<div class="toast toast--success toast--with-icon">
  <div class="toast__icon">✓</div>
  <div class="toast__content">
    <h4 class="toast__title">Success</h4>
    <p class="toast__message">Your file has been uploaded.</p>
  </div>
  <button class="toast__close" aria-label="Close notification">×</button>
</div>

<!-- Toast with progress and action -->
<div class="toast toast--info toast--with-progress toast--with-action">
  <div class="toast__icon">ℹ️</div>
  <div class="toast__content">
    <p class="toast__message">Download started</p>
    <div class="toast__actions">
      <button>Pause</button>
      <button>Cancel</button>
    </div>
  </div>
  <div class="toast__progress" style="--toast-duration: 10s;"></div>
</div>
```

## Variants

### Position Variants
- `toast-container--top` - Center top of screen
- `toast-container--top-left` - Top left corner
- `toast-container--top-right` - Top right corner
- `toast-container--bottom` - Center bottom of screen
- `toast-container--bottom-left` - Bottom left corner
- `toast-container--bottom-right` - Bottom right corner

### Color Variants
- Default (no class) - Uses surface color
- `toast--primary` - Primary theme color
- `toast--secondary` - Secondary theme color
- `toast--info` - Information theme color
- `toast--notice` - Notice theme color
- `toast--success` - Success/confirmation theme color
- `toast--danger` - Error/danger theme color
- `toast--warning` - Warning theme color
- `toast--muted` - Subtle theme color

### Size Variants
- `toast--xs` - Extra small toast
- `toast--sm` - Small toast
- `toast--md` (default) - Medium toast
- `toast--lg` - Large toast
- `toast--xl` - Extra large toast

### Shape Variants
- Default - Standard border radius
- `toast--rounded` - More rounded corners
- `toast--square` - No border radius
- `toast--pill` - Pill-shaped (fully rounded sides)

### Type Variants
- Default - With close button
- `toast--text-only` - No icon
- `toast--with-icon` - Includes icon
- `toast--with-action` - Includes action buttons
- `toast--with-progress` - Includes auto-dismiss progress indicator

### Animation Variants
- Default - Slide animation
- `toast--fade` - Fade in/out animation
- `toast--scale` - Scale in/out animation

## JavaScript Integration

While this component is primarily CSS-based, you'll need to implement JavaScript to handle:

1. Toast creation and insertion into DOM
2. Auto-dismissal timing
3. Close button functionality
4. Managing multiple toasts in a container

## Accessibility Considerations

- Toasts should be announced to screen readers (use `role="alert"` for important notifications)
- Provide enough time before auto-dismissal or allow disabling auto-dismissal
- Ensure any interactive elements within toasts are keyboard accessible
- Consider using `aria-live="polite"` for non-critical toasts

## Implementation Notes

- Toasts stack within their container in the order they are added
- A toast can be manually dismissed with the close button
- The progress indicator shows the remaining time before auto-dismissal
- Use the `toast--hiding` class for exit animations