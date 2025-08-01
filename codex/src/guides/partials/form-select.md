# Form Select Component

## Overview
The Form Select component provides a styled dropdown selector that allows users to choose one option from a list. It supports various sizes, colors, and states while maintaining accessibility.

## Basic Usage

```html
<!-- Basic select -->
<div class="form-select">
  <label class="form-select__label" for="country">Country</label>
  <select id="country" class="form-select__field">
    <option value="">Choose a country</option>
    <option value="us">United States</option>
    <option value="ca">Canada</option>
    <option value="mx">Mexico</option>
  </select>
</div>

<!-- With helper text -->
<div class="form-select">
  <label class="form-select__label" for="role">Role</label>
  <select id="role" class="form-select__field">
    <option value="user">User</option>
    <option value="editor">Editor</option>
    <option value="admin">Administrator</option>
  </select>
  <div class="form-select__hint">Select your access level</div>
</div>

<!-- With validation state -->
<div class="form-select is-invalid">
  <label class="form-select__label" for="required-select">Required field</label>
  <select id="required-select" class="form-select__field">
    <option value="">Please select an option</option>
    <option value="1">Option 1</option>
    <option value="2">Option 2</option>
  </select>
  <div class="form-select__hint">This field is required</div>
</div>

<!-- Multiple select -->
<div class="form-select form-select--multiple">
  <label class="form-select__label" for="interests">Interests</label>
  <select id="interests" class="form-select__field" multiple size="4">
    <option value="tech">Technology</option>
    <option value="sports">Sports</option>
    <option value="music">Music</option>
    <option value="books">Books</option>
    <option value="travel">Travel</option>
  </select>
</div>

<!-- With prefix -->
<div class="form-select form-select--with-prefix">
  <label class="form-select__label" for="currency">Currency</label>
  <div class="form-select__prefix">$</div>
  <select id="currency" class="form-select__field">
    <option value="usd">USD</option>
    <option value="eur">EUR</option>
    <option value="gbp">GBP</option>
  </select>
</div>
```

## Variants

### Color Variants
- Default - Uses primary color for focus
- `form-select--primary` - Primary theme color
- `form-select--secondary` - Secondary theme color
- `form-select--info` - Information theme color
- `form-select--notice` - Notice theme color
- `form-select--success` - Success/confirmation theme color
- `form-select--danger` - Error/danger theme color
- `form-select--warning` - Warning theme color
- `form-select--muted` - Subtle theme color

### Size Variants
- `form-select--xs` - Extra small select
- `form-select--sm` - Small select
- `form-select--md` (default) - Medium select
- `form-select--lg` - Large select
- `form-select--xl` - Extra large select
- `form-select--xxl` - Extra extra large select

### Shape Variants
- Default - Standard border radius
- `form-select--rounded` - More rounded corners
- `form-select--square` - No border radius
- `form-select--pill` - Fully rounded select

### State Variants
- `is-invalid` - Error state
- `is-valid` - Valid/success state
- `is-warning` - Warning state
- `is-disabled` - Disabled state (also works with the disabled attribute)

### Type Variants
- Default - Single select
- `form-select--multiple` - Multiple selection enabled
- `form-select--native` - Uses browser's default styling

### Layout Variants
- `form-select--with-leading-icon` - Icon at beginning of select
- `form-select--with-prefix` - Text/element before select
- `form-select--with-floating-label` - Label moves when option selected

## Best Practices

1. Provide a meaningful default option or prompt
2. Limit the number of options to a reasonable amount
3. Sort options in a logical order
4. Use optgroups to categorize related options in long lists
5. Consider alternative UI patterns for very short lists (radio buttons) or very long lists (autocomplete)

## Accessibility Considerations

- Select elements are natively keyboard accessible
- Use `<optgroup>` for grouping related options
- Ensure sufficient color contrast for all states
- Provide clear labels and instructions
- For complex requirements, consider using custom select components with proper ARIA attributes

## Implementation Notes

- The component uses a custom dropdown arrow that scales with size variants
- Multiple select removes the custom arrow and allows selecting multiple options
- The select's width defaults to 100% of its container
- The arrow position adjusts for validation states
- Select field height is calculated based on font size and padding