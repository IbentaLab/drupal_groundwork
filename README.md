# 🚀 Groundwork Theme Framework

**The fast, accessible, atomic foundation for block-based Drupal.**

---

<div align="center">

<img src="images/drupal-11+--blue.svg" alt="Drupal 11+" height="24">
<img src="images/no-build-tools-100-percent-vanilla--brightgreen.svg" alt="No Build Tools" height="24">
<img src="images/accessibility-wcag_2.1_aa _norwegian-law--blueviolet.svg" alt="WCAG 2.1 AA & Norwegian Law" height="24">
<img src="images/performance-first-informational.svg" alt="Performance First" height="24">

</div>

---

**Groundwork Theme Framework** is the next-generation Drupal theming framework—engineered for ⚡ speed, ♿ accessibility, and 💡 developer/editor joy. Experience utility-driven, atomic theming—**no build tools, no dependencies, instant results**.

---

## ✨ Why Choose Groundwork?

### 🎨 Atomic Utility Classes & Block Style Components (BSC)
- **Instant atomic styling:** Add spacing, color, alignment, and effects with classes like `.p-4`, `.bg-primary`, `.text-center`, `.shadow-lg`—anywhere in your markup.
- **Composable & universal:** BSCs work on blocks, fields, SDCs, and any element. Apply via UI or class attribute—no custom markup or templates needed.
- **Block presets:** Transform blocks instantly with `.card`, `.alert--warning`, `.banner` and more using the **Block Styles UI** (see below) or by adding classes.

### 🛠️ No Build Tools. No Bloat.
- **Zero Node, SCSS, or Webpack:** 100% vanilla CSS, Twig, and JS. Start instantly, keep your theme future-proof and maintainable.
- **Design tokens:** Every color, space, and type is powered by CSS variables (`var(--token)`)—for a scalable, consistent design system.

### ♿ Accessibility By Default
- **WCAG 2.1 AA & Norwegian Universal Design Regulation:** Semantic markup, visible focus, high-contrast tokens, full keyboard/screen reader support.
- **Accessibility is built in:** Every template, utility, and component is designed for inclusivity.

### 📦 Block-Based & Layout Builder-Ready
- **Drag-and-drop page building:** Compose layouts visually with Drupal’s Layout Builder.
- **Hybrid Style Components (HSC):** Solve complex layouts (like media objects, two-columns) with reusable CSS classes—no custom markup needed.
- **Single Directory Components (SDC):** Build modular, self-contained UI pieces (hero, modal, accordion) with their own Twig, CSS, JS, and YAML.

### 🧑‍💻 Modern CSS—No Legacy Baggage
- **Built for the future:** Flexbox, Grid, gap, container queries, aspect-ratio, and custom properties. No floats or legacy resets.
- **SMACSS/BEM naming:** Maintainable, predictable CSS structure.

### 🤝 Developer & Editor Joy
- **Clear docs:** Practical, concise documentation for developers and site builders.
- **No lock-in:** Easily extend, override, or swap out components as your project grows.
- **Performance-first:** Optimized for Lighthouse a11y/perf out of the box.

---

## 🚀 Quick Start

```sh
composer require drupal/groundwork
```
Or download from [drupal.org/project/groundwork](https://www.drupal.org/project/groundwork).

```sh
drush theme:enable groundwork
drush config-set system.theme default groundwork
```

1. **Compose pages using either:**
    - **Layout Builder** for visual, drag-and-drop page building (optional but fully supported), **or**
    - **Drupal's core Block UI** for familiar block placement.
2. **Apply Block Style Components (BSC) atomic classes** or block presets via the “Groundwork Block Styles” UI (see below) or class field.
3. **Use Hybrid Style Components (HSC)** for complex internal layouts.
4. **Build with SDC** for modular, reusable custom elements.

---

## 🧩 Key Features

- 🎯 **Atomic utility classes for instant layout and style—anywhere**
- 🖌️ **Universal Block Style Components & Hybrid Style Components**
- 🏗️ **Responsive 12-column grid system**
- 🧑‍🎨 **100% Vanilla CSS, HTML, Twig, and JS—no build process required**
- 🎨 **Design tokens for all colors, spacing, and typography**
- ♿ **Accessibility-first: WCAG 2.1 AA & Norwegian compliance**
- 🧱 **Works perfectly with Layout Builder & Single Directory Components**
- ⚡ **Performance-first, future-proof architecture**

---

## 🛠️ Extend Groundwork with Companion Modules

Want even more power?  
Pair Groundwork Theme Framework with the official **Groundwork Helpers** companion module:

- **Groundwork Helpers** is a modular meta module that supercharges your Groundwork theme experience. It brings design-system tools, icon management, block styling, accessibility helpers, responsive images, layout patterns, and developer/a11y tools into the Drupal UI for both developers and editors.  
  *Install once, enable only the features you need!*

    - **Block Styles**: Effortlessly apply and preview custom styles and layouts to any block with a drag-and-drop admin UI and live preview.
    - **Gwicons**: Browse, search, and insert SVG icons directly from the Drupal admin with an icon picker and centralized SVG management.
    - **Responsive Images**: Smart, automatic image handling for performance and accessibility.
    - **Layout Patterns**: Pre-built, flexible layout recipes for rapid prototyping.
    - **DevTools & A11y Audit**: Developer and accessibility helpers to optimize theming, debugging, and compliance.

<sub>*Groundwork Helpers is optional, but highly recommended for teams wanting drag-and-drop block styling, design tokens, instant icon access, and advanced dev/editor tools—all seamlessly integrated with Groundwork and the Drupal 11 block system.*</sub>

---

## 📚 Documentation & Support

- [Full Documentation](https://groundwork.ibenta.no)
- [Component Library](./components/)
- [Contributing Guide](./CONTRIBUTING.md)

---

## 🏆 About Groundwork

Groundwork Theme Framework is developed and maintained by [John Filipstad (JohnNoc)](https://www.drupal.org/u/johnnoc), a Drupal specialist and frontend innovator with nearly 20 years of experience in the Drupal community. Groundwork is dependency-free, future-ready, and built for teams who want to _build ambitious Drupal sites, faster_.

---

> “Groundwork Theme Framework empowers you to build fast, accessible, and beautiful Drupal sites—**without the bloat or build tools**. Embrace atomic design, block-based authoring, and deliver results at any scale.”

---

<div align="center">

🌟 **Adopt Groundwork Theme Framework today and experience the future of Drupal theming!** 🌟

</div>