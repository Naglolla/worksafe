(function ($) {
	Drupal.behaviors.apiPrograms = {
		attach: function (context) {
			var state;
			var operator;
			// Program node id.
			var program_nid = $('input[name=program_nid]').val();
			// Available courses for the selected state and operator.
			var courses;
			var allCorseModulesChecked = false;
			// Total $
			var total = 0;
			// hide final exam?
			var hide_exam = false;
			$('#api-programs-buy-form .total').hide();
			$('#api-programs-buy-form .form-type-checkbox input').attr('checked', false).change();
			$('#api-programs-buy-form .form-type-checkbox').hide();
			$('#api-programs-buy-form  input[type=submit]').hide();

			$('#api-programs-buy-form  div.form-item-operator-type').hide();
			$('#api-programs-buy-form  div.form-item-courses').hide();

			$('#edit-regulatory-questions').hide();
			$('#edit-state').val('');
			$('select[name=operator_type]').val('');
			$('#edit-state').change(function() {
				state = $(this).val();
				total = 0;
				if ($(this).val() != '') {
					$('select[name=operator_type]').attr('disabled', true);
					// Get state's operators.
					var dataString = "program=" + program_nid + "&state=" + state;
					$.ajax({
						type: "POST",
						url: Drupal.settings.basePath + "api/api_programs/getStateOperators",
						data: dataString,
						dataType: "json",
						success: function(msg){
							var $el = $('select[name=operator_type]');
							$el.html(' ');
							$.each(msg, function(key, value) {
								var optionKey = key;
								if (optionKey == "A+B") {
									optionKey = 'AB';
								}
								$el.append($("<option></option>")
								.attr("value", optionKey).text(value));
							});
							$('select[name=operator_type]').trigger('change');
							$('select[name=operator_type]').attr('disabled', false);
							$('div.total').show();
						}
					});
					$('#api-programs-buy-form .total').show();
					$('#api-programs-buy-form  input[type=submit]').show();
				} else {
					operator = '';
					$('#edit-courses .form-type-checkbox input').attr('checked', false).change();
					courses = '';
					$('#api-programs-buy-form .total').hide();
					$('#api-programs-buy-form  input[type=submit]').hide();
					$('#edit-regulatory-questions').hide();

					$('#api-programs-buy-form  div.form-item-operator-type').hide();
					$('#api-programs-buy-form  div.form-item-courses').hide();
				}
			});

			// Operation type selection.
			$('select[name=operator_type]').change(function() {
				operator = $(this).val();
				total = 0;
				if ($(this).val() != '') {
				    // Get course rules.
				    var array_rules = [];
		  			$.ajax({
				     type: "GET",
				     url: Drupal.settings.basePath + "program/rules/product-types/" + state + "/" + operator,
				     dataType: "json",
				     success: function(msg){
				     	try {
				     		var rules = msg.cart.types;
				     		var module_type_test = 2;
				     		$.each(rules, function(module_type, module_name) {
				     			array_rules[module_type] = parseInt(module_type);
				     		});

							// Get state's operators.
							var dataString = "program=" + program_nid + "&state=" + state + "&operator=" + operator;
							$.ajax({
								type: "POST",
								url: Drupal.settings.basePath + "api/api_programs/getProgramCourses",
								data: dataString,
								dataType: "json",
								success: function(msg){
									$('#edit-courses .form-type-checkbox input').attr('checked', false).change();
									courses = msg;
									$('#edit-courses .form-type-checkbox').hide();
									$.each(courses, function(module_number, modules) {
										$.each(modules, function(module_type, module) {
											// do not display quizzes options.
											if ($.inArray(parseInt(module_type), array_rules) < 0) {
												$('div.form-item-courses-'+ module.product_id).show();
											} else {
												$('div.form-item-courses-'+ module.product_id).hide();
											}
											$('div.form-item-courses-'+ module.product_id + ' input').attr('attr_module_number', module_number);
											$('div.form-item-courses-'+ module.product_id + ' input').attr('attr_module_type', module_type);
											$('div.form-item-courses-'+ module.product_id + ' input').attr('attr_price', module.price.amount);

											$('div.product-price.product-'+ module.product_id).html(module.price_display);

											// is final exam in rules array?
											if ($.inArray(3, array_rules) > 0) {
												hide_exam = true;
											} else {
												hide_exam = false;
											}
										});
									});
									$('#api-programs-buy-form .total').show();
									$('#api-programs-buy-form  input[type=submit]').show();
									$('#api-programs-buy-form  div.form-item-operator-type').show();
									$('#api-programs-buy-form  div.form-item-courses').show();
								}
							});
							// Show regulatory questions?
				  			$.ajax({
						     type: "GET",
						     url: Drupal.settings.basePath + "program/rules/state/" + state + "/type/" + operator,
						     dataType: "json",
						     success: function(msg){
						     	try {
						     		if (msg.regulatory_questions) {
						     			$('#edit-regulatory-questions').show();
						     		} else {
						     			$('#edit-regulatory-questions').hide();
						     		}
					     		} catch(e) {
					     			$('#edit-regulatory-questions').hide();
					     		}
						     }
						    });

			     		} catch(e) {
			     			// do nothing.
			     		}
				     }
				    });


				}
			});

			$('#edit-courses .form-type-checkbox').change(function() {
				var module_number = $('input', this).attr('attr_module_number');
				var module_type = $('input', this).attr('attr_module_type');
				var checked = false;
				if ($('input', this).is(':checked')) {
					checked = true;
				}
				try{
					//var price = parseInt($('input', this).attr('attr_price'));
					if (typeof(module_number) != "undefined"
						&& typeof(module_type) != "undefined"
						&& typeof(courses) != "undefined"
						&& state != '') {

						var course = courses[module_number][module_type];

						// Uncheck final exam because rule's definition.
						if (hide_exam) {
							var finalExam = getCourseType(3);
							$('div.form-item-courses-'+ finalExam.product_id + ' input').attr('checked', false);
						}

						switch(module_type) {
							case '1':
								// If trainig checked/unchecked, check/uncheck quiz && full course+exam && all modules
								try{
									var quiz_id = courses[module_number][2].product_id;
									$('div.form-item-courses-'+ quiz_id + ' input').attr('checked', checked).change();

									allCorseModulesChecked = allTrainingModulesChecked();

									var allModules = getCourseType(5);
									var fullCourse = getCourseType(4);
									var finalExam = getCourseType(3);
									// all trainigs checked?
									if (allCorseModulesChecked || !checked) {
										if (allModules != '') {
											$('div.form-item-courses-'+ allModules.product_id + ' input').attr('checked', checked);
										}
									}

									// si se deselecciono un training -> deseleccionar full course+exam
									if (!checked && fullCourse != '') {
										if ($('div.form-item-courses-'+ fullCourse.product_id + ' input').is(':checked')) {
											$('div.form-item-courses-'+ fullCourse.product_id + ' input').attr('checked', checked);
										}
									}
									if (finalExam != '') {
										var finalExamInput = $('div.form-item-courses-'+ finalExam.product_id + ' input');
										// only if full course is not checked.
										if (allCorseModulesChecked && finalExamInput.is(':checked') && !$('div.form-item-courses-'+ fullCourse.product_id + ' input').is(':checked')) {
											$('div.form-item-courses-'+ fullCourse.product_id + ' input').attr('checked', true);
										}
									}
								} catch(e) {
									// do nothing.
								}
								break;

							case '3':
								// Final exam
								allCorseModulesChecked = allTrainingModulesChecked();
								if (!checked || (checked && allCorseModulesChecked)) {
									var fullCourse = getCourseType(4);
									if (fullCourse != '') {
										$('div.form-item-courses-'+ fullCourse.product_id + ' input').attr('checked', checked);
									}
								}
								break;
							case '4':
								// If all full course+exam option checked/unchecked, check/uncheck trainings and quizzes
								$.each(courses, function(course_module_number, modules) {
									$.each(modules, function(course_module_type, module) {
										if (course_module_type == 5 || course_module_type == 3) {
											$('div.form-item-courses-'+ module.product_id + ' input').attr('checked', checked).change();
										}
									});
								});
								allCorseModulesChecked = checked;
								break;
							case '5':
								// If all modules option checked/unchecked, check/uncheck trainings and quizzes
								$.each(courses, function(course_module_number, modules) {
									$.each(modules, function(course_module_type, module) {
										if (course_module_type == 1 || course_module_type == 2) {
											if ((!$('div.form-item-courses-'+ module.product_id + ' input').is(':checked') && checked) ||
												($('div.form-item-courses-'+ module.product_id + ' input').is(':checked') && !checked)) {
												$('div.form-item-courses-'+ module.product_id + ' input').attr('checked', checked).change();
											}
										}
									});
								});
								allCorseModulesChecked = checked;
								break;
						}

					}

					total = calculate_total();
					total_decimal = parseFloat(total/100).toFixed(2);
					var parts = total_decimal.toString().split(".");
					parts[0] = parts[0].replace(/\B(?=(\d{3})+(?!\d))/g, ",");
					$('.total .amount').html('$ ' + parts.join("."));

				} catch(e) {
					$('.total .amount').html('');
				}

			});

			/* Return first course of a type */
			function getCourseType(moduleTypeId) {
				var ret = '';
				try {
					$.each(courses, function(course_module_number, modules) {
						$.each(modules, function(course_module_type, module) {
							if (course_module_type == moduleTypeId) {
								ret = module;
								return false;
							}
						});
						if (ret != '') {
							return false;
						}
					});
				} catch(e) {
					// do nothing
				}
				return ret;
			}

			function getAllModulesByType(moduleTypeId) {
				var output = [];
				try {
					$.each(courses, function(course_module_number, modules) {
						$.each(modules, function(course_module_type, module) {
							if (parseInt(course_module_type) === moduleTypeId) {
								output[output.length] = module;
							}
						});
					});
				} catch(e) {
					// do nothing
				}
				return output;
			}

			// Calculate total amount.
			function calculate_total() {
				total = 0;
				// full course+exam
				var  fullCourse = getCourseType(4);
				if (fullCourse != '') {
					var inputFullCourse = $('div.form-item-courses-'+ fullCourse.product_id + ' input');
					if (inputFullCourse.is(':checked')) {
						total = parseInt(inputFullCourse.attr('attr_price'));
						return total;
					}
				}

				// final exam
				var  exam = getCourseType(3);
				if (exam != '') {
					var examInput = $('div.form-item-courses-'+ exam.product_id + ' input');
					if (examInput.is(':checked')) {
						total += parseInt(examInput.attr('attr_price'));
					}
				}

				// all modules
				var  allModules = getCourseType(5);
				if (allModules != '') {
					var inputAllModules = $('div.form-item-courses-'+ allModules.product_id + ' input');
					if (inputAllModules.is(':checked')) {
						total += parseInt(inputAllModules.attr('attr_price'));
						return total;
					}
				}

				// trainings
				var trainingInputs = $('input[attr_module_type=1]');
				$.each(trainingInputs, function(key, input) {
					if ($(this).is(':checked')) {
						total += parseInt($(this).attr('attr_price'));
					}
				});

				// recommended practice
				var  recommended = getCourseType(6);
				if (recommended != '') {
					var recommendedInput = $('div.form-item-courses-'+ recommended.product_id + ' input');
					if (recommendedInput.is(':checked')) {
						total += parseInt(recommendedInput.attr('attr_price'));
					}
				}

				return total;
			}

			// Checks if all trainigs modules are checked.
			function allTrainingModulesChecked() {
				// False by default.
				var allChecked = true;
				// Gets all training modules.
				var trainings = getAllModulesByType(1);

				$.each(trainings, function(key, training) {
					var trainingInput = $('div.form-item-courses-'+ training.product_id + ' input');
					if (!trainingInput.is(':checked')) {
						allChecked = false;
						return false;
					}
				});
				return allChecked;
			}
		}
	};
})(jQuery);
