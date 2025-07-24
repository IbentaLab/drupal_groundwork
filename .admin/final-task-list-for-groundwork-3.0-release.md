# ✅ Groundwork 3.0 Final Task List

This task list is structured for creating GitHub issues. Each item represents a distinct piece of work for the 3.0 milestone.

## 🏛️ Foundational & Architectural Tasks

*   **Task: Finalize Core Layout Structure**
    *   **Description:** Review and complete the primary page and region-level layouts (`page.html.twig`, region templates). Ensure all regions (`header`, `content`, `sidebar`, `footer`, etc.) are defined and behave responsively. This sets the global structure for all other components.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Finalize Theme Settings UI Design**
    *   **Description:** Design and style the theme settings page (`theme-settings.css`). Create a clean, user-friendly interface for site builders to configure Groundwork's features.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Finalize Block Demo Admin Page**
    *   **Description:** Complete the design and functionality of the admin block demo page (`block-demo.css`). This page is crucial for developers and site builders to see available BSCs and HSCs in action.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Implement Dark/Light Mode Strategy**
    *   **Description:** Implement the `data-theme="dark"` toggle mechanism. All color tokens in `color-utilities.css` must be defined in `:root` and have overrides for the dark theme. Create the theme setting toggle to control the default mode and respect user preference.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Implement RTL Support Strategy**
    *   **Description:** Refactor all relevant CSS to use logical properties (e.g., `margin-inline-start` instead of `margin-left`). Create an `rtl.css` file for any necessary overrides that logical properties cannot handle.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Establish Groundwork Helpers Module MVP**
    *   **Description:** Create the `groundwork_helpers` module. The minimum viable product must bundle the Block Styles UI, allowing site builders to apply BSCs to blocks without making the theme dependent on another module.
    *   **Priority:** `[ESSENTIAL]`

---
## 🧱 Single Directory Components (SDC)

*SDCs are used for components requiring a unique combination of structure (Twig), style (CSS), and/or behavior (JS).*

*   **Task: Create SDC: `Alert`**
    *   **Description:** Build a component for contextual feedback messages (status, warning, error) with `role="alert"`, accessible color-coded types, and an optional dismiss button (JS).
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create SDC: `Accordion`**
    *   **Description:** Build a component for vertically stacked headers that reveal content panels, following ARIA patterns for `aria-expanded` and state toggling (JS).
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create SDC: `Tabs`**
    *   **Description:** Build a component for layered content sections, following ARIA patterns for `role="tablist"` and managing active states (JS).
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create SDC: `Modal`**
    *   **Description:** Build a dialog/popup component that manages a focus trap, `role="dialog"`, and `aria-modal="true"` state (JS).
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Review & Refactor SDC: `Dropdown Menu`**
    *   **Description:** We have `js/menu-toggle.js`. Review this and the associated CSS (`menu-horizontal.css`). Refactor into a robust, accessible SDC that manages `aria-expanded` states and focus. It should replace the existing HSC/JS implementation.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create SDC: `Hero`**
    *   **Description:** Build a large banner component with slots for a background image, content overlay, semantic heading, and a call-to-action.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create SDC: `Pagination`**
    *   **Description:** Build a navigation component for paginated content, using `<nav aria-label="pagination">` and `aria-current="page"`.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create SDC: `Skip Nav`**
    *   **Description:** Build a component for the "Skip to main content" link, a core accessibility feature that is visible on focus.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create SDC: `Site Header`**
    *   **Description:** Build a wrapper SDC for the site header. This component will provide the core structure and slots for branding, navigation, and utility menus. It will be the target for the `header--*` HSC layout classes.
    *   **Theme Settings:** The theme settings UI will apply an HSC class to this component to switch between layouts.
    *   **Priority:** `[DISCUSS]`

*   **Task: Create SDC: `Site Footer`**
    *   **Description:** Build a wrapper SDC for the site footer, providing slots for menus, legal text, etc. This component can be styled with HSCs like `footer--3-col`.
    *   **Priority:** `[DISCUSS]`

*   **Task: Create SDC: `Carousel`**
    *   **Description:** Build a slideshow component with a high focus on accessibility (play/pause controls, screen reader announcements). Due to a11y risks, this is optional.
    *   **Priority:** `[OPTIONAL]`

---
## 🧩 Hybrid Style Components (HSC)

*HSCs are CSS classes (with optional JS) that apply layout and style to the internal structure of a generic Drupal block or SDC.*

