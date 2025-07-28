(function () {
  'use strict';

  function calculateHeaderBottom() {
    const headerRegion = document.querySelector('.region-header');
    if (!headerRegion) {
      return 0;
    }

    // Get the current position in the viewport
    const headerRect = headerRegion.getBoundingClientRect();
    
    // Return the bottom position relative to viewport (for fixed positioning)
    return headerRect.bottom;
  }

  function positionAccordion(accordion) {
    if (!accordion) return;
    
    if (accordion.closest('.region-header')) {
      const headerBottom = calculateHeaderBottom();
      // Set position relative to viewport (for fixed positioning)
      accordion.style.top = headerBottom + 'px';
    }
  }

  function initHorizontalMenu() {
    const toggles = document.querySelectorAll('.horizontal-menu__toggle:not(.js-processed)');

    toggles.forEach(function (toggle) {
      toggle.classList.add('js-processed');

      const accordionId = toggle.getAttribute('aria-controls');
      const accordion = document.getElementById(accordionId);

      if (!accordion) return;

      // Position the accordion initially
      positionAccordion(accordion);

      toggle.addEventListener('click', function (e) {
        e.preventDefault();

        const isExpanded = toggle.getAttribute('aria-expanded') === 'true';

        // Toggle the expanded state
        toggle.setAttribute('aria-expanded', !isExpanded);
        accordion.hidden = isExpanded;
        toggle.classList.toggle('is-active', !isExpanded);

        // Recalculate position when opening
        if (!isExpanded) {
          positionAccordion(accordion);
        }
      });
    });

    // Recalculate positions on window resize
    let resizeTimeout;
    window.addEventListener('resize', function() {
      clearTimeout(resizeTimeout);
      resizeTimeout = setTimeout(function() {
        const accordions = document.querySelectorAll('.region-header .horizontal-menu__accordion');
        accordions.forEach(positionAccordion);
      }, 250);
    });

    // ADD BACK: Recalculate positions on scroll to stick under header
    let scrollTimeout;
    window.addEventListener('scroll', function() {
      clearTimeout(scrollTimeout);
      scrollTimeout = setTimeout(function() {
        const accordions = document.querySelectorAll('.region-header .horizontal-menu__accordion:not([hidden])');
        accordions.forEach(positionAccordion);
      }, 16); // ~60fps for smooth tracking
    });
  }

  // Try Drupal behaviors first
  if (typeof Drupal !== 'undefined' && Drupal.behaviors) {
    Drupal.behaviors.horizontalMenu = {
      attach: function (context, settings) {
        initHorizontalMenu();
      }
    };
  }

  // Fallback for when Drupal behaviors don't work
  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initHorizontalMenu);
  } else {
    initHorizontalMenu();
  }
})();
