/* 
 * API Safety Keys module (JavaScript functions)
 */
(function ($) {
  $(document).ready(function() {
    $('body.page-search-safety-key input.form-submit').click(function(evt){
      safetyKey = $.trim($('body.page-search-safety-key input.form-text').val());
      if (safetyKey === ''){
        evt.preventDefault();
      }
    });
  });
})(jQuery);

