# Form Number Component

## Overview
The Form Number component provides an input specifically designed for numeric values, with increment/decrement controls for easy adjustment. It supports various styles, sizes, and states.

## Basic Usage

```html
<!-- Basic number input -->
<div class="form-number">
  <button class="form-number__control form-number__control--decrement" aria-label="Decrease value">-</button>
  <input type="number" class="form-number__field form-input__field" value="1" min="0" max="10" step="1">
  <button class="form-number__control form-number__control--increment" aria-label="Increase value">+</button>
</div>

<!-- With label -->
<div class="form-input">
  <label class="form-input__label" for="quantity">Quantity</label>
  <div class="form-number">
    <button class="form-number__control form-number__control--decrement" aria-label="Decrease quantity">-</button>
    <input type="number" id="quantity" class="form-number__field form-input__field" value="1" min="1" max="100">
    <button class="form-number__control form-number__control--increment" aria-label="Increase quantity">+</button>
  </div>
</div>

<!-- Currency input -->
<div class="form-number form-number--currency">
  <button class="form-number__control form-number__control--decrement" aria-label="Decrease value">-</button>
  <input type="number" class="form-number__field form-input__field" value="99.99" step="0.01" min="0">
  <button class="form-number__control form-number__control--increment" aria-label="Increase value">+</button>
</div>

<!-- Vertical layout -->
<div class="form-number form-number--vertical">
  <button class="form-number__control form-number__control--increment" aria-label="Increase value">+</button>
  <input type="number" class="form-number__field form-input__field" value="50" min="0" max="100">
  <button class="form-number__control form-number__control--decrement" aria-label="Decrease value">-</button>
</div>
```

## Variants

### Color Variants
- Default - Uses text color for controls
- `form-number--primary` - Primary theme color for controls
- `form-number--secondary` - Secondary theme color for controls
- `form-number--info` - Information theme color for controls
- `form-number--notice` - Notice theme color for controls
- `form-number--success` - Success theme color for controls
- `form-number--danger` - Danger theme color for controls
- `form-number--warning` - Warning theme color for controls
- `form-number--muted` - Muted theme color for controls

### Size Variants
- Inherits from form-input size variants
- Control buttons adjust automatically to input size

### Type Variants
- Default - Standard number input with controls
- `form-number--currency` - With currency symbol
- `form-number--compact` - Smaller control buttons
- `form-number--touch-friendly` - Larger controls for touch devices

### Layout Variants
- Default (horizontal) - Controls on either side
- `form-number--vertical` - Controls stacked vertically

## Best Practices

1. Set appropriate `min`, `max`, and `step` attributes
2. Consider the precision needed for your numeric values
3. Use appropriate input widths based on the expected range of values
4. Provide clear labels describing what the number represents
5. Consider using the currency variant for monetary values

## Accessibility Considerations

- Ensure increment/decrement buttons have appropriate aria labels
- Control buttons should be large enough to be easily clickable
- Provide keyboard access to all functions
- Consider adding aria-valuemin, aria-valuemax, and aria-valuenow for screen readers
- Respect user preferences for reduced motion

## Implementation Notes

- JavaScript is required to make the increment/decrement buttons functional
- The component works best when combined with form-input styles
- Browser implementations of number inputs can vary; this component provides consistent styling
- The currency variant prepends a currency symbol but you may need to format the value for display
- Touch-friendly variant increases button size for better mobile usability