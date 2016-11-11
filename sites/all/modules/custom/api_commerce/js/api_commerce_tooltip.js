(function ($) {
  Drupal.behaviors.apiCommerceTooltip = {
    attach: function (context, settings) {
      var $content = $("#payment-details");
      var $tooltipIcon = $content.find('#tooltip-link');
      var $tooltipContent  = $content.find('#csc-tooltip');
      $tooltipIcon.click(function(e){
        e.preventDefault();
        if($tooltipIcon.attr('current-click') === 'true')
          return;
        $tooltipIcon.attr('current-click',true);
        if($tooltipContent.is(':visible')){
          $tooltipContent.fadeOut(function(){
            $tooltipIcon.attr('current-click',false);
          });
        }else{
          $tooltipContent.fadeIn(function(){
            $tooltipIcon.attr('current-click',false);
          });
        }
      });
      $('html').click(function(e) {
        if(e.target.id === 'tooltip-link')
          return;
        $tooltipContent.fadeOut();
      });
    }
  }
})(jQuery);
