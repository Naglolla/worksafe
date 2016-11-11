(function ($) {
  Drupal.behaviors.apiCompanyAdmin = {
    attach: function (context, settings) {
        $('#edit-field-country-und').change(function() {
            showStateField($('#edit-field-country-und').val());
        });

        //this is for when you enter the page
        showStateField($('#edit-field-country-und').val());
  }}

  function showStateField(country) {
      if (country == 'US') {
        $('#edit-field-us-states').show();
        $('#edit-field-states-where-operates').hide();
      }
      else {
        $('#edit-field-us-states').hide();
        $('#edit-field-states-where-operates').show();
      }
  }
})(jQuery);
