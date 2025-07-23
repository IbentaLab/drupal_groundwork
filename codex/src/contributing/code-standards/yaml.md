# YAML Coding Standards

This document outlines the coding standards for YAML files (`.yml`) when contributing to the Groundwork Theme Framework. Clear YAML comments are vital for understanding configuration.

## General Principles

Effective configuration is clear and purposeful. Comments should explain *why* a setting is configured in a particular way.

* **Be Descriptive:** Avoid vague comments. Explain the intent.
* **Keep it Updated:** Outdated comments are worse than no comments.
* **Focus on the "Why":** The configuration itself shows "what" it is. Comments should clarify "why" a setting is configured in a particular way.
* **Target Audience:** Remember that junior developers will be reading these comments.

## Commenting Standards

### Top-of-file Docblock (Mandatory)

Every YAML file *must* begin with a top-of-file docblock.

**Structure:**

```
# -----------------------------------------------------------------------------
# @file    filename.yml
# @description Brief summary of the file’s purpose.
# @author  Your Name
# @version 1.0.0
# -----------------------------------------------------------------------------

```

### Section Headers

Before each top-level key or logical group of settings, add a single comment line acting as a section header.

**Example:**

```
# Theme Settings
settings:
  logo:
    use_default: true

# Regions Definition
regions:
  header: 'Header'
  content: 'Content'

```

### Key-Level Comments

Place comments immediately above the key they describe to explain its purpose, allowed values, or default value.

**Example:**

```
# The default color scheme for the theme.
# Allowed values: 'light', 'dark'.
color_scheme: 'light'

```

### Anchors & Aliases

When using YAML anchors (`&`) and aliases (`*`), comment above their definitions and merges to explain what is being defined and inherited.

**Example:**

```
# Define a common set of permissions for authenticated users.
authenticated_permissions: &auth_perms
  - 'access content'

roles:
  # Editor role inherits authenticated user permissions.
  editor:
    permissions:
      - *auth_perms
      - 'edit any content'

```

## Checklist Before Committing YAML

Before committing your YAML files, please review the following checklist:

* **Top-of-file Docblock:** Is the header present with all required tags: `@file`, `@description`, `@author`, and `@version`?
* **Section Headers:** Are logical groups of keys organized under clear section headers (e.g., `# Theme Settings`)?
* **Key-Level Comments:** Does every non-obvious configuration key have a comment above it explaining its purpose, allowed values, or impact?
* **Anchor/Alias Comments:** Are YAML anchors (`&`) and aliases (`*`) clearly commented to explain what is being defined and inherited?
* **Correct Syntax:** Do all comments start with `# ` (a hash and a space)?
* **Comment Sync:** Have you updated comments if you changed the configuration values or structure?
* **Readability:** Are comments and keys indented correctly? Is the file easy to read?
