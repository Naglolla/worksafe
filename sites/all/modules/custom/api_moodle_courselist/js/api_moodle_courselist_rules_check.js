(function ($) {
	Drupal.behaviors.apiMoodleCourselistRulesCheck = {
            attach: function(context, settings) {
                if ($('#ief-entity-table-edit-field-product-und-entities').length ) {
                  //we are in the IEF
                  $('#ief-entity-table-edit-field-product-und-entities').once('rules-added', function() {
                    Drupal.behaviors.apiMoodleCourselistRulesCheck.initialize(context, settings);
                  })
                }
                else {
                  //we are in the standalone product edit form
                  Drupal.behaviors.apiMoodleCourselistRulesCheck.initialize(context, settings);
                }
            },
            initialize: function(context, settings) {
                $('.field-name-field-images').remove();
                var rulesInput = $('.field-name-field-apply-rules input');
                rulesInput.click(function() {
                    if ($(this).is(':checked')) {
                        /*
                        $('.field-name-field-states', context).show();
                        $('.field-name-field-operator-types', context).show();
                        */
                    } else {
                        $('.field-name-field-states select', context).val('_none').change();
                        $('.field-name-field-operator-types select', context).val('_none').change();
                        $('.field-name-field-states select', context).trigger("chosen:updated");
                        $('.field-name-field-operator-types select', context).trigger("chosen:updated");
                    }
                });

                $('.field-name-field-states select', context).change(function() {
                    var state = $(this).val();
                    var state_element_name = $(this).attr('name');
                    var operator_element_name = state_element_name.replace("states", "operator_types");
                    var elementToUpdate = $(".field-name-field-operator-types select[name='" + operator_element_name + "']", context);

                    var url = Drupal.settings.basePath + "program/rules/state/" + state;

                    if (state != '') {
                        Drupal.behaviors.apiMoodleCourselistRulesCheck.updateOptions(url, elementToUpdate);
                    }
                });

                $('.field-name-field-operator-types select', context).change(function() {
                    var operator_type = $(this).val();
                    if (operator_type == "A+B") {
                      operator_type = 'A B';
                    }
                    var operator_element_name = $(this).attr('name');
                    var state_element_name = operator_element_name.replace("operator_types", "states");
                    var state = $(".field-name-field-states select[name='" + state_element_name + "']", context).val();

                    var course_type_name = operator_element_name.replace("operator_types", "course_type");
                    var elementToUpdate = $(".field-name-field-course-type select[name='" + course_type_name + "']", context);

                    var url = Drupal.settings.basePath + "program/rules/product-types/" + state + "/" + operator_type;

                    Drupal.behaviors.apiMoodleCourselistRulesCheck.updateOptions(url, elementToUpdate);
                });

                $('.field-name-field-course-type select', context).change(function() {
                    //hide course if not a type that needs to be associated with a Moodle course
                    if ($(this).val() == settings.course_type_full_course || $(this).val() == settings.course_type_all_modules) {
                        $('.form-item-field-product-und-form-sku').hide();
                        var selected_course_type = $(this).val();

                        $('#edit-field-product-und-form-sku > option').each(function() {
                           var moodle_course = $(this).val().split('|');
                           if (moodle_course[0] == selected_course_type) {
                             $(this).attr('selected', true);
                           }
                        });
                    }
                    else {
                        $('.form-item-field-product-und-form-sku').show();
                        $('#edit-field-product-und-form-sku').val("_none");
                    }
                });

                //hide All modules and Full course in the Moodle courses select
                $('#edit-field-product-und-form-sku > option').each(function() {
                  var moodle_course = $(this).val().split('|');
                  if (moodle_course[0] == settings.course_type_full_course
                      || moodle_course[0] == settings.course_type_all_modules) {
                    $(this).hide();
                  }
                });
                //to update the values when entering the page
                $('.field-name-field-states select', context).trigger("change");
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
        }
})(jQuery);
