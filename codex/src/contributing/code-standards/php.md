# PHP Coding Standards

This document outlines the coding standards for PHP files (`.inc`, `.theme`, `.module`, `.php`) when contributing to the Groundwork Theme Framework. Consistent and detailed comments are critical for understanding Drupal's hook system, services, and custom logic.

## General Principles

Effective code is clear and purposeful. Your code and comments should explain *why* something is done, *what* it does, and *how* it fits into the larger system, especially for non-obvious code.

* **Be Descriptive:** Write self-documenting code and avoid vague comments.
* **Keep it Updated:** Outdated comments are worse than no comments. Always update comments when the code changes.
* **Focus on the "Why":** The code itself often explains "what" it does. Comments should clarify "why" a particular approach was chosen.
* **Target Audience:** Remember that junior developers will be reading these comments. Provide sufficient detail and context.

## Commenting Standards

### File-Level Docblock

Every PHP file *must* start with a file-level docblock.

**Structure:**

```
/**
 * @file example.module
 * @ingroup example
 * @description Brief purpose of the file.
 * @author Your Name
 * @license GPL-2.0+ https://opensource.org/licenses/GPL-2.0
 */

```

### Docblocks for Functions & Methods

Every function and method (especially public ones and Drupal hook implementations) *must* have a comprehensive docblock.

**Structure:**

```
/**
 * Short, one-line summary of what the function does.
 *
 * More detailed explanation if needed.
 *
 * @param type $parameter_name
 * Description of the parameter.
 *
 * @return type
 * Description of what the function returns.
 *
 * @throws \Exception (Optional)
 * Description of when and why an exception might be thrown.
 */
function example_function($parameter_name) { /* ... */ }

```

### Annotations

Drupal uses annotations (special PHP docblocks) for plugins and controllers. These also require clear documentation.

**Structure:**

```
/**
 * @Block(
 * id = "groundwork_custom_block",
 * admin_label = @Translation("Groundwork Custom Block")
 * )
 *
 * Provides a custom block for Groundwork.
 */
class GroundworkCustomBlock extends BlockBase {
  // ... block implementation ...
}

```

## Checklist Before Committing PHP

Before committing your PHP code, please review the following checklist:

* **File-level Docblock:** Is the header present with all required tags: `@file`, `@ingroup`, `@description`, `@author`, and `@license`?
* **Function/Method Docblocks:** Does every function, method, and hook implementation have a complete docblock?
  * Does it have a clear summary and detailed description?
  * Are all parameters documented with `@param type $name` and a description?
  * Is the return value documented with `@return type` and a description?
  * Are potential exceptions documented with `@throws`?
* **Annotation Documentation:** Is there a descriptive comment block above every Plugin or Controller class explaining its purpose?
* **Drupal Standards:** Do comments follow Drupal's coding standards for indentation and formatting?
* **Clarity and Purpose:** Do comments explain the "why" behind complex logic, especially in hooks or services?
* **Comment Sync:** Have you updated all docblocks if you changed a function's signature, return value, or behavior?
* **Readability:** Are comments and code wrapped at a reasonable line length (approx. 80-100 characters)?
