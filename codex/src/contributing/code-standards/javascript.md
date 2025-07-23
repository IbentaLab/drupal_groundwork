# JavaScript (JSDoc) Coding Standards

This document outlines the JSDoc coding standards for JavaScript when contributing to the Groundwork Theme Framework. This allows for generating documentation and provides clear information for developers.

## General Principles

Effective code is clear and purposeful. Your code and comments should explain *why* something is done, *what* it does, and *how* it fits into the larger system, especially for non-obvious code.

* **Be Descriptive:** Write self-documenting code and avoid vague comments.
* **Keep it Updated:** Outdated comments are worse than no comments. Always update comments when the code changes.
* **Focus on the "Why":** The code itself often explains "what" it does. Comments should clarify "why" a particular approach was chosen.
* **Target Audience:** Remember that junior developers will be reading these comments. Provide sufficient detail and context.

## JSDoc Commenting Standards

Groundwork uses JSDoc for documenting JavaScript code.

### Top-of-file Header

Every JavaScript file needs a top-of-file header.

**Structure:**

```
/**
 * @file filename.js
 * @module ModuleName
 * @description Brief overview of the file's purpose.
 * @author Your Name
 * @version 1.0.0
 */

```

**Tags:**

* `@file`: The exact filename.
* `@module`: The name of the JavaScript module defined in this file.
* `@description`: A brief summary of the file's functionality.
* `@author`: Your name.
* `@version`: The current version of the file.

### Function-level Docs

Every public function or method *must* have a JSDoc block explaining its purpose, parameters, return values, and any exceptions it might throw.

**Structure:**

```
/**
 * @function functionName
 * @description Describes what the function does.
 * @param {type} parameterName – Description of the parameter.
 * @returns {type} – Description of what the function returns.
 * @throws {Error} – If the function can throw an error, describe when and why.
 * @async (Optional) – If the function is asynchronous.
 * @example Example usage of the function.
 */
function functionName(parameterName) { /* ... */ }

```

## Checklist Before Committing JavaScript

Before committing your JavaScript code, please review the following checklist:

* **Top-of-file Header:** Is the header present with all required tags: `@file`, `@module`, `@description`, `@author`, and `@version`?
* **Function JSDoc:** Does every public function and method have a complete JSDoc block?
  * Does it have a clear `@description`?
  * Are all parameters documented with `@param {type} name – description`?
  * Is the return value documented with `@returns {type} – description`?
  * Are potential errors documented with `@throws`?
  * Is there an `@example` of its usage?
  * Is the `@async` tag used for asynchronous functions?
* **Clarity and Purpose:** Do comments explain the "why" behind complex algorithms, regular expressions, or business logic?
* **Comment Sync:** Have you updated all relevant JSDoc blocks and inline comments if you changed the function's signature or behavior?
* **Readability:** Are comments and code wrapped at a reasonable line length (approx. 80-100 characters)?
