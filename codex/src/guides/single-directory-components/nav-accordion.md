# Nav Accordion SDC

The Nav Accordion SDC is a robust, accessible, and themeable menu component for expandable navigation—perfect for sidebars, mobile nav, vertical menus, or anywhere you want an expandable/collapsible menu with Drupal menus.

## Features

* Matches Drupal menu structure (`<ul>/<li>`)
* Clean, accessible (button triggers, ARIA)
* Dark/light token-based theming
* One markup, infinite menu flexibility

---

## Usage

### Props

* `items` (array,  **required** ):

  Array of menu items. Each can have:

  * `title`: The link text
  * `url`: The href
  * `children`: Array of child items (same structure)

### Example Twig Include

```twig
{{ include('groundwork:nav-accordion', {
  items: [
    { title: 'Home', url: '/', children: [] },
    {
      title: 'About', url: '/about', children: [
        { title: 'Our Team', url: '/about/team' }
      ]
    }
  ]
}, with_context = false) }}
```

---

## Markup Output

```html
<ul class="nav-accordion nav-accordion--level-0">
  <li class="nav-accordion__item nav-accordion__item--expandable">
    <button class="nav-accordion__trigger" aria-expanded="false" aria-controls="nav-accordion-panel-1">
      About
    </button>
    <ul class="nav-accordion nav-accordion--level-1" id="nav-accordion-panel-1" hidden>
      <li class="nav-accordion__item">
        <a href="/about/team">Our Team</a>
      </li>
    </ul>
  </li>
  <li class="nav-accordion__item">
    <a href="/">Home</a>
  </li>
</ul>
```

---

## Theming & Tokens

All styles use your tokens.css for color, spacing, and font. Supports both light and dark themes.

---

## Accessibility

* Expand/collapse with keyboard or mouse
* Proper ARIA markup for menu items and panels
* Works with screen readers, meets WCAG AA/AAA

---

## JS Behavior

* Click or tap on a button to expand/collapse child menu.
* Multiple panels can be open at once (can be adjusted for “single open” mode).

---

## Example: Vertical Sidebar Menu

```twig
{{ include('groundwork:nav-accordion', {
  items: [
    { title: 'Dashboard', url: '/dashboard' },
    { title: 'Settings', url: '/settings', children: [
      { title: 'Profile', url: '/settings/profile' },
      { title: 'Account', url: '/settings/account' }
    ]}
  ]
}, with_context = false) }}
```

---
