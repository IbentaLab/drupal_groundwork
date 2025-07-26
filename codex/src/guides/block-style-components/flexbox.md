# Flexbox Utilities

Flexbox utilities are a powerful set of tools for controlling the alignment, direction, and flow of content  **inside a flex container** . These utilities are the essential companions to the `.d-flex` class.

## Core Concept: The Flex Container

To use any of the utilities in this file, you must first turn a block's content area into a flex container. You do this by applying the **`.d-flex`** class (from `display.css`) to the block.

Once `.d-flex` is applied, the direct children inside the block's content become "flex items," and you can use the classes below to control how they are arranged.

## Tutorial for All Users

This guide shows you how to align content within a block using Flexbox.

### Recommended Method: Using the Block Styles UI

The easiest way to apply flexbox styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block and Add Content

Place a block and add at least two distinct elements inside it, such as an image and a paragraph of text.

#### Step 2: Enable Flexbox and Apply Alignment

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

Let's align the image and text side-by-side and center them vertically.

1. First, select **`.d-flex`** to enable the flex container. By default, this will place the image and text in a row.
2. Next, select **`.items-center`** to vertically align them.
3. You might also want to add a gap between them. Select a class like **`.gap-3`** from the `gap.css` utilities.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the classes directly into the text field (e.g., `d-flex items-center gap-3`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Vertically align content for a specific block.
  if ($variables['plugin_id'] == 'my_image_and_text_block') {
    $variables['attributes']['class'][] = 'd-flex';
    $variables['attributes']['class'][] = 'items-center';
    $variables['attributes']['class'][] = 'gap-3';
  }
}

```

## Class Reference

### Flex Direction (BSCs)

| **Class**                 | **Description**                         |
| ------------------------------- | --------------------------------------------- |
| **`.flex-row`**         | Arranges items horizontally (default).        |
| **`.flex-col`**         | Stacks items vertically.                      |
| **`.flex-row-reverse`** | Arranges items horizontally in reverse order. |
| **`.flex-col-reverse`** | Stacks items vertically in reverse order.     |

### Align Items (BSCs)

Controls vertical alignment if `flex-direction` is `row`, or horizontal alignment if `flex-direction` is `col`.

| **Class**             | **Description**       |
| --------------------------- | --------------------------- |
| **`.items-start`**  | Aligns items to the start.  |
| **`.items-center`** | Aligns items to the center. |
| **`.items-end`**    | Aligns items to the end.    |

### Justify Content (BSCs)

Controls horizontal alignment if `flex-direction` is `row`, or vertical alignment if `flex-direction` is `col`.

| **Class**                | **Description**                    |
| ------------------------------ | ---------------------------------------- |
| **`.justify-start`**   | Justifies items to the start.            |
| **`.justify-center`**  | Justifies items to the center.           |
| **`.justify-end`**     | Justifies items to the end.              |
| **`.justify-between`** | Distributes items evenly along the axis. |

### Flex Wrap (BSCs)

| **Class**            | **Description**                                              |
| -------------------------- | ------------------------------------------------------------------ |
| **`.flex-wrap`**   | Allows items to wrap onto multiple lines if they run out of space. |
| **`.flex-nowrap`** | Forces all items to stay on a single line (default).               |
