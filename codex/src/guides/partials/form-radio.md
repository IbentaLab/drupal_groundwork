# Form Radio Partial (`form-radio.css`)

The `form-radio` partial is a flexible, accessible, and themeable UI fragment designed for radio button inputs. It supports a wide range of design variants and shapes to accommodate different use cases while ensuring consistency with the Groundwork design system.

---

## 🎨 Features

- Fully themeable (light/dark mode supported via tokens).
- Accessibility-first: Focus styles, disabled states, and user-friendly interactions.
- Highly customizable with size, color, state, shape, and layout variants.
- Includes unconventional shapes like square, toggle, and capsule/pill.
- Supports inline and stacked layouts for flexibility.

---

## 🔧 Usage

Include the `form-radio.css` file in your project and apply the `form-radio` class to your radio button elements. Customize further using the design variants listed below.

### Basic Example

```html
<div class="form-radio">
  <input type="radio" id="radio1" name="example" class="form-radio__input">
  <label for="radio1" class="form-radio__label">Option 1</label>
</div>
```

### Advanced Example (with Variants)

```html
<div class="form-radio form-radio--pill form-radio--success">
  <input type="radio" id="radio-pill1" name="category" class="form-radio__input">
  <label for="radio-pill1" class="form-radio__label">Category 1</label>
</div>
```

---

## 📏 Supported Variants

### 1. **🎨 Color Variants**

- **`form-radio--primary`**: Primary color for the checked state.
- **`form-radio--success`**: Success (green) for checked state.
- **`form-radio--danger`**: Error (red) for checked state.
- **`form-radio--warning`**: Warning (yellow) for checked state.
- **`form-radio--muted`**: Muted (gray) for checked state.

### 2. **📏 Size Variants**

- **`form-radio--xs`**: Extra small.
- **`form-radio--sm`**: Small.
- **`form-radio` (default)**: Medium.
- **`form-radio--lg`**: Large.
- **`form-radio--xl`**: Extra large.
- **`form-radio--xxl`**: Double extra large.

### 3. **✳️ State Variants**

- **`is-invalid`**: Highlights the radio in red for errors.
- **`is-valid`**: Highlights the radio in green for success.
- **`is-warning`**: Highlights the radio in yellow for warnings.
- **`form-radio__input:disabled`**: Styles for disabled radio buttons.

### 4. **⬜ Shape Variants**

- **`form-radio--square`**: Square-shaped radio buttons.
- **`form-radio--toggle`**: Toggle-style radios for switch-like functionality.
- **`form-radio--pill`**: Capsule-shaped (pill) radio buttons for text-based options.

### 5. **🧠 Layout Variants**

- **`form-radio--inline`**: Displays radio buttons inline.
- **`form-radio--stacked`**: Stacks radio buttons vertically.

---

## 💻 Example HTML

### Square Radio Button

```html
<div class="form-radio form-radio--square">
  <input type="radio" id="radio-square1" name="example" class="form-radio__input">
  <label for="radio-square1" class="form-radio__label">Square Option</label>
</div>
```

### Toggle Radio Button

```html
<div class="form-radio form-radio--toggle">
  <input type="radio" id="radio-toggle1" name="toggle-example" class="form-radio__input">
  <label for="radio-toggle1" class="form-radio__label">Toggle Option</label>
</div>
```

### Capsule/Pill Radio Button

```html
<div class="form-radio form-radio--pill">
  <input type="radio" id="radio-pill1" name="pill-example" class="form-radio__input">
  <label for="radio-pill1" class="form-radio__label">Pill Option</label>
</div>
```

### Inline and Stacked Radio Buttons

```html
<!-- Inline -->
<div class="form-radio form-radio--inline">
  <input type="radio" id="radio-inline1" name="example" class="form-radio__input">
  <label for="radio-inline1" class="form-radio__label">Option 1</label>

  <input type="radio" id="radio-inline2" name="example" class="form-radio__input">
  <label for="radio-inline2" class="form-radio__label">Option 2</label>
</div>

<!-- Stacked -->
<div class="form-radio form-radio--stacked">
  <input type="radio" id="radio-stacked1" name="example" class="form-radio__input">
  <label for="radio-stacked1" class="form-radio__label">Option 1</label>

  <input type="radio" id="radio-stacked2" name="example" class="form-radio__input">
  <label for="radio-stacked2" class="form-radio__label">Option 2</label>
</div>
```

---

## 🛠️ Notes for Developers

1. **Tokenized Variables:** All styles use `groundwork-tokens.css` for consistent themeability.
2. **Light/Dark Support:** Ensure your design tokens (`--color-*`) are configured for both light and dark themes.
3. **Accessibility:** Radios include proper focus styles and user-friendly interactions.

---

## 🧪 Testing Checklist

- [X] Light and dark theme compatibility.
- [X] Validation states (invalid, valid, warning).
- [X] Square, toggle, and pill shapes render as expected.
- [X] Responsiveness across size variants.
- [X] Accessibility for disabled and focus states.
