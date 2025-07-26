# Rounded Corner Utilities

Rounded corner utilities are used to soften the edges of blocks and elements by controlling the `border-radius` property. This can be used to create everything from slightly rounded cards to perfectly circular avatars.

## Core Concept: Naming Convention

The rounded utilities follow a simple naming convention:

`rounded{side}-{size}`

* **Property:** `rounded` is the base.
* **Side (Optional):**
  * `t` - top-left and top-right corners
  * `b` - bottom-left and bottom-right corners
  * `l` - top-left and bottom-left corners
  * `r` - top-right and bottom-right corners
  * `tl` - top-left corner only
  * `tr` - top-right corner only
  * `bl` - bottom-left corner only
  * `br` - bottom-right corner only
* **Size:** A number from `1` to `5` that corresponds to the radius scale in your theme's `tokens.css` file. There are also special utilities like `rounded-full` and `rounded-circle`.

## Tutorial for All Users

This guide shows you how to apply rounded corners to a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply rounding is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place a block with content in a region. This is most effective on blocks that have a border or a background color, like a `.card`.

#### Step 2: Apply a Rounded Class

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* To apply a standard, medium rounding to all corners of a card, you could select  **`.rounded-3`** .
* To create a "tab" effect where only the top corners are rounded, you could apply  **`.rounded-t-3`** .
* To create a circular avatar, apply **`.rounded-circle`** to a square image.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `rounded-t-3`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Make a specific block pill-shaped.
  if ($variables['plugin_id'] == 'my_special_button_block') {
    $variables['attributes']['class'][] = 'rounded-full';
  }
}

```

## Class Reference

### General Radius Utilities (BSCs)

| **Class**               | **Description**                         |
| ----------------------------- | --------------------------------------------- |
| `.rounded-{size}`           | Applies the same radius to all four corners.  |
| **`.rounded-full`**   | Creates a pill shape on rectangular elements. |
| **`.rounded-circle`** | Creates a circle on square elements.          |
| **`.rounded-none`**   | Removes all rounding.                         |

### Directional Radius Utilities (BSCs)

| **Class**        | **Description**                            |
| ---------------------- | ------------------------------------------------ |
| `.rounded-t-{size}`  | Rounds the top-left and top-right corners.       |
| `.rounded-b-{size}`  | Rounds the bottom-left and bottom-right corners. |
| `.rounded-l-{size}`  | Rounds the top-left and bottom-left corners.     |
| `.rounded-r-{size}`  | Rounds the top-right and bottom-right corners.   |
| `.rounded-tl-{size}` | Rounds the top-left corner only.                 |
| `.rounded-tr-{size}` | Rounds the top-right corner only.                |
| `.rounded-bl-{size}` | Rounds the bottom-left corner only.              |
| `.rounded-br-{size}` | Rounds the bottom-right corner only.             |

*(Note: `{size}` is a number from `1` to `5`)*
