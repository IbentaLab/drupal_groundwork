# Alert Component

The Alert component is a pre-styled Block Style Component (BSC) used for displaying contextual feedback messages to the user, such as success confirmations, warnings, or error notifications.

## Core Concept

Alerts are designed to be applied to a block to transform its entire content area into a styled message. The system works by combining a base `.alert` class (which provides the padding, border, and shape) with a contextual color class (like `.alert-success`) that provides the specific colors for that message type.

## Tutorial for All Users

This guide shows you how to turn any block into an alert message.

### Recommended Method: Using the Block Styles UI

The easiest way to create an alert is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place a "Basic block" or any other block with text content into a region.

#### Step 2: Apply Alert Classes

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

To create a "Success" message, you need to combine the base class and a color class. Select both:

* **`.alert`**
* **`.alert-success`**

The block will now be rendered as a green success message, complete with a colored left border, a light green background, and dark green text.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type both classes directly into the text field (e.g., `alert alert-success`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Apply alert styling to a specific block.
  if ($variables['plugin_id'] == 'my_status_message_block') {
    $variables['attributes']['class'][] = 'alert';
    $variables['attributes']['class'][] = 'alert-warning';
  }
}

```

## Class Reference

### Base Class (Required)

| **Class**      | **Description**                                                       |
| -------------------- | --------------------------------------------------------------------------- |
| **`.alert`** | **Required.**Applies the base padding, border, and shape for the component. |

### Contextual Color Classes

Combine one of these with the base `.alert` class.

| **Class**              | **Description**                                                |
| ---------------------------- | -------------------------------------------------------------------- |
| **`.alert-info`**    | For general, informational messages (styled with the primary color). |
| **`.alert-success`** | For confirming that an action was successful.                        |
| **`.alert-warning`** | For indicating something that needs attention.                       |
| **`.alert-danger`**  | For communicating an error or a destructive action.                  |
