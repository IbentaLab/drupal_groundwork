# Groundwork Grid System

The Groundwork Grid System is a powerful yet beginner-friendly layout engine built into the Groundwork theme. It allows you to create flexible, responsive, and accessible layouts using simple building blocks. Whether you're a site builder who never touches code or a front-end developer looking for atomic control, the grid system gives you tools that just work—out of the box.

---

## 🚀 What is the Groundwork Grid System?

The Groundwork Grid System is based on a 12-column layout model. It divides each row (or region) into 12 equal parts. You can then decide how many of those parts a block should take up.

For example:

- A block with `is-6` spans 6 out of 12 columns (50% width).
- A block with `is-3` spans 3 out of 12 columns (25% width).

Each region in Groundwork is treated as a **grid container**, and every block placed inside that region automatically becomes a **grid cell**.

This setup makes it easy to build clean, responsive layouts without needing custom templates or hand-written CSS.

You can use layout utility classes to:

- Define how wide a block should be
- Align it vertically
- Reorder it on different screen sizes
- Create gaps and offsets between blocks

---

## 🧱 Key Concepts

### 1. `.grid` (Container)

This class is automatically applied to Groundwork regions. It enables flexbox layout and wraps its children into a row-based system.

### 2. `.grid-cell` (Item)

All blocks in Groundwork automatically get this class. These are your columns—the things you move, size, and align.

You never need to manually add `.grid` or `.grid-cell` classes. The theme does this for you.

---

## 📐 How to Use It Without Code

Whether you're building a simple landing page or a complex homepage layout, the Grid System is made to work visually through the admin interface. You won’t need to touch code or adjust templates manually.

You don’t need to be a developer or know CSS. Groundwork was built so that layout changes can be done visually, using the admin UI.

If you’re a site builder using Layout Builder or the Block Layout UI, you can control layout using:

- ✅ **Block Styles UI** (preferred)
- ✅ Other modules that allow custom classes on blocks

### Example: Make a block take half the width

1. Edit the block in Layout Builder or the Block Layout UI.
2. Open the Block Styles tab.
3. Find the "Grid Cell Width" category.
4. Select `is-half` from the dropdown.

This class tells the grid system that the block should take up 6 out of 12 columns, or half of the total width. It's especially useful for placing two blocks side by side, like a menu and a logo, or an image next to a paragraph.

### Example: Reorder blocks on mobile

1. Use `order-1--s`, `order-2--s`, etc. to change the block's visual position when viewed on smaller screens (like phones).
2. For stronger placement control, use `order-first--s` or `order-last--s`.

This does not affect the order in which the blocks appear in the backend—only how they are visually arranged in the browser. It's great for creating mobile-first layouts where you want content to appear in a different order than on desktop.

### Example: Vertically center a block

1. Choose `align-middle` in the Block Styles UI.

This class aligns the **block itself** to the vertical center of the row. If the row contains other blocks of different heights, this block will align to their middle.

However, this only affects the **outer block container**. If you want to center the **text or image inside the block**, you may also need to:

- Add `text-center` for centering text horizontally
- Use custom styles or layout tools for full content alignment

---

## 🎨 Responsive Widths

Groundwork supports mobile-first design. This means you can change how blocks behave depending on screen size—without using breakpoints or writing code.

You can change widths per screen size using responsive suffixes:

- `is-6` → 50% width on medium screens and up
- `is-6--s` → 50% on small screens
- `is-6--l` → 50% on large screens

### Semantic shortcuts:

- `is-half` = `is-6`
- `is-third` = `is-4`
- `is-quarter` = `is-3`

You can mix and match:

```html
is-12 is-6--s is-4--l
```

> Full width by default, 50% on small screens, 33% on large.

---

## ↕ Alignment Options

Use these classes to align the **block itself** (the `.grid-cell`) vertically relative to other blocks in the same row. This is useful when you have rows where the blocks are different heights—for example, an image beside a paragraph. You can decide if each block should stick to the top, bottom, middle, or stretch to match its neighbors.

- `align-top` – aligns the block to the top of the row. Good for headings or content that should start from the top.
- `align-middle` – centers the block vertically between taller blocks. Great for logos, buttons, or icons.
- `align-bottom` – places the block at the bottom of the row.
- `align-stretch` – stretches the block’s height to match the tallest block in the row. – align the block to the top of the row
- `align-middle` – center the block vertically
- `align-bottom` – align the block to the bottom
- `align-stretch` – make the block match the tallest block in the row

---

## 🔁 Reordering Blocks

