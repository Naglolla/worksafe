jQuery(document).ready(function ($) {
    var options = {
        $DragOrientation: 1,
        $SlideWidth: 400,
        $SlideHeight: 200,
        $BulletNavigatorOptions: {                               
            $Class: $JssorBulletNavigator$,
            $ChanceToShow: 2,
            $ActionMode: 1,
            $AutoCenter: 1,                                 
            $Steps: 1,                                      
            $Lanes: 1,
            $SpacingX: 0,
            $SpacingY: 0,
            $Orientation: 1
        }
    };

  setTimeout(function(){
    if($("#slider-program-container").length > 0){
      var jssor_slider = new $JssorSlider$("slider-program-container", options);
      function ScaleSlider() {
          var bodyWidth = document.body.clientWidth;
          if (bodyWidth){
            var scale;
            if(bodyWidth > 600){
              scale = Math.min((bodyWidth-70), 650);
            }else {
              scale = Math.min((bodyWidth-40), 650);
            }
            jssor_slider.$ScaleWidth(scale);
          }else{
            window.setTimeout(ScaleSlider, 30);
          }
      }
      ScaleSlider();
      $(window).bind("load", ScaleSlider);
      $(window).bind("resize", ScaleSlider);
      $(window).bind("orientationchange", ScaleSlider);
    }
    
    
    if($('#program-container').length > 0){
      $('#program-container .program .name').dotdotdot({
        watch: true
      });
    }
    
  },100);
  
  
});


