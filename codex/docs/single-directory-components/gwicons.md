
# gwicons – Icon Macro Component

---

## Introduction

The `gwicons` component is a reusable Single Directory Component (SDC) for rendering SVG icons from the Groundwork theme’s centralized sprite, `gwicons.svg`. It lets themers and site builders use icons anywhere, with accessible markup, flexible sizing, and design token support. This approach ensures icons are scalable, consistent, and easy to maintain across any Groundwork-based project.

---

## Installation & Integration

1. Ensure your theme includes the `components/gwicons/` SDC and the `gwicons/gwicons.svg` sprite in its structure.
2. Sprite injection should be handled by the theme (see example in `attachments.inc`).
3. Macro is auto-imported if exposed globally via `groundwork_preprocess_html()`.
4. Reference the macro as `gwicons.icon` in any Twig file.

---

## Macro Reference

The macro signature:

```twig
{{ gwicons.icon(name, label = '', class = '') }}
```
- **name** (`string`, required): The icon symbol ID from the sprite (e.g., `'user'`).
- **label** (`string`, optional): Accessible label for screen readers. If omitted, icon is marked as decorative.
- **class** (`string`, optional): One or more CSS classes or utilities for per-instance sizing, color, etc.

---

## Usage Example

```twig
{{ gwicons.icon('user', 'User profile') }}
{{ gwicons.icon('heart') }} {# Decorative, no label #}
{{ gwicons.icon('drupal', 'Drupal logo', 'text-xxl') }} {# Sizing this instance only #}
```

- **First argument:** Symbol ID (matches the icon in the sprite)
- **Second argument:** Optional label for screen readers. Omit for decorative icons.
- **Third argument:** (optional) CSS class or utility for custom per-instance sizing.

---

## Sizing and Customization

Icons are sized by CSS `font-size` (not width/height), following the design token `--gw-icon-size` (default: `2.4rem`, or 24px when 1rem = 10px).

- To change the size for a single icon, add a class in the third macro argument:
  ```twig
  {{ gwicons.icon('drupal', 'Drupal', 'text-xxl') }}
  ```
- To globally change all icons, override `--gw-icon-size` in `tokens.css`.
- You may use any of Groundwork’s BSC utilities for sizing (`text-xl`, `text-xxl`, etc.).
- To align icons with text or button sizes, simply inherit the parent’s font size.

### Custom Colors
- Icons will inherit the current text color (`currentColor`).
- To color an icon, use a utility class or custom CSS variable on the icon or parent.

  ```twig
  {{ gwicons.icon('check', 'Check', 'text-lg text-success') }}
  ```

---

## Accessibility & Best Practices

- Always provide a `label` argument for meaningful, interactive, or informative icons.
- Omit the label for purely decorative icons—they will be hidden from assistive tech.
- Prefer semantic placement (e.g., inside buttons, next to headings).
- Use consistent sizing and spacing with design tokens or BSC utilities.

---

## Troubleshooting

- **Icon not visible?** Check that `gwicons.svg` is being injected into your HTML (search page source for `<symbol`).
- **Wrong size?** Ensure you’re using the correct class or that `--gw-icon-size` is set.
- **Accessibility errors?** Supply a label for icons that are not purely decorative.
- **Color issues?** Icons inherit `currentColor`; ensure no CSS is overriding color unexpectedly.

---

## Related Files

- `components/gwicons/gwicons.component.yml`
- `components/gwicons/gwicons.twig`
- `components/gwicons/gwicons.css`
- `gwicons/gwicons.svg` (theme root)

---

## Available Icons

