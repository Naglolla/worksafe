(function ($) {
	Drupal.behaviors.apiMoodleCourselist = {
		attach: function (context) {
      var rulesInput = $('.field-name-field-apply-rules input', context);

      if (rulesInput.is(':checked')) {
          $('.field-name-field-states', context).show();
          $('.field-name-field-operator-types', context).show();
          $('div#edit-field-col-sk-certificates').show();
      } else {
          $('.field-name-field-states', context).hide();
          $('.field-name-field-operator-types', context).hide();
          $('div#edit-field-col-sk-certificates').hide();
      }
      rulesInput.click(function() {
          if ($(this).is(':checked')) {
              $('.field-name-field-states', context).show();
              $('.field-name-field-operator-types', context).show();
              $('div#edit-field-col-sk-certificates').show();
          } else {
              $('.field-name-field-states', context).hide();
              $('.field-name-field-operator-types', context).hide();
              $('div#edit-field-col-sk-certificates').hide();
          }
      });

			$('#edit-field-product-und-form-sku').change(function() {
				$('#edit-field-product-und-form-title-field input').val($('option:selected', this).text());

			});

			$('.field-name-field-course-type select', context).change(function() {
				/*
				 _none
				 1: Training
				 2: Quiz
				 3: Final Exam
				 4: Full Course + Exam
				 5: All Modules
				 6: Recommended Practice
				*/
				var course_type_element_name = $(this).attr('name');
				var course_type_wrapper_id = $(this).parents('.field-name-field-course-type').attr('id');

				var module_number_wrapper_id = '#' + course_type_wrapper_id.replace("course-type", "module-number");
				var commerce_price_wrapper_id = '#' + course_type_wrapper_id.replace("field-course-type", "commerce-price");
				$(module_number_wrapper_id, context).show();
				// Show module number field only for training, quiz and practice
				if ($(this).val() == 1 || $(this).val() == 2) {
					$(module_number_wrapper_id, context).show();
          if ($(module_number_wrapper_id + ' input', context).val() >= 4000 || $(module_number_wrapper_id + ' input', context).val() == 0) {
            $(module_number_wrapper_id + ' input', context).val('').change();
          }
				}

				if ($(this).val() == 3) {
					$(module_number_wrapper_id + ' input', context).val(0).change();
					$(module_number_wrapper_id, context).hide();
				}
				if ($(this).val() == 4 || $(this).val() == 5 || $(this).val() == 6) {
					$(module_number_wrapper_id + ' input', context).val($(this).val()*1000).change();
					$(module_number_wrapper_id, context).hide();
				}
				// If course type = quiz, hide price
				if ($(this).val() == 2) {
					$(commerce_price_wrapper_id + ' input', context).val(0).change();
					$(commerce_price_wrapper_id, context).hide();
				} else {
					$(commerce_price_wrapper_id, context).show();
				}

			});
			function change_course_type(value) {
				try{
					if (value == 4 || value == 5) {
						$('.field-name-field-module-number input').val(value*1000).change();
						$('.field-name-field-module-number input').attr('disabled', true);
					} else {
						$('.field-name-field-module-number input').val('').change();
						$('.field-name-field-module-number input').attr('disabled', false);
					}
				} catch(e) {
					$('.field-name-field-module-number input').val('').change();
					$('.field-name-field-module-number input').attr('disabled', false);
				}
			}

      $('.field-name-field-states select', context).change(function() {
          var state = $(this).val();
          var state_element_name = $(this).attr('name');
          var operator_element_name = state_element_name.replace("states", "operator_types");
          var elementToUpdate = $(".field-name-field-operator-types select[name='" + operator_element_name + "']", context);

          var url = Drupal.settings.basePath + "program/rules/state/" + state;

          if (state != '') {
              Drupal.behaviors.apiMoodleCourselist.updateOptions(url, elementToUpdate);
          }
      });
      //to update the values when entering the page
      $('div#edit-field-col-sk-certificates .field-name-field-states select', context).trigger("change");
		},
    updateOptions: function(ajaxUrl, selectElement) {
      $.ajax({
        type: "GET",
        url: ajaxUrl,
        dataType: "json",
        success: function (msg) {
          var defaultValue = selectElement.val();
          selectElement.html(' ');
          //the product types service response comes in this format
          if (msg.hasOwnProperty("creation")) {
              msg = msg['creation']['types'];
          }

          $.each(msg, function (key, value) {
              var optionKey = key;
              selectElement.append($("<option></option>")
                      .attr("value", optionKey).text(value));
          });
          selectElement.val(defaultValue);
          selectElement.trigger("chosen:updated");
          selectElement.trigger("change");
        }
      });
    }
	};
})(jQuery);
