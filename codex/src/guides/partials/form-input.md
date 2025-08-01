# Form Input Partial (`form-input.css`)

The `form-input` partial is a flexible, accessible, and themeable UI fragment designed for text input fields. It supports a wide range of design variants to accommodate various use cases, ensuring consistency with the Groundwork design system.

---

## 🎨 Features

- Fully themeable (light/dark mode supported via tokens).
- Accessibility-first: Focus styles, placeholder visibility, and disabled states built-in.
- Highly customizable with size, color, state, shape, and layout variants.
- Prefix and suffix support for icons or labels.
- Additional effects like glow and elevated styles.

---

## 🔧 Usage

Include the `form-input.css` file in your project and apply the `form-input` class to your input elements. Customize further using the design variants listed below.

### Basic Example

```html
<input type="text" class="form-input" placeholder="Enter your name">
```

### Advanced Example (with Variants)

```html
<div class="form-input-wrapper">
  <span class="form-input__prefix">$</span>
  <input type="text" class="form-input form-input--lg form-input--primary form-input--pill" placeholder="Enter amount">
  <span class="form-input__suffix">.00</span>
</div>
```

---

## 📏 Supported Variants

### 1. **🎨 Color Variants**

- `form-input--primary`: Primary border color.
- `form-input--success`: Success (green) border color.
- `form-input--danger`: Error (red) border color.
- `form-input--warning`: Warning (yellow) border color.
- `form-input--muted`: Muted (gray) border color.

### 2. **📏 Size Variants**

- `form-input--xs`: Extra small.
- `form-input--sm`: Small.
- `form-input` (default): Medium.
- `form-input--lg`: Large.
- `form-input--xl`: Extra large.
- `form-input--xxl`: Double extra large.

### 3. **✳️ State Variants**

- `is-invalid`: Highlights the input in red for errors.
- `is-valid`: Highlights the input in green for successful validation.
- `is-warning`: Highlights the input in yellow for warnings.
- `is-disabled`: Applies disabled styles.
- `is-readonly`: Styles for read-only input fields.

### 4. **⬜ Shape Variants**

- `form-input--rounded`: Slightly rounded corners.
- `form-input--pill`: Fully rounded corners for a pill-shaped input.

### 5. **🧠 Layout Variants**

- `form-input--inline`: Aligns the input inline with other elements.
- `form-input--stacked`: Ensures the input field is stacked and full-width.

### 6. **💡 Additional Variants**

- `form-input--has-prefix`: Adds padding for a prefix (e.g., `$` or an icon).
- `form-input--has-suffix`: Adds padding for a suffix (e.g., `.00` or an icon).
- `form-input--glow`: Adds a glowing effect on focus for better visibility.
- `form-input--elevated`: Adds a shadow to the input for elevation.
- `form-input--transparent`: Removes the background, making the input blend with the surrounding design.

---

## 💻 Example HTML

### Rounded Input

```html
<input type="text" class="form-input form-input--rounded" placeholder="Enter your name">
```

### Pill Input

```html
<input type="text" class="form-input form-input--pill" placeholder="Search">
```

### Input with Validation States

```html
<input type="text" class="form-input is-invalid" placeholder="Invalid input">
<input type="text" class="form-input is-valid" placeholder="Valid input">
<input type="text" class="form-input is-warning" placeholder="Warning input">
```

### Input with Prefix and Suffix

```html
<div class="form-input-wrapper">
  <span class="form-input__prefix">$</span>
  <input type="text" class="form-input form-input--has-prefix" placeholder="Amount">
  <span class="form-input__suffix">.00</span>
</div>
```

---

## 🛠️ Notes for Developers

1. **Tokenized Variables:** All styles use `groundwork-tokens.css` for consistent themeability.
2. **Light/Dark Support:** Ensure your design tokens (`--color-*`) are configured for both light and dark themes.
3. **Accessibility:** Inputs include proper focus styles and placeholder visibility for accessibility.

---

## 🧪 Testing Checklist

- [X] Light and dark theme compatibility.
- [X] Validation states (invalid, valid, warning).
- [X] Prefix and suffix alignment.
- [X] Responsiveness across size variants.
- [X] Accessibility for disabled/read-only inputs.

---

## 📄 License

This partial is part of the Groundwork framework and is licensed under the MIT License. See the [LICENSE.md](../LICENSE.md) file for more details.
