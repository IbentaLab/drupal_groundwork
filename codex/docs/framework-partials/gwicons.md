# gwicons – Icon System Documentation

## Introduction

The **gwicons** system provides a robust and accessible method for rendering SVG icons throughout the Groundwork Theme Framework. It leverages a centralized SVG sprite and a dedicated Twig partial to ensure icons are scalable, consistent, and easily maintainable. This approach optimizes performance by loading all icons in a single request and allows for flexible sizing and color customization via CSS.

---

## Installation & Integration

The gwicons system is integrated into the Groundwork Theme Framework as follows:

**File Structure:**  
Core files are located in `groundwork/framework-partials/gwicons/`:

- `gwicons.twig` — Twig partial for rendering icons
- `gwicons.css` — Styling for icons
- `gwicons.svg` — SVG sprite containing all icon definitions

**Sprite Injection:**  
The `gwicons.svg` sprite is automatically injected into the `<head>` section of every page, handled by the `groundwork_page_attachments()` function in `groundwork/inc/attachments.inc`. This ensures the sprite is globally available for efficient `<use>` referencing.

**CSS Loading:**  
The `gwicons.css` stylesheet is loaded globally via the theme's `groundwork.libraries.yml` file, typically in the `global-styling` section.

---

## Icon Reference (How to Use)

To render an icon in any Twig template (e.g., `html.html.twig`, `node.html.twig`, `block.html.twig`, or other partials), use:

```twig
{% include '@groundwork/framework-partials/gwicons/gwicons.twig' with {
  name: 'bars',          {# REQUIRED: The unique ID of the SVG symbol from gwicons.svg (e.g., if your sprite has <symbol id="gw-bars">, use 'bars'). #}
  label: 'Open menu',    {# OPTIONAL: A descriptive text label for accessibility (screen readers). Omit for purely decorative icons. #}
  attributes: create_attribute({ class: 'text-xxl text-blue-600', id: 'my-custom-icon' }) {# OPTIONAL: An Attribute object for adding custom HTML attributes (e.g., classes, IDs, data attributes) to the rendered <svg> tag. #}
} %}
```

---

### Parameter Details

- **name** (`string`, required):  
  Corresponds to the `id` of a `<symbol>` in the sprite.  
  _Example:_ To display `<symbol id="gw-user">`, use `name: 'user'`.

- **label** (`string`, optional):  
  Accessible text for screen readers.  
  _Provide for meaningful/interative icons; omit for decorative icons (will be marked `aria-hidden="true"`)._

- **attributes** (`Drupal\Core\Template\Attribute`, optional):  
  Add custom HTML attributes to the `<svg>`.  
  _Use for utility classes, unique IDs, or custom data attributes. Leverages Drupal's `create_attribute()` function._

---

## Sizing and Customization

Icons are sized using CSS `font-size` (not width/height attributes), integrating seamlessly with typography.

- **Default Sizing:**  
  Inherits size from CSS variable `--gw-icon-size` (defaults to `2.4rem`).

- **Per-Icon Sizing:**  
  Apply sizing via utility class (e.g., `text-xl`, `text-xxl`, `text-3xl`) in the `attributes` parameter:

  ```twig
  {{ include('@groundwork/framework-partials/gwicons/gwicons.twig' with {
    name: 'drupal',
    label: 'Drupal logo',
    attributes: create_attribute({ class: 'text-xxl' })
  }) }}
  ```

- **Global Sizing:**  
  Override `--gw-icon-size` in your theme's `tokens.css` or a global stylesheet.

- **Text Alignment:**  
  Icons align with parent text by inheriting the parent `font-size`.

---

## Custom Colors

Icons inherit `currentColor` from their parent, matching surrounding text by default.

- **Applying Custom Colors:**  
  Use a CSS utility class (e.g., `text-success`, `text-blue-600`) or a custom CSS variable in the icon's attributes or parent container:

  ```twig
  {{ include('@groundwork/framework-partials/gwicons/gwicons.twig' with {
    name: 'check',
    label: 'Check',
    attributes: create_attribute({ class: 'text-lg text-success' })
  }) }}
  ```

---

## Accessibility & Best Practices

- **Meaningful Icons:**  
  Always provide a descriptive `label` for icons that convey meaning or are interactive.

- **Decorative Icons:**  
  Omit the `label` for decorative icons. They will be marked as `aria-hidden="true"`.

- **Semantic Placement:**  
  Position icons semantically (inside buttons, near headings, in lists).

- **Consistency:**  
  Use design tokens or BSC utilities for sizing, spacing, and colors.

---

## Troubleshooting

**Icon Not Visible?**
- Confirm `gwicons.svg` is injected; check for `<symbol>` tags in page source.
- Ensure `name` parameter matches a `<symbol id="...">` in the sprite.

