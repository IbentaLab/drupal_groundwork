# Well / Aside Component

The Well component (also known as an "aside" or "callout") is a pre-styled Block Style Component (BSC) used to subtly highlight a piece of content. It's perfect for contextual information like "pro tips," "related info," or any content that should be visually distinct but less prominent than a `.card`.

## Core Concept

While a `.card` uses an outer shadow to appear "lifted" off the page, a `.well` uses a soft background and an inner shadow to appear slightly "inset" into the page.

The Well component is designed to be dual-purpose. It can be:

1. Applied to a Drupal block to transform its entire content area into a styled callout.
2. Applied directly to any HTML element (like a `<div>` or `<aside>`) for atomic use within Twig templates or the WYSIWYG editor.

## Tutorial for All Users

This guide shows you how to create a styled well.

### Recommended Method: Using the Block Styles UI (for Blocks)

The easiest way to turn an entire block into a well is with the **Block Styles UI** module, which is part of the **Groundwork Helpers** meta module.

#### Step 1: Place a Block

Place a "Basic block" or any other block with text content into a region.

#### Step 2: Apply the Well Class

Click "Configure" on the block and navigate to the **Styles** tab. In the interactive UI, select the **`.well`** class.

The entire block will now be rendered as a styled, inset container.

### Alternative Method: Manual Entry

#### For Site Builders (on Blocks)

If you do not have the `Block Styles UI` module installed, you can use a contributed module that allows adding classes to blocks. In the configuration form, you would type the class directly into the text field (e.g., `well`).

#### For Themers & Editors (Atomic Use)

Themers and content editors can apply the `.well` class directly to any container element within a Twig template or the WYSIWYG "Source" view.

**Example: In the WYSIWYG Editor**

```
<aside class="well">
  <h4>Pro Tip!</h4>
  <p>You can use the Well component to draw attention to important information without the strong elevation of a card.</p>
</aside>

```

## Class Reference

### Well Class

| **Class**     | **Description**                                                                 |
| ------------------- | ------------------------------------------------------------------------------------- |
| **`.well`** | Applies the standard well styling with a subtle background, border, and inner shadow. |
