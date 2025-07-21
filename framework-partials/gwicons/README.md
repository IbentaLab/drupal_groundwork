# Gwicons Partial

This directory serves as the dedicated home for the gwicons Twig partial, encompassing its core Twig template, associated CSS styles, and the comprehensive SVG sprite.

---

## Contents

- **gwicons.twig**  
  The primary Twig template responsible for rendering individual SVG icons, dynamically inserting the correct icon based on provided parameters.

- **gwicons.css**  
  Contains the foundational CSS rules for the icons, defining their size, alignment, and other default visual properties.

- **gwicons.svg**  
  The scalable vector graphics sprite file, which acts as a central repository for all defined icon symbols, allowing for efficient and performant icon display across the site.

---

## How to Use

To seamlessly integrate and display an icon within any Twig template across your theme (such as `html.html.twig`, `node.html.twig`, or `block.html.twig`), utilize the following include syntax. This method ensures that the icon is rendered with the correct markup and attributes, leveraging the partial's encapsulated logic.

```twig
{% include '@groundwork/framework-partials/gwicons/gwicons.twig' with {
  name: 'bars',          {# REQUIRED: This parameter specifies the unique ID of the SVG symbol you wish to render. For example, if your gwicons.svg contains a symbol defined as <symbol id="gw-bars">...</symbol>, then 'bars' would be the correct value here. This ensures the correct icon from the sprite is displayed. #}
  label: 'Open menu',    {# OPTIONAL: Providing a descriptive text label is crucial for accessibility. This label is used by screen readers to convey the icon's meaning to users with visual impairments, ensuring a more inclusive user experience. If no label is provided, the icon will be marked as aria-hidden="true". #}
  attributes: create_attribute({ class: 'text-xxl text-blue-600', id: 'my-custom-icon', 'data-icon-type': 'navigation' }) {# OPTIONAL: This allows you to pass additional HTML attributes directly to the <svg> element. You can add custom CSS classes (like Tailwind utility classes for size or color), unique IDs, data attributes, or any other standard HTML attribute to further customize the icon's appearance or behavior. #}
} %}
```

---

## Important Notes

- The `gwicons.svg` sprite is automatically injected directly into the `<head>` section of every page. This global injection is handled by the `groundwork_page_attachments()` function, located within `inc/attachments.inc`. This approach ensures that the entire icon sprite is available on the page as early as possible, optimizing performance by preventing individual icon requests and making all icons immediately accessible for rendering via `<use>` tags throughout the document.

- To ensure the styling for your icons is correctly applied, verify that `framework-partials/gwicons/gwicons.css` is properly loaded through your theme's library definition in `groundwork.libraries.yml`, specifically within the `global-styling` section. The Groundwork Theme Framework's library system efficiently manages asset loading and aggregation, contributing to overall site performance.

- After making any modifications to the gwicons partial (including changes to its Twig, CSS, or the SVG sprite) or any related theme files, it is imperative to clear Drupal's cache. Running `drush cr` (or `ddev drush cr` if using DDEV) ensures that Drupal recognizes all your updates and rebuilds its internal caches, preventing unexpected display issues or outdated asset references.

---