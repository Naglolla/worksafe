(function ($) {
  Drupal.behaviors.apiCustom = {
    attach: function (context) {

      if (jQuery('body').attr('class').indexOf('page-admin-commerce-coupons') !== -1) {

        if (window.location.href.indexOf('?') !== -1) {
          //alert("existe");
          url = window.location.href;
          parts = url.split("?");
          jQuery('#coupon-export').attr('href', Drupal.settings.basePath + 'export/couponslist?' + parts[1].toString());
        }
        else {

          jQuery('#coupon-export').attr('href', Drupal.settings.basePath + 'export/couponslist');
        }
      }

      if (document.URL.indexOf('pass-reset-token') !== -1) {

        jQuery('html,body').animate({scrollTop: jQuery("#edit-mail").offset().top});
        jQuery("#edit-pass-pass1").focus();
      }

    }
  }

})(jQuery);