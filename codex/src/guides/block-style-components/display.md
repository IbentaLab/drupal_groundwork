# Display Utilities

Display utilities are a foundational part of the Groundwork framework. They control the CSS `display` property, which dictates how an element is rendered and how it interacts with the elements around it. Most importantly, these utilities are the key to enabling the powerful **Flexbox** and **CSS Grid** content layout systems.

## Core Concept

By default, most elements are either `block` (taking up their own line, like a paragraph) or `inline` (flowing with text, like a link). These utilities allow you to change that behavior. The most critical use case is applying `.d-flex` or `.d-grid` to a block, which turns its content area into a container for advanced content layouts.

## Tutorial for All Users

This guide shows you how to use display utilities on a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply display styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place any block with content into a region.

#### Step 2: Apply a Display Class

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* To enable the **Flexbox** content layout system, select the **`.d-flex`** class. You can now use flexbox utilities (from `flexbox.css`) to align the content inside this block.
* To enable the **CSS Grid** content layout system, select the **`.d-grid`** class. You can now use grid utilities (from `d-grid.css`) to create columns for the content inside this block.
* To hide the block's content completely, select  **`.d-none`** .

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `d-flex`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Enable a flex layout for a specific block's content.
  if ($variables['plugin_id'] == 'my_special_promo') {
    $variables['attributes']['class'][] = 'd-flex';
  }
}

```

## Class Reference

### Display Classes (BSCs)

Apply one of these classes to a block to change the display behavior of its content area.

| **Class**        | **Description**                                              |
| ---------------------- | ------------------------------------------------------------------ |
| **`.d-flex`**  | **Enables Flexbox.**Turns the content area into a flex container.  |
| **`.d-grid`**  | **Enables CSS Grid.**Turns the content area into a grid container. |
| **`.d-block`** | Renders the content area as a standard block-level element.        |
| **`.d-none`**  | Hides the content area completely.                                 |
