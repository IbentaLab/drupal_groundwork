# Codex: Card Component

The Card component is one of the most versatile Block Style Components (BSCs) in the Groundwork framework. It is used to group related content into a container that has a distinct background, padding, and elevation (shadow), making it stand out from the page.

## Core Concept

Cards are self-contained modules of content. By applying a `.card` class to a block, you can instantly transform it into a visually distinct unit. You can then combine this with other BSCs, like padding or color utilities, to create a wide variety of designs.

## Tutorial for All Users

This guide shows you how to turn any block into a card.

### Recommended Method: Using the Block Styles UI

The easiest way to apply card styles is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place any block with content into a region.

#### Step 2: Apply Card and Padding Styles

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* To apply the default card style, select the **`.card`** class.
* Cards almost always need internal spacing. It is highly recommended to also select a padding utility, such as **`.p--lg`** or  **`.p--xl`** .

You can experiment with different card variants, like `.card--1` for more shadow or `.card--outline` for a more subtle look.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the classes directly into the text field (e.g., `card p--lg`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Apply card styling to a specific block.
  if ($variables['plugin_id'] == 'my_promo_block') {
    $variables['attributes']['class'][] = 'card';
    $variables['attributes']['class'][] = 'p--xl';
  }
}

```

## Class Reference

### Card Base & Elevation

Apply one of these classes to a block to give it a card-like appearance.

| **Class**     | **Description**                                      |
| ------------------- | ---------------------------------------------------------- |
| **`.card`** | The default card style with subtle elevation.              |
| `.card--1`        | Applies a medium-level shadow for more emphasis.           |
| `.card--2`        | Applies a strong shadow for a floating effect.             |
| `.card--3`        | Applies the maximum shadow for modals or primary callouts. |

### Card Variants

These variants can be combined with a base card class or used on their own.

| **Class**              | **Description**                                         |
| ---------------------------- | ------------------------------------------------------------- |
| **`.card--hover`**   | Adds an elevation effect that appears only on hover.          |
| **`.card--outline`** | A transparent card with a simple border.                      |
| **`.card--inverse`** | A dark card surface. Best paired with `.text-light`.        |
| **`.card--primary`** | A card with the site's primary brand color as the background. |
