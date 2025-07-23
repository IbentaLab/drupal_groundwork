# Twig Coding Standards

**This document outlines the coding standards for Twig templates (**`<span class="selected">.html.twig</span>`) when contributing to the Groundwork Theme Framework. Clear comments in Twig templates are essential for understanding the structure and logic of the markup.

## General Principles

**Effective code is clear and purposeful. Your code and comments should explain ***why* something is done, *what* it does, and *how* it fits into the larger system, especially for non-obvious code.

* **Be Descriptive:** Write self-documenting code and avoid vague comments.
* **Keep it Updated:** Outdated comments are worse than no comments. Always update comments when the code changes.
* **Focus on the "Why":** The code itself often explains "what" it does. Comments should clarify "why" a particular approach was chosen.
* **Target Audience:** Remember that junior developers will be reading these comments. Provide sufficient detail and context.

## Commenting Standards

### Mandatory Template-level Docblock

**Every Twig template file (**`<span class="selected">.html.twig</span>`) *must* start with a docblock.

**Structure:**

```
{#
  @file filename.html.twig
  @description Template for a specific component or block.
  @variables
  • variableName: Description of the variable.
  • anotherVariable: Another variable's description.
#}

```

**Tags:**

* `<span class="selected">@file</span>`: The exact filename of the Twig template.
* `<span class="selected">@description</span>`: A brief, clear description of what this Twig template renders.
* `<span class="selected">@variables</span>`: Lists all variables that are passed into this Twig template.

### Inline Comments

**Use inline comments sparingly within Twig to explain complex logic or specific sections of markup.**

**Structure:**

```
{# Your inline comment here #}

```

## Checklist Before Committing Twig

**Before committing your Twig templates, please review the following checklist:**

* **Template-level Docblock:** Is the header present with all required tags: `<span class="selected">@file</span>`, `<span class="selected">@description</span>`, and `<span class="selected">@variables</span>`?
* **Variable Documentation:** Are all variables used within the template listed and described under the `<span class="selected">@variables</span>` tag?
* **Logic Explanation:** Are complex conditional logic (`<span class="selected">if/else</span>`), loops (`<span class="selected">for</span>`), or filters explained with inline `<span class="selected">{# ... #}</span>` comments?
* **Clarity and Purpose:** Do comments explain *why* a certain structure is used or why a block is included conditionally?
* **Comment Sync:** Have you updated the `<span class="selected">@variables</span>` list and any inline comments if you changed the template's logic or the data it requires?
* **Readability:** Are comments and code wrapped at a reasonable line length (approx. 80-100 characters)?