| Name         | Usage                         |
|--------------|------------------------------|
| `500px` | `{{ gwicons.icon('500px') }}` |
| `accessibility` | `{{ gwicons.icon('accessibility') }}` |
| `address-book` | `{{ gwicons.icon('address-book') }}` |
| `aid-kit` | `{{ gwicons.icon('aid-kit') }}` |
| `airplane` | `{{ gwicons.icon('airplane') }}` |
| `alarm` | `{{ gwicons.icon('alarm') }}` |
| `amazon` | `{{ gwicons.icon('amazon') }}` |
| `android` | `{{ gwicons.icon('android') }}` |
| `angry` | `{{ gwicons.icon('angry') }}` |
| `angry2` | `{{ gwicons.icon('angry2') }}` |
| `appleinc` | `{{ gwicons.icon('appleinc') }}` |
| `arrow-down` | `{{ gwicons.icon('arrow-down') }}` |
| `arrow-down2` | `{{ gwicons.icon('arrow-down2') }}` |
| `arrow-down-left` | `{{ gwicons.icon('arrow-down-left') }}` |
| `arrow-down-left2` | `{{ gwicons.icon('arrow-down-left2') }}` |
| `arrow-down-right` | `{{ gwicons.icon('arrow-down-right') }}` |
| `arrow-down-right2` | `{{ gwicons.icon('arrow-down-right2') }}` |
| `arrow-left` | `{{ gwicons.icon('arrow-left') }}` |
| `arrow-left2` | `{{ gwicons.icon('arrow-left2') }}` |
| `arrow-right` | `{{ gwicons.icon('arrow-right') }}` |
| `arrow-right2` | `{{ gwicons.icon('arrow-right2') }}` |
| `arrow-up` | `{{ gwicons.icon('arrow-up') }}` |
| `arrow-up2` | `{{ gwicons.icon('arrow-up2') }}` |
| `arrow-up-left` | `{{ gwicons.icon('arrow-up-left') }}` |
| `arrow-up-left2` | `{{ gwicons.icon('arrow-up-left2') }}` |
| `arrow-up-right` | `{{ gwicons.icon('arrow-up-right') }}` |
| `arrow-up-right2` | `{{ gwicons.icon('arrow-up-right2') }}` |
| `attachment` | `{{ gwicons.icon('attachment') }}` |
| `backward` | `{{ gwicons.icon('backward') }}` |
| `backward2` | `{{ gwicons.icon('backward2') }}` |
| `baffled` | `{{ gwicons.icon('baffled') }}` |
| `baffled2` | `{{ gwicons.icon('baffled2') }}` |
| `barcode` | `{{ gwicons.icon('barcode') }}` |
| `basecamp` | `{{ gwicons.icon('basecamp') }}` |
| `behance` | `{{ gwicons.icon('behance') }}` |
| `behance2` | `{{ gwicons.icon('behance2') }}` |
| `bell` | `{{ gwicons.icon('bell') }}` |
| `bin` | `{{ gwicons.icon('bin') }}` |
| `bin2` | `{{ gwicons.icon('bin2') }}` |
| `binoculars` | `{{ gwicons.icon('binoculars') }}` |
| `blocked` | `{{ gwicons.icon('blocked') }}` |
| `blog` | `{{ gwicons.icon('blog') }}` |
| `blogger` | `{{ gwicons.icon('blogger') }}` |
| `blogger2` | `{{ gwicons.icon('blogger2') }}` |
| `bold` | `{{ gwicons.icon('bold') }}` |
| `book` | `{{ gwicons.icon('book') }}` |
| `bookmark` | `{{ gwicons.icon('bookmark') }}` |
| `bookmarks` | `{{ gwicons.icon('bookmarks') }}` |
| `books` | `{{ gwicons.icon('books') }}` |
| `box-add` | `{{ gwicons.icon('box-add') }}` |
| `box-remove` | `{{ gwicons.icon('box-remove') }}` |
| `briefcase` | `{{ gwicons.icon('briefcase') }}` |
| `brightness-contrast` | `{{ gwicons.icon('brightness-contrast') }}` |
| `bubble` | `{{ gwicons.icon('bubble') }}` |
| `bubble2` | `{{ gwicons.icon('bubble2') }}` |
| `bubbles` | `{{ gwicons.icon('bubbles') }}` |
| `bubbles2` | `{{ gwicons.icon('bubbles2') }}` |
| `bubbles3` | `{{ gwicons.icon('bubbles3') }}` |
| `bubbles4` | `{{ gwicons.icon('bubbles4') }}` |
| `bug` | `{{ gwicons.icon('bug') }}` |
| `bullhorn` | `{{ gwicons.icon('bullhorn') }}` |
| `calculator` | `{{ gwicons.icon('calculator') }}` |
| `calendar` | `{{ gwicons.icon('calendar') }}` |
| `camera` | `{{ gwicons.icon('camera') }}` |
| `cancel-circle` | `{{ gwicons.icon('cancel-circle') }}` |
| `cart` | `{{ gwicons.icon('cart') }}` |
| `checkbox-checked` | `{{ gwicons.icon('checkbox-checked') }}` |
| `checkbox-unchecked` | `{{ gwicons.icon('checkbox-unchecked') }}` |
| `checkmark` | `{{ gwicons.icon('checkmark') }}` |
| `checkmark2` | `{{ gwicons.icon('checkmark2') }}` |
| `chrome` | `{{ gwicons.icon('chrome') }}` |
| `circle-down` | `{{ gwicons.icon('circle-down') }}` |
| `circle-left` | `{{ gwicons.icon('circle-left') }}` |
| `circle-right` | `{{ gwicons.icon('circle-right') }}` |
| `circle-up` | `{{ gwicons.icon('circle-up') }}` |
| `clear-formatting` | `{{ gwicons.icon('clear-formatting') }}` |
| `clipboard` | `{{ gwicons.icon('clipboard') }}` |
| `clock` | `{{ gwicons.icon('clock') }}` |
| `clock2` | `{{ gwicons.icon('clock2') }}` |
| `cloud` | `{{ gwicons.icon('cloud') }}` |
| `cloud-check` | `{{ gwicons.icon('cloud-check') }}` |
| `cloud-download` | `{{ gwicons.icon('cloud-download') }}` |
| `cloud-upload` | `{{ gwicons.icon('cloud-upload') }}` |
| `clubs` | `{{ gwicons.icon('clubs') }}` |
| `codepen` | `{{ gwicons.icon('codepen') }}` |
| `cog` | `{{ gwicons.icon('cog') }}` |
| `cogs` | `{{ gwicons.icon('cogs') }}` |
| `coin-dollar` | `{{ gwicons.icon('coin-dollar') }}` |
| `coin-euro` | `{{ gwicons.icon('coin-euro') }}` |
| `coin-pound` | `{{ gwicons.icon('coin-pound') }}` |
| `coin-yen` | `{{ gwicons.icon('coin-yen') }}` |
| `command` | `{{ gwicons.icon('command') }}` |
| `compass` | `{{ gwicons.icon('compass') }}` |
| `compass2` | `{{ gwicons.icon('compass2') }}` |
| `confused` | `{{ gwicons.icon('confused') }}` |
| `confused2` | `{{ gwicons.icon('confused2') }}` |
| `connection` | `{{ gwicons.icon('connection') }}` |
| `contrast` | `{{ gwicons.icon('contrast') }}` |
| `cool` | `{{ gwicons.icon('cool') }}` |
| `cool2` | `{{ gwicons.icon('cool2') }}` |
| `copy` | `{{ gwicons.icon('copy') }}` |
| `credit-card` | `{{ gwicons.icon('credit-card') }}` |
| `crop` | `{{ gwicons.icon('crop') }}` |
| `cross` | `{{ gwicons.icon('cross') }}` |
| `crying` | `{{ gwicons.icon('crying') }}` |
| `crying2` | `{{ gwicons.icon('crying2') }}` |
| `css3` | `{{ gwicons.icon('css3') }}` |
| `ctrl` | `{{ gwicons.icon('ctrl') }}` |
| `database` | `{{ gwicons.icon('database') }}` |
| `delicious` | `{{ gwicons.icon('delicious') }}` |
| `deviantart` | `{{ gwicons.icon('deviantart') }}` |
| `diamonds` | `{{ gwicons.icon('diamonds') }}` |
| `dice` | `{{ gwicons.icon('dice') }}` |
| `display` | `{{ gwicons.icon('display') }}` |
| `download` | `{{ gwicons.icon('download') }}` |
| `download2` | `{{ gwicons.icon('download2') }}` |
| `download3` | `{{ gwicons.icon('download3') }}` |
| `drawer` | `{{ gwicons.icon('drawer') }}` |
| `drawer2` | `{{ gwicons.icon('drawer2') }}` |
| `dribbble` | `{{ gwicons.icon('dribbble') }}` |
| `drive` | `{{ gwicons.icon('drive') }}` |
| `dropbox` | `{{ gwicons.icon('dropbox') }}` |
| `droplet` | `{{ gwicons.icon('droplet') }}` |
| `drupal` | `{{ gwicons.icon('drupal') }}` |
| `earth` | `{{ gwicons.icon('earth') }}` |
| `edge` | `{{ gwicons.icon('edge') }}` |
| `eject` | `{{ gwicons.icon('eject') }}` |
| `ello` | `{{ gwicons.icon('ello') }}` |
| `embed` | `{{ gwicons.icon('embed') }}` |
| `embed2` | `{{ gwicons.icon('embed2') }}` |
| `enlarge` | `{{ gwicons.icon('enlarge') }}` |
| `enlarge2` | `{{ gwicons.icon('enlarge2') }}` |
| `enter` | `{{ gwicons.icon('enter') }}` |
| `envelop` | `{{ gwicons.icon('envelop') }}` |
| `equalizer` | `{{ gwicons.icon('equalizer') }}` |
| `equalizer2` | `{{ gwicons.icon('equalizer2') }}` |
| `evil` | `{{ gwicons.icon('evil') }}` |
| `evil2` | `{{ gwicons.icon('evil2') }}` |
| `exit` | `{{ gwicons.icon('exit') }}` |
| `eye` | `{{ gwicons.icon('eye') }}` |
| `eye-blocked` | `{{ gwicons.icon('eye-blocked') }}` |
| `eyedropper` | `{{ gwicons.icon('eyedropper') }}` |
| `eye-minus` | `{{ gwicons.icon('eye-minus') }}` |
| `eye-plus` | `{{ gwicons.icon('eye-plus') }}` |
| `facebook` | `{{ gwicons.icon('facebook') }}` |
| `facebook2` | `{{ gwicons.icon('facebook2') }}` |
| `feed` | `{{ gwicons.icon('feed') }}` |
| `file-empty` | `{{ gwicons.icon('file-empty') }}` |
| `file-excel` | `{{ gwicons.icon('file-excel') }}` |
| `file-music` | `{{ gwicons.icon('file-music') }}` |
| `file-openoffice` | `{{ gwicons.icon('file-openoffice') }}` |
| `file-pdf` | `{{ gwicons.icon('file-pdf') }}` |
| `file-picture` | `{{ gwicons.icon('file-picture') }}` |
| `file-play` | `{{ gwicons.icon('file-play') }}` |
| `files-empty` | `{{ gwicons.icon('files-empty') }}` |
| `file-text` | `{{ gwicons.icon('file-text') }}` |
| `file-text2` | `{{ gwicons.icon('file-text2') }}` |
| `file-video` | `{{ gwicons.icon('file-video') }}` |
| `file-word` | `{{ gwicons.icon('file-word') }}` |
| `file-zip` | `{{ gwicons.icon('file-zip') }}` |
| `film` | `{{ gwicons.icon('film') }}` |
| `filter` | `{{ gwicons.icon('filter') }}` |
| `finder` | `{{ gwicons.icon('finder') }}` |
| `fire` | `{{ gwicons.icon('fire') }}` |
| `firefox` | `{{ gwicons.icon('firefox') }}` |
| `first` | `{{ gwicons.icon('first') }}` |
| `flag` | `{{ gwicons.icon('flag') }}` |
| `flattr` | `{{ gwicons.icon('flattr') }}` |
| `flickr` | `{{ gwicons.icon('flickr') }}` |
| `flickr2` | `{{ gwicons.icon('flickr2') }}` |
| `floppy-disk` | `{{ gwicons.icon('floppy-disk') }}` |
| `folder` | `{{ gwicons.icon('folder') }}` |
| `folder-download` | `{{ gwicons.icon('folder-download') }}` |
| `folder-minus` | `{{ gwicons.icon('folder-minus') }}` |
| `folder-open` | `{{ gwicons.icon('folder-open') }}` |
| `folder-plus` | `{{ gwicons.icon('folder-plus') }}` |
| `folder-upload` | `{{ gwicons.icon('folder-upload') }}` |
| `font` | `{{ gwicons.icon('font') }}` |
| `font-size` | `{{ gwicons.icon('font-size') }}` |
| `forward` | `{{ gwicons.icon('forward') }}` |
| `forward2` | `{{ gwicons.icon('forward2') }}` |
| `forward3` | `{{ gwicons.icon('forward3') }}` |
| `foursquare` | `{{ gwicons.icon('foursquare') }}` |
| `frustrated` | `{{ gwicons.icon('frustrated') }}` |
| `frustrated2` | `{{ gwicons.icon('frustrated2') }}` |
| `gift` | `{{ gwicons.icon('gift') }}` |
| `git` | `{{ gwicons.icon('git') }}` |
| `github` | `{{ gwicons.icon('github') }}` |
| `glass` | `{{ gwicons.icon('glass') }}` |
| `glass2` | `{{ gwicons.icon('glass2') }}` |
| `google` | `{{ gwicons.icon('google') }}` |
| `google2` | `{{ gwicons.icon('google2') }}` |
| `google-drive` | `{{ gwicons.icon('google-drive') }}` |
| `grin` | `{{ gwicons.icon('grin') }}` |
| `grin2` | `{{ gwicons.icon('grin2') }}` |
| `hackernews` | `{{ gwicons.icon('hackernews') }}` |
| `hammer` | `{{ gwicons.icon('hammer') }}` |
| `hammer2` | `{{ gwicons.icon('hammer2') }}` |
| `hangouts` | `{{ gwicons.icon('hangouts') }}` |
| `happy` | `{{ gwicons.icon('happy') }}` |
| `happy2` | `{{ gwicons.icon('happy2') }}` |
| `headphones` | `{{ gwicons.icon('headphones') }}` |
| `heart` | `{{ gwicons.icon('heart') }}` |
| `heart-broken` | `{{ gwicons.icon('heart-broken') }}` |
| `hipster` | `{{ gwicons.icon('hipster') }}` |
| `hipster2` | `{{ gwicons.icon('hipster2') }}` |
| `history` | `{{ gwicons.icon('history') }}` |
| `home` | `{{ gwicons.icon('home') }}` |
| `home2` | `{{ gwicons.icon('home2') }}` |
| `home3` | `{{ gwicons.icon('home3') }}` |
| `hour-glass` | `{{ gwicons.icon('hour-glass') }}` |
| `html-five` | `{{ gwicons.icon('html-five') }}` |
| `html-five2` | `{{ gwicons.icon('html-five2') }}` |
| `image` | `{{ gwicons.icon('image') }}` |
| `images` | `{{ gwicons.icon('images') }}` |
| `indent-decrease` | `{{ gwicons.icon('indent-decrease') }}` |
| `indent-increase` | `{{ gwicons.icon('indent-increase') }}` |
| `infinite` | `{{ gwicons.icon('infinite') }}` |
| `info` | `{{ gwicons.icon('info') }}` |
| `insert-template` | `{{ gwicons.icon('insert-template') }}` |
| `instagram` | `{{ gwicons.icon('instagram') }}` |
| `italic` | `{{ gwicons.icon('italic') }}` |
| `key` | `{{ gwicons.icon('key') }}` |
| `key2` | `{{ gwicons.icon('key2') }}` |
| `keyboard` | `{{ gwicons.icon('keyboard') }}` |
| `lab` | `{{ gwicons.icon('lab') }}` |
| `lanyrd` | `{{ gwicons.icon('lanyrd') }}` |
| `laptop` | `{{ gwicons.icon('laptop') }}` |
| `last` | `{{ gwicons.icon('last') }}` |
| `lastfm` | `{{ gwicons.icon('lastfm') }}` |
| `lastfm2` | `{{ gwicons.icon('lastfm2') }}` |
| `leaf` | `{{ gwicons.icon('leaf') }}` |
| `library` | `{{ gwicons.icon('library') }}` |
| `libreoffice` | `{{ gwicons.icon('libreoffice') }}` |
| `lifebuoy` | `{{ gwicons.icon('lifebuoy') }}` |
| `ligature` | `{{ gwicons.icon('ligature') }}` |
| `ligature2` | `{{ gwicons.icon('ligature2') }}` |
| `link` | `{{ gwicons.icon('link') }}` |
| `linkedin` | `{{ gwicons.icon('linkedin') }}` |
| `linkedin2` | `{{ gwicons.icon('linkedin2') }}` |
| `list` | `{{ gwicons.icon('list') }}` |
| `list2` | `{{ gwicons.icon('list2') }}` |
| `list-numbered` | `{{ gwicons.icon('list-numbered') }}` |
| `location` | `{{ gwicons.icon('location') }}` |
| `location2` | `{{ gwicons.icon('location2') }}` |
| `lock` | `{{ gwicons.icon('lock') }}` |
| `loop` | `{{ gwicons.icon('loop') }}` |
| `loop2` | `{{ gwicons.icon('loop2') }}` |
| `ltr` | `{{ gwicons.icon('ltr') }}` |
| `magic-wand` | `{{ gwicons.icon('magic-wand') }}` |
| `magnet` | `{{ gwicons.icon('magnet') }}` |
| `mail` | `{{ gwicons.icon('mail') }}` |
| `mail2` | `{{ gwicons.icon('mail2') }}` |
| `mail3` | `{{ gwicons.icon('mail3') }}` |
| `mail4` | `{{ gwicons.icon('mail4') }}` |
| `make-group` | `{{ gwicons.icon('make-group') }}` |
| `man` | `{{ gwicons.icon('man') }}` |
| `man-woman` | `{{ gwicons.icon('man-woman') }}` |
| `map` | `{{ gwicons.icon('map') }}` |
| `map2` | `{{ gwicons.icon('map2') }}` |
| `menu` | `{{ gwicons.icon('menu') }}` |
| `menu2` | `{{ gwicons.icon('menu2') }}` |
| `menu3` | `{{ gwicons.icon('menu3') }}` |
| `menu4` | `{{ gwicons.icon('menu4') }}` |
| `meter` | `{{ gwicons.icon('meter') }}` |
| `meter2` | `{{ gwicons.icon('meter2') }}` |
| `mic` | `{{ gwicons.icon('mic') }}` |
| `minus` | `{{ gwicons.icon('minus') }}` |
| `mobile` | `{{ gwicons.icon('mobile') }}` |
| `mobile2` | `{{ gwicons.icon('mobile2') }}` |
| `move-down` | `{{ gwicons.icon('move-down') }}` |
| `move-up` | `{{ gwicons.icon('move-up') }}` |
| `mug` | `{{ gwicons.icon('mug') }}` |
| `music` | `{{ gwicons.icon('music') }}` |
| `neutral` | `{{ gwicons.icon('neutral') }}` |
| `neutral2` | `{{ gwicons.icon('neutral2') }}` |
| `newspaper` | `{{ gwicons.icon('newspaper') }}` |
| `new-tab` | `{{ gwicons.icon('new-tab') }}` |
| `next` | `{{ gwicons.icon('next') }}` |
| `next2` | `{{ gwicons.icon('next2') }}` |
| `notification` | `{{ gwicons.icon('notification') }}` |
| `npm` | `{{ gwicons.icon('npm') }}` |
| `office` | `{{ gwicons.icon('office') }}` |
| `omega` | `{{ gwicons.icon('omega') }}` |
| `onedrive` | `{{ gwicons.icon('onedrive') }}` |
| `opera` | `{{ gwicons.icon('opera') }}` |
| `opt` | `{{ gwicons.icon('opt') }}` |
| `pacman` | `{{ gwicons.icon('pacman') }}` |
| `pagebreak` | `{{ gwicons.icon('pagebreak') }}` |
| `page-break` | `{{ gwicons.icon('page-break') }}` |
| `paint-format` | `{{ gwicons.icon('paint-format') }}` |
| `paragraph-center` | `{{ gwicons.icon('paragraph-center') }}` |
| `paragraph-justify` | `{{ gwicons.icon('paragraph-justify') }}` |
| `paragraph-left` | `{{ gwicons.icon('paragraph-left') }}` |
| `paragraph-right` | `{{ gwicons.icon('paragraph-right') }}` |
| `paste` | `{{ gwicons.icon('paste') }}` |
| `pause` | `{{ gwicons.icon('pause') }}` |
| `pause2` | `{{ gwicons.icon('pause2') }}` |
| `paypal` | `{{ gwicons.icon('paypal') }}` |
| `pen` | `{{ gwicons.icon('pen') }}` |
| `pencil` | `{{ gwicons.icon('pencil') }}` |
| `pencil2` | `{{ gwicons.icon('pencil2') }}` |
| `phone` | `{{ gwicons.icon('phone') }}` |
| `phone-hang-up` | `{{ gwicons.icon('phone-hang-up') }}` |
| `pie-chart` | `{{ gwicons.icon('pie-chart') }}` |
| `pilcrow` | `{{ gwicons.icon('pilcrow') }}` |
| `pinterest` | `{{ gwicons.icon('pinterest') }}` |
| `pinterest2` | `{{ gwicons.icon('pinterest2') }}` |
| `play` | `{{ gwicons.icon('play') }}` |
| `play2` | `{{ gwicons.icon('play2') }}` |
| `play3` | `{{ gwicons.icon('play3') }}` |
| `plus` | `{{ gwicons.icon('plus') }}` |
| `podcast` | `{{ gwicons.icon('podcast') }}` |
| `point-down` | `{{ gwicons.icon('point-down') }}` |
| `point-left` | `{{ gwicons.icon('point-left') }}` |
| `point-right` | `{{ gwicons.icon('point-right') }}` |
| `point-up` | `{{ gwicons.icon('point-up') }}` |
| `power` | `{{ gwicons.icon('power') }}` |
| `power-cord` | `{{ gwicons.icon('power-cord') }}` |
| `previous` | `{{ gwicons.icon('previous') }}` |
| `previous2` | `{{ gwicons.icon('previous2') }}` |
| `price-tag` | `{{ gwicons.icon('price-tag') }}` |
| `price-tags` | `{{ gwicons.icon('price-tags') }}` |
| `printer` | `{{ gwicons.icon('printer') }}` |
| `profile` | `{{ gwicons.icon('profile') }}` |
| `pushpin` | `{{ gwicons.icon('pushpin') }}` |
| `qrcode` | `{{ gwicons.icon('qrcode') }}` |
| `question` | `{{ gwicons.icon('question') }}` |
| `quill` | `{{ gwicons.icon('quill') }}` |
| `quotes-left` | `{{ gwicons.icon('quotes-left') }}` |
| `quotes-right` | `{{ gwicons.icon('quotes-right') }}` |
| `radio-checked` | `{{ gwicons.icon('radio-checked') }}` |
| `radio-checked2` | `{{ gwicons.icon('radio-checked2') }}` |
| `radio-unchecked` | `{{ gwicons.icon('radio-unchecked') }}` |
| `reddit` | `{{ gwicons.icon('reddit') }}` |
| `redo` | `{{ gwicons.icon('redo') }}` |
| `redo2` | `{{ gwicons.icon('redo2') }}` |
| `renren` | `{{ gwicons.icon('renren') }}` |
| `reply` | `{{ gwicons.icon('reply') }}` |
| `road` | `{{ gwicons.icon('road') }}` |
| `rocket` | `{{ gwicons.icon('rocket') }}` |
| `rss` | `{{ gwicons.icon('rss') }}` |
| `rss2` | `{{ gwicons.icon('rss2') }}` |
| `rtl` | `{{ gwicons.icon('rtl') }}` |
| `sad` | `{{ gwicons.icon('sad') }}` |
| `sad2` | `{{ gwicons.icon('sad2') }}` |
| `safari` | `{{ gwicons.icon('safari') }}` |
| `scissors` | `{{ gwicons.icon('scissors') }}` |
| `search` | `{{ gwicons.icon('search') }}` |
| `section` | `{{ gwicons.icon('section') }}` |
| `share` | `{{ gwicons.icon('share') }}` |
| `share2` | `{{ gwicons.icon('share2') }}` |
| `shield` | `{{ gwicons.icon('shield') }}` |
| `shift` | `{{ gwicons.icon('shift') }}` |
| `shocked` | `{{ gwicons.icon('shocked') }}` |
| `shocked2` | `{{ gwicons.icon('shocked2') }}` |
| `shrink` | `{{ gwicons.icon('shrink') }}` |
| `shrink2` | `{{ gwicons.icon('shrink2') }}` |
| `shuffle` | `{{ gwicons.icon('shuffle') }}` |
| `sigma` | `{{ gwicons.icon('sigma') }}` |
| `sina-weibo` | `{{ gwicons.icon('sina-weibo') }}` |
| `sleepy` | `{{ gwicons.icon('sleepy') }}` |
| `sleepy2` | `{{ gwicons.icon('sleepy2') }}` |
| `smile` | `{{ gwicons.icon('smile') }}` |
| `smile2` | `{{ gwicons.icon('smile2') }}` |
| `sort-alpha-asc` | `{{ gwicons.icon('sort-alpha-asc') }}` |
| `sort-alpha-desc` | `{{ gwicons.icon('sort-alpha-desc') }}` |
| `sort-amount-asc` | `{{ gwicons.icon('sort-amount-asc') }}` |
| `sort-amount-desc` | `{{ gwicons.icon('sort-amount-desc') }}` |
| `sort-numberic-desc` | `{{ gwicons.icon('sort-numberic-desc') }}` |
| `sort-numeric-asc` | `{{ gwicons.icon('sort-numeric-asc') }}` |
| `soundcloud` | `{{ gwicons.icon('soundcloud') }}` |
| `soundcloud2` | `{{ gwicons.icon('soundcloud2') }}` |
| `spades` | `{{ gwicons.icon('spades') }}` |
| `spell-check` | `{{ gwicons.icon('spell-check') }}` |
| `sphere` | `{{ gwicons.icon('sphere') }}` |
| `spinner` | `{{ gwicons.icon('spinner') }}` |
| `spinner2` | `{{ gwicons.icon('spinner2') }}` |
| `spinner3` | `{{ gwicons.icon('spinner3') }}` |
| `spinner4` | `{{ gwicons.icon('spinner4') }}` |
| `spinner5` | `{{ gwicons.icon('spinner5') }}` |
| `spinner6` | `{{ gwicons.icon('spinner6') }}` |
| `spinner7` | `{{ gwicons.icon('spinner7') }}` |
| `spinner8` | `{{ gwicons.icon('spinner8') }}` |
| `spinner9` | `{{ gwicons.icon('spinner9') }}` |
| `spinner10` | `{{ gwicons.icon('spinner10') }}` |
| `spinner11` | `{{ gwicons.icon('spinner11') }}` |
| `spoon-knife` | `{{ gwicons.icon('spoon-knife') }}` |
| `spotify` | `{{ gwicons.icon('spotify') }}` |
| `stack` | `{{ gwicons.icon('stack') }}` |
| `stackoverflow` | `{{ gwicons.icon('stackoverflow') }}` |
| `star-empty` | `{{ gwicons.icon('star-empty') }}` |
| `star-full` | `{{ gwicons.icon('star-full') }}` |
| `star-half` | `{{ gwicons.icon('star-half') }}` |
| `stats-bars` | `{{ gwicons.icon('stats-bars') }}` |
| `stats-bars2` | `{{ gwicons.icon('stats-bars2') }}` |
| `stats-dots` | `{{ gwicons.icon('stats-dots') }}` |
| `steam` | `{{ gwicons.icon('steam') }}` |
| `steam2` | `{{ gwicons.icon('steam2') }}` |
| `stop` | `{{ gwicons.icon('stop') }}` |
| `stop2` | `{{ gwicons.icon('stop2') }}` |
| `stopwatch` | `{{ gwicons.icon('stopwatch') }}` |
| `strikethrough` | `{{ gwicons.icon('strikethrough') }}` |
| `stumbleupon` | `{{ gwicons.icon('stumbleupon') }}` |
| `stumbleupon2` | `{{ gwicons.icon('stumbleupon2') }}` |
| `subscript` | `{{ gwicons.icon('subscript') }}` |
| `subscript2` | `{{ gwicons.icon('subscript2') }}` |
| `sun` | `{{ gwicons.icon('sun') }}` |
| `superscript` | `{{ gwicons.icon('superscript') }}` |
| `superscript2` | `{{ gwicons.icon('superscript2') }}` |
| `svg` | `{{ gwicons.icon('svg') }}` |
| `switch` | `{{ gwicons.icon('switch') }}` |
| `tab` | `{{ gwicons.icon('tab') }}` |
| `table` | `{{ gwicons.icon('table') }}` |
| `table2` | `{{ gwicons.icon('table2') }}` |
| `tablet` | `{{ gwicons.icon('tablet') }}` |
| `target` | `{{ gwicons.icon('target') }}` |
| `telegram` | `{{ gwicons.icon('telegram') }}` |
| `terminal` | `{{ gwicons.icon('terminal') }}` |
| `text-color` | `{{ gwicons.icon('text-color') }}` |
| `text-height` | `{{ gwicons.icon('text-height') }}` |
| `text-width` | `{{ gwicons.icon('text-width') }}` |
| `ticket` | `{{ gwicons.icon('ticket') }}` |
| `tongue` | `{{ gwicons.icon('tongue') }}` |
| `tongue2` | `{{ gwicons.icon('tongue2') }}` |
| `tree` | `{{ gwicons.icon('tree') }}` |
| `trello` | `{{ gwicons.icon('trello') }}` |
| `trophy` | `{{ gwicons.icon('trophy') }}` |
| `truck` | `{{ gwicons.icon('truck') }}` |
| `tumblr` | `{{ gwicons.icon('tumblr') }}` |
| `tumblr2` | `{{ gwicons.icon('tumblr2') }}` |
| `tux` | `{{ gwicons.icon('tux') }}` |
| `tv` | `{{ gwicons.icon('tv') }}` |
| `twitch` | `{{ gwicons.icon('twitch') }}` |
| `underline` | `{{ gwicons.icon('underline') }}` |
| `undo` | `{{ gwicons.icon('undo') }}` |
| `undo2` | `{{ gwicons.icon('undo2') }}` |
| `ungroup` | `{{ gwicons.icon('ungroup') }}` |
| `unlocked` | `{{ gwicons.icon('unlocked') }}` |
| `upload` | `{{ gwicons.icon('upload') }}` |
| `upload2` | `{{ gwicons.icon('upload2') }}` |
| `upload3` | `{{ gwicons.icon('upload3') }}` |
| `user` | `{{ gwicons.icon('user') }}` |
| `user-check` | `{{ gwicons.icon('user-check') }}` |
| `user-minus` | `{{ gwicons.icon('user-minus') }}` |
| `user-plus` | `{{ gwicons.icon('user-plus') }}` |
| `users` | `{{ gwicons.icon('users') }}` |
| `user-tie` | `{{ gwicons.icon('user-tie') }}` |
| `video-camera` | `{{ gwicons.icon('video-camera') }}` |
| `vimeo` | `{{ gwicons.icon('vimeo') }}` |
| `vimeo2` | `{{ gwicons.icon('vimeo2') }}` |
| `vine` | `{{ gwicons.icon('vine') }}` |
| `vk` | `{{ gwicons.icon('vk') }}` |
| `volume-decrease` | `{{ gwicons.icon('volume-decrease') }}` |
| `volume-high` | `{{ gwicons.icon('volume-high') }}` |
| `volume-increase` | `{{ gwicons.icon('volume-increase') }}` |
| `volume-low` | `{{ gwicons.icon('volume-low') }}` |
| `volume-medium` | `{{ gwicons.icon('volume-medium') }}` |
| `volume-mute` | `{{ gwicons.icon('volume-mute') }}` |
| `volume-mute2` | `{{ gwicons.icon('volume-mute2') }}` |
| `warning` | `{{ gwicons.icon('warning') }}` |
| `whatsapp` | `{{ gwicons.icon('whatsapp') }}` |
| `wikipedia` | `{{ gwicons.icon('wikipedia') }}` |
| `windows` | `{{ gwicons.icon('windows') }}` |
| `wink` | `{{ gwicons.icon('wink') }}` |
| `wink2` | `{{ gwicons.icon('wink2') }}` |
| `woman` | `{{ gwicons.icon('woman') }}` |
| `wondering` | `{{ gwicons.icon('wondering') }}` |
| `wondering2` | `{{ gwicons.icon('wondering2') }}` |
| `wordpress` | `{{ gwicons.icon('wordpress') }}` |
| `wrench` | `{{ gwicons.icon('wrench') }}` |
| `yahoo` | `{{ gwicons.icon('yahoo') }}` |
| `yahoo2` | `{{ gwicons.icon('yahoo2') }}` |
| `yelp` | `{{ gwicons.icon('yelp') }}` |
| `youtube` | `{{ gwicons.icon('youtube') }}` |
| `youtube2` | `{{ gwicons.icon('youtube2') }}` |
| `zoom-in` | `{{ gwicons.icon('zoom-in') }}` |
| `zoom-out` | `{{ gwicons.icon('zoom-out') }}` |

---

## Changelog

- v1.0: Initial release, 478 icons, macro with name/label/class arguments, BSC and token-based sizing.

---
