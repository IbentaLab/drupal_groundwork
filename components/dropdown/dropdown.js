// dropdown-edge-flip.js: Edge-aware flyout for Level-2
(() => {
  function flipFlyoutIfNeeded(panel) {
    // Reset first
    panel.style.left = '100%';
    panel.style.right = 'auto';
    // Check if it overflows right edge
    const rect = panel.getBoundingClientRect();
    if (rect.right > window.innerWidth) {
      panel.style.left = 'auto';
      panel.style.right = '100%';
    }
  }
  document.addEventListener('DOMContentLoaded', () => {
    document.querySelectorAll('.dropdown--level-2').forEach(panel => {
      const parent = panel.parentElement;
      if (!parent) return;
      parent.addEventListener('mouseenter', () => flipFlyoutIfNeeded(panel));
      parent.addEventListener('focusin', () => flipFlyoutIfNeeded(panel));
      window.addEventListener('resize', () => flipFlyoutIfNeeded(panel));
    });
  });
})();
