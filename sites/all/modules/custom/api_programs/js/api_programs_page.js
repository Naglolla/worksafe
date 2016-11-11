(function ($) {
  $(document).ready( function () {
    $('a.show-more').click(function() {
      var program_nid = $(this).attr('attr-program-id');
      $(this).hide();
      $('.program-' + program_nid + '-long-description').show();
    });
  });
}(jQuery));