**Wrong Size?**
- Apply the correct sizing class via `attributes`.
- Check global `--gw-icon-size` variable in your CSS.

**Accessibility Errors?**
- Ensure interactive/meaningful icons have a descriptive `label`.

**Color Issues?**
- Icons inherit `currentColor`; check for conflicting CSS rules.

**Cache Issues:**  
After any changes to the icon partial, CSS, or SVG sprite, run a full Drupal cache clear (`drush cr` or `ddev drush cr`).

---

## Related Files

- `groundwork/framework-partials/gwicons/gwicons.twig`
- `groundwork/framework-partials/gwicons/gwicons.css`
- `groundwork/framework-partials/gwicons/gwicons.svg`
- `groundwork/inc/attachments.inc` (contains `groundwork_page_attachments()` for sprite injection)
- `groundwork/groundwork.libraries.yml` (registers `gwicons.css`)

---

## Available Icons

| Column 1 | Column 2 | Column 3 | Column 4 |
|----------|----------|----------|----------|
| `500px` | `accessibility` | `address-book` | `aid-kit` |
| `airplane` | `alarm` | `amazon` | `android` |
| `angry` | `angry2` | `appleinc` | `arrow-down` |
| `arrow-down2` | `arrow-down-left` | `arrow-down-left2` | `arrow-down-right` |
| `arrow-down-right2` | `arrow-left` | `arrow-left2` | `arrow-right` |
| `arrow-right2` | `arrow-up` | `arrow-up2` | `arrow-up-left` |
| `arrow-up-left2` | `arrow-up-right` | `arrow-up-right2` | `attachment` |
| `backward` | `backward2` | `baffled` | `baffled2` |
| `barcode` | `basecamp` | `behance` | `behance2` |
| `bell` | `bin` | `bin2` | `binoculars` |
| `blocked` | `blog` | `blogger` | `blogger2` |
| `bold` | `book` | `bookmark` | `bookmarks` |
| `books` | `box-add` | `box-remove` | `briefcase` |
| `brightness-contrast` | `bubble` | `bubble2` | `bubbles` |
| `bubbles2` | `bubbles3` | `bubbles4` | `bug` |
| `bullhorn` | `calculator` | `calendar` | `camera` |
| `cancel-circle` | `cart` | `checkbox-checked` | `checkbox-unchecked` |
| `checkmark` | `checkmark2` | `chrome` | `circle-down` |
| `circle-left` | `circle-right` | `circle-up` | `clear-formatting` |
| `clipboard` | `clock` | `clock2` | `cloud` |
| `cloud-check` | `cloud-download` | `cloud-upload` | `clubs` |
| `codepen` | `cog` | `cogs` | `coin-dollar` |
| `coin-euro` | `coin-pound` | `coin-yen` | `command` |
| `compass` | `compass2` | `confused` | `confused2` |
| `connection` | `contrast` | `cool` | `cool2` |
| `copy` | `credit-card` | `crop` | `cross` |
| `crying` | `crying2` | `css3` | `ctrl` |
| `database` | `delicious` | `deviantart` | `diamonds` |
| `dice` | `display` | `download` | `download2` |
| `download3` | `drawer` | `drawer2` | `dribbble` |
| `drive` | `dropbox` | `droplet` | `drupal` |
| `earth` | `edge` | `eject` | `ello` |
| `embed` | `embed2` | `enlarge` | `enlarge2` |
| `enter` | `envelop` | `equalizer` | `equalizer2` |
| `evil` | `evil2` | `exit` | `eye` |
| `eye-blocked` | `eyedropper` | `eye-minus` | `eye-plus` |
| `facebook` | `facebook2` | `feed` | `file-empty` |
| `file-excel` | `file-music` | `file-openoffice` | `file-pdf` |
| `file-picture` | `file-play` | `files-empty` | `file-text` |
| `file-text2` | `file-video` | `file-word` | `file-zip` |
| `film` | `filter` | `finder` | `fire` |
| `firefox` | `first` | `flag` | `flattr` |
| `flickr` | `flickr2` | `floppy-disk` | `folder` |
| `folder-download` | `folder-minus` | `folder-open` | `folder-plus` |
| `folder-upload` | `font` | `font-size` | `forward` |
| `forward2` | `forward3` | `foursquare` | `frustrated` |
| `frustrated2` | `gift` | `git` | `github` |
| `glass` | `glass2` | `google` | `google2` |
| `google-drive` | `grin` | `grin2` | `hackernews` |
| `hammer` | `hammer2` | `hangouts` | `happy` |
| `happy2` | `headphones` | `heart` | `heart-broken` |
| `hipster` | `hipster2` | `history` | `home` |
| `home2` | `home3` | `hour-glass` | `html-five` |
| `html-five2` | `image` | `images` | `indent-decrease` |
| `indent-increase` | `infinite` | `info` | `insert-template` |
| `instagram` | `italic` | `key` | `key2` |
| `keyboard` | `lab` | `lanyrd` | `laptop` |
| `last` | `lastfm` | `lastfm2` | `leaf` |
| `library` | `libreoffice` | `lifebuoy` | `ligature` |
| `ligature2` | `link` | `linkedin` | `linkedin2` |
| `list` | `list2` | `list-numbered` | `location` |
| `location2` | `lock` | `loop` | `loop2` |
| `ltr` | `magic-wand` | `magnet` | `mail` |
| `mail2` | `mail3` | `mail4` | `make-group` |
| `man` | `man-woman` | `map` | `map2` |
| `menu` | `menu2` | `menu3` | `menu4` |
| `meter` | `meter2` | `mic` | `minus` |
| `mobile` | `mobile2` | `move-down` | `move-up` |
| `mug` | `music` | `neutral` | `neutral2` |
| `newspaper` | `new-tab` | `next` | `next2` |
| `notification` | `npm` | `office` | `omega` |
| `onedrive` | `opera` | `opt` | `pacman` |
| `pagebreak` | `page-break` | `paint-format` | `paragraph-center` |
| `paragraph-justify` | `paragraph-left` | `paragraph-right` | `paste` |
| `pause` | `pause2` | `paypal` | `pen` |
| `pencil` | `pencil2` | `phone` | `phone-hang-up` |
| `pie-chart` | `pilcrow` | `pinterest` | `pinterest2` |
| `play` | `play2` | `play3` | `plus` |
| `podcast` | `point-down` | `point-left` | `point-right` |
| `point-up` | `power` | `power-cord` | `previous` |
| `previous2` | `price-tag` | `price-tags` | `printer` |
| `profile` | `pushpin` | `qrcode` | `question` |
| `quill` | `quotes-left` | `quotes-right` | `radio-checked` |
| `radio-checked2` | `radio-unchecked` | `reddit` | `redo` |
| `redo2` | `renren` | `reply` | `road` |
| `rocket` | `rss` | `rss2` | `rtl` |
| `sad` | `sad2` | `safari` | `scissors` |
| `search` | `section` | `share` | `share2` |
| `shield` | `shift` | `shocked` | `shocked2` |
| `shrink` | `shrink2` | `shuffle` | `sigma` |
| `sina-weibo` | `sleepy` | `sleepy2` | `smile` |
| `smile2` | `sort-alpha-asc` | `sort-alpha-desc` | `sort-amount-asc` |
| `sort-amount-desc` | `sort-numberic-desc` | `sort-numeric-asc` | `soundcloud` |
| `soundcloud2` | `spades` | `spell-check` | `sphere` |
| `spinner` | `spinner2` | `spinner3` | `spinner4` |
| `spinner5` | `spinner6` | `spinner7` | `spinner8` |
| `spinner9` | `spinner10` | `spinner11` | `spoon-knife` |
| `spotify` | `stack` | `stackoverflow` | `star-empty` |
| `star-full` | `star-half` | `stats-bars` | `stats-bars2` |
| `stats-dots` | `steam` | `steam2` | `stop` |
| `stop2` | `stopwatch` | `strikethrough` | `stumbleupon` |
| `stumbleupon2` | `subscript` | `subscript2` | `sun` |
| `superscript` | `superscript2` | `svg` | `switch` |
| `tab` | `table` | `table2` | `tablet` |
| `target` | `telegram` | `terminal` | `text-color` |
| `text-height` | `text-width` | `ticket` | `tongue` |
| `tongue2` | `tree` | `trello` | `trophy` |
| `truck` | `tumblr` | `tumblr2` | `tux` |
| `tv` | `twitch` | `underline` | `undo` |
| `undo2` | `ungroup` | `unlocked` | `upload` |
| `upload2` | `upload3` | `user` | `user-check` |
| `user-minus` | `user-plus` | `users` | `user-tie` |
| `video-camera` | `vimeo` | `vimeo2` | `vine` |
| `vk` | `volume-decrease` | `volume-high` | `volume-increase` |
| `volume-low` | `volume-medium` | `volume-mute` | `volume-mute2` |
| `warning` | `whatsapp` | `wikipedia` | `windows` |
| `wink` | `wink2` | `woman` | `wondering` |
| `wondering2` | `wordpress` | `wrench` | `yahoo` |
| `yahoo2` | `yelp` | `youtube` | `youtube2` |
| `zoom-in` | `zoom-out` |  |  |

---