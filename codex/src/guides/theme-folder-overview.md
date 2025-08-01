**🧱 Understanding the Groundwork Theme Framework**

Welcome to the heart of the Groundwork Theme Framework — where structure meets strategy. If you're new to Groundwork or looking to understand how it’s built under the hood, this guide will walk you through the theme’s folder structure, philosophy, and the tools available to help you build powerful, accessible Drupal websites without friction.

---

## 📘 The `codex/` Folder – Documentation That Teaches and Inspires

This is where the magic of Groundwork documentation lives. Everything inside the `codex/` folder powers the Groundwork Codex — our live documentation and demo site. It’s designed to guide you step-by-step through how Groundwork works and how you can make the most of it. Whether you're a seasoned developer or just starting out, the Codex is your go-to reference.

---

## 🧩 The `components/` Folder – Fully Encapsulated SDCs

Inside `components/`, you’ll find **Single Directory Components** — a built-in feature of Drupal core introduced in version 11+. Each SDC is a complete unit: a Twig file, CSS, optional JavaScript, and a component definition YAML file. These components are reusable, encapsulated, and can be dropped directly into Layout Builder or templates.

Best of all? Many of them are automatically made available as Drupal blocks via the **Groundwork Components** module (included in the Groundwork Helpers meta-module). This gives both developers and site builders an easy way to use them visually — no custom code needed.

---

## 🎨 The `css/` Folder – Groundwork’s Visual Powerhouse

This is where Groundwork truly shines. The `css/` directory is smartly organized into several subfolders, each with a focused role:

### 🔧 `block-style-components/` – Style Blocks, Instantly or Atomically

This is the home of **Block Style Components (BSCs)** — Groundwork’s hybrid utility system. These utility classes have dual purpose. You can style any element atomically by manually adding them to your HTML, or you can style Drupal blocks visually through the **Groundwork Block Styles UI** (a submodule of Groundwork Helpers). It's powerful, flexible, and designed for both code and no-code workflows.

### 💎 `partials/` – Tiny, Reusable UI Fragments

These are small, atomic UI helpers — like `.badge`, `.ribbon`, `.chip`, and more. They are typically used inside SDCs or template files, but of course, you can use them anywhere in your HTML. They are not intended to style entire blocks and are excluded from the Block Styles UI to keep things clean and purposeful.

### 🖌️ `theme/` – Your Brand’s Style, Instantly

Groundwork comes with a set of prebuilt theme utility stylesheets — one for each supported color palette. These files (e.g., `theme-utility-blue.css`, `theme-utility-orange.css`, etc.) can be toggled on or off from the Groundwork theme settings page. You choose the brand style — Groundwork does the rest.

These utilities work seamlessly with the design token system defined in `groundwork-tokens.css`, giving you consistent, accessible color behavior across your entire site.

### 🧱 `layout/` – The Page Structure Layer

This folder contains the grid system and macro layout classes that shape your page. This is where layout behavior is defined — from the outer page structure to the alignment of block regions. It's less about styling individual elements and more about ensuring your entire layout stays flexible and consistent across breakpoints.

### 🪄 `admin/`, `base/`, `system/`

These folders contain critical foundational styles: resets, accessibility helpers, admin UI tweaks, and structural base rules. They're part of what makes Groundwork accessible and consistent out of the box.

---

## 🧰 Additional Essential Folders

* `templates/` contains Drupal template overrides — such as `html.html.twig`, `page.html.twig`, and `block.html.twig`.
* `inc/` holds preprocess logic and theme settings definitions. For example, `inc/settings/` defines the comprehensive **Groundwork Theme Settings UI** — allowing users to style layout, navigation, social links, regions, and more from the Appearance settings page.
* `icons/`, `fonts/`, `images/`, and `logo/` store all your media assets. Groundwork’s SVG icons integrate directly into Gwicons for easy theming.

---

## 🎯 Why It All Matters

Groundwork is more than just a theme — it’s a modern framework for Drupal front-end development. Everything is structured to help you:

* Build consistent layouts and patterns faster.
* Apply styles with or without code.
* Customize design while keeping accessibility and performance intact.

So go ahead — explore the folders, test out the utilities, and drop in an SDC. You’ll quickly discover that Groundwork isn’t just organized. It’s empowering.

You're not just theming a site. You're building with intention, flexibility, and the future of Drupal theming.
