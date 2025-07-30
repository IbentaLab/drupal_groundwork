(() => {
  document.addEventListener('DOMContentLoaded', () => {
    const triggers = document.querySelectorAll('.accordion__trigger');

    triggers.forEach(trigger => {
      trigger.addEventListener('click', () => {
        const expanded = trigger.getAttribute('aria-expanded') === 'true';
        const targetId = trigger.getAttribute('aria-controls');
        const target = document.getElementById(targetId);

        trigger.setAttribute('aria-expanded', String(!expanded));
        target.hidden = expanded;
      });
    });
  });
})();
