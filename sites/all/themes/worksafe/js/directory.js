jQuery(document).ready(function ($) {
  function getPadding(){
    var topMargin = parseInt($('#edit-field-address-administrative-area-wrapper').css('margin-top'));
    return $('#edit-field-address-administrative-area-wrapper').outerHeight() + topMargin
        + $('#edit-field-address-data-wrapper').outerHeight() + topMargin
        + $('#edit-field-types-of-work-value-wrapper').outerHeight() + topMargin ;
  }
  function alignButtons() {
    if($(window).width() > 900){
        $('.column-2 .submit-company').css('padding-top', getPadding());
      }else{
        $('.column-2 .submit-company').css('padding-top',0);
      }
  }
  if($('body').hasClass('page-directory')){
    if($(window).width() > 900){
      $('.column-2 .submit-company').css('padding-top', getPadding());
    }
    $(window).bind("resize", function(){
      alignButtons();
    });
    $('.chosen-choices').bind("DOMSubtreeModified",function(){
      alignButtons();
    });
  }
});