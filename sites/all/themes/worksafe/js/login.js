jQuery(document).ready(function ($) {
  function isIE() {
    var ua = window.navigator.userAgent;
    var msie = ua.indexOf('MSIE ');
    if (msie > 0) {
        // IE 10 or older => return version number
        return parseInt(ua.substring(msie + 5, ua.indexOf('.', msie)), 10);
    }
    var trident = ua.indexOf('Trident/');
    if (trident > 0) {
        // IE 11 => return version number
        var rv = ua.indexOf('rv:');
        return parseInt(ua.substring(rv + 3, ua.indexOf('.', rv)), 10);
    }
    var edge = ua.indexOf('Edge/');
    if (edge > 0) {
       // IE 12 => return version number
       return parseInt(ua.substring(edge + 5, ua.indexOf('.', edge)), 10);
    }
    // other browser
    return false;
  }
  if($('body').hasClass('page-user-login')){
    var fixSize = 147;
    if(isIE())
      fixSize = 150;
    var margin = (25
            +$('.form-item-name').height()
            +$('.form-item-pass').height()
            +$('.form-item-remember-me').height()) - fixSize;
    $('div.information').css('margin-bottom',margin);
  }
});