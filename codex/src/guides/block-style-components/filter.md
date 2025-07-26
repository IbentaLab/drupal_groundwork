
# Filter Utilities

Filter utilities allow you to apply graphical effects like `blur`, `brightness`, `contrast`, and `grayscale` to blocks and elements. They are most commonly used to alter the appearance of images, but can be applied to any element for creative effects.

## Core Concept: A Composable System

The filter system is designed to be composable. This means you can stack multiple filter effects together.

1. **Enable Filters:** You must first apply the base **`.filter`** class. This class "turns on" the filter functionality.
2. **Apply Effects:** Then, you add one or more filter utility classes (e.g., `.grayscale`, `.blur-sm`) to create the desired look.

For interactive effects, you can combine these with hover and transition utilities. For example, you can make a block grayscale by default and then return it to full color on hover.

## Tutorial for All Users

This guide shows you how to apply a filter to a block, such as an image block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply filters is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place an Image Block

Place a block that contains an image.

#### Step 2: Apply Filter Classes

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

Let's make an image black and white by default, and return it to full color with a smooth transition when hovered.

1. First, select **`.filter`** to enable the filter system.
2. Next, select **`.grayscale`** to make the image black and white.
3. Then, select **`.hover-grayscale-0`** to make it return to color on hover.
4. **Crucially** , add **`.transition-all`** to make the change from grayscale to color happen smoothly.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the classes directly into the text field (e.g., `filter grayscale hover-grayscale-0 transition-all`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Apply a filter effect to a specific image block.
  if ($variables['plugin_id'] == 'my_image_block') {
    $variables['attributes']['class'][] = 'filter';
    $variables['attributes']['class'][] = 'grayscale';
    $variables['attributes']['class'][] = 'hover-grayscale-0';
    $variables['attributes']['class'][] = 'transition-all';
  }
}

```

## Class Reference

### Filter Utilities (BSCs)

| **Class**                  | **Description**                                                      |
| -------------------------------- | -------------------------------------------------------------------------- |
| **`.filter`**            | **Required.**Enables the filter system. Must be used with other utilities. |
| **`.blur-sm`**           | Applies a small blur effect.                                               |
| **`.grayscale`**         | Renders the element in black and white.                                    |
| **`.brightness-75`**     | Reduces the element's brightness to 75%.                                   |
| **`.contrast-125`**      | Increases the element's contrast to 125%.                                  |
| **`.filter-none`**       | Removes all filter effects.                                                |
| **`.hover-grayscale-0`** | Removes the grayscale effect on hover.                                     |
