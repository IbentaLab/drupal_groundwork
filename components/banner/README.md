# Banner Single-Directory Component

A flexible, accessible banner component for Drupal 11+ that leverages Groundwork's atomic design system for consistent styling and optimal performance.

## 📦 Included with Groundwork

This component ships with the Groundwork Theme Framework and is ready to use immediately.

 **Component ID** : `groundwork:banner`

### Optional: Enhanced Block Integration

For a user-friendly admin interface, install the **Groundwork Helpers Components** module:

```bash
composer require drupal/groundwork_helpers
drush en groundwork_helpers groundwork_helpers_components -y
```

The Banner block will then be available at `/admin/structure/block` under "Groundwork Components" with a full configuration UI.

## 🚀 Features

* **Smart Background System** : Color backgrounds with automatic contrast OR image backgrounds with overlay options
* **Atomic Design Integration** : Uses existing Groundwork utilities (`.bg--*`, `.overlay--*`, `.vh-*`, `.btn-group`)
* **Accessibility First** : WCAG-compliant contrast, high contrast mode support, reduced motion support
* **Flexible Actions** : Full button system integration with colors, styles, and sizes
* **Responsive** : Mobile-first design with responsive button behavior
* **Theme Safe** : Works seamlessly in light and dark modes

## 📁 File Structure

```
components/banner/
├── banner.component.yml    # Component metadata and props schema
├── banner.twig            # Template with atomic class integration
├── banner.css             # Minimal component-specific styles
└── BannerBlock.php        # Drupal block integration (optional)
```

## 🎨 Background Options

### Color Backgrounds

* **16 predefined colors** from Groundwork's design system
* **Automatic text contrast** - each color sets appropriate text color
* **Theme safe** - works in both light and dark modes

Available colors: `blue`, `indigo`, `deep-purple`, `purple`, `pink`, `red`, `orange`, `amber`, `yellow`, `lime`, `green`, `teal`, `cyan`, `brown`, `blue-gray`, `gray`

### Image Backgrounds

* **Upload any image** format (jpg, png, gif, svg, webp, avif)
* **Smart text contrast** via "background is dark" checkbox
* **Overlay system** for enhanced readability and branding

## 🎭 Overlay System

When using image backgrounds, choose from:

* **None** : No overlay (use when image already has good contrast)
* **Dark** : Dark tint (makes light text readable on bright images)
* **Light** : Light tint (makes dark text readable on dark images)
* **Primary** : Brand color overlay (uses `--color-primary` for subtle branding)
* **Black/White** : Explicit black or white overlays

 **Opacity levels** : 10%, 25%, 50%, 75%, 90%

### Branding with Primary Overlay

The "Primary" overlay uses your site's primary brand color (configurable in theme settings) at the selected opacity. This creates subtle brand recognition across all banners while maintaining image visibility. Best used at 25-50% opacity.

## 📐 Layout Options

### Content Alignment

* **Center** : Default centered layout
* **Left** : Left-aligned content
* **Right** : Right-aligned content

### Height Variants

* **Natural** : Content-based height (default)
* **50vh** : 50% viewport height
* **75vh** : 75% viewport height
* **100vh** : Full viewport height (hero style)

## 🔘 Action Buttons

Each banner supports up to 2 action buttons with full customization:

### Button Colors

`primary`, `secondary`, `info`, `notice`, `success`, `danger`, `warning`, `muted`

### Button Styles

* **Filled** (default): Solid background
* **Ghost** : Outline style
* **Light** : Light variant of the color
* **Gradient** : Animated gradient effect
* **Glow** : Glowing shadow effect

### Button Sizes

* **Default** : Standard size (`--ms-md`)
* **Small** : Subtle actions (`--ms-sm`)
* **Medium** : Explicit medium size (`--ms-md`)
* **Large** : Primary CTAs (`--ms-lg`)
* **Extra Large** : Major conversion buttons (`--ms-xl`)

## 🛠 Usage Examples

### In PHP (Render Array)

```php
$banner = [
  '#type' => 'component',
  '#component' => 'groundwork:banner',
  '#props' => [
    'title' => 'Welcome to Our Site',
    'subtitle' => 'Discover amazing features',
    'background_color' => 'blue',
    'layout' => 'center',
    'height_variant' => '75',
    'primary_action' => [
      'label' => 'Get Started',
      'url' => '/contact',
      'color' => 'success',
      'size' => 'lg',
    ],
  ],
];
```

### In Twig Templates

```twig
{{ include('groundwork:banner', {
  title: 'Hero Banner',
  background_image: 'https://example.com/hero.jpg',
  background_is_dark: true,
  overlay_type: 'dark',
  overlay_opacity: '50',
  primary_action: {
    label: 'Learn More',
    url: '/about',
    color: 'primary'
  }
}, with_context = false) }}
```

### With Optional Block Integration

If you've installed the Groundwork Helpers Components module, the `BannerBlock.php` provides a user-friendly block configuration interface. Users need the "Use Banner component" permission to access it.

## ♿ Accessibility Features

* **Automatic contrast** : Color backgrounds set WCAG-compliant text colors
* **Semantic HTML** : Proper heading hierarchy and landmarks
* **High contrast support** : Removes overlays that might reduce readability
* **Reduced motion support** : Disables animations for users who prefer less motion
* **Focus management** : Proper focus styles for interactive elements
* **Screen reader friendly** : Meaningful content structure

## 🎯 Design System Integration

This component maximally leverages Groundwork's existing utilities:

### CSS Classes Used

* **Background** : `.bg--blue`, `.bg--red`, etc.
* **Overlays** : `.overlay`, `.overlay--dark`, `.overlay-50`, etc.
* **Layout** : `.vh-50`, `.content-wrapper`, `.mobile-center`
* **Buttons** : `.button`, `.button--primary`, `.btn-group`, etc.
* **Responsive** : `.mobile-stack`, `.btn-group--responsive`

### Design Tokens Used

* **Typography** : `--ms-xxl`, `--ms-lg`, `--line-height-heading`
* **Spacing** : `--space-xxl`, `--space-lg`, `--space-md`
* **Colors** : `--text-on-dark`, `--text-on-light`, `--color-primary`
* **Effects** : `--transition-base`, `--shadow-sm`

## 🔧 Customization

### Theme Integration

The component automatically uses your theme's:

* Primary brand color (for primary overlay and default button color)
* Typography scale and spacing
* Color palette and contrast ratios
* Responsive breakpoints

### Extending the Component

To add new features:

1. Update `banner.component.yml` with new props
2. Modify `banner.twig` to handle new props
3. Add minimal CSS to `banner.css` if needed
4. Update `BannerBlock.php` form if using block plugin

## 📱 Responsive Behavior

* **Mobile typography scaling** : Titles scale down appropriately
* **Button stacking** : Action buttons stack vertically on mobile
* **Content reflow** : All layouts become center-aligned on small screens
* **Touch targets** : Buttons maintain proper touch target sizes

## 🚀 Performance

* **Minimal CSS** : Only 2KB of component-specific styles
* **Utility-first** : Leverages existing cached CSS utilities
* **Optimized images** : Proper responsive image handling
* **Efficient markup** : Semantic HTML without unnecessary wrappers

This banner component provides maximum flexibility while maintaining consistency with Groundwork's design system and performance standards.
