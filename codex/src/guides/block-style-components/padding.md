# Padding Utilities

Padding utilities are used to create space **inside** a block or an element, pushing the content away from its own edges. This is known as "internal spacing" and is essential for preventing content from touching the borders of a component, such as a card.

## Core Concept: Naming Convention

The padding utilities follow a simple and predictable naming convention that mirrors the margin utilities:

`{property}{side}-{size}`

* **Property:** `p` for `padding`.
* **Side (Optional):**
  * `t` - `padding-top`
  * `b` - `padding-bottom`
  * `l` - `padding-left`
  * `r` - `padding-right`
  * `x` - left and right (`x-axis`)
  * `y` - top and bottom (`y-axis`)
* **Size:** A number from `0` to `6` that corresponds to the spacing scale in your theme's `tokens.css` file.

**Examples:**

* `.p-3`: Applies a medium padding to all four sides.
* `.pt-4`: Applies a large padding to the top only.
* `.px-5`: Applies extra-large padding to the left and right sides.

## Tutorial for All Users

This guide shows you how to add padding to a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply padding is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place a block with content in a region. For this example, using a `.card` block is ideal.

#### Step 2: Apply a Padding Class

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* To add equal space on all sides of the content, select a class like  **`.p-4`** . This is the most common use case.
* To add more vertical space than horizontal, you could combine classes like **`.px-3`** and  **`.py-5`** .

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you can apply classes manually.

* **For Site Builders:** Install a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `p-4`).
* **For Themers:** Add classes programmatically in your theme's `.theme` file using a preprocess hook.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Add padding to a specific card block.
  if ($variables['plugin_id'] == 'my_card_block') {
    $variables['attributes']['class'][] = 'card';
    $variables['attributes']['class'][] = 'p-4';
  }
}

```

## Class Reference

### Padding Utilities (BSCs)

| **Class** | **CSS Property**             |
| --------------- | ---------------------------------- |
| `.p-{size}`   | `padding`                        |
| `.pt-{size}`  | `padding-top`                    |
| `.pb-{size}`  | `padding-bottom`                 |
| `.pl-{size}`  | `padding-left`                   |
| `.pr-{size}`  | `padding-right`                  |
| `.px-{size}`  | `padding-left`&`padding-right` |
| `.py-{size}`  | `padding-top`&`padding-bottom` |

*(Note: `{size}` is a number from `0` to `6`)*
