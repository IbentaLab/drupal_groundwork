# Shadow & Elevation Utilities

Shadow utilities are used to lift elements and blocks off the page by applying a `box-shadow`. This creates a sense of depth and elevation, which is fundamental for modern UI design, especially for components like cards and modals.

## Core Concept

The shadow utilities provide a scale of predefined shadow styles that are tied directly to your theme's design tokens. This ensures that the appearance of shadows is consistent across the entire site and can automatically adapt to different themes, such as dark mode.

## Tutorial for All Users

This guide shows you how to apply a shadow to a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply shadows is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place a block with a background color in a region. Shadows are most visible on components like a `.card`.

#### Step 2: Apply a Shadow Class

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* To apply a standard, medium shadow, select the **`.shadow`** class.
* For a more dramatic, lifted effect, select  **`.shadow-lg`** .
* To make it look like the component is pressed "into" the page, select  **`.shadow-inner`** .

Remember that shadows can be combined with hover effects. For a professional feel, try combining `.card`, `.shadow`, `.hover-shadow`, and `.transition-all`.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `shadow-lg`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Apply a large shadow to a specific block.
  if ($variables['plugin_id'] == 'my_modal_block') {
    $variables['attributes']['class'][] = 'shadow-lg';
  }
}

```

## Class Reference

### Shadow Utilities (BSCs)

Apply one of these classes to a block to add a box shadow.

| **Class**             | **Description**                                     |
| --------------------------- | --------------------------------------------------------- |
| **`.shadow-sm`**    | Applies a small, subtle shadow.                           |
| **`.shadow`**       | Applies a standard-sized shadow for default elevation.    |
| **`.shadow-lg`**    | Applies a large, prominent shadow for a "lifted" effect.  |
| **`.shadow-inner`** | Applies an inner shadow, making the element appear inset. |
| **`.shadow-none`**  | Removes any existing shadow.                              |
