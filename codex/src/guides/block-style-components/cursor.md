# Cursor Utilities

Cursor utilities provide important visual feedback to users by changing the mouse cursor's appearance when it hovers over an element. This helps communicate the interactivity of different parts of your site.

## Core Concept

The primary use for cursor utilities is to signal that an entire block or component is interactive. For example, a card that links to a news article should have a "pointer" cursor to indicate that the whole area is clickable, not just the title.

## Tutorial for All Users

This guide shows you how to change the cursor on a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply cursor styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place any block in a region. This is most effective on blocks that are wrapped in a link or have custom JavaScript click events.

#### Step 2: Apply a Cursor Class

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* To indicate that the block is clickable, select the **`.cursor-pointer`** class.
* If the block represents a disabled action, you could select  **`.cursor-not-allowed`** .

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `cursor-pointer`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Apply a pointer cursor to a specific block.
  if ($variables['plugin_id'] == 'my_clickable_promo') {
    $variables['attributes']['class'][] = 'cursor-pointer';
  }
}

```

## Class Reference

### Cursor Classes (BSCs)

Apply one of these classes to a block to change its cursor on hover.

| **Class**                   | **Description**                                          |
| --------------------------------- | -------------------------------------------------------------- |
| **`.cursor-pointer`**     | Shows a pointer (hand), indicating a clickable link or button. |
| **`.cursor-not-allowed`** | Shows a disabled symbol, indicating an action is unavailable.  |
| **`.cursor-wait`**        | Shows a waiting symbol, indicating a process is running.       |
| **`.cursor-default`**     | Reverts to the standard system pointer.                        |
