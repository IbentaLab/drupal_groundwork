/**
 * @file
 * Vertical Tabs component behavior.
 * This script provides an accessible and responsive vertical tabs component.
 * The core logic is identical to the horizontal tabs component.
 */
(() => {
  class VerticalTabs {
    constructor(container) {
      this.container = container;
      this.triggers = Array.from(container.querySelectorAll('.vertical-tabs__trigger'));
      this.panels = Array.from(container.querySelectorAll('.vertical-tabs__panel'));

      this.init();
    }

    init() {
      // Set initial state: activate the first tab
      if (this.triggers.length > 0) {
        this.activateTab(this.triggers[0], this.panels[0]);
        this.triggers.slice(1).forEach((trigger, i) => {
          this.deactivateTab(trigger, this.panels[i + 1]);
        });
      }

      // Attach event listeners
      this.container.addEventListener('click', this.handleClick.bind(this));
      this.container.addEventListener('keydown', this.handleKeydown.bind(this));
    }

    handleClick(event) {
      const clickedTrigger = event.target.closest('.vertical-tabs__trigger');
      if (!clickedTrigger || clickedTrigger.getAttribute('aria-selected') === 'true') {
        return;
      }

      // Deactivate all others
      this.triggers.forEach((trigger, i) => {
        this.deactivateTab(trigger, this.panels[i]);
      });

      // Activate the clicked one
      const panel = document.getElementById(clickedTrigger.getAttribute('aria-controls'));
      this.activateTab(clickedTrigger, panel);
    }

    handleKeydown(event) {
      const currentTrigger = event.target.closest('.vertical-tabs__trigger');
      if (!currentTrigger) return;

      let nextTrigger;
      const currentIndex = this.triggers.indexOf(currentTrigger);

      // Vertical navigation for vertical tabs
      const keyMap = { ArrowDown: 1, ArrowUp: -1 };
      const direction = keyMap[event.key];

      if (direction) {
        event.preventDefault();
        const nextIndex = (currentIndex + direction + this.triggers.length) % this.triggers.length;
        nextTrigger = this.triggers[nextIndex];
      } else if (event.key === 'Home') {
        event.preventDefault();
        nextTrigger = this.triggers[0];
      } else if (event.key === 'End') {
        event.preventDefault();
        nextTrigger = this.triggers[this.triggers.length - 1];
      }

      if (nextTrigger) {
        this.handleClick({ target: nextTrigger });
        nextTrigger.focus();
      }
    }

    activateTab(trigger, panel) {
      trigger.setAttribute('aria-selected', 'true');
      trigger.setAttribute('tabindex', '0');
      panel.hidden = false;
    }

    deactivateTab(trigger, panel) {
      trigger.setAttribute('aria-selected', 'false');
      trigger.setAttribute('tabindex', '-1');
      panel.hidden = true;
    }
  }

  document.addEventListener('DOMContentLoaded', () => {
    const tabContainers = document.querySelectorAll('[data-drupal-nav-tabs]');
    tabContainers.forEach(container => {
      // Simple check to not re-initialize
      if (!container.classList.contains('js-vertical-tabs-processed')) {
        container.classList.add('js-vertical-tabs-processed');
        new VerticalTabs(container);
      }
    });
  });
})();
