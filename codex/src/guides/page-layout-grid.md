
# The Page Layout Grid

The Groundwork framework includes two distinct grid systems designed for different purposes. Understanding the difference is key to building powerful and maintainable layouts.

1. **Page Layout Grid (`.grid` & `.grid-cell`):** This is the primary **Flexbox-based** system used to arrange **blocks** within a page's  **regions** . It controls the main structure of your site.
2. **Content Layout Grid (`.d-grid`):** This is an optional, more powerful CSS Grid system you can apply to a single block to arrange the content *inside* it.

This tutorial focuses on the foundational  **Page Layout Grid** .

## Core Concept: Regions and Blocks

The Page Layout Grid is fundamental to how Groundwork structures every page.

* **The Container (`.grid`):** In Groundwork, every theme **region** is automatically a flex container with the `.grid` class. Its job is to align the blocks placed within it.
* **The Items (`.grid-cell`):** Every **block** you place in a region is automatically a flex item with the `.grid-cell` class. You use utility classes to control the width and alignment of these blocks.

Unlike the Content Layout Grid, you do not need to add a class like `.grid` to enable this system—it is the default behavior for all regions.

## Tutorial for All Users

This guide shows you how to control the width of blocks within any theme region.

### Recommended Method: Using the Block Styles UI

The easiest and most powerful way to apply styles is with the **Block Styles UI** module. This module is part of the **Groundwork Helpers** meta module, which is highly recommended for the best content editing experience.

#### Step 1: Place Multiple Blocks

Start by placing two or more blocks in the same region (e.g., the "Preface" or "Content" region). By default, each block will take up 100% of the available width and stack vertically.

#### Step 2: Define Block Widths

Now, let's arrange these blocks side-by-side. Click "Configure" on a block, then navigate to the **Styles** tab. This will open the interactive Block Styles UI where you can apply classes to control the width of each block.

Let's create a common 75% / 25% layout.

* **On the first block** , select the `.is-9` class from the UI. This will make the block take up 9 out of 12 columns, or 75% of the region's width.
* **On the second block** , repeat the process and select the `.is-3` class. This will make it take up the remaining 3 columns, or 25%.

### Alternative Method: Manual Entry

If you do not have the `Block Styles UI` module installed, you will need another way to add classes to your blocks.

* **For Site Builders:** You can install a** contributed module that allows adding classes to blocks. These modules typically provide** a simple text field in the block configuration form** where you can** add your classes manually (e.g., typing `is-9`).
* **For Themers:** You can add classes programmatically in your theme's `.theme` file using a preprocess hook. This is the most powerful method for controlling block classes across your site.

**Example: `mytheme.theme` file**

```
/**
 * Implements hook_preprocess_block().
 */
function mytheme_preprocess_block(&$variables) {
  // Add the .is-9 class to a specific block.
  if ($variables['plugin_id'] == 'my_custom_block_id') {
    $variables['attributes']['class'][] = 'is-9';
  }
}

```

## Advanced Usage: Responsive and Semantic Widths

The Page Layout Grid includes powerful modifiers for responsive design and readability.

### Responsive Modifiers

You can specify different widths for different screen sizes by appending a suffix to the width classes.

* `--s`: Applies only on small screens (≤780px).
* `--l`: Applies only on large screens (≥1200px).
* **(no suffix)** : Applies on medium screens and up (≥992px).

**Example:** A block with the classes `.is-12--s .is-6 .is-4--l` will be:

* Full-width on small screens.
* Half-width on medium screens.
* One-third-width on large screens.

### Semantic Aliases

For common layouts, you can use semantic aliases to make your class names more readable.

| **Alias** | **Equivalent** | **Width** |
| --------------- | -------------------- | --------------- |
| `.is-half`    | `.is-6`            | 50%             |
| `.is-third`   | `.is-4`            | 33.3%           |
| `.is-quarter` | `.is-3`            | 25%             |

## Class Reference

### Block Width Classes

Apply these to any block to control its width within a region. All classes support responsive suffixes (e.g., `.is-4--s`, `.is-half--l`).

| **Class**             | **Width** |
| --------------------------- | --------------- |
| `.is-1`                   | 8.33%           |
| `.is-2`                   | 16.67%          |
| `.is-3`or `.is-quarter` | 25%             |
| `.is-4`or `.is-third`   | 33.33%          |
| `.is-5`                   | 41.67%          |
| `.is-6`or `.is-half`    | 50%             |
| `.is-7`                   | 58.33%          |
| `.is-8`                   | 66.67%          |
| `.is-9`                   | 75%             |
| `.is-10`                  | 83.33%          |
| `.is-11`                  | 91.67%          |
| `.is-12`                  | 100%            |

### Cell Behavior Classes

These utilities (from `grid-cell-utilities.css`) control how a block behaves within the flex container.

| **Class**   | **Description**                                        |
| ----------------- | ------------------------------------------------------------ |
| `.align-top`    | Aligns the block to the top of its row.                      |
| `.align-middle` | Vertically centers the block in its row.                     |
| `.align-bottom` | Aligns the block to the bottom of its row.                   |
| `.is-offset-1`  | Pushes the block to the right by one column width.           |
| `.order-first`  | Visually moves the block to be the first item in the region. |
| `.order-last`   | Visually moves the block to be the last item in the region.  |
