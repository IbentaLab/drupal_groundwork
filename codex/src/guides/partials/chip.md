# Chip Component

## Overview
Chips are compact interactive elements that represent an input, attribute, or action. They are commonly used for selections, filters, tags, and contacts.

## Basic Usage

```html
<!-- Basic chip -->
<div class="chip">Basic Chip</div>

<!-- Colored chip -->
<div class="chip chip--primary">Primary</div>

<!-- Dismissible chip -->
<div class="chip chip--dismissible">
  <span class="chip__content">Dismissible</span>
  <button class="chip__remove" aria-label="Remove">×</button>
</div>

<!-- Chip with avatar -->
<div class="chip chip--avatar">
  <img class="chip__avatar" src="/path/to/avatar.jpg" alt="User Name">
  <span>John Doe</span>
</div>

<!-- Chip with icon -->
<div class="chip chip--icon">
  <span class="chip__icon">🔔</span>
  <span>Notifications</span>
</div>

<!-- Input chips (tags input) -->
<div class="chip-input-container">
  <div class="chip chip--input chip--primary chip--dismissible">
    <span class="chip__content">JavaScript</span>
    <button class="chip__remove" aria-label="Remove tag">×</button>
  </div>
  <div class="chip chip--input chip--primary chip--dismissible">
    <span class="chip__content">CSS</span>
    <button class="chip__remove" aria-label="Remove tag">×</button>
  </div>
  <input class="chip-input-container__input" placeholder="Add tag...">
</div>

<!-- Chip group (for filters or multi-select) -->
<div class="chip-group chip-group--choice">
  <div class="chip chip--clickable">All</div>
  <div class="chip chip--clickable is-selected">Active</div>
  <div class="chip chip--clickable">Archived</div>
</div>
```

## Variants

### Color Variants
- Default - Uses surface colors
- `chip--primary` - Primary theme color
- `chip--secondary` - Secondary theme color
- `chip--info` - Information theme color
- `chip--notice` - Notice theme color
- `chip--success` - Success/confirmation theme color
- `chip--danger` - Error/danger theme color
- `chip--warning` - Warning theme color
- `chip--muted` - Subtle theme color

### Size Variants
- `chip--xs` - Extra small chip
- `chip--sm` - Small chip
- `chip--md` (default) - Medium chip
- `chip--lg` - Large chip
- `chip--xl` - Extra large chip

### Shape Variants
- Default - Standard border radius
- `chip--rounded` - More rounded corners
- `chip--square` - No border radius
- `chip--pill` - Fully rounded (pill shape)

### Type Variants
- `chip--basic` (default) - Simple text chip
- `chip--dismissible` - With close/remove button
- `chip--clickable` - Interactive, clickable chip
- `chip--avatar` - With user avatar
- `chip--icon` - With leading icon
- `chip--input` - For use in form inputs

### State Variants
- `is-active` - For active state
- `is-selected` - For selected state
- `is-disabled` - For disabled state

## Best Practices

1. Keep chip text concise
2. Use consistent chip types for similar functionality
3. Ensure sufficient space between chips for touch targets
4. Provide clear visual feedback for interactive chips
5. Include appropriate ARIA attributes for accessibility

## Accessibility Considerations

- Ensure interactive chips have appropriate keyboard navigation
- Use proper semantic elements (buttons for clickable chips)
- Make sure dismiss buttons are accessible to screen readers and keyboard users
- Consider using `role="listbox"` and `role="option"` for selectable chip groups

## Implementation Notes

- For dismissible chips, you'll need JavaScript to handle removal
- For input chips, you'll need JavaScript for adding new chips
- Chip groups can represent either multiple choices or single selection
- Clickable chips should provide hover/focus states for better usability