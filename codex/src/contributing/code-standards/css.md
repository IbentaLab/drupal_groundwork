# CSS Coding Standards

This document outlines the CSS coding standards for contributing to the Groundwork Theme Framework. Adhering to these guidelines ensures consistency, readability, and maintainability across the codebase.

## General Principles

Effective code is clear and purposeful. Your code and comments should explain *why* something is done, *what* it does, and *how* it fits into the larger system, especially for non-obvious code.

* **Be Descriptive:** Write self-documenting class names and avoid vague comments.
* **Keep it Updated:** Outdated comments are worse than no comments. Always update comments when the code changes.
* **Focus on the "Why":** The code itself often explains "what" it does. Comments should clarify "why" a particular approach was chosen.
* **Target Audience:** Remember that junior developers will be reading these comments. Provide sufficient detail and context.

## Commenting Standards

Groundwork uses specific docblock formats for CSS to provide rich metadata and improve understanding of styles.

### Top-of-file Header (Required)

Every CSS file *must* begin with a top-of-file header. This provides essential information about the file's purpose, its layer within the Groundwork architecture, and authorship.

**Structure:**

```
/**
  * @file filename.css
  * @layer Module
  * @description Brief overview of the file's purpose.
  * @author Your Name
  * @version 1.0.0
  */

```

**Tags:**

* `@file`: The exact filename.
* `@layer`: The architectural layer this file belongs to (e.g., `Block Style Components`, `Layout`).
* `@description`: A concise summary of what the CSS file controls.
* `@author`: Your name.
* `@version`: The file version, following semantic versioning.

### Component-level Docblocks

Use a component-level docblock directly above a distinct UI component's main CSS selector.

**Structure:**

```
/**
  * @component ComponentName
  * @description Styles for a specific UI element.
  * @example <div class="component-name">Content</div>
  * @cssVars
  * • --component-bg: #fff;
  * • --component-padding: 1rem;
  * @accessibility
  * • Ensure sufficient contrast for readability.
  */
.component-name { /* styles */ }

```

### State/Modifier Docblocks

Document states (e.g., `:hover`, `.is-active`) or modifiers (e.g., `.card--large`) with a specific docblock.

**Structure:**

```
/**
  * @state .is-active
  * @description Indicates active state.
  * @state-details
  * • background-color changes to highlight
  * • text color inverted
  */
.component-name.is-active { /* styles */ }

```

### Utility-class Docblocks

Document single-purpose utility classes (BSCs) with their own docblock.

**Structure:**

```
/**
  * @utility utility-class-name
  * @description Describes what the utility class does.
  * @example <span class="utility-class-name">Text</span>
  * @accessibility Any specific accessibility notes for this utility.
  */
.utility-class-name { /* styles */ }

```

## Checklist Before Committing CSS

Before committing your CSS code, please review the following checklist:

* **Top-of-file Docblock:** Is the header present with all required tags: `@file`, `@layer`, `@description`, `@author`, and `@version`?
* **Component Docblocks:** Does every distinct UI component have a `@component` docblock detailing its purpose, `@example` usage, `@cssVars`, and `@accessibility` notes?
* **State/Modifier Docblocks:** Are all states (`.is-active`, `:hover`) and modifiers (`.card--large`) documented with `@state`, `@description`, and `@state-details`?
* **Utility Docblocks:** Does every utility class have a `@utility` docblock with a clear `@description` and `@example`?
* **Clarity and Purpose:** Do comments explain the "why" behind complex selectors or non-obvious properties (e.g., z-index values, specific transform hacks)?
* **Comment Sync:** Have you updated all relevant comments if you changed the CSS code?
* **Readability:** Are comments and code wrapped at a reasonable line length (approx. 80-100 characters)?
