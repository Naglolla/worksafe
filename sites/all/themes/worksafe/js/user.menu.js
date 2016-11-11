jQuery(document).ready(function ($) {
  var $menuContent = $('#region-user-second');
  var $menu = $menuContent.find('.menu');
  var $menuBtn = $('#hello-user-block');
  if($menuBtn.size() > 0){
    $menu.addClass('loginuser');
    $menuBtn.click(function(e){
      e.stopPropagation();
      $menu.fadeToggle();
    });
    $('html').click(function() {
      $menu.fadeOut();
    });
  }
  $(window).bind("resize", function(){
    if(document.body.clientWidth < 600){
      $menuContent.find('.menu.loginuser').fadeOut();
    }
  });
});

