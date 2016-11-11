jQuery(document).ready(function ($) {
  var $content = $("#edit-commerce-payment-payment-method");
  if($content.length > 0){
    var methods = $content.find('div');
    $(methods).find('input:checked').parent().addClass('select-payment-method');
    $(methods).click(function(e){
      e.stopPropagation();
      $(methods).removeClass('select-payment-method');
      $(this).addClass('select-payment-method');
    });
  }
  
});
