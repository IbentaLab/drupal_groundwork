# Form Radio Component

## Overview
Radio buttons allow users to select a single option from a list of mutually exclusive choices. The Form Radio component provides an accessible, customizable implementation that works across light and dark themes.

## Basic Usage

```html
<!-- Basic radio buttons -->
<label class="form-radio">
  <input type="radio" class="form-radio__input" name="option" value="1">
  <span class="form-radio__label">Option 1</span>
</label>

<label class="form-radio">
  <input type="radio" class="form-radio__input" name="option" value="2" checked>
  <span class="form-radio__label">Option 2</span>
</label>

<!-- Colored radio -->
<label class="form-radio form-radio--success">
  <input type="radio" class="form-radio__input" name="color-option" value="success">
  <span class="form-radio__label">Success Radio</span>
</label>

<!-- Toggle-style radio -->
<label class="form-radio form-radio--toggle">
  <input type="radio" class="form-radio__input" name="toggle-option" value="on">
  <span class="form-radio__label">On</span>
</label>

<!-- Radio button group -->
<div class="form-radio form-radio--stacked">
  <label class="form-radio">
    <input type="radio" class="form-radio__input" name="stacked" value="1">
    <span class="form-radio__label">First option</span>
  </label>
  <label class="form-radio">
    <input type="radio" class="form-radio__input" name="stacked" value="2">
    <span class="form-radio__label">Second option</span>
  </label>
</div>
```

## Variants

### Color Variants
- Default - Uses primary color
- `form-radio--primary` - Primary theme color
- `form-radio--secondary` - Secondary theme color
- `form-radio--info` - Information theme color
- `form-radio--notice` - Notice theme color
- `form-radio--success` - Success/confirmation theme color
- `form-radio--danger` - Error/danger theme color
- `form-radio--warning` - Warning theme color
- `form-radio--muted` - Subtle theme color

### Size Variants
- `form-radio--xs` - Extra small radio
- `form-radio--sm` - Small radio
- `form-radio--md` (default) - Medium radio
- `form-radio--lg` - Large radio
- `form-radio--xl` - Extra large radio
- `form-radio--xxl` - Extra extra large radio

### Shape Variants
- Default (rounded) - Standard circular radio
- `form-radio--square` - Square radio button
- `form-radio--toggle` - Toggle switch appearance
- `form-radio--pill` - Pill-shaped radio option

### State Variants
- `is-invalid` - Error state
- `is-valid` - Valid/success state
- `is-warning` - Warning state
- `is-disabled` - Disabled state (also works with the disabled attribute)

### Layout Variants
- `form-radio--inline` - Horizontal arrangement
- `form-radio--stacked` - Vertical arrangement

## Best Practices

1. Always use the same `name` attribute for related radio buttons
2. Provide clear, concise labels for each option
3. Limit the number of radio options to a reasonable amount (use select dropdowns for long lists)
4. Pre-select the most common option when appropriate
5. Arrange options in a logical order (alphabetical, numerical, or by frequency of use)

## Accessibility Considerations

- Radio buttons are natively keyboard accessible (Tab to navigate, Space to select)
- Always use proper `<label>` elements to associate text with radio inputs
- Group related radio buttons with `fieldset` and `legend` for screen readers
- Avoid using custom radio buttons that can't be navigated via keyboard
- Ensure color is not the only way to identify the selected state

## Implementation Notes

- The component uses `::before` and `::after` pseudo-elements for custom styling
- Radio buttons maintain their native accessible behavior
- Toggle style variant transforms the radio into a switch-like appearance
- Square style removes the standard circular appearance