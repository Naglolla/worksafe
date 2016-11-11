(function ($) {
  function enableactions() {
    jQuery('#edit-submit').show();
    jQuery('#edit-cancel-button').show();
  }
  function disablecouponfields() {
    jQuery(".region-content :input").attr("disabled", 'disabled');
    jQuery('#edit-update-button').attr('disabled', '');
  }
  function reenablecouponfields() {
    jQuery(".date-popup-init").datepicker('enable');
    jQuery(".region-content :input").attr("disabled", '');
  }
  
  Drupal.behaviors.apiCustom = {
    attach: function (context) {

      if (jQuery('body').attr('class').indexOf('coupons-edit') !== -1) {
        disablecouponfields();
        jQuery('#edit-submit').hide();
      }
      
      jQuery('#edit-update-button').click(function (event) {
        event.preventDefault();
        reenablecouponfields();
        enableactions();
      });

      jQuery('#edit-cancel-button').click(function (event) {
        event.preventDefault();
        window.location = Drupal.settings.basePath + "admin/commerce/coupons/list";
        //disablecouponfields();
      });

      jQuery('#edit-code-verification-button').click(function (event) {
        event.preventDefault();
        //clean result
        $("#coupon-ok").remove();
        $("#coupon-exists").remove();
        var dataString = "couponcode=" + jQuery('#edit-commerce-coupon-code-und-0-value').val();
        jQuery.ajax({
          type: "POST",
          url: Drupal.settings.basePath + "api/api/getCuponCodeVerification",
          data: dataString,
          dataType: "json",
          complete: function (msg) {
            obj = JSON.parse(msg.response);
            if (obj.result) {
              jQuery('#edit-code-verification-button').after('<span id="coupon-exists" style="margin:20px;color:red;">This Coupon Code exists</span>');
            } else {
              jQuery('#edit-code-verification-button').after('<span id="coupon-ok" style="margin:20px; color:blue;">Coupon Code OK!</span>');
            }
          }});
      });

      jQuery('#edit-code-generationn-button').click(function (event) {
        event.preventDefault();
        //clean result
        $("#coupon-ok").remove();
        $("#coupon-exists").remove();
        var dataString = "lenght=4"
        jQuery.ajax({
          type: "POST",
          url: Drupal.settings.basePath + "api/api/getCuponGeneration",
          data: dataString,
          dataType: "json",
          complete: function (msg) {
            obj = JSON.parse(msg.response);
            jQuery('#edit-commerce-coupon-code-und-0-value').val(obj.result)
          }});
      });
    }}
})(jQuery);