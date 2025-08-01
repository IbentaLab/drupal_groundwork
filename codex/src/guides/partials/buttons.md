# Buttons

Welcome to the button guide! This page shows you all the different button styles available and gives you tips on when to use each one.

## Base Button

This is your standard, go-to button. It's designed to be the main action on a page.

**Best for:** Primary actions like "Submit," "Save," or "Add to Cart."

`<button class="button">`Primary Button`</button>`

```
<button class="button">Primary Button</button>

```

## Color Variants

Changing the color of a button can help communicate its purpose to the user.

### Filled Buttons

These are your standard, high-impact buttons.

* **Primary:** The default, for the most important action.
* **Secondary:** For actions that are important but not the main focus.
* **Success:** Great for confirming a positive action, like "Save Successful."
* **Danger:** **Use with caution!** This is for actions that delete something or cannot be undone, like "Delete Account."
* **Warning:** For actions that the user should think about before clicking.
* **Info:** To highlight a neutral piece of information or action.
* **Muted:** For disabled or less important actions.

`<button class="button">`Primary`</button>`

`<button class="button button--secondary">`Secondary`</button>`

`<button class="button button--success">`Success`</button>`

`<button class="button button--danger">`Danger`</button>`

`<button class="button button--warning">`Warning`</button>`

`<button class="button button--info">`Info`</button>`

`<button class="button button--muted">`Muted`</button>`

```
<button class="button button--secondary">Secondary</button>
<button class="button button--success">Success</button>
<button class="button button--danger">Danger</button>

```

## Style Variants

Sometimes you need a button that doesn't stand out as much.

### Ghost Buttons

**Best for:** Secondary actions. For example, next to a primary "Create Account" button, you might have a ghost "Learn More" button.

`<button class="button button--ghost">`Primary`</button>`

`<button class="button button--ghost button--secondary">`Secondary`</button>`

`<button class="button button--ghost button--danger">`Danger`</button>`

```
<button class="button button--ghost">Primary</button>

```

### Outline Button

A simple, neutral button that works well in forms and toolbars where you need an action that doesn't draw too much attention.

`<button class="button button--outline">`Outline`</button>`

```
<button class="button button--outline">Outline</button>

```

### Light Buttons

**Best for:** Low-priority actions, like filters or tags in a sidebar, where a solid button would be too visually heavy.

`<button class="button button--primary-light">`Primary Light`</button>`

`<button class="button button--success-light">`Success Light`</button>`

`<button class="button button--warning-light">`Warning Light`</button>`

```
<button class="button button--primary-light">Primary Light</button>

```

## Size Variants

You can change the button size to fit its location. A large button might be used in a hero banner, while a small button might be used inside a table row.

`<button class="button button--xxl">`XXL Button`</button>`

`<button class="button button--xl">`XL Button`</button>`

`<button class="button button--lg">`LG Button`</button>`

`<button class="button">`MD Button (Default)`</button>`

`<button class="button button--sm">`SM Button`</button>`

`<button class="button button--xs">`XS Button`</button>`

```
<button class="button button--lg">LG Button</button>
<button class="button button--sm">SM Button</button>

```

## Modifiers

### Pill Button

Use this for a more modern, rounded look.

`<button class="button button--pill">`Pill Button`</button>`

```
<button class="button button--pill">Pill Button</button>

```

### Block Button

**Best for:** Situations where you need a button to fill the entire width of its container, which is common on mobile devices to make tapping easier.

`<button class="button button--block">`Block Button`</button>`

```
<button class="button button--block">Block Button</button>

```

### Icon Button

**Best for:** Toolbars or compact spaces where a text label would be too cluttered. Make sure the icon's meaning is clear and consider adding a tooltip!

`<button class="button button--icon">`

<svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M5 12h14" /><path d="M12 5v14" /></svg>

</button>

```
<button class="button button--icon">
  <!-- Your SVG icon goes here -->
</button>

```
