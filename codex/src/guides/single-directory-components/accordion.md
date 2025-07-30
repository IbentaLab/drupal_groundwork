# Accordion SDC

The Accordion SDC is a flexible, accessible, and themeable component for collapsible content blocks—perfect for FAQs, documentation, “show more” patterns, and anywhere you want to reveal/hide related content.

## Features

* Clean, semantic HTML (headings, buttons, panels)
* Fully accessible (WAI-ARIA pattern)
* Token-based for dark/light theming
* No dependencies—just copy, drop, and use

---

## Usage

### Props

* `items` (array,  **required** ):

  Each item is an object with:

  * `title`: The question or heading (string)
  * `content`: The answer or panel content (HTML string)

* `unique_id` (string, **required**):

  A unique ID used to isolate multiple accordions on the same page. Use `random()` when including manually.

---

## How to use in a Twig snippet

You can include the Accordion SDC directly in a template like `page.html.twig` using:

```twig
{{ include('groundwork:accordion', {
  unique_id: random(),
  items: [
    {
      title: 'What is Groundwork?',
      content: '<p>Groundwork is a modern, atomic theme framework for Drupal that emphasizes accessibility, performance, and modularity.</p>'
    },
    {
      title: 'Is Groundwork compatible with Drupal 11?',
      content: '<p>Yes! Groundwork is built specifically for Drupal 11+ using Single Directory Components (SDC), Layout Builder, and modern theming best practices.</p>'
    }
  ]
}, with_context = false) }}
```

Make sure `unique_id: random()` is included to prevent ID collisions when multiple accordions are present on the page.

---

## How to use via block

A prebuilt Accordion block is available in the **Groundwork Components** module, which ships with the meta module **Groundwork Helpers**.

You can add it via the Drupal Block UI or Layout Builder. Each block instance allows you to:

* Enter multiple accordion items (title + content)
* Configure the order and content in a structured UI

The block automatically handles unique ID generation internally.

---

## Markup Output

```html
<div class="accordion">
  <h3 class="accordion__header">
    <button class="accordion__trigger" aria-expanded="false" aria-controls="accordion-123456-panel-0" id="accordion-123456-trigger-0">
      What is Groundwork?
    </button>
  </h3>
  <div id="accordion-123456-panel-0" class="accordion__panel" role="region" aria-labelledby="accordion-123456-trigger-0" hidden>
    <p>Groundwork is a modern Drupal theme…</p>
  </div>
  <!-- Repeat for each item -->
</div>
```

---

## Theming & Tokens

All colors, spacing, and font are controlled by your `tokens.css`. Both light and dark themes are supported out of the box.

---

## Accessibility

* Keyboard navigable (tab to button, space/enter to toggle)
* Screen-reader friendly (ARIA markup, region labeling)
* Follows WAI-ARIA accordion pattern

---

## JS Behavior

* Clicking the header toggles the panel.
* Multiple panels can be open at once (optional: adjust for single-open).

---
