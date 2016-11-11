(function ($) {
    function showChangePassword(){
        $('.form-item.form-type-password.form-item-fake-pass.form-disabled').hide();
        $('.form-item.form-type-checkbox.form-item-show-character-pass').show();
        $('.form-item.form-type-password-confirm.form-item-pass').show();
        $('.form-item.form-type-password.form-item-current-pass').show();
        $('#change-pass').hide();
    }
    
    function hideChangePassword(){
        $('.form-item.form-type-password-confirm.form-item-pass').hide();
        $('.form-item.form-type-checkbox.form-item-show-character-pass').hide();
        $('.form-item.form-type-password.form-item-current-pass').hide();
    }
    
    function isChangePasswordError(){
        return $('#edit-current-pass').hasClass('error') ||
            $('#edit-pass-pass1').hasClass('error') ||
            $('#edit-pass-pass2').hasClass('error');
    }
    
    function showFakePass(){
      document.getElementById('edit-fake-pass').value ='*****';
    }
    
    $(document).ready(function ($) {
        
        if(!isChangePasswordError()){
            hideChangePassword();
            showFakePass();
        }else{
            showChangePassword();
        }
        $('#change-pass').click(function(e){
            e.preventDefault();
            showChangePassword();
        });
        $('#show-character-pass').click(function(){
           if($(this).is(':checked')){
               document.getElementById('edit-pass-pass1').type='text';
               document.getElementById('edit-pass-pass2').type='text';
           }else{
               document.getElementById('edit-pass-pass1').type='password';
               document.getElementById('edit-pass-pass2').type='password';
           }
        });
    });
})(jQuery);