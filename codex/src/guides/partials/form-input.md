# Form Input Component

## Overview
The Form Input component provides a standardized, accessible way to collect user text input across your application. It supports various input types, states, and visual variants.

## Basic Usage

```html
<!-- Basic text input -->
<div class="form-input">
  <label class="form-input__label" for="name">Name</label>
  <input type="text" id="name" class="form-input__field" placeholder="Enter your name">
</div>

<!-- With helper text -->
<div class="form-input">
  <label class="form-input__label" for="email">Email address</label>
  <input type="email" id="email" class="form-input__field" placeholder="name@example.com">
  <div class="form-input__hint">We'll never share your email with anyone else.</div>
</div>

<!-- With validation state -->
<div class="form-input is-invalid">
  <label class="form-input__label" for="password">Password</label>
  <input type="password" id="password" class="form-input__field">
  <div class="form-input__hint">Password must be at least 8 characters.</div>
</div>

<!-- With prefix and suffix -->
<div class="form-input form-input--with-prefix form-input--with-suffix">
  <label class="form-input__label" for="price">Price</label>
  <div class="form-input__prefix">$</div>
  <input type="number" id="price" class="form-input__field" value="99">
  <div class="form-input__suffix">.00</div>
</div>

<!-- With floating label -->
<div class="form-input form-input--with-floating-label">
  <input type="text" id="floating" class="form-input__field" placeholder=" ">
  <label class="form-input__label" for="floating">Floating label</label>
</div>
```

## Variants

### Color Variants
- Default - Uses primary color for focus
- `form-input--primary` - Primary theme color
- `form-input--secondary` - Secondary theme color
- `form-input--info` - Information theme color
- `form-input--notice` - Notice theme color
- `form-input--success` - Success/confirmation theme color
- `form-input--danger` - Error/danger theme color
- `form-input--warning` - Warning theme color
- `form-input--muted` - Subtle theme color

### Size Variants
- `form-input--xs` - Extra small input
- `form-input--sm` - Small input
- `form-input--md` (default) - Medium input
- `form-input--lg` - Large input
- `form-input--xl` - Extra large input
- `form-input--xxl` - Extra extra large input

### Shape Variants
- Default - Standard border radius
- `form-input--rounded` - More rounded corners
- `form-input--square` - No border radius
- `form-input--pill` - Fully rounded input

### State Variants
- `is-invalid` - Error state
- `is-valid` - Valid/success state
- `is-warning` - Warning state
- `is-disabled` - Disabled state
- `is-readonly` - Read-only state

### Type Variants
- Default (text input)
- `form-input--textarea` - Multi-line text input
- `form-input--search` - Search input with search icon
- `form-input--password` - Password input with toggle

### Layout Variants
- `form-input--with-leading-icon` - Icon at beginning of input
- `form-input--with-trailing-icon` - Icon at end of input
- `form-input--with-prefix` - Text/element before input
- `form-input--with-suffix` - Text/element after input
- `form-input--with-floating-label` - Label moves when input has content
- `form-input--with-character-count` - Shows character counter

## Best Practices

1. Always use labels for form inputs
2. Provide clear placeholder text but don't rely on it exclusively
3. Use appropriate input types (email, tel, number, etc.)
4. Provide validation feedback with helpful error messages
5. Group related inputs logically
6. Consider using floating labels for compact forms

## Accessibility Considerations

- Ensure all inputs have associated labels
- Use `aria-describedby` to connect inputs with help/error text
- Don't disable paste functionality for security fields
- Ensure error messages are announced to screen readers
- Maintain sufficient color contrast for all states
- Don't rely solely on color to convey state information

## Implementation Notes

- Input heights are calculated based on font size and padding
- Icons should be appropriately sized based on the input size
- Character count requires JavaScript to update the count
- Password toggle visibility requires JavaScript to change input type
- Some variants can be combined (e.g., with-icon and rounded)