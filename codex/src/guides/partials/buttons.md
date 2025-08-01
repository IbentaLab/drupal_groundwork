# Buttons

Modern, accessible buttons with multiple variants and states.

## Overview

The button component provides a comprehensive set of styles for interactive elements. It supports multiple colors, states, and variants to suit different UI needs while maintaining accessibility and visual consistency.

## Usage

```html
<!-- Default (primary) button -->
<button class="button">Default Button</button>

<!-- Color variants -->
<button class="button button--secondary">Secondary</button>
<button class="button button--success">Success</button>
<button class="button button--danger">Danger</button>
<button class="button button--warning">Warning</button>
<button class="button button--info">Info</button>
<button class="button button--notice">Notice</button>
<button class="button button--muted">Muted</button>

<!-- Style variants -->
<button class="button button--ghost">Ghost</button>
<button class="button button--outline">Outline</button>
<button class="button button--light button--primary">Light Primary</button>
<button class="button button--gradient">Gradient</button>
<button class="button button--pill">Pill</button>
<button class="button button--glow">Glow</button>

<!-- Size variants -->
<button class="button button--xs">Extra Small</button>
<button class="button button--sm">Small</button>
<button class="button">Medium (default)</button>
<button class="button button--lg">Large</button>
<button class="button button--xl">Extra Large</button>
<button class="button button--xxl">XXL</button>
<button class="button button--block">Block</button>
<button class="button button--icon">
  <svg><!-- icon --></svg>
</button>

<!-- States -->
<button class="button" disabled>Disabled</button>
<button class="button button--loading">Loading</button>

<!-- Button groups -->
<div class="button-group">
  <button class="button">Left</button>
  <button class="button">Middle</button>
  <button class="button">Right</button>
</div>

<!-- Layout button groups -->
<div class="btn-group btn-group--center">
  <button class="button">First</button>
  <button class="button">Second</button>
</div>
```

## Component Structure

The button component uses a system of CSS custom properties to define its appearance, making it highly customizable:

```css
.button {
  --button-bg: var(--color-primary);
  --button-text: var(--white);
  --button-border-color: transparent;
  /* ...additional variables... */
}
```

## Variants

### Color Variants

- `button--primary` (default)
- `button--secondary`
- `button--success`
- `button--danger`
- `button--warning`
- `button--info`
- `button--notice`
- `button--muted`

### Style Variants

- `button--ghost`: Transparent background with colored border
- `button--outline`: Neutral outline button
- `button--light`: Light colored background with dark text
- `button--gradient`: Animated gradient background
- `button--pill`: Fully rounded corners
- `button--glow`: Subtle glow effect around the button

### Size Variants

- `button--xs`: Extra small
- `button--sm`: Small
- `button--md`: Medium (default)
- `button--lg`: Large
- `button--xl`: Extra large
- `button--xxl`: XXL size
- `button--block`: Full width button
- `button--icon`: Square button for icons

## States

- Default: Normal button state
- `:hover`: When mouse is over the button
- `:focus-visible`: When button receives keyboard focus
- `:active`: When button is being pressed
- `:disabled`: When button is disabled
- `button--loading`: Shows a loading spinner

## Button Groups

### Connected Button Group

The `.button-group` class creates a set of connected buttons with shared borders:

```html
<div class="button-group">
  <button class="button">Left</button>
  <button class="button">Middle</button>
  <button class="button">Right</button>
</div>
```

### Layout Button Group

The `.btn-group` utility classes help arrange groups of separate buttons:

```html
<div class="btn-group btn-group--center">
  <button class="button">First</button>
  <button class="button">Second</button>
</div>
```

Available modifiers:
- Alignment: `btn-group--start`, `btn-group--center`, `btn-group--end`, `btn-group--between`, `btn-group--around`
- Direction: `btn-group--vertical`
- Spacing: `btn-group--sm`, `btn-group--lg`
- Responsive: `btn-group--responsive`, `mobile-full`

## Accessibility

- All buttons maintain WCAG 2.1 AA contrast requirements
- Focus states are clearly visible
- Loading states prevent multiple submissions
- Text remains visible during loading for screen readers
- Disabled states are visually distinct

## JavaScript Integration

The ripple effect and loading state can be triggered via JavaScript:

```js
// Add loading state
document.querySelector('.button').classList.add('button--loading');

// Remove loading state
document.querySelector('.button').classList.remove('button--loading');
```