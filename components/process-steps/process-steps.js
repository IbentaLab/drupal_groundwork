/**
 * @file
 * Adds interactive checklist functionality to the Process Steps component.
 *
 * This script saves the checked state of each step to the browser's
 * localStorage, so progress is remembered across page loads. It also
 * handles the print functionality.
 */
(function (Drupal, once) {
  'use strict';

  // Global counter to ensure unique IDs across all components on the page
  let processStepsCounter = 0;

  /**
   * Handles the checklist functionality for a single Process Steps component.
   */
  class ProcessChecklist {
    constructor(element) {
      this.element = element;
      this.originalUniqueId = this.element.dataset.uniqueId;
      this.uniqueId = this.originalUniqueId;

      // Increment counter for each component instance
      processStepsCounter++;

      if (!this.uniqueId || this.uniqueId === 'process-block-groundwork_process_steps') {
        // Generate a guaranteed unique ID using counter + timestamp
        this.uniqueId = 'process-fallback-' + Date.now() + '-' + processStepsCounter;
        this.element.dataset.uniqueId = this.uniqueId;
        this.element.id = 'process-steps-' + this.uniqueId;

        // Also update all checkbox IDs in this component to be unique
        const checkboxes = this.element.querySelectorAll('.process-steps__checkbox');
        checkboxes.forEach((checkbox, index) => {
          const newId = `step-${this.uniqueId}-${index}`;
          const oldId = checkbox.id;
          checkbox.id = newId;

          // Update the corresponding label
          const label = this.element.querySelector(`label[for="${oldId}"]`);
          if (label) {
            label.setAttribute('for', newId);
          }
        });
      }

      // For localStorage, use the original ID if it was valid, otherwise use the new one
      // This ensures persistence when blocks are edited
      let storageId = this.originalUniqueId;
      if (!storageId || storageId === 'process-block-groundwork_process_steps') {
        // If original ID was invalid, create a stable storage ID based on content
        const firstStepTitle = this.element.querySelector('.process-steps__item-title')?.textContent || '';
        const heading = this.element.querySelector('.process-steps__heading')?.textContent || '';
        const contentHash = this.simpleHash(firstStepTitle + heading);
        storageId = 'process-content-' + contentHash;
      }

      this.storageKey = `process-steps-progress-${storageId}`;

      this.checkboxes = Array.from(this.element.querySelectorAll('.process-steps__checkbox'));
      this.resetButton = this.element.querySelector('.process-steps__reset-button');
      this.printButton = this.element.querySelector('.process-steps__print-button');

      this.loadState();
      this.addEventListeners();
    }

    // Simple hash function for creating stable content-based IDs
    simpleHash(str) {
      let hash = 0;
      if (str.length === 0) return hash.toString();
      for (let i = 0; i < str.length; i++) {
        const char = str.charCodeAt(i);
        hash = ((hash << 5) - hash) + char;
        hash = hash & hash; // Convert to 32bit integer
      }
      return Math.abs(hash).toString();
    }

    loadState() {
      try {
        const savedState = localStorage.getItem(this.storageKey);
        if (!savedState) return;

        const checkedStates = JSON.parse(savedState);
        if (Array.isArray(checkedStates) && checkedStates.length === this.checkboxes.length) {
          this.checkboxes.forEach((checkbox, index) => {
            if (checkedStates[index] === true) {
              checkbox.checked = true;
              this.updateStepAppearance(checkbox, true);
            }
          });
        }
      } catch (e) {
        localStorage.removeItem(this.storageKey);
      }
    }

    saveState() {
      try {
        const checkedStates = this.checkboxes.map(checkbox => checkbox.checked);
        localStorage.setItem(this.storageKey, JSON.stringify(checkedStates));
      } catch (e) {
        // localStorage might not be available, fail silently
      }
    }

    clearState() {
      try {
        localStorage.removeItem(this.storageKey);
        this.checkboxes.forEach(checkbox => {
          checkbox.checked = false;
          this.updateStepAppearance(checkbox, false);
        });
      } catch (e) {
        // localStorage might not be available, fail silently
      }
    }

    updateStepAppearance(checkbox, isChecked) {
      // The strikethrough effect is now handled by CSS using the form-check--strikethrough class
      // We just need to ensure the checkbox state is properly reflected
      // The visual styling is automatically handled by your form checkbox system
    }

    handlePrint() {
      // Try the popup window approach first
      try {
        const printContent = this.element.cloneNode(true);

        // Preserve checkbox states in the clone
        const originalCheckboxes = this.element.querySelectorAll('.process-steps__checkbox');
        const clonedCheckboxes = printContent.querySelectorAll('.process-steps__checkbox');

        originalCheckboxes.forEach((originalCheckbox, index) => {
          if (clonedCheckboxes[index]) {
            clonedCheckboxes[index].checked = originalCheckbox.checked;
            // Also add checked attribute for HTML
            if (originalCheckbox.checked) {
              clonedCheckboxes[index].setAttribute('checked', 'checked');
            }
          }
        });

        // Remove the action buttons from the clone
        const actionsInClone = printContent.querySelector('.process-steps__actions');
        if (actionsInClone) {
          actionsInClone.remove();
        }

        // Create a new window for printing
        const printWindow = window.open('', '_blank', 'width=800,height=600');
        if (printWindow) {
          printWindow.document.write(`
            <!DOCTYPE html>
            <html>
            <head>
              <title>Process Steps - Print</title>
              <style>
                body { font-family: Arial, sans-serif; margin: 20px; color: black; }
                .process-steps { margin: 0; }
                .process-steps__heading { font-size: 24px; margin-bottom: 16px; }
                .process-steps__list { list-style: none; padding: 0; margin: 0; counter-reset: process-counter; }
                .process-steps__item { position: relative; padding-left: 60px; margin-bottom: 24px; padding-bottom: 16px; border-bottom: 1px solid #ccc; }
                .process-steps__item:last-child { border-bottom: none; }
                .process-steps__item::before { counter-increment: process-counter; content: counter(process-counter); position: absolute; left: 0; top: 0; font-size: 24px; font-weight: bold; color: white; background-color: #666; width: 40px; height: 40px; border-radius: 50%; display: flex; align-items: center; justify-content: center; }
                .form-check { display: flex; align-items: flex-start; gap: 8px; margin-bottom: 8px; }
                .form-check__input { width: 16px; height: 16px; margin: 0; }
                .form-check__input:checked + .form-check__label { text-decoration: line-through; opacity: 0.7; }
                .form-check__label { margin: 0; font-weight: bold; }
                .process-steps__item-description { margin-left: 24px; }
                .process-steps__intro, .process-steps__outro { border: 1px solid #ccc; padding: 16px; margin: 16px 0; }
                @media print { body { margin: 0; } }
              </style>
            </head>
            <body>
              ${printContent.outerHTML}
            </body>
            </html>
          `);
          printWindow.document.close();

          printWindow.onload = function() {
            printWindow.focus();
            printWindow.print();
            printWindow.close();
          };

          return;
        }
      } catch (e) {
        // Fallback to CSS method if popup fails
        this.handlePrintCSS();
      }
    }

    handlePrintCSS() {
      // Clean up any existing print states first
      document.body.classList.remove('is-printing');
      document.querySelectorAll('.print-this-component').forEach(el => {
        el.classList.remove('print-this-component');
      });

      // Create a cleanup function that will run after printing
      const afterPrint = () => {
        document.body.classList.remove('is-printing');
        this.element.classList.remove('print-this-component');
        window.removeEventListener('afterprint', afterPrint);
      };

      const beforePrint = () => {
        document.body.classList.add('is-printing');
        this.element.classList.add('print-this-component');
      };

      // Set up the print event listeners
      window.addEventListener('afterprint', afterPrint);

      // Trigger the print with proper setup
      try {
        beforePrint();
        // Small delay to ensure CSS is applied
        setTimeout(() => {
          window.print();
        }, 100);
      } catch (e) {
        afterPrint(); // Clean up on error
      }
    }

    addEventListeners() {
      // Add change listeners to checkboxes with component scope
      this.checkboxes.forEach((checkbox, index) => {
        checkbox.addEventListener('change', (e) => {
          this.updateStepAppearance(checkbox, checkbox.checked);
          this.saveState();
        });
      });

      // Add reset button listener
      if (this.resetButton) {
        this.resetButton.addEventListener('click', (e) => {
          e.preventDefault();
          this.clearState();
        });
      }

      // Add print button listener
      if (this.printButton) {
        this.printButton.addEventListener('click', (e) => {
          e.preventDefault();
          this.handlePrint();
        });
      }
    }
  }

  /**
   * Drupal behavior to initialize all Process Steps components.
   */
  Drupal.behaviors.processSteps = {
    attach: function (context, settings) {
      // Use once() to ensure the script only attaches once per element
      once('process-steps', '.process-steps', context).forEach(function (element) {
        new ProcessChecklist(element);
      });
    }
  };

})(Drupal, once);
