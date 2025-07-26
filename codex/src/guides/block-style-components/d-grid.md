# The Content Layout Grid

The Groundwork framework includes two distinct grid systems designed for different purposes. Understanding the difference is key to building powerful and maintainable layouts.

1. **Page Layout Grid (`.grid` & `.grid-cell`):** This is the primary Flexbox-based system used to arrange **blocks** within a page's  **regions** . It controls the main structure of your site.
2. **Content Layout Grid (`.d-grid`):** This is an optional, more powerful **CSS Grid** system you can apply to a single block. Its purpose is to arrange the content ( *text, images, links* ) **inside** that block.

This tutorial focuses on the  **Content Layout Grid** .

## Core Concept: Container & Items

The Content Layout Grid works by defining a **Grid Container** and arranging **Grid Items** within it.

* **The Container:** When you apply `.d-grid` to a block, its content area (`.block-style-target`) becomes the grid container. You use Block Style Components (BSCs) like `.d-grid-cols-3` to define the column structure of this container.
* **The Items:** The individual HTML elements (headings, paragraphs, images) inside the block's content are the grid items. You use standard atomic utility classes like `.col-span-2` to control how these items are placed on the grid.

## Tutorial for Content Editors

This guide shows you how to create a complex layout inside a block using the **Block Styles UI** module. This module is part of the **Groundwork Helpers** meta module, which is highly recommended for the best content editing experience.

### Step 1: Place Your Block

Start by placing a standard block in any region. For this example, we'll use a "Basic block" and make it full-width in the region.

### Step 2: Define the Grid Container

With the block placed, click "Configure" and navigate to the **Styles** tab. This will open the interactive Block Styles UI where you will apply the BSCs that define your grid container.

Let's create a 4-column grid with a medium gap between the items. In the UI, select the following classes:

* `d-grid`: This is the most important class. It turns the block's content area into a grid container.
* `d-grid-cols-4`: This divides the container into four equal-width columns.
* `gap-4`: This utility (from `gap.css`) adds a consistent space between all columns and rows.

### Step 3: Add and Style Your Content

Now, edit the block's content. In your WYSIWYG editor, switch to the "Source" view to work with the HTML directly. This is where you will use the atomic classes to place your items on the grid you just created.

Let's build a simple feature list.

```
<!-- This content goes inside your block's body field -->

<div class="col-span-full">
  <h2 class="text-center">Our Features</h2>
  <p class="text-center">Discover what makes our service unique.</p>
</div>

<div>
  <h4>Feature One</h4>
  <p>A short description of the first amazing feature.</p>
</div>

<div>
  <h4>Feature Two</h4>
  <p>A short description of the second amazing feature.</p>
</div>

<!-- This item will start on the 4th column -->
<div class="col-start-4">
  <h4>Feature Three</h4>
  <p>A short description of the third amazing feature.</p>
</div>

<!-- This item will span two columns -->
<div class="col-span-2">
  <h4>A Wider Feature (Four)</h4>
  <p>This feature is important, so its description takes up more horizontal space, spanning two of our four columns.</p>
</div>

<div>
  <h4>Feature Five</h4>
  <p>A short description of the fifth amazing feature.</p>
</div>

```

### The Result

Even though you only selected a few styles and added some classes, you have created a complex, responsive layout inside a single block. The header spans the full width, items are placed in specific columns, and some items take up more space than others.

## Guide for Themers

If you are working in Twig templates, you can apply these classes programmatically.

* **Container Classes (BSCs):** Add these to the block's attributes in a `hook_preprocess_block`.
* **Item Classes (Atomic):** Apply these directly in the block's Twig template.

**Example: `my-custom-block.html.twig`**

```
{#
  In a preprocess function, the block would have been given the
  'd-grid', 'd-grid-cols-12', and 'gap-4' classes.
#}
<div{{ attributes }}>
  {{ title_prefix }}
  {% if label %}
    {# Make the title span all 12 columns of our content grid #}
    <h2{{ title_attributes.addClass('col-span-full') }}>{{ label }}</h2>
  {% endif %}
  {{ title_suffix }}

  {% block content %}
    {# Place the main content starting at column 3 and spanning 8 columns #}
    <div{{ content_attributes.addClass('col-start-3', 'col-span-8') }}>
      {{ content }}
    </div>
  {% endblock %}
</div>

```

## Class Reference

### Grid Container Classes (BSCs)

Apply these to a block to define its internal grid structure.

| **Class**       | **Description**                                              |
| --------------------- | ------------------------------------------------------------------ |
| **`.d-grid`** | **Required.**Turns the block's content area into a grid container. |
| `.d-grid-cols-2`    | Creates a grid with 2 equal-width columns.                         |
| `.d-grid-cols-3`    | Creates a grid with 3 equal-width columns.                         |
| `.d-grid-cols-4`    | Creates a grid with 4 equal-width columns.                         |
| `.d-grid-cols-6`    | Creates a grid with 6 equal-width columns.                         |
| `.d-grid-cols-12`   | Creates a grid with 12 equal-width columns.                        |

### Grid Item Classes (Atomic)

Apply these directly to the HTML elements *inside* the block's content.

| **Class**              | **Description**                             |
| ---------------------------- | ------------------------------------------------- |
| **`.col-span-2`**    | Makes the item span across 2 columns.             |
| **`.col-span-3`**    | Makes the item span across 3 columns.             |
| **`.col-span-full`** | Makes the item span across all available columns. |
| **`.row-span-2`**    | Makes the item span across 2 rows.                |
| **`.col-start-2`**   | Forces the item to begin in the second column.    |
| **`.col-start-3`**   | Forces the item to begin in the third column.     |
