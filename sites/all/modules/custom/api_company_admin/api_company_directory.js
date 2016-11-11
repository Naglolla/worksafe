(function ($) {
  Drupal.behaviors.apiCompanyAdmin = {
    attach: function (context, settings) {
        $('select#edit-field-address-administrative-area').chosen({placeholder_text_multiple: Drupal.t('Multi Select')});
        $('select#edit-field-types-of-work-value').chosen({placeholder_text_multiple: Drupal.t('Multi Select')});
        // If search by company name, set default country to US.
        if ($('input[name=title]').val() != '') {
          $('select[name=field_address_country]').val('US');
        }

        $('#edit-field-address-country').change(function() {
            showStateField($('#edit-field-address-country').val());
        });

        //this is for when you enter the page
        showStateField($('#edit-field-address-country').val());

        $('.submit-state input[type=submit]').click(function() {
          $('input[name=title]').attr('disabled', true);
        });
        $('.submit-company input[type=submit]').click(function() {
          $('select[name=field_address_country]').val('All');
          $('select#edit-field-address-administrative-area').attr('disabled', true);
          $('input[name=field_address_data]').attr('disabled', true);
          $('select#edit-field-types-of-work-value').attr('disabled', true);
        });
    }}

  function showStateField(country) {
      if (country == 'US') {
        // Disable Province/Region field.
        $('#edit-field-address-data').val('');
        $('#edit-field-address-data').attr('disabled', true);
        // Enable States dropdown field.
        $('#edit-field-address-administrative-area').attr('disabled', false);
        $('#edit-field-address-administrative-area').trigger("chosen:updated");
      }
      else {
        // Enable Province/Region field.
        $('#edit-field-address-data').attr('disabled', false);
        // Clean States dropdown field.
        $('#edit-field-address-administrative-area').val('');
        $('#edit-field-address-administrative-area').attr('disabled', true);
        $('#edit-field-address-administrative-area').trigger("chosen:updated");
      }
  }
})(jQuery);
