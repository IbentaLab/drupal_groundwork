# Border Utilities

The Groundwork framework provides a flexible, composable system for adding borders to blocks and elements. Instead of having one class for every possible border combination, you can combine independent utilities for  **width** ,  **style** , and **color** to create exactly the look you need.

## Core Concept: A Composable System

Creating a custom border involves combining up to three different types of classes:

1. **Application & Width:** First, you decide *where* the border should be and how *thick* it is (e.g., `.border-b-4` for a thick bottom border).
2. **Style:** Next, you can optionally define a style (e.g., `.border-dashed`). If you don't specify a style, it will default to solid.
3. **Color:** Finally, you can apply a color from the `color-utilities.css` library (e.g., `.red-border`). If you don't specify a color, it will use the theme's default border color.

This approach gives you complete creative control. For example, to create a thick, dashed, red bottom border, you would simply combine `.border-b-4`, `.border-dashed`, and `.red-border`.

## Tutorial for All Users

This guide shows you how to add and style borders on a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply border styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place any block with content into a region.

#### Step 2: Apply Border Classes

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI where you can compose your border.

Let's create a decorative left "bar" on a block that is thick, dotted, and uses the site's primary color.

* First, select **`.border-l-8`** to apply a thick, 8px border to the left side.
* Next, select **`.border-dotted`** to change the style.
* Finally, select a color utility like **`.primary-border`** (if you have one) or **`.blue-border`** to set the color.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the classes directly into the text field (e.g., `border-l-8 border-dotted blue-border`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Apply a custom border to a specific block.
  if ($variables['plugin_id'] == 'my_special_block') {
    $variables['attributes']['class'][] = 'border-l-8';
    $variables['attributes']['class'][] = 'border-dotted';
    $variables['attributes']['class'][] = 'blue-border';
  }
}

```

## Class Reference

### Default Border Application (BSCs)

These classes apply a `1px solid` border using the theme's default border color. They are a great starting point.

| **Class**         | **Description**                |
| ----------------------- | ------------------------------------ |
| **`.border`**   | Applies a border to all four sides.  |
| **`.border-t`** | Applies a border to the top only.    |
| **`.border-b`** | Applies a border to the bottom only. |
| **`.border-l`** | Applies a border to the left only.   |
| **`.border-r`** | Applies a border to the right only.  |

### Border Width Utilities (Atomic)

These classes **only** control the border's thickness. They can be applied to any element.

| **Class**                                 | **Description**              |
| ----------------------------------------------- | ---------------------------------- |
| `.border-2`/`.border-4`/`.border-8`       | Sets the width for all sides.      |
| `.border-t-2`/`.border-t-4`/`.border-t-8` | Sets the top border width only.    |
| `.border-b-2`/`.border-b-4`/`.border-b-8` | Sets the bottom border width only. |
| `.border-l-2`/`.border-l-4`/`.border-l-8` | Sets the left border width only.   |
| `.border-r-2`/`.border-r-4`/`.border-r-8` | Sets the right border width only.  |

### Border Style Utilities (BSCs)

These classes **only** control the border's visual style.

| **Class**              | **Description**   |
| ---------------------------- | ----------------------- |
| **`.border-solid`**  | A solid line (default). |
| **`.border-dashed`** | A series of dashes.     |
| **`.border-dotted`** | A series of dots.       |
| **`.border-none`**   | Removes all borders.    |

*(Note: Border color is controlled by the separate `color-utilities.css` file, using classes like `.blue-border`, `.red-border`, etc.)*
