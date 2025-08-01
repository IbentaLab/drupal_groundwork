# Form Rating Component

## Overview
The Form Rating component allows users to select a rating from a set of options, typically displayed as stars, numbers, or other symbols. It can be used for both input (collecting ratings) and display (showing ratings).

## Basic Usage

```html
<!-- Basic star rating input -->
<div class="form-rating">
  <div class="form-rating__group">
    <input class="form-rating__input" type="radio" id="rating5" name="rating" value="5">
    <label class="form-rating__label" for="rating5">★</label>
    <input class="form-rating__input" type="radio" id="rating4" name="rating" value="4">
    <label class="form-rating__label" for="rating4">★</label>
    <input class="form-rating__input" type="radio" id="rating3" name="rating" value="3">
    <label class="form-rating__label" for="rating3">★</label>
    <input class="form-rating__input" type="radio" id="rating2" name="rating" value="2">
    <label class="form-rating__label" for="rating2">★</label>
    <input class="form-rating__input" type="radio" id="rating1" name="rating" value="1">
    <label class="form-rating__label" for="rating1">★</label>
  </div>
</div>

<!-- Display-only rating (3 out of 5) -->
<div class="form-rating form-rating--readonly" data-rating="3">
  <div class="form-rating__group">
    <label class="form-rating__label">★</label>
    <label class="form-rating__label">★</label>
    <label class="form-rating__label">★</label>
    <label class="form-rating__label">★</label>
    <label class="form-rating__label">★</label>
  </div>
</div>

<!-- Emoji rating -->
<div class="form-rating form-rating--emoji">
  <div class="form-rating__group">
    <input class="form-rating__input" type="radio" id="emoji5" name="emoji-rating" value="5">
    <label class="form-rating__label" for="emoji5"></label>
    <input class="form-rating__input" type="radio" id="emoji4" name="emoji-rating" value="4">
    <label class="form-rating__label" for="emoji4"></label>
    <input class="form-rating__input" type="radio" id="emoji3" name="emoji-rating" value="3">
    <label class="form-rating__label" for="emoji3"></label>
    <input class="form-rating__input" type="radio" id="emoji2" name="emoji-rating" value="2">
    <label class="form-rating__label" for="emoji2"></label>
    <input class="form-rating__input" type="radio" id="emoji1" name="emoji-rating" value="1">
    <label class="form-rating__label" for="emoji1"></label>
  </div>
</div>

<!-- With visible value -->
<div class="form-rating form-rating--with-value">
  <div class="form-rating__group">
    <!-- Star rating inputs here -->
  </div>
  <span class="form-rating__value">4.2</span>
</div>
```

## Variants

### Color Variants
- Default - Uses warning color (typically yellow/gold for stars)
- `form-rating--primary` - Primary theme color
- `form-rating--secondary` - Secondary theme color
- `form-rating--info` - Information theme color
- `form-rating--notice` - Notice theme color
- `form-rating--success` - Success theme color
- `form-rating--danger` - Danger theme color
- `form-rating--warning` - Warning theme color (default for stars)
- `form-rating--muted` - Muted theme color

### Size Variants
- `form-rating--xs` - Extra small rating
- `form-rating--sm` - Small rating
- `form-rating--md` (default) - Medium rating
- `form-rating--lg` - Large rating
- `form-rating--xl` - Extra large rating
- `form-rating--xxl` - Extra extra large rating

### Type Variants
- Default (stars) - Star rating symbols
- `form-rating--emoji` - Emoji-based rating
- `form-rating--hearts` - Heart symbols rating
- `form-rating--thumbs` - Thumbs up/down rating
- `form-rating--numeric` - Numeric rating

### Layout Variants
- Default - Stars side by side
- `form-rating--compact` - No spacing between items
- `form-rating--with-value` - Shows numeric value alongside stars
- `form-rating--inline` - For inline display with text

### Scale Variants
- Default - 5-point scale
- `form-rating--scale-10` - 10-point scale
- `form-rating--scale-100` - Percentage scale (slider)

## Best Practices

1. Use clear, recognizable symbols for the rating scale
2. Provide a label explaining what is being rated
3. Consider allowing half-star ratings for more precision when needed
4. Show both the graphical rating and numeric value for clarity
5. Use appropriate color coding (yellow/gold for stars is conventional)
6. For readonly ratings, clearly differentiate from interactive ones

## Accessibility Considerations

- Ensure rating widgets are keyboard accessible
- Provide proper form labels describing what's being rated
- Include text alternatives for visual rating displays
- Group related form elements with fieldset and legend
- Consider using aria-valuemin, aria-valuemax, and aria-valuenow for screen readers

## Implementation Notes

- The component uses hidden radio inputs for the interactive rating
- The reverse ordering of elements creates the "fill from the right" visual effect
- JavaScript is needed to fully implement hover effects and to update the display value
- For readonly ratings, use the data-rating attribute to set the display value
- The emoji and other symbol variants need font/Unicode support in the user's browser