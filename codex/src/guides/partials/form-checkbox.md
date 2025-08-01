# Form Checkbox

Accessible, customizable checkbox input with variants.

## Overview

The form-checkbox component provides styled checkbox inputs that maintain accessibility while offering visual customization options. It includes variants for different visual styles and states.

## Usage

```html
<!-- Basic checkbox -->
<div class="form-checkbox">
  <input class="form-checkbox__input" type="checkbox" id="checkbox1" name="checkbox1">
  <label class="form-checkbox__label" for="checkbox1">Default checkbox</label>
</div>

<!-- Checked state -->
<div class="form-checkbox">
  <input class="form-checkbox__input" type="checkbox" id="checkbox2" name="checkbox2" checked>
  <label class="form-checkbox__label" for="checkbox2">Checked checkbox</label>
</div>

<!-- Disabled state -->
<div class="form-checkbox">
  <input class="form-checkbox__input" type="checkbox" id="checkbox3" name="checkbox3" disabled>
  <label class="form-checkbox__label" for="checkbox3">Disabled checkbox</label>
</div>

<!-- Toggle variant -->
<div class="form-checkbox form-checkbox--toggle">
  <input class="form-checkbox__input" type="checkbox" id="toggle1" name="toggle1">
  <label class="form-checkbox__label" for="toggle1">Toggle switch</label>
</div>

<!-- Switch variant -->
<div class="form-checkbox form-checkbox--switch">
  <input class="form-checkbox__input" type="checkbox" id="switch1" name="switch1">
  <label class="form-checkbox__label" for="switch1">Switch control</label>
</div>

<!-- Strikethrough variant (text gets strikethrough when checked) -->
<div class="form-checkbox form-checkbox--strikethrough">
  <input class="form-checkbox__input" type="checkbox" id="strike1" name="strike1">
  <label class="form-checkbox__label" for="strike1">Strikethrough when checked</label>
</div>

<!-- Colored variants -->
<div class="form-checkbox form-checkbox--primary">
  <input class="form-checkbox__input" type="checkbox" id="primary" name="primary">
  <label class="form-checkbox__label" for="primary">Primary color</label>
</div>

<div class="form-checkbox form-checkbox--secondary">
  <input class="form-checkbox__input" type="checkbox" id="secondary" name="secondary">
  <label class="form-checkbox__label" for="secondary">Secondary color</label>
</div>
```

## Component Structure

The form-checkbox component uses a wrapper with input and label elements:

```
.form-checkbox
  ├── .form-checkbox__input
  └── .form-checkbox__label
```

## Variants

### Style Variants

- Default: Standard checkbox with custom styling
- `form-checkbox--toggle`: Toggle switch style
- `form-checkbox--switch`: Alternative switch style
- `form-checkbox--strikethrough`: Strikes through label text when checked

### Color Variants

- Default: Uses primary color
- `form-checkbox--primary`: Primary color (same as default)
- `form-checkbox--secondary`: Secondary color
- `form-checkbox--success`: Success color
- `form-checkbox--danger`: Danger/error color
- `form-checkbox--warning`: Warning color
- `form-checkbox--info`: Info color
- `form-checkbox--notice`: Notice color
- `form-checkbox--muted`: Subdued/muted color

## States

- Unchecked: Default state
- Checked: When the checkbox is selected
- Disabled: When the checkbox is not interactive
- Focus: When the checkbox receives keyboard focus
- Indeterminate: Can be set via JavaScript for partial selection

## Accessibility

- Maintains native checkbox behavior for screen readers
- Provides visible focus states
- Preserves keyboard navigation
- Maintains sufficient color contrast for all states
- Uses properly associated labels

## JavaScript Integration

To set the indeterminate state:

```js
document.getElementById('checkbox1').indeterminate = true;
```

For the strikethrough variant, the styling is automatically applied when the checkbox is checked.

## Customization

The component uses CSS custom properties that can be overridden:

```css
.form-checkbox {
  --check-size: 1.25em;
  --check-bg: #fff;
  --check-border-color: var(--color-border);
  --check-border-radius: 0.25em;
  --check-color: var(--color-primary);
  /* Additional custom properties available */
}
```