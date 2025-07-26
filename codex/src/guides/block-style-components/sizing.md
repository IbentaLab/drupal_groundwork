# Sizing Utilities

Sizing utilities provide explicit control over the `width`, `height`, and `max-width` of a block or element. These are essential for creating common design patterns like full-screen "hero" sections or for constraining text-heavy blocks to a readable line length.

## Core Concept

These utilities complement the Page Layout Grid. While the `.is-*` classes set a *relative* width based on a 12-column grid, the sizing utilities set *explicit* or *viewport-relative* dimensions. The `max-w-*` utilities are particularly important for typography and readability, as they prevent text lines from becoming uncomfortably long on wide screens.

## Tutorial for All Users

This guide shows you how to control the dimensions of a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply sizing styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place a block with content in a region.

#### Step 2: Apply a Sizing Class

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* **To create a full-height hero block:** Select  **`.h-screen`** . This will make the block's content area fill the entire height of the user's browser window.
* **To constrain a text block for readability:** Place a block in a wide region. Then, select a class like  **`.max-w-lg`** . You can then use the **`.mx-auto`** margin utility to center this constrained block within the wider region.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `h-screen`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Make the hero block full-height.
  if ($variables['plugin_id'] == 'my_hero_block') {
    $variables['attributes']['class'][] = 'h-screen';
  }
}

```

## Class Reference

### Width Utilities (BSCs)

| **Class**         | **Description**                              |
| ----------------------- | -------------------------------------------------- |
| **`.w-full`**   | Sets `width: 100%`.                              |
| **`.w-screen`** | Sets `width: 100vw`(100% of the viewport width). |
| **`.w-auto`**   | Sets `width: auto`.                              |

### Height Utilities (BSCs)

| **Class**         | **Description**                                |
| ----------------------- | ---------------------------------------------------- |
| **`.h-full`**   | Sets `height: 100%`of its parent container.        |
| **`.h-screen`** | Sets `height: 100vh`(100% of the viewport height). |
| **`.h-auto`**   | Sets `height: auto`.                               |

### Max-Width Utilities (BSCs)

| **Class**           | **Description**                                               |
| ------------------------- | ------------------------------------------------------------------- |
| **`.max-w-md`**   | Constrains the element to your theme's medium container width.      |
| **`.max-w-lg`**   | Constrains the element to your theme's large container width.       |
| **`.max-w-xl`**   | Constrains the element to your theme's extra-large container width. |
| **`.max-w-full`** | Sets `max-width: 100%`.                                           |
