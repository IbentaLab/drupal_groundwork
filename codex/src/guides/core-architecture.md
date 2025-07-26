# Core Architecture of Groundwork

Groundwork is more than just a Drupal theme — it’s a modular frontend system designed to help you build fast, accessible, and flexible layouts using native Drupal tools.

At the core of Groundwork are  **six powerful building blocks** , each serving a specific purpose and designed to work together:

1. **Block Style Components (BSC)**
2. **Hybrid Style Components (HSC)**
3. **Single Directory Components (SDC)**
4. **Framework Partials (FP)**
5. **Grid System**
6. **Layout Builder Integration**

These pieces form the architectural backbone of Groundwork.

---

## 🔧 1. Block Style Components (BSC)

**Concept:** Atomic utility classes that apply visual styling to any block or element — no CSS files or overrides needed.

**Purpose:** BSCs allow both developers and editors to apply consistent, reusable styles via class names.

**Examples:**

```html
<div class="card p-4 shadow text-center">Styled with BSCs!</div>
```

| Category       | Sample Classes                    | CSS File Location                                  |
| -------------- | --------------------------------- | -------------------------------------------------- |
| Spacing        | `.p-4`,`.mt-2`,`.mb-6`      | `css/block-style-components/spacing.css`         |
| Typography     | `.text-lg`,`.text-center`     | `css/block-style-components/text-utilities.css`  |
| Color          | `.bg-light`,`.text-dark`      | `css/block-style-components/color-utilities.css` |
| Visual Effects | `.card`,`.shadow`,`.border` | `css/block-style-components/shadow.css`etc.      |

**How to Use:**

* Developers: Add BSCs in templates or custom markup
* Editors: Use the **Block Styles UI** from the Groundwork Helpers module

---

## 🧱 2. Hybrid Style Components (HSC)

**Concept:** Predefined layout + style patterns — more than just utilities, but less than full components.

**Purpose:** Quickly create consistent sections like hero banners, grids, or media layouts.

**Example:**

```html
<section class="grid grid--cards bg-light p-4">
  <div class="card">Card 1</div>
  <div class="card">Card 2</div>
</section>
```

**Use Cases:**

* Card grids
* Highlight sections
* Two-column layouts with image + text

📁 Location: `css/hybrid-style-components/`

---

## 📦 3. Single Directory Components (SDC)

**Concept:** Self-contained UI components in a single folder, powered by Drupal core’s SDC system.

**Why It Matters:**

* No external modules needed
* Everything lives together: Twig + CSS + JS + YAML
* Automatically registered by Drupal

**Structure Example:**

```
/components/hero/
├── hero.twig
├── hero.css
├── hero.js (optional)
└── hero.component.yml
```

**Use Cases:**

* Hero sections
* Accordions
* Modals, tabs, or sliders
* Social bar (e.g., injected via theme settings)

📁 Location: `components/`

---

## ✂️ 4. Framework Partials (FP)

**Concept:** Small, reusable UI snippets — perfect for keeping code DRY.

**Examples:**

* SVG icon: `gwicons.twig`
* Dividers, ribbons, or taglines

**How to Use:**

```twig
{% include '@framework-partials/icon.twig' with { name: 'search' } %}
```

📁 Location: `framework-partials/`

> Groundwork automatically injects the SVG icon sprite into the `<head>`, enabling inline performance.

---

## 📐 5. Grid System

**Concept:** A full 12-column responsive layout system using Flexbox. No Bootstrap or frameworks.

**Features:**

* `.grid`, `.grid-cell`, `.grid--with-gutter`
* Width utilities like `.is-6`, `.is-third`, `.is-4--l`

**Example:**

```html
<div class="grid grid--with-gutter">
  <div class="grid-cell is-4">1/3</div>
  <div class="grid-cell is-8">2/3</div>
</div>
```

📁 Location: `css/layout/grid.css`

---

## 🎨 6. Layout Builder Integration

**Concept:** Groundwork augments Drupal’s Layout Builder with visual styling and reusable components.

**Highlights:**

* Use Layout Builder to drag in SDCs and core blocks
* Apply BSC and HSC classes using the Block Styles UI
* Groundwork Helpers adds layout patterns and visual previews

**Example Workflow:**

1. Enable Layout Builder on a content type
2. Add a section and block
3. Apply BSC classes like `p-6 bg-light text-center`

---

## 🧠 Summary: When to Use What

| Goal                                     | Use This          |
| ---------------------------------------- | ----------------- |
| Style any block or element               | ✅ BSC            |
| Structure a full-width visual section    | ✅ HSC            |
| Reuse complex UI across pages            | ✅ SDC            |
| Reuse small bits of markup (e.g., icons) | ✅ FP             |
| Create responsive multi-column layouts   | ✅ Grid System    |
| Build drag-and-drop page layouts         | ✅ Layout Builder |

> Groundwork’s architecture is designed to be  **modular** ,  **composable** , and  **accessible by default** .

Start exploring each component in the [Guides Index](index.md).
