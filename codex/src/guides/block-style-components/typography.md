# Typography Utilities

Typography utilities provide comprehensive control over every aspect of text styling, from font family and size to alignment and decoration. This file is the single source of truth for all text-related styles in the Groundwork framework.

## Core Concept

This file contains a large number of classes. Most are  **atomic utilities** , designed to be applied directly to text elements (like headings and paragraphs) for a specific effect. Some utilities, like `.font-sans` or `.text-center`, can also be applied to an entire block as a BSC to style all the text within it consistently.

## Tutorial for All Users

This guide shows you how to style text within a block.

### Recommended Method: Using the Block Styles UI

The easiest way to apply block-level typography is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place a block with text content in a region.

#### Step 2: Apply Block-Level Text Styles

Click "Configure" on the block and navigate to the **Styles** tab. This opens the interactive UI.

* To center all the text within the block, select the **`.text-center`** class.
* To change the font for the entire block, select  **`.font-serif`** .

### Applying Styles to Specific Text (Atomic Usage)

For more granular control, you will apply atomic classes directly to the HTML in your content editor's "Source" view.

**Example: Styling a heading and a paragraph differently**

```
<!-- This content goes inside your block's body field -->

<h2 class="text-xl font-bold uppercase tracking-tight">A Bold, Tight Heading</h2>

<p class="font-light italic">
  This paragraph has a lighter font weight and is italicized,
  making it distinct from the heading above.
</p>

<a href="#" class="underline">This is an underlined link.</a>

```

## Class Reference

### Font Family (BSCs)

| **Class**           | **Description**                |
| ------------------------- | ------------------------------------ |
| **`.font-sans`**  | Applies the primary sans-serif font. |
| **`.font-serif`** | Applies the serif font.              |
| **`.font-mono`**  | Applies the monospace font.          |

### Font Size (BSCs)

| **Class**               | **Description**                                              |
| ----------------------------- | ------------------------------------------------------------------ |
| `.text-xs`to `.text-xxxl` | A scale of font sizes from extra-small to extra-extra-extra-large. |

### Font Weight & Style (BSCs & Atomic)

| **Class**                                 | **Description**                    |
| ----------------------------------------------- | ---------------------------------------- |
| `.font-thin`to `.font-black`                | A scale of font weights from 100 to 900. |
| **`.italic`**/**`.not-italic`** | Applies or removes italic styling.       |

### Text Alignment (BSCs)

| **Class**                                                               | **Description**     |
| ----------------------------------------------------------------------------- | ------------------------- |
| **`.text-left`**/**`.text-center`**/**`.text-right`** | Aligns text horizontally. |
| **`.text-justify`**                                                   | Justifies text.           |

### Text Decoration (BSCs & Atomic)

| **Class**                                                                  | **Description**           |
| -------------------------------------------------------------------------------- | ------------------------------- |
| **`.underline`**/**`.line-through`**/**`.no-underline`** | Controls text decoration lines. |

### Text Transform (BSCs & Atomic)

| **Class**                                                             | **Description**         |
| --------------------------------------------------------------------------- | ----------------------------- |
| **`.uppercase`**/**`.lowercase`**/**`.capitalize`** | Controls text capitalization. |

### Line Height & Letter Spacing (BSCs & Atomic)

| **Class** | **Description**                                   |
| --------------- | ------------------------------------------------------- |
| `.leading-*`  | Controls the space between lines of text (line-height). |
| `.tracking-*` | Controls the space between characters (letter-spacing). |

### Accessibility (Atomic)

| **Class**        | **Description**                                                    |
| ---------------------- | ------------------------------------------------------------------------ |
| **`.sr-only`** | Hides an element visually while keeping it accessible to screen readers. |
