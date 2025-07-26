# Hover Utilities

Hover utilities are used to apply styles to a block or element when a user moves their mouse cursor over it. They are essential for providing visual feedback and creating a polished, interactive user experience.

## Core Concept: The Importance of Transitions

Hover effects feel best when they are smooth, not instantaneous. For this reason, it is **highly recommended** that you **always** combine a hover utility with a transition utility (from `transitions.css`).

* **Without Transition:** The block's shadow instantly appears.
* **With `.transition-all`:** The shadow smoothly fades in, creating a much more professional effect.

A proper implementation always looks like a combination of classes: `card hover-shadow transition-all`.

## Tutorial for All Users

This guide shows you how to add a hover effect to a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply hover styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place any block in a region. This is most effective on interactive components like cards or buttons.

#### Step 2: Apply Hover and Transition Classes

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

Let's make a card lift up and gain a shadow when hovered.

1. First, ensure the block has a base style, like  **`.card`** .
2. Next, select the hover effect you want, such as  **`.hover-raise`** .
3. **Crucially** , add a transition by selecting  **`.transition-all`** .

The combination of `card`, `hover-raise`, and `transition-all` will create the desired smooth effect.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the classes directly into the text field (e.g., `card hover-raise transition-all`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Add a smooth hover effect to a specific block.
  if ($variables['plugin_id'] == 'my_interactive_card') {
    $variables['attributes']['class'][] = 'card';
    $variables['attributes']['class'][] = 'hover-raise';
    $variables['attributes']['class'][] = 'transition-all';
  }
}

```

## Class Reference

### Hover Classes (BSCs)

Apply one of these classes to a block to add an effect on hover.

| **Class**               | **Description**                           |
| ----------------------------- | ----------------------------------------------- |
| **`.hover-shadow`**   | Adds a soft shadow on hover.                    |
| **`.hover-raise`**    | Lifts the element up by 4px.                    |
| **`.hover-scale`**    | Slightly enlarges the element.                  |
| **`.hover-opacity`**  | Reduces the element's opacity.                  |
| **`.hover-bg-light`** | Applies a subtle, contrasting background color. |
