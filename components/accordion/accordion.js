(() => {
  document.addEventListener('DOMContentLoaded', () => {
    document.querySelectorAll('.accordion__trigger').forEach((btn) => {
      const panelId = btn.getAttribute('aria-controls');
      if (!panelId) return;
      const panel = document.getElementById(panelId);
      if (!panel) return;

      btn.addEventListener('click', () => {
        const expanded = btn.getAttribute('aria-expanded') === 'true';
        btn.setAttribute('aria-expanded', String(!expanded));
        panel.hidden = expanded;
      });
    });
  });
})();
