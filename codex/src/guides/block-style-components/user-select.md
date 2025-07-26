# User Selection Utilities

User selection utilities control whether the text inside a block or element can be highlighted by the user. This is a "quality-of-life" feature that is useful for polishing highly interactive components where accidental text selection can be distracting.

## Core Concept

The primary use case for these utilities is to prevent text selection on elements that are meant to be clicked or dragged. For example, on a custom-built slider or a block that acts as a button, highlighting the text when a user clicks and drags can make the component feel unpolished. The `.select-none` utility prevents this.

## Tutorial for All Users

This guide shows you how to control text selection on a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply these styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place an Interactive Block

Place a block in a region that is designed to be highly interactive, such as a card that is wrapped in a link.

#### Step 2: Apply a User Select Class

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* To prevent users from being able to highlight the text on the card, select the **`.select-none`** class. Now, when a user clicks and drags on the card, the text will not be selected, making the interaction feel cleaner.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `select-none`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Prevent text selection on a custom button block.
  if ($variables['plugin_id'] == 'my_custom_button') {
    $variables['attributes']['class'][] = 'select-none';
  }
}

```

## Class Reference

### User Select Classes (BSCs)

Apply one of these classes to a block to control how its text can be selected.

| **Class**            | **Description**                                               |
| -------------------------- | ------------------------------------------------------------------- |
| **`.select-none`** | Prevents the user from selecting the text inside the element.       |
| **`.select-text`** | Allows text selection (this is the default browser behavior).       |
| **`.select-all`**  | A single click by the user will select all text within the element. |
