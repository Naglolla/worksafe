jQuery(document).ready(function ($) {
  var $finalExamWidget = $('#block-api-moodle-api-moodle-program-block');
  var $finalExamMessage = $('#block-api-moodle-api-moodle-program-block .message');
  var $safetyKeyWidget = $('#block-api-safety-keys-safety-key-program-block');
  var $safetyKeyMessage = $('#block-api-safety-keys-safety-key-program-block .message');
  
  function resizeWidget() {
    $finalExamMessage.height('auto');
    $safetyKeyMessage.height('auto');
    if(document.body.clientWidth > 590) {
      if($finalExamWidget.length > 0 && $safetyKeyWidget.length > 0) {
        // message height reset
        $finalExamMessage.height('auto');
        $safetyKeyMessage.height('auto');
        if($finalExamMessage.height() > $safetyKeyMessage.height()){
          $safetyKeyMessage.height($finalExamMessage.height());
        }else{
          $finalExamMessage.height($safetyKeyMessage.height());
        }
      }
    }
  }
  if($('body').hasClass('page-course')){
    setTimeout(function(){
      resizeWidget();
    },100);
    $( window ).resize(function() {
      resizeWidget();
    });
  }
});

