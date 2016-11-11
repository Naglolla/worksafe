(function() {
  
  /**
   * Check if page load into iframe
   * @returns {Boolean}
   */
  function inIframe () {
    try {
        return window.self !== window.top;
    } catch (e) {
        return true;
    }
  }
  
  /**
   * On document ready event
   * if page is load into iframe, add specific class to body
   */
  function documentReady(){
    if(inIframe()){
      document.getElementsByTagName('body')[0].setAttribute('class', 'iframe-page-load');
    }
  }
  
  
  document.addEventListener('DOMContentLoaded', documentReady, false);
})();