jQuery(document).ready(function ($) {
  var $menu = $('#mobile-menu-content ul.menu');
  function getMenuCloseSize(){
    return $('#mobile-menu-content').height();
  }
  function getMenuOpenSize(){
    var height = $($menu.children()[0]).height()+1;
    var amountElement = $menu.children().size()
    return (height * amountElement)+ (getMenuCloseSize()-2);
  }
  $('#mobile-menu-content #mobile-menu-icon').click(function(){
    $(this).toggleClass('open');
    if($(this).hasClass('open')){
      $menu.show();
      $('#zone-menu').height(getMenuOpenSize());
      $('#zone-menu').css('max-height',getMenuOpenSize());
    }else{
      $('#zone-menu').height(getMenuCloseSize());
      $menu.hide();
    }
  });
  $('#zone-menu').bind("transitionend webkitTransitionEnd oTransitionEnd MSTransitionEnd", function(){
    if(!$('#mobile-menu-content #mobile-menu-icon').hasClass('open')){
      $menu.hide();
    }
  });
  $(window).bind("resize", function(){
    var bodyWidth = document.body.clientWidth;
    if(bodyWidth > 600){
      $('#zone-menu').css("height", "");
      if($('#mobile-menu-content #mobile-menu-icon').hasClass('open')){
        $('#mobile-menu-content #mobile-menu-icon').removeClass('open');
        $menu.hide();
      }
    }
  });
  $menu.hide();
  $('.second-menu ul.menu');
  //hide mobile main links
  $('.second-menu ul.menu li a.show-only-mobile').parent().hide()
});

