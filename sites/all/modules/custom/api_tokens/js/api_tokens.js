(function($) {
    Drupal.behaviors.apiTokens = {
        attach: function(context) {
            $('#edit-field-token-entity-id-und-0-value').attr('maxlength', 8);
            $('#edit-field-token-entity-id-und-0-value').attr('size', 8);
            $('.get-random-code').click(function(event) {
                var txtCode = $(this).attr('rel');
                event.preventDefault();
                $.ajax({
                    type: "POST",
                    url: Drupal.settings.basePath + "api/api/generateTokenCode",
                    dataType: "json",
                    success: function(msg) {
                        $('input[name="' + txtCode + '"]').val(msg.result);
                    }
                });
            });

            //this is for the token creation page for Regular user and Company Admin (add_to_cart form)
            $("label[for='edit-line-item-fields-field-date-from-to-und-0-value-datepicker-popup-0']").html('Start Date');
            $("label[for='edit-line-item-fields-field-date-from-to-und-0-value2-datepicker-popup-0']").html('End Date');
            
            //this is the token creation for Customer support and edition for all roles
            $("label[for='edit-field-token-entity-date-from-to-und-0-value-datepicker-popup-0']").html('Start Date');
            $("label[for='edit-field-token-entity-date-from-to-und-0-value2-datepicker-popup-0']").html('End Date');
        }
    };
})(jQuery);