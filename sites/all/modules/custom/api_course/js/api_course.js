/* 
 * API Course module (JavaScript functions)
 */
(function ($) {
  /**
   * returns version of IE or false, if browser is not Internet Explorer
   * @returns {Boolean}
   */
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
  

  $(document).ready(function() {
    $('body').addClass('has-iframe');
    $('a.without-link').click(function(evt){
      evt.preventDefault();
      return false;
    });
    
    var offset = 20;
    $('iframe.autoresize').iframeAutoHeight(
      {
        debug: false,
        diagnostics: false,
        heightOffset: offset,
        callback: function(callbackObject) {

        }
      }
    );

    // fix IE delay iframe load issue
    if(isIE()){
      var lastHeight = 0, curHeight = 0, $frame = $('iframe:eq(0)');
      setInterval(function(){
        curHeight = $frame.contents().find('body').height() + offset;
        if ( curHeight - lastHeight > offset*5 ) {
          $frame.css('height', (lastHeight = curHeight) + 'px' );
        }
      },1000);
    }

    $('body.page-courses-training iframe.autoresize').load(function(evt){
      
    });
    // Prevent browser 'back' navigation
    $('body.page-courses-quiz iframe.autoresize,body.page-courses-finalexam iframe.autoresize').load(function(evt){
      evt.currentTarget.contentWindow.history.forward();
      $('body.page-courses-quiz iframe.autoresize,body.page-courses-finalexam iframe.autoresize').contents().find('div.submitbtns div.link a').click(function(evt){
        var r = confirm("Are you sure you want to Exit ?");
        if (r == true) {
            return true;
        } else {
            return false;
        }
        evt.preventDefault();
        return false;
      });
    });
    
  });
})(jQuery);