Sometimes you may want blocks to appear in a different order on different screen sizes—for example, showing a call-to-action button at the top of the page on mobile, but placing it at the bottom on desktop.

Use these classes to change visual order without changing the actual content structure:

- `order-1`, `order-2`, etc. – set the position of a block in its row.
- `order-first` – force the block to be first.
- `order-last` – force the block to be last.

You can also make it responsive:

- `order-1--s` – order for small screens (like mobile)
- `order-last--l` – order for large screens

These utilities help you build mobile-first layouts that adapt intelligently. entire layouts without changing the source content.

---

## ⬅️ Offsets

Sometimes you want to create space between blocks or intentionally shift one to the right to achieve a layout like centering or spacing.

Use offset utility classes to add left margin to a block (as a percentage of the grid):

- `is-offset-1` → adds a left margin of 1 column (8.333%)
- `is-offset-6` → pushes the block halfway across the row
- `is-offset-3--l` → adds a 3-column offset on large screens only

Offsets are perfect for spacing out blocks without using empty spacer blocks or complex nested layouts. to the right? Use offset classes like:

- `is-offset-1` → adds left margin equal to 1 column
- `is-offset-3--l` → push right on large screens only

---

## ⚙️ Advanced Layout Utilities (Optional for Themers)

If you're a front-end developer or themer looking for more flexible behavior, Groundwork includes utility classes based on native flexbox properties.

- `col-auto` – sizes the block based on its content. Great for buttons or logos that shouldn't stretch.
- `col-fill` – expands the block to fill remaining space in the row.
- `col-grow` – allows the block to grow when space is available.
- `col-shrink` – allows the block to shrink when space is tight.

These give you atomic-level layout control for more dynamic and content-aware designs. or themer, you can use:

- `.col-auto` → fits to content
- `.col-fill` → fills remaining space
- `.col-grow` / `.col-shrink` → grow/shrink responsively

These give you fine control over how blocks behave in flexible layouts.

---

## 🧩 Combining Utilities

You can combine different utility classes on the same block to get more precise control over layout. This is especially helpful when you're working with multiple screen sizes or complex alignments.

Grid classes are atomic—you can combine them:

```html
is-half align-middle order-last
```

This means:

- Take half width
- Center vertically
- Go to the end of the row

---

## 📋 Class Reference Table

| Feature       | Class Example           | Notes                      |
| ------------- | ----------------------- | -------------------------- |
| Width         | `is-6`, `is-half`       | 12-column grid             |
| Responsive    | `is-4--l`               | Width on large screen      |
| Offset        | `is-offset-3`           | Push block right           |
| Alignment     | `align-middle`          | Vertical centering         |
| Order         | `order-2`, `order-last` | Control block sequence     |
| Flex behavior | `col-auto`, `col-fill`  | Optional, advanced control |

---

## 🧾 Full Class List

Below is a complete reference of utility classes available in the Groundwork Grid System. These classes can be used individually or in combination for powerful, responsive layouts.

### 📏 Widths (Grid Cell Size)

#### Medium (default)

- `is-1` to `is-12`
- `is-half` → `is-6`
- `is-third` → `is-4`
- `is-quarter` → `is-3`

#### Small (≤780px)

- `is-1--s` to `is-12--s`
- `is-half--s`, `is-third--s`, `is-quarter--s`

#### Large (≥1200px)

- `is-1--l` to `is-12--l`
- `is-half--l`, `is-third--l`, `is-quarter--l`

### ↕ Vertical Alignment

- `align-top`
- `align-middle`
- `align-bottom`
- `align-stretch`

### 🔁 Order Utilities

- `order-1`, `order-2`, …
- `order-first`, `order-last`
- `order-1--s`, `order-last--l`

### ⬅️ Offsets

- `is-offset-1` to `is-offset-11`
- Responsive: `is-offset-1--s`, `is-offset-2--l`, etc.

### ⚙️ Flex Behavior (Advanced)

- `col-auto`
- `col-fill`
- `col-grow`
- `col-shrink`

You can mix multiple classes together for responsive and adaptive layout behavior like:

```html
is-half align-middle order-2--s col-grow
```

This gives you flexible layout control that works across all screen sizes.

## ✅ Quick Recap for Site Builders

- Use the **Block Styles UI** to apply layout behaviors
- All Groundwork blocks and regions are already grid-ready
- You don’t need to write code—just apply the right class
- The system is responsive, accessible, and works everywhere

Let Groundwork’s grid system handle the layout—so you can focus on the content.

