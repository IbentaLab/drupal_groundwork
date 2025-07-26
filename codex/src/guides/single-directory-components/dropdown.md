# Dropdown SDC (Groundwork)

A **Single Directory Component** (SDC) for accessible, reusable dropdown menus and popovers. Ideal for navigation, actions, and more.

---

## What is the Dropdown SDC?

The Dropdown SDC provides a trigger (button or link) that reveals a panel of menu items or custom content. It can be used for navigation menus, action menus, user profile dropdowns, and more.

---

## Where and Why Use Dropdowns?

* Navigation bars (multi-level menus)
* Action menus (edit, delete, more options)
* User avatar/profile menu in headers
* Any place you need a popover or hidden panel that opens on demand

---

## How to Use (For Site Builders)

### **1. In Layout Builder**

* Add a block or component
* Select the "Dropdown" component
* Define the trigger label/icon and the menu items/content
* Save—done!

### **2. In Twig Templates (for themers/developers)**

```twig
{% set nav_items = [
  { title: 'My Profile', url: '/user/profile' },
  { title: 'Settings', url: '/user/settings' },
  { title: 'Logout', url: '/user/logout' },
] %}
{{ include('groundwork:dropdown', { trigger: 'Account', items: nav_items }, with_context = false) }}
```

---

## Features

* **Fully accessible:**
  * Keyboard navigation and focus trap
  * ESC closes dropdown
  * ARIA roles (menu/menuitem)
* **Customizable:**
  * Any content, not just links
  * Uses theme tokens for style
* **Reusable:**
  * Can be embedded in Navigation SDCs, headers, footers, sidebars

---

## Accessibility Notes

* All triggers are keyboard-focusable
* Full ARIA menu support
* Works for both mouse and keyboard users

---

## Screenshot Example

![Dropdown SDC Screenshot](https://chatgpt.com/g/g-p-6847e31f43d08191a965bb28943bccc9-groundwork/c/path/to/screenshot.png)

---

> Need help? See the [Groundwork Codex Components Guide](https://chatgpt.com/g/g-p-6847e31f43d08191a965bb28943bccc9-groundwork/c/link/to/guide).
>
