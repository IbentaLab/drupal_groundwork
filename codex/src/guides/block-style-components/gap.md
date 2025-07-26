# Gap & Spacing Utilities

Gap utilities provide the modern and preferred way to create consistent space between items in a layout container. These utilities work for both the **Page Layout Grid (Flexbox)** and the  **Content Layout Grid (CSS Grid)** .

## Core Concept

The `gap` property is a simple way to define the gutters between rows and columns. Instead of adding margins to individual items, you apply a single `gap` utility to the parent container, and it handles the spacing for all children automatically.

This is the best way to space out blocks within a region or content elements within a block.

## Tutorial for All Users

This guide shows you how to add spacing between items in a layout.

### Recommended Method: Using the Block Styles UI

The easiest way to apply gap styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Create a Layout Container

This method works on any layout container.

* **For Page Layout:** Place several blocks in the same region.
* **For Content Layout:** Apply `.d-grid` or `.d-flex` to a single block.

#### Step 2: Apply a Gap Class

Click "Configure" on the block (or on the region settings, if the UI supports it) and navigate to the **Styles** tab.

* To add space between the items, select a gap utility like  **`.gap-4`** . This will apply a consistent horizontal and vertical space between all items in the container.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `d-grid gap-4`).
* **For Themers:** Add classes programmatically. You can add gap utilities to regions via `hook_preprocess_region()` or to blocks via `hook_preprocess_block()`.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Add a gap to a block that uses a content layout grid.
  if ($variables['plugin_id'] == 'my_feature_list_block') {
    $variables['attributes']['class'][] = 'd-grid';
    $variables['attributes']['class'][] = 'd-grid-cols-3';
    $variables['attributes']['class'][] = 'gap-4';
  }
}

```

## Class Reference

### Gap Utilities (BSCs)

Apply one of these classes to a flex or grid container to control the space between its children.

| **Class**        | **Description**                             |
| ---------------------- | ------------------------------------------------- |
| **`.gap-1`**   | Applies a small gap (`0.4rem`).                 |
| **`.gap-2`**   | Applies a small-medium gap (`0.8rem`).          |
| **`.gap-3`**   | Applies a medium gap (`1.6rem`).                |
| **`.gap-4`**   | Applies a medium-large gap (`2.4rem`).          |
| **`.gap-5`**   | Applies a large gap (`3.2rem`).                 |
| **`.gap-6`**   | Applies an extra-large gap (`4.0rem`).          |
| **`.gap-x-3`** | Applies a medium gap to the horizontal axis only. |
| **`.gap-y-3`** | Applies a medium gap to the vertical axis only.   |
