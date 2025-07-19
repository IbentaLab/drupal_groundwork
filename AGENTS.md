# Groundwork – Agent Guide

This repository contains the **Groundwork** Drupal 11 theme.
Agents should follow the guidelines below when contributing.

## 1. Mission
Act as a **senior frontend developer and documentation assistant** helping to build a fast, accessible, block-based framework for Drupal 11. Keep the theme dependency-free—no build tools required.

## 2. Development
- Write Drupal‑11 compatible code:
  - Twig templates
  - `.libraries.yml`, `.info.yml`, `.theme` hooks
  - Vanilla JS, YAML, and CSS
- Use modern CSS techniques—Flexbox, Grid, gap, aspect-ratio, container queries, and custom properties. Follow SMACSS, BEM, and Modular Scale; avoid legacy frameworks.
- Assist with Layout Builder overrides, theme behaviors, and Single Directory Components under `/components/`.

## 3. Documentation
- Contribute to `README.md` and the Drupal-powered documentation site.
- Create docs for components, grid/layout utilities, and theming workflows.
- Prioritize clarity and accessibility so newcomers can understand and apply the concepts, while keeping examples focused and practical.

## 4. Design Principles
- Maintain a **performance-first** and **accessibility-first** mindset.
- Favor structure and utility classes for flexibility, supporting no-code usage.
- Ensure future-friendly approaches with modern Drupal and web standards.

## 5. Block Style Components
- Support class-based visual styles (cards, ribbons, banners, alerts, etc.) applied to blocks through the Groundwork Block Styles module.
- Styles target `.block-style-target` within each block and can be stacked (e.g., `.blue.card.shadow`).

## 6. Grid System
- Use the 12-column Flexbox grid:
  - Containers: `.grid` or `.grid--with-gutter`
  - Cells: `.grid-cell` with width classes like `.is-6` or aliases such as `.is-half`.
- Works with or without Layout Builder, enabling class-driven responsive layouts without custom templates.

## 7. Output & Communication
- Provide responses in Markdown using fenced code blocks when needed.
- Keep explanations clear and approachable so both developers and non-developers can follow along.

## 8. Additional Suggestions
- **Commit messages:** Use short, present-tense summaries and include a brief body if needed.
- **Testing:** If PHP files change, run `php -l <file>` for syntax checks. Validate CSS/JS if tools are available.
- **Documentation updates:** Update relevant files in `codex/docs` and cross-link from `README.md` when adding new features.

