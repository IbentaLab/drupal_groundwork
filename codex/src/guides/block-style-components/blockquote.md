# Blockquote Component

The Blockquote component is a pre-styled Block Style Component (BSC) used to visually distinguish quoted text from the surrounding content. It's an essential tool for articles, testimonials, or any content that includes citations.

## Core Concept

The Blockquote component is designed to be dual-purpose. It can be:

1. Applied to a Drupal block to transform its entire content area into a styled quote.
2. Applied directly to a `<blockquote>` HTML element for atomic use within Twig templates or the WYSIWYG editor.

The style typically includes a prominent left border, a subtle background color, and italicized text to make the quote stand out.

## Tutorial for All Users

This guide shows you how to create a styled blockquote.

### Recommended Method: Using the Block Styles UI (for Blocks)

The easiest way to turn an entire block into a blockquote is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place a "Basic block" or any other block with text content into a region. It's common to include a `<p>` tag for the quote and a `<footer>` tag for the citation.

#### Step 2: Apply the Blockquote Class

Click "Configure" on the block and navigate to the **Styles** tab. In the interactive UI, select the **`.blockquote`** class.

The entire block will now be rendered as a styled quote.

### Alternative Method: Manual Entry

#### For Site Builders (on Blocks)

If you do not have the `Block Styles UI` module installed, you can use a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `blockquote`).

#### For Themers & Editors (Atomic Use)

Themers and content editors can apply the `.blockquote` class directly to a `<blockquote>` element within a Twig template or the WYSIWYG "Source" view.

**Example: In the WYSIWYG Editor**

```
<blockquote class="blockquote">
  <p>This is the part that is quoted. It stands out from the rest of the text.</p>
  <footer>—Author's Name</footer>
</blockquote>

```

## Class Reference

### Blockquote Class

| **Class**           | **Description**                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------- |
| **`.blockquote`** | Applies the standard blockquote styling with a left border, background, and italic text. |
