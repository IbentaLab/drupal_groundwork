(function () {
  'use strict';

  function initNavAccordion() {
    const toggles = document.querySelectorAll('.nav-accordion__toggle-btn:not(.js-processed)');

    toggles.forEach(function (btn) {
      btn.classList.add('js-processed');

      const panelId = btn.getAttribute('aria-controls');
      if (!panelId) return;
      const panel = document.getElementById(panelId);
      if (!panel) return;

      btn.addEventListener('click', function (e) {
        e.stopPropagation();

        const expanded = btn.getAttribute('aria-expanded') === 'true';
        btn.setAttribute('aria-expanded', String(!expanded));
        panel.hidden = expanded;
      });
    });
  }

  // Try Drupal behaviors first
  if (typeof Drupal !== 'undefined' && Drupal.behaviors) {
    Drupal.behaviors.navAccordion = {
      attach: function (context, settings) {
        initNavAccordion();
      }
    };
  }

  // Fallback for when Drupal behaviors don't work
  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initNavAccordion);
  } else {
    initNavAccordion();
  }
})();
