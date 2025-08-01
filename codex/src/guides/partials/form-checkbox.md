# Form Checkbox

This guide shows you all the different checkbox styles available and gives you tips on when to use each one.

## Base Structure

To make a custom checkbox, you need a specific HTML structure. This is usually handled by the component you are using (like the "Process Steps" component), but it's good to know how it works.

```
<div class="form-check">
  <input class="form-check__input" type="checkbox" id="check1">
  <label class="form-check__label" for="check1">My Checkbox</label>
</div>

```

## Style Variants

There are two main styles of checkbox to choose from.

### Default Checkbox

This is your standard square checkbox.

**Best for:** Forms, "I agree to the terms" boxes, and selecting multiple options from a list.

<div class="form-check">

<input class="form-check__input" type="checkbox" id="check-default" checked>

<label class="form-check__label" for="check-default">Default Checkbox</label>

</div>

```
<div class="form-check">...</div>

```

### Toggle Switch

This is a modern, pill-shaped on/off switch.

**Best for:** Settings or preferences, like "Enable Notifications" or "Dark Mode." It gives a clear visual indication of an active or inactive state.

<div class="form-check form-check--toggle">

<input class="form-check__input" type="checkbox" id="check-toggle" checked>

<label class="form-check__label" for="check-toggle">Toggle Switch</label>

</div>

```
<div class="form-check form-check--toggle">...</div>

```

## Color Variants

Changing the color can help communicate the purpose of the checkbox, but use it thoughtfully.

* **Success:** Great for "Mark as Complete" actions.
* **Danger:** Could be used for an "I understand the risks" confirmation.
* **Warning:** Useful for options that have important consequences.

<div style="display: flex; flex-direction: column; gap: 1rem;">

<div class="form-check"><input class="form-check__input" type="checkbox" id="c1" checked><label class="form-check__label" for="c1">Primary</label></div>

<div class="form-check form-check--success"><input class="form-check__input" type="checkbox" id="c3" checked><label class="form-check__label" for="c3">Success</label></div>

<div class="form-check form-check--danger"><input class="form-check__input" type="checkbox" id="c4" checked><label class="form-check__label" for="c4">Danger</label></div>

</div>

```
<div class="form-check form-check--success">...</div>
<div class="form-check form-check--danger">...</div>

```

## Size Variants

You can change the checkbox size to fit its context. Larger sizes are easier to tap on mobile devices.

<div style="display: flex; flex-direction: column; gap: 1rem;">

<div class="form-check form-check--lg"><input class="form-check__input" type="checkbox" id="s3" checked><label class="form-check__label" for="s3">Large Checkbox</label></div>

<div class="form-check"><input class="form-check__input" type="checkbox" id="s4" checked><label class="form-check__label" for="s4">Medium Checkbox (Default)</label></div>

<div class="form-check form-check--sm"><input class="form-check__input" type="checkbox" id="s5" checked><label class="form-check__label" for="s5">Small Checkbox</label></div>

</div>

```
<div class="form-check form-check--lg">...</div>
<div class="form-check">...</div> <!-- MD is default -->
<div class="form-check form-check--sm">...</div>

```

## Strikethrough Modifier

This modifier adds a line through the label text when the box is checked.

**Best for:** To-do lists or step-by-step guides (like our **Process Steps** component) to give a clear visual sign of completion.

<div class="form-check form-check--strikethrough">

<input class="form-check__input" type="checkbox" id="check-strike" checked>

<label class="form-check__label" for="check-strike">Complete this task</label>

</div>

```
<div class="form-check form-check--strikethrough">...</div>

```
