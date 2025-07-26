
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

### Example Twig Include

```twig
{{ include('groundwork:accordion', {
  items: [
    { title: 'What is Groundwork?', content: '<p>Groundwork is a modern Drupal theme…</p>' },
    { title: 'How do I install it?', content: '<p>See the installation guide…</p>' }
  ]
}, with_context = false) }}
```

---

## Markup Output

```html
<div class="accordion">
  <h3 class="accordion__header">
    <button class="accordion__trigger" aria-expanded="false" aria-controls="content-accordion-panel-0" id="content-accordion-trigger-0">
      What is Groundwork?
    </button>
  </h3>
  <div id="content-accordion-panel-0" class="accordion__panel" role="region" aria-labelledby="content-accordion-trigger-0" hidden>
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

## Example: FAQ Block

```twig
{{ include('groundwork:accordion', {
  items: [
    { title: 'Is Groundwork free?', content: '<p>Yes. 100% open source.</p>' },
    { title: 'Does it support dark mode?', content: '<p>Yes, instantly via tokens.css.</p>' }
  ]
}, with_context = false) }}
```

---
