# SVG Styling Utilities

These utilities are designed to make styling inline SVG icons effortless. The framework provides two powerful methods for styling SVGs: a **dynamic** approach for icons that inherit text color, and a **static** approach for setting a specific brand color.

## Core Concept: Atomic vs. BSC

The SVG utilities are unique because they can be used in two ways:

1. **Atomically (on a single `<svg>`):** When you apply a class like `.svg-fill-blue` directly to an `<svg>` tag, it styles only that specific icon. This is for precision.
2. **As a BSC (on a block):** When you apply the same class to a block, it styles **every single SVG** inside that block. This is for convenience and creating a uniform look.

## Method 1: Dynamic Color (`currentColor`)

This is the most flexible method, used for icons that need to dynamically match the color of the text they are inside (e.g., an icon in a link that changes color on hover).

### Tutorial

#### Step 1: Place an Inline SVG in Your Content

In your content editor's "Source" view, place an inline SVG inside a link or a paragraph.

```
<!-- This content goes inside your block's body field -->
<a href="#" class="blue-text">
  <!-- Apply the class directly to the SVG tag -->
  <svg class="svg-fill-current" ...> <!-- SVG code here --> </svg>
  Click Me
</a>

```

#### Step 2: Apply the Utility

Add the `.svg-fill-current` class directly to the `<svg>` tag as shown above.

### The Result

The SVG icon will now automatically be blue, matching its parent link. If the link color changes on hover, the SVG color will change too.

## Method 2: Static Color (Brand Colors)

This method is a convenient shortcut for blocks that contain many icons that should all have the same, specific color, such as a "list of features."

### Tutorial

#### Step 1: Place a Block with Multiple SVGs

Place a block that contains several inline SVG icons.

#### Step 2: Apply the BSC in the Block Styles UI

Click "Configure" on the block and navigate to the **Styles** tab. In the UI, select a color-specific class like  **`.svg-fill-blue`** .

### The Result

Every single SVG inside that block will now have a blue fill color, providing a uniform look for all icons. This color is static and will not change based on the surrounding text color.

## Class Reference

### Dynamic Color Utilities (Atomic & BSC)

| **Class**                   | **Description**                                     |
| --------------------------------- | --------------------------------------------------------- |
| **`.svg-fill-current`**   | Sets the `fill`color to match the current text color.   |
| **`.svg-stroke-current`** | Sets the `stroke`color to match the current text color. |

### Static Color Utilities (Atomic & BSC)

| **Class**                   | **Description**                                                          |
| --------------------------------- | ------------------------------------------------------------------------------ |
| **`.svg-fill-[color]`**   | Sets the `fill`color to a specific brand color (e.g.,`.svg-fill-blue`).    |
| **`.svg-stroke-[color]`** | Sets the `stroke`color to a specific brand color (e.g.,`.svg-stroke-red`). |

*(Note: `[color]` can be replaced with any of the primary brand colors from your theme: `blue`, `red`, `green`, `orange`, `purple`, etc.)*
