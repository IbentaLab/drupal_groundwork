// dropdown-edge-flip.js: Edge-aware flyout for Level-2 with LTR/RTL support.
(() => {
  function flipFlyoutIfNeeded(panel) {
    const isRTL = document.documentElement.dir === 'rtl';

    if (isRTL) {
      // --- RTL LOGIC ---
      // Reset to default RTL position (opens to the left)
      panel.style.right = '100%';
      panel.style.left = 'auto';

      // Check if it overflows the left edge
      const rect = panel.getBoundingClientRect();
      if (rect.left < 0) {
        // Flip to open to the right
        panel.style.right = 'auto';
        panel.style.left = '100%';
      }
    } else {
      // --- LTR LOGIC (Original) ---
      // Reset to default LTR position (opens to the right)
      panel.style.left = '100%';
      panel.style.right = 'auto';

      // Check if it overflows the right edge
      const rect = panel.getBoundingClientRect();
      if (rect.right > window.innerWidth) {
        // Flip to open to the left
        panel.style.left = 'auto';
        panel.style.right = '100%';
      }
    }
  }

  document.addEventListener('DOMContentLoaded', () => {
    document.querySelectorAll('.dropdown--level-2').forEach(panel => {
      const parent = panel.parentElement;
      if (!parent) return;
      parent.addEventListener('mouseenter', () => flipFlyoutIfNeeded(panel));
      parent.addEventListener('focusin', () => flipFlyoutIfNeeded(panel));
      // It's more efficient to recalculate on resize than to listen for every scroll event.
      window.addEventListener('resize', () => flipFlyoutIfNeeded(panel));
    });
  });
})();
