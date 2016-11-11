(function ($) {
  Drupal.behaviors.apiProgramRules = {
    attach: function (context) {
    	var state;
    	var operator;
    	if ($('#edit-state').val() == '') {
    		$('div.description').hide();
    	}
	  	$('#edit-state').change(function() {
	  		state = $(this).val();
	  		if ($(this).val() != '') {
				// Get state's operators.
	  			$.ajax({
			     type: "GET",
			     url: Drupal.settings.basePath + "program/rules/state/" + state,
			     dataType: "json",
			     success: function(msg){
					var $el = $('#edit-operator-type');
					$el.html(' ');
					$.each(msg, function(key, value) {
					 var optionKey = key;
					 if (optionKey == "A+B") {
					 	optionKey = 'A B';
					 }
					 $el.append($("<option></option>")
					 .attr("value", optionKey).text(value));
					});
					$('#edit-operator-type').trigger('change');
					$('div.description').show();
			     }
			    });
	  		} else {
	  			$('div.state-rules').html('');
	  			$('div.description').hide();
	  		}
	  	});
	  	$('#edit-operator-type').change(function() {
	  		operator = $(this).val();
	  		if ($(this).val() != '') {
				// Get state's operators.
	  			$.ajax({
			     type: "GET",
			     url: Drupal.settings.basePath + "program/rules/state/" + state + "/type/" + operator,
			     dataType: "json",
			     success: function(msg){
					output = prettyPrint(msg);
					$('div.state-rules').html(output);
			     }
			    });
	  		}
	  	});
    }
  };
})(jQuery);
