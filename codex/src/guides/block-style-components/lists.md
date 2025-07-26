# List Style Utilities

List style utilities give you control over the appearance and position of list markers (the bullets in unordered lists and the numbers in ordered lists).

## Core Concept

These utilities allow you to change the default style of lists within a block. The most powerful use case is applying `.list-none` to remove the default browser markers, which allows you to create completely custom-styled lists using your own icons or images as the markers (for example, a "checklist" with custom checkmark icons).

## Tutorial for All Users

This guide shows you how to change the list style within a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply list styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block with a List

Place a block that contains a `<ul>` or `<ol>` list in a region.

#### Step 2: Apply a List Style Class

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* To change the bullets to numbers on all lists in the block, select the **`.list-decimal`** class.
* To remove the bullets entirely so you can add your own custom icons, select  **`.list-none`** .

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `list-none`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Remove list styling from a specific block.
  if ($variables['plugin_id'] == 'my_custom_checklist_block') {
    $variables['attributes']['class'][] = 'list-none';
  }
}

```

## Class Reference

### List Style Utilities (BSCs)

Apply one of these classes to a block to control the styling of lists within it.

| **Class**             | **Description**                                             |
| --------------------------- | ----------------------------------------------------------------- |
| **`.list-disc`**    | Sets the list marker to a standard disc (bullet).                 |
| **`.list-decimal`** | Sets the list marker to decimal numbers (1, 2, 3...).             |
| **`.list-none`**    | Removes all list markers.                                         |
| **`.list-inside`**  | Positions the marker inside the list item's text flow.            |
| **`.list-outside`** | Positions the marker outside the list item's text flow (default). |
