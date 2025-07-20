/**
 * Groundwork Main Menu toggle (mobile-first)
 * -----------------------------------------
 * 1. Hamburger open/close for the whole nav.
 * 2. Sub-menu expansion on mobile is disabled for this theme.
 *
 * Expected markup:
 * <nav class="block block-menu menu--main">
 * <button class="gw-menu-toggle" aria-controls="main-menu-list" ...>…</button>
 * <ul id="main-menu-list" class="menu"> … </ul>
 * </nav>
 *
 * Vanilla JS – no jQuery dependency.
 */
(function () {
  'use strict';

  const nav = document.querySelector('nav.block.block-menu.menu--main');
  if (!nav) return;

  /* Hamburger toggle */
  const toggle = nav.querySelector('.gw-menu-toggle');
  const topMenu = nav.querySelector('#main-menu-list') || nav.querySelector('ul.menu');

  if (toggle) {
    toggle.addEventListener('click', () => {
      const open = nav.classList.toggle('is-open');
      toggle.setAttribute('aria-expanded', String(open));
      if (topMenu && !topMenu.id) {
        topMenu.id = 'main-menu-list';
      }
    });
  }

  // Sub-menu toggles on mobile have been removed to meet new requirements.
  // Clicks on all links will now navigate directly. The CSS handles hiding
  // sub-menus on mobile viewports.

})();