# Groundwork Theme

**Groundwork** is a sleek, high-performance Drupal frontend framework that puts block-based design at the core—making it powerful, flexible, and effortlessly customizable for modern web projects.

## 🚀 Features

- **Lightweight & Fast** – Clean and minimal footprint, optimized for performance.
- **Block-Based & Customizable** – Groundwork leverages the power of Drupal blocks to give you full control over layout, design, and content—unlocking unlimited possibilities with ease.
- **Responsive & Accessible** – Mobile-first design that meets WCAG and Norwegian accessibility standards.
- **Developer-Friendly** – Clean codebase, logical structure, and no build tools required.
- **Starter Kit** – Includes example templates and component structure.
- **Companion Module** – Includes the optional *Groundwork Block Styles* module to easily configure block styles and layout directly from the UI.
- **Optional Support** – Compatible with Drupal's Single Directory Components (SDC) and Layout Builder for flexible, modern site building.

## 📦 Requirements

- Drupal 10.1+ or 11
- PHP 8.1+

## 📁 Folder Structure

```
groundwork/
├── components/              # Optional: Single Directory Components
├── config/                  # Configuration files (if applicable)
├── css/                     # Organized CSS structure
│   ├── base/                # Reset, typography, and global styles
│   ├── components/          # Styles for reusable UI components
│   ├── layout/              # Grid and layout-specific CSS
│   ├── theme/               # Theme-specific styling rules
│   ├── vendor/              # Third-party CSS (if any)
│   ├── app-settings.css     # Editable custom properties; overrides variables.css
│   ├── groundwork.css       # Main theme stylesheet
│   └── variables.css        # CSS custom properties and variables
├── fonts/                   # Web font files
├── images/                  # Theme image assets
├── js/                      # JavaScript files (optional enhancements)
├── templates/               # Base Twig templates
├── groundwork.info.yml      # Theme definition
├── groundwork.libraries.yml # CSS/JS library declarations
├── groundwork.theme         # Theme hooks and preprocessing functions
├── logo.svg                 # Placeholder logo
├── README.md                # Theme documentation
└── screenshot.png           # Theme preview screenshot
```

## ⚙️ Installation

1. **Clone** or download the theme into your custom themes directory:

   ```bash
   git clone https://github.com/your-org/groundwork.git themes/custom/groundwork
   ```

2. **Enable the theme**:

   ```bash
   drush theme:enable groundwork
   drush config:set system.theme default groundwork
   ```

3. *(Optional)* Enable the **Groundwork Block Styles** module to make block style and layout customization even easier.

## ✏️ Customization

- Add custom templates to `templates/` or SDCs to `components/`.
- Add your own CSS to the `css/` directory and reference it in `theme.info.yml`.
- Use with Layout Builder and Drupal blocks for advanced page layouts.

## 🎨 Groundwork Block Styles Module

The optional **Groundwork Block Styles** module extends the theme's flexibility by allowing style options to be configured directly in the Drupal UI.

With it, you can:

- Apply predefined or custom CSS classes to blocks
- Control layout placement and styling without writing code
- Build visually rich and adaptable layouts more easily

This module is recommended if you want a no-code way to manage block design and layout.

## 🔧 Layout Builder & SDC Support

Groundwork works seamlessly with:

- **Layout Builder** – Define flexible, drag-and-drop page layouts.
- **Single Directory Components** – Add SDCs under `components/` if you want to use Drupal’s modern component architecture.

These are optional but fully supported.

## 🤝 Contributing

Pull requests are welcome! Please follow Drupal coding standards.

## 📄 License

GPL-2.0 License – see the `LICENSE` file.

---

> Groundwork helps you build modern, fast, and accessible Drupal websites—without unnecessary complexity. Its true power lies in the block system, giving you full control over layout, design, and content flexibility.

