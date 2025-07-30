# Horizontal Menu (Single‑level & Multi‑level)

The Groundwork framework provides two ways to create horizontal navigation bars. Both use a common set of design tokens and SMACSS/BEM naming, but they serve different purposes depending on the depth of your menu:

* **Single‑level Horizontal Menu (HSC)** – a pure CSS *Hybrid Style Component* used to lay out a list of links in a single row. It contains **no JavaScript** and makes no assumptions about dropdowns or sub‑menus. It is ideal for simple navigation lists, footers, or any `<ul>`/`<nav>` with only top‑level links.
* **Multi‑level Horizontal Menu (SDC)** – a *Single Directory Component* that builds on the single‑level styling and adds the necessary markup and behaviour for **dropdowns** (level‑2) and **mobile accordions** (level‑3). It includes its own Twig template, CSS, and JS to manage `aria-expanded` states, focus and keyboard support. It automatically uses the Accordion SDC for deeper levels.

---

## 🧱 Single‑level Horizontal Menu (HSC)

Use the single‑level horizontal menu when your list has no child items. It’s nothing more than a layout/skin class. Applying the HSC class will:

* Display the list items horizontally using flexbox.
* Apply consistent padding, colours and spacing using design tokens.
* Require **no** additional markup or JavaScript.

### How to apply

1. Create or identify a `<nav>` or `<ul>` element that contains only top‑level links.
2. Add the `menu--horizontal` class to the parent element. For example:

```html
<nav class="menu--horizontal">
  <ul class="menu menu--level-0">
    <li class="menu-item"><a href="/about">About Us</a></li>
    <li class="menu-item"><a href="/contact">Contact</a></li>
    <li class="menu-item"><a href="/blog">Blog</a></li>
  </ul>
</nav>
```

Because this is a pure HSC, there is  **no dropdown or accordion support** . If you need interactive sub‑menus, use the multi‑level horizontal menu described below.

### When to use

* Simple navigation bars with no child items.
* Lists of quick links in a header or footer.
* Horizontal lists in custom blocks where editors have manually typed `<ul>` markup.

---

## 🧩 Multi‑level Horizontal Menu (SDC)

When your menu has two or more levels, you need more than just CSS. The multi‑level horizontal menu is delivered as an SDC and includes:

* A Twig template that renders the correct semantic structure (`<nav>`, `<ul>`, `<li>`) and inserts **toggle buttons** for child items.
* CSS that inherits the horizontal layout from the HSC, plus styles for dropdown panels on desktop and accordions on mobile. It uses classes like `.submenu-toggle`, `.is-open`, and `.menu--level-1` to control visibility.
* JavaScript that listens for clicks on the main hamburger and each submenu toggle. It updates `aria-expanded` attributes and toggles `.is-open` on the menu, nav wrapper, and body for accessibility.
* Integration with other SDCs: level‑2 dropdowns rely on the **Dropdown SDC** and level‑3 accordions rely on the  **Accordion SDC** .

### How to use

1. Place the `navigation-menu` component (or whatever the component is named) via Layout Builder or a block placement. You can pass props such as `menuName`, `orientation` and `transparent` via the component YAML or block configuration.
2. The component automatically adds the `menu--horizontal` class for you and attaches its own JS library. You don’t need to manually add the HSC class unless you are overriding the layout.
3. The component will detect the depth of your menu:
   * Two levels → top‑level items are horizontal, second level items appear in dropdown panels on hover/focus.
   * Three levels → on mobile, the third level is displayed in an accordion under the second level using the Accordion SDC.

Example usage in a Twig template:

```twig
{% set props = {
  menuName: 'main',
  orientation: 'horizontal',
  transparent: true
} %}
{% component 'navigation-menu' with props %}
```

### When to use

* Primary navigation bars with nested sections.
* Secondary or tertiary menus that require dropdowns on desktop and collapsible sections on mobile.
* Anywhere a site builder needs a fully featured navigation component that remains accessible and responsive.

---

## ⚖️ Choosing between HSC and SDC

| Use case                                                    | Recommended approach                                                                                      |
| ----------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| A menu or list with**no child items**                 | Apply the `menu--horizontal`HSC directly. No SDC needed.                                                |
| A menu with**two levels**(needs dropdowns)            | Use the**Multi‑level Horizontal Menu SDC** ; it will include the dropdown behaviour automatically. |
| A menu with**three or more levels**(needs accordions) | Use the**Multi‑level Horizontal Menu SDC** ; it will use the Accordion SDC for deeper levels.      |
| A custom list where you only want horizontal layout, no JS  | Use a utility BSC (e.g.`list--horizontal`) for simple flex styling, or the HSC for menu lists.          |

---

## 🛡️ Accessibility considerations

* Always wrap navigation in a `<nav>` element and provide an `aria-label` or `aria-labelledby` attribute so screen readers can identify the menu.
* Use `<ul>` and `<li>` elements for the menu structure. Each link should be an `<a>` element.
* For multi‑level menus, ensure toggle buttons update their `aria-expanded` attributes and point to the correct `aria-controls` IDs. The Groundwork SDC handles this for you. Avoid hand‑coding complex menus without these attributes.
* On mobile, disabling body scrolling (`body.is-menu-open { overflow:hidden; }`) prevents background content from moving while the menu is open.

---

## 🛠️ Developer notes

* The single‑level horizontal menu is implemented as a **Hybrid Style Component** in `css/hybrid-style-components/menu-horizontal.css`. It should contain **only CSS** and no structural assumptions.
* The multi‑level horizontal menu lives in the **components/** directory as a  **Single Directory Component** . Its JS behaviour comes from `js/menu-toggle.js` and will eventually be migrated to a component‑local script.
* Preprocess logic in `inc/preprocess.inc` attaches the `.menu--horizontal` class and `#is_horizontal` flag based on theme settings. When refactoring to an SDC, this logic should be moved into the component so any menu can be rendered horizontally, not just the main and secondary menus.

By keeping the single‑level HSC and the multi‑level SDC separate, Groundwork provides a clear, accessible way to style simple lists horizontally while still offering a powerful, reusable navigation component for more complex menus.

---
