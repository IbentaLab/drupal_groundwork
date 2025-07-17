
# 🧱 Layout Strategy – Groundwork Theme

This document explains how layout is structured and managed in the Groundwork theme, ensuring consistency between block placement, Layout Builder usage, and Drupal regions.

---

## 🎯 General Philosophy

Groundwork separates layout responsibilities into two layers:

- **Content Layout (dynamic)** → Powered by **Layout Builder**
- **Structural/Thematic Layout (static)** → Managed via **Theme Regions + Block Layout UI**

This allows for flexibility where it's needed and simplicity where it's not.

---

## 🔷 Layout Builder – For Content Region

Layout Builder is enabled **only** for the `content` region on content types (e.g., Basic Page, Landing Page).

### Use Cases:
- Flexible page-specific layouts
- Drag-and-drop placement of:
  - Core blocks
  - SDCs (Single Directory Components)
  - Custom blocks
- Visual design for content-rich pages

---

## 🟧 Theme Regions – For All Other Layout Areas

All other layout areas are defined as theme regions in `groundwork.info.yml`, and are managed using Drupal’s **Block Layout UI**.

### Example Regions:
- `header`, `hero`, `highlighted`, `footer`
- `preface`, `appendix`, `sidebar_first`, `extra`, `supplement`, etc.

### Use Cases:
- Menus, branding, hero areas
- Sitewide banners or announcements
- Sidebars and footer widgets

Place any of the following in these regions:
- Custom blocks
- Reusable SDCs (via plugin or include)
- Views blocks
- Menu blocks

---

## 🧩 Summary Table

| Region Type     | How it's Managed         | Example Use                     |
|------------------|--------------------------|----------------------------------|
| `content`        | Layout Builder           | Per-page layouts with blocks     |
| `header`, `footer`, etc. | Block Layout UI         | Global site structure            |
| `hero`, `highlighted`    | Block Layout UI         | Homepage visuals or announcements |

---

## 💡 Best Practices

- Use **BSCs** (Block Style Components) for styling reusable blocks visually
- Use **SDCs** (Single Directory Components) for structured, configurable layout blocks
- Keep global UI in regions, and page-specific design inside Layout Builder
- Use Layout Builder overrides only when a page truly needs it

---

Groundwork provides both power and structure. This layout strategy gives you the best of both worlds.