*   **Task: Create HSC: Header Layouts (`header--brand-left`, `header--brand-center`, `header--stacked`)**
    *   **Description:** Create three distinct CSS-only layout classes that use flexbox or grid to arrange the blocks within the header region (or the `Site Header` SDC).
    *   **Theme Settings:** These will be exposed as a radio/select list in the theme settings to allow site builders to choose a header layout.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create HSC: Footer Layouts (`footer--3-col`, `footer--legal`)**
    *   **Description:** Create CSS classes to style the blocks within the footer, providing a 3-column default and a compact variant for legal/copyright info.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create HSC: Two-Column Layouts (`layout--2-col-sidebar-left`, `layout--2-col-sidebar-right`)**
    *   **Description:** Create CSS classes that arrange a container's direct children into a main content area and a sidebar, with logical DOM ordering.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create HSC: `prose`**
    *   **Description:** Create a CSS class that applies beautiful, readable typography styling to long-form text containers (e.g., the body of an article).
    *   **Priority:** `[DISCUSS]`

---
## 🖌️ Block Style Classes (BSC) / Utilities

*BSCs are atomic, single-purpose, reusable CSS classes. We have ~10 existing BSC files. We need to add ~30-40 more utilities to reach our goal.*

*   **Task: Review & Finalize Existing BSCs**
    *   **Description:** Review all existing BSC files (`border.css`, `card.css`, `grid-system.css`, `hover.css`, `margin.css`, `padding.css`, `rounded.css`, `shadow.css`, `text.css`, `text-utilities.css`). Ensure they use CSS variables and logical properties where appropriate and are documented.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create BSC: `Display & Position` Utilities**
    *   **Description:** Create classes like `.d-block`, `.d-inline-block`, `.d-flex`, `.d-grid`, `.d-none`, `.position-relative`, `.position-absolute`. (5-10 classes)
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create BSC: `Flexbox & Grid` Utilities**
    *   **Description:** Create classes for flex/grid behavior: `flex-direction-column`, `justify-content-start`, `align-items-center`, `gap-1`, `grid-template-columns-3`, etc. (10-15 classes)
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create BSC: `Sizing` Utilities**
    *   **Description:** Create classes for width and height: `.w-25`, `.w-50`, `.w-75`, `.w-100`, `.w-auto`, `.max-w-100`, `.vh-100`. (5-10 classes)
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create BSC: `Overflow` Utilities**
    *   **Description:** Create classes like `.overflow-hidden`, `.overflow-auto`, `.overflow-x-scroll`. (3 classes)
    *   **Priority:** `[OPTIONAL]`

*   **Task: Create BSC: `Z-Index` Utilities**
    *   **Description:** Create classes like `.z-index-0`, `.z-index-10`, `.z-index-master`. (3-5 classes)
    *   **Priority:** `[DISCUSS]`

---
## 📄 Framework Partials (FP)

*FPs are Twig-only macros/includes for reusing HTML structure. They are helpers, not full components, and should not be confused with CSS Core Overrides.*

*   **Task: Create FP: `icon.twig`**
    *   **Description:** Create a Twig macro to render SVG icons with proper accessibility attributes (`aria-hidden="true"`).
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create FP: `form-element.twig`**
    *   **Description:** Create a Twig macro to standardize rendering of form elements (label, input, description, errors) with correct `for`/`id` and `aria-describedby` attributes.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create FP: `link.twig`**
    *   **Description:** Create a Twig macro to render `<a>` tags, centralizing logic for adding attributes for external links (`target`, `rel`) or other states.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Create FP: `image.twig`**
    *   **Description:** Create a Twig macro for responsive images using the `<picture>` element, handling lazy loading and aspect ratios.
    *   **Priority:** `[DISCUSS]`

---
## ✅ Release & Documentation Tasks

*   **Task: Write Documentation for All Components**
    *   **Description:** Create a documentation page/section for every SDC, HSC, and BSC. Each page must include a description, usage example, accessibility notes, and any relevant props/variables.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Perform Comprehensive Accessibility Audit**
    *   **Description:** Conduct a full WCAG 2.1 AA audit using automated tools (axe, Lighthouse) and manual testing (keyboard navigation, NVDA/VoiceOver).
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Conduct Cross-Browser & Device Testing**
    *   **Description:** Test all components and layouts on the latest versions of major browsers (Chrome, Firefox, Safari, Edge) and on various device sizes.
    *   **Priority:** `[ESSENTIAL]`

*   **Task: Prepare `3.0.0` Stable Release**
    *   **Description:** Finalize the `CHANGELOG.md`, update all version numbers, and tag the official `3.0.0` release once all other tasks are complete.
    *   **Priority:** `[ESSENTIAL]`

---
