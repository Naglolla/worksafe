/*
 * API Users Feed Import (JavaScript functions)
 */
(function ($) {
  Drupal.behaviors.apiUsersFeedsImport = {
    attach: function (context) {
      var filterXHR = null;
      $(document).ajaxSend(function (event, jqXHR, settings) {
        filterXHR = jqXHR; // cache XHR object for current ajax request
      });

      $('body.page-import-users .view-display-id-company_admin_user_import_search input.form-submit').click(function(evt){
        userName = $.trim($('body.page-import-users .view-display-id-company_admin_user_import_search input.form-text').val());
        if (userName === ''){
          evt.preventDefault();
          if (filterXHR && filterXHR.readyState != 4) {
            // abort ajax request
            filterXHR.abort();

            // subsequent requests will add their own progress indicator,
            // so you probably want to remove the old one here
            $('.ajax-progress').remove();
          }
          evt.stopPropagation();
        }
      });
    }
  }

  /**
   * Handler for the form redirection error.
   */
  Drupal.ajax.prototype.error = function (response, uri) {
    var path = window.location.pathname;
    // Prevent ajax error in user import page.
    if (path.indexOf("/import/users") < 0) {
      alert(Drupal.ajaxError(response, uri));
    }
    // Remove the progress element.
    if (this.progress.element) {
      $(this.progress.element).remove();
    }
    if (this.progress.object) {
      this.progress.object.stopMonitoring();
    }
    // Undo hide.
    $(this.wrapper).show();
    // Re-enable the element.
    $(this.element).removeClass('progress-disabled').removeAttr('disabled');
    // Reattach behaviors, if they were detached in beforeSerialize().
    if (this.form) {
      var settings = response.settings || this.settings || Drupal.settings;
      Drupal.attachBehaviors(this.form, settings);
    }
  };

})(jQuery);
