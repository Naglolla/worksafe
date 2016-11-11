(function ($) {
  Drupal.behaviors.apiUsersProfileForm = {
    attach: function (context) {

                // ScrollTo 'element'
                if ($(window.location).attr('hash')){
                  setTimeout(function(){
                    $('html, body').animate({scrollTop: $($(window.location).attr('hash')).offset().top}, 0);
                  }, 800);
                }

		$("#edit-user-company").attr('disabled', true).trigger("chosen:updated");
		$("#edit-user-branch").attr('disabled', true).trigger("chosen:updated");
		$('.form-item-user-create-option').hide();
		$('.form-item-user-create-option').addClass('element-invisible');
		$('.form-item-user-branch-create-option').hide();
		$('.form-item-user-branch-create-option').addClass('element-invisible');

		// User wants to change company.
		$(':input[name="user-change-company"]').click(function() {
			if ($(this).is(':checked')) {
				$("#edit-user-company").attr('disabled', false).trigger("chosen:updated");
			}
		});

		// User selected a company or want to create a new one.
		$('#edit-user-company').change(function() {
			$(':input[name="user-change-branch"]').attr('checked', true).change();
			$('#edit-user-branch-create-option-create-a-new-facility').attr('checked', true).change();
			$('#edit-user-branch').val('_none').trigger("chosen:updated");
			if ($(this).val() == '_none') {
				$('.form-item-user-change-branch').hide();
				$(':input[name="user-create-option"]').attr('checked', true).change();
			} else {
				$('.form-item-user-change-branch').show();
			}
			// If user changes the company, enable facility selection.
			$("#edit-user-branch").attr('disabled', false).trigger("chosen:updated");
		});

		// User wants to change facility.
		$(':input[name="user-change-branch"]').click(function() {
			if ($(this).is(':checked')) {
				$("#edit-user-branch").attr('disabled', false).trigger("chosen:updated");
			}
		});

		// User selected a facility or want to create a new one.
		$('#edit-user-branch').change(function() {
			if ($(this).val() == '_none') {
				$(':input[name="user-branch-create-option"]').attr('checked', true).change();
				$('#edit-user-branch-create-option-create-a-new-facility').attr('checked', true).change();

				if ($('#edit-branch-country').val() == 'US') {
					$('.form-item-branch-state').hide();
				} else {
					$('.form-item-branch-state').show();
				}
			} else {
				$('.form-item-branch-state').hide();
			}

		});
    }
  }
})(jQuery);
