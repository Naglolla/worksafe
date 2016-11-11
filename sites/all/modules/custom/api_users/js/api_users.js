(function($) {
    Drupal.behaviors.apiUsers = {
        attach: function(context) {
            // Map company, facility and user fields.
            var fieldsMap = {
                address_1: {
                    branch: '',
                    newBranch: '#edit-branch-address-1',
                    company: '',
                    newCompany: '#edit-company-address-1',
                    user: '#edit-user-address-1'
                },
                address_2: {
                    branch: '',
                    newBranch: '#edit-branch-address-2',
                    company: '',
                    newCompany: '#edit-company-address-2',
                    user: '#edit-user-address-2'
                },
                country: {
                    branch: '',
                    newBranch: '#edit-branch-country',
                    company: '',
                    newCompany: '#edit-company-country',
                    user: '#edit-user-country'
                },
                state: {
                    branch: '',
                    newBranch: '#edit-branch-state',
                    company: '',
                    newCompany: '#edit-company-state',
                    user: '#edit-user-state'
                },
                us_state: {
                    branch: '',
                    newBranch: '#edit-branch-us-state',
                    company: '',
                    newCompany: '#edit-company-us-state',
                    user: '#edit-user-us-state'
                },
                city: {
                    branch: '',
                    newBranch: '#edit-branch-city',
                    company: '',
                    newCompany: '#edit-company-city',
                    user: '#edit-user-city'
                },
                province_region: {
                    branch: '',
                    newBranch: '#edit-branch-province-region',
                    company: '',
                    newCompany: '#edit-company-province-region',
                    user: '#edit-user-province-region'
                },
                zip: {
                    branch: '',
                    newBranch: '#edit-branch-postal-code',
                    company: '',
                    newCompany: '#edit-company-postal-code',
                    user: '#edit-user-postal-code'
                },
                telephone: {
                    branch: '',
                    newBranch: '#edit-branch-primary-telephone',
                    company: '',
                    newCompany: '#edit-company-primary-telephone',
                    user: '#edit-user-primary-telephone'
                }
            };
            var branches, branch = '';
            var create_option = $(':input[name="user-create-option"]').attr('checked');
            if (create_option) {
                $('#edit-branch-select').show();
            } else {
                // Get company info.
                if ($('#edit-user-company').val() != '_none') {
                    get_company_info($('#edit-user-company').val());
                    // Get company branches.
                    var dataString = "nid=" + $('#edit-user-company').val();
                    $.ajax({
                        type: "POST",
                        url: Drupal.settings.basePath + "api/api/getCompanyBranches",
                        data: dataString,
                        dataType: "json",
                        success: function(msg) {
                            branches = msg;
                            var selected_facility = $('#edit-user-branch').val();
                            if ($('#edit-user-company').val() != "_none") {
                                // The only time the register form has facilities options is
                                // when using a preloaded register form (coming from company admin users list.)
                                var $el = $('#edit-user-branch');
                                $el.html(' ');
                                $el.append($("<option></option>").attr("value", '_none').text(Drupal.t('Facility not found (Not applicable)')));
                                $.each(branches, function(key, value) {
                                    $el.append($("<option></option>").attr("value", value.nid).text(value.name));
                                });
                                $el.trigger("chosen:updated");
                            }
                            // Get facility info
                            if (selected_facility != "_none") {
                                get_facility_info(selected_facility);
                                $('.form-item-user-branch-create-option').hide();
                                $('#edit-user-branch').val(selected_facility);
                                $('#edit-user-branch').trigger("chosen:updated");
                            } else {
                                $('.form-item-user-branch-create-option').show();
                            }
                        }
                    });
                }
            }
            var password_textfield = $('#edit-user-show-password').attr('checked');
            if (password_textfield) {
                $new = $('#edit-pass-pass1').clone();
                $new.attr('type', 'text');
                $('#edit-pass-pass1').replaceWith($new);
                $new = $('#edit-pass-pass2').clone();
                $new.attr('type', 'text');
                $('#edit-pass-pass2').replaceWith($new);
            }
            // init chosen fields.
            $("#edit-user-company").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-user-branch").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-company-country").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-company-us-state").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-branch-country").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-branch-us-state").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-user-country").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-user-us-state").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-company-work-types").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-company-countries-operation").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            $("#edit-company-state-provinces").chosen({
                disable_search_threshold: 2,
                width: "400px"
            });
            // hide Register title
            $('#user_register_form h1').hide();
            // if use hq info is checked, disable facility fields.
            if ($('#edit-branch-use-company-hq-info').is(':checked')) {
                $.each(fieldsMap, function(key, value) {
                    $(value.newBranch).attr('disabled', true);
                });
                $('#edit-branch-country').trigger('chosen:updated');
                $('#edit-branch-us-state').trigger('chosen:updated');
            }
            // handle company selection.
            $('#edit-user-company').change(function() {
                // Clean form info.
                $('#edit-user-create-option-create-a-new-company').attr('checked', false).change();
                $('#edit-user-branch-create-option-create-a-new-facility').attr('checked', false).change();
                $('.company-details .company-info').html('');
                var $el = $('#edit-user-branch');
                $el.html(' ');
                $el.append($("<option></option>").attr("value", '_none').text(Drupal.t('Facility not found (Not applicable)')));
                $('.branch-details .branch-info').html('');
                branches = '';
                branch = '';
                // Show loading icon.
                $('.company-details .company-info').html('<div class="ajax-progress ajax-progress-throbber"><div class="throbber">&nbsp;</div></div>');
                // Is an existing company?
                if ($(this).val() != '_none') {
                    // Show facility selection field.
                    $('#edit-branch-select').show();
                    var nid = $(this).val();
                    // Get company info.
                    get_company_info(nid);
                    // Get company branches.
                    var dataString = "nid=" + nid;
                    $.ajax({
                        type: "POST",
                        url: Drupal.settings.basePath + "api/api/getCompanyBranches",
                        data: dataString,
                        dataType: "json",
                        success: function(msg) {
                            branches = msg;
                            // Change branch select options
                            var $el = $('#edit-user-branch');
                            $el.html(' ');
                            $el.append($("<option></option>").attr("value", '_none').text(Drupal.t('Facility not found (Not applicable)')));
                            $.each(branches, function(key, value) {
                                $el.append($("<option></option>").attr("value", value.nid).text(value.name));
                            });
                            $el.trigger("chosen:updated");
                        }
                    });
                } else {
                    $('.company-details .company-info').html('');
                    var $el = $('#edit-user-branch');
                    $el.html(' ');
                    $el.append($("<option></option>").attr("value", '_none').text(Drupal.t('Facility not found (Not applicable)')));
                    $el.trigger("chosen:updated");
                    $('.branch-details .branch-info').html('');
                    branches = '';
                    branch = '';
                }
            });
            // handle facility selection.
            $('#edit-user-branch').change(function() {
                $('#edit-user-branch-create-option-create-a-new-facility').attr('checked', false).change();
                if ($(this).val() != '_none') {
                    $('.form-item-user-branch-create-option').hide();
                    $('.form-item-branch-state').hide();
                } else {
                    $('.form-item-user-branch-create-option').show();
                    if ($('#edit-branch-country').val() == 'US') {
                        $('.form-item-branch-state').hide();
                    }
                }
                if (typeof(branches[$(this).val()]) != "undefined") {
                    get_facility_info($(this).val());
                } else {
                    $('.branch-details .branch-info').html('');
                }
            });
            $('#edit-user-branch-create-option-create-a-new-facility').click(function() {
                if ($('#edit-branch-country').val() == 'US') {
                    $('.form-item-branch-state').hide();
                } else {
                    $('.form-item-branch-state').show();
                }
            });
            $('#edit-user-create-option-create-a-new-company').click(function() {
                if ($(this).is(':checked')) {
                    $(':input[name="user-branch-create-option"]').attr('checked', true).change();
                }
            });
            // use company info in facility's address fields
            $('#edit-branch-use-company-hq-info').click(function() {
                if ($(this).is(':checked')) {
                    $.each(fieldsMap, function(key, value) {
                        if ($('#edit-user-company').val() != '_none') {
                            // try to use selected company info
                            $(value.newBranch).val(value.company).change();
                        } else {
                            // try to use new company info
                            $(value.newBranch).val($(value.newCompany).val()).change();
                        }
                        $(value.newBranch).attr('disabled', true);
                    });
                } else {
                    $.each(fieldsMap, function(key, value) {
                        // Clean facility fields
                        $(value.newBranch).val('').change();
                        $(value.newBranch).attr('disabled', false);
                    });
                }
                $('#edit-branch-country').trigger('chosen:updated');
                $('#edit-branch-us-state').trigger('chosen:updated');
            });
            // use facility info in user's address fields.
            $('#edit-user-use-branch-info').click(function() {
                if ($(this).is(':checked')) {
                    $.each(fieldsMap, function(key, value) {
                        if ($('#edit-user-branch').val() != '_none') {
                            // try to use selected branch info
                            $(value.user).val(value.branch).change();
                        } else {
                            // try to use new branch info
                            $(value.user).val($(value.newBranch).val()).change();
                        }
                    });
                    $('#edit-user-country').trigger('chosen:updated');
                    $('#edit-user-us-state').trigger('chosen:updated');
                }
            });
            $('#edit-user-show-password').click(function() {
                var changeTo = 'password';
                if ($(this).is(':checked')) {
                    changeTo = 'text';
                }
                $new = $('#edit-pass-pass1').clone();
                $new.attr('type', changeTo);
                $('#edit-pass-pass1').replaceWith($new);
                $new = $('#edit-pass-pass2').clone();
                $new.attr('type', changeTo);
                $('#edit-pass-pass2').replaceWith($new);
            });
            // handle form submit.
            $('form', context).submit(function() {
                if ($('#edit-branch-use-company-hq-info').is(':checked')) {
                    // enable facility fields for submit
                    $.each(fieldsMap, function(key, value) {
                        $(value.newBranch).attr('disabled', false);
                    });
                    $('#edit-branch-country').trigger('chosen:updated');
                    $('#edit-branch-us-state').trigger('chosen:updated');
                }
            });

            function get_company_info(nid) {
                $.ajax({
                    type: "GET",
                    url: Drupal.settings.basePath + "api/node/" + nid + ".json",
                    dataType: "json",
                    success: function(msg) {
                        fieldsMap.address_1.company, fieldsMap.address_2.company, fieldsMap.country.company, fieldsMap.state.company, fieldsMap.us_state.company, fieldsMap.city.company, fieldsMap.zip.company, fieldsMap.telephone.company = '';
                        fieldsMap.address_1.company = msg.field_address.und[0].thoroughfare;
                        if (typeof(msg.field_address.und[0].premise) != "undefined" && msg.field_address.und[0].premise != null) {
                            fieldsMap.address_2.company = msg.field_address.und[0].premise;
                        } else {
                            fieldsMap.address_2.company = '';
                        }
                        if (typeof(msg.field_address.und[0].country) != "undefined" && msg.field_address.und[0].country != null) {
                            fieldsMap.country.company = msg.field_address.und[0].country;
                        } else {
                            fieldsMap.country.company = '';
                        }
                        if (typeof(msg.field_address.und[0].administrative_area) != "undefined" && msg.field_address.und[0].administrative_area != null) {
                            fieldsMap.state.company = msg.field_address.und[0].administrative_area;
                            fieldsMap.us_state.company = msg.field_address.und[0].administrative_area;
                        } else {
                            fieldsMap.state.company = '';
                            fieldsMap.us_state.company = '';
                        }
                        if (typeof(msg.field_address.und[0].locality) != "undefined" && msg.field_address.und[0].locality != null) {
                            fieldsMap.city.company = msg.field_address.und[0].locality;
                        } else {
                            fieldsMap.city.company = '';
                        }
                        if (typeof(msg.field_address.und[0].province_region) != "undefined") {
                            fieldsMap.province_region.company = msg.field_address.und[0].province_region;
                        } else {
                            fieldsMap.province_region.company = '';
                        }
                        if (typeof(msg.field_address.und[0].postal_code) != "undefined" && msg.field_address.und[0].postal_code != null) {
                            fieldsMap.zip.company = msg.field_address.und[0].postal_code;
                        } else {
                            fieldsMap.zip.company = '';
                        }
                        var country_name = '';
                        if (typeof(msg.field_address.und[0].country_name) != "undefined" && msg.field_address.und[0].country_name != null) {
                            country_name = msg.field_address.und[0].country_name;
                        }
                        var administrative_area_name = '';
                        if (typeof(msg.field_address.und[0].administrative_area_name) != "undefined" && msg.field_address.und[0].administrative_area_name != null) {
                            administrative_area_name = msg.field_address.und[0].administrative_area_name;
                        }

                        var types_of_work = '';
                        if (typeof(msg.field_types_of_work.und) != "undefined") {
                          $.each(msg.field_types_of_work.und, function(key, value) {
                            if (value.name != null) {
                              types_of_work += '<span>' + Drupal.t(value.name) + '<br/></span>';
                            }
                          });
                        }
                        var us_states = '';
                        if (typeof(msg.field_us_states.und) != "undefined") {
                          $.each(msg.field_us_states.und, function(key, value) {
                            if (value.name != null) {
                              us_states += '<span>' + Drupal.t(value.name) + '<br/></span>';
                            }
                          });
                        }
                        // Countries of Operation
                        var countries_operate = '';
                        if (typeof(msg.field_country.und) != "undefined") {
                          $.each(msg.field_country.und, function(key, value) {
                            if (value.name != null) {
                              countries_operate += '<span>' + Drupal.t(value.name) + '<br/></span>';
                            }
                          });
                        }

                        var company_info = '<div class="data-information">';
                        company_info += '<div><label>' + Drupal.t('Address 1') + '</label><span>' + fieldsMap.address_1.company + "</span></div>";
                        company_info += '<div><label>' + Drupal.t('Address 2') + '</label><span>' + fieldsMap.address_2.company + "</span></div>";
                        company_info += '<div><label>' + Drupal.t('Country') + '</label><span>' + country_name + "</span></div>";
                        company_info += '<div><label>' + Drupal.t('City') + '</label><span>' + fieldsMap.city.company + "</span></div>";
                        if (fieldsMap.country.company == 'US') {
                            company_info += '<div><label>' + Drupal.t('State') + '</label><span>' + administrative_area_name + "</span></div>";
                        }
                        company_info += '<div><label>' + Drupal.t('Province / Region') + '</label><span>' + fieldsMap.province_region.company + "</span></div>";
                        company_info += '<div><label>' + Drupal.t('ZIP / Postal Code') + '</label><span>' + fieldsMap.zip.company + "</span></div>";
                        if (typeof(msg.field_tel.und) != "undefined") {
                            fieldsMap.telephone.company = msg.field_tel.und[0].value;
                            company_info += '<div><label>' + Drupal.t('Primary Telephone') + '</label><span>' + fieldsMap.telephone.company + "</span></div>";
                        }
                        if (types_of_work != '') {
                          company_info += '<div><label>' + Drupal.t('Work Types') + '</label><div>' + types_of_work + "</div></div>";
                        }
                        if (countries_operate != '') {
                          company_info += '<div><label>' + Drupal.t('Countries of Operation') + '</label><div>' + countries_operate + "</div></div>";
                        }
                        if (us_states != '') {
                          company_info += '<div><label>' + Drupal.t('State / Provinces') + '</label><div>' + us_states + "</div></div>";
                        }
                        company_info += '</div>';

                        $('.company-details .company-info').html(company_info);
                    }
                });
            }

            function get_facility_info(nid) {
                branch = branches[nid];
                fieldsMap.address_1.branch, fieldsMap.address_2.branch, fieldsMap.country.branch, fieldsMap.state.branch, fieldsMap.us_state.branch, fieldsMap.city.branch, fieldsMap.zip.branch, fieldsMap.telephone.branch = '';
                fieldsMap.address_1.branch = branch.address_1;
                fieldsMap.address_2.branch = branch.address_2;
                fieldsMap.country.branch = branch.country;
                fieldsMap.state.branch = branch.state;
                fieldsMap.us_state.branch = branch.state;
                fieldsMap.city.branch = branch.city;
                fieldsMap.province_region.branch = branch.province_region;
                fieldsMap.zip.branch = branch.zip;
                var branch_info = '<div class="data-information">';
                branch_info += '<div><label>' + Drupal.t('Address 1') + '</label><span>' + fieldsMap.address_1.branch + "</span></div>";
                branch_info += '<div><label>' + Drupal.t('Address 2') + '</label><span>' + fieldsMap.address_2.branch + "</span></div>";
                branch_info += '<div><label>' + Drupal.t('Country') + '</label><span>' + branch.country_name + "</span></div>";
                branch_info += '<div><label>' + Drupal.t('City') + '</label><span>' + fieldsMap.city.branch + "</span></div>";
                if (fieldsMap.country.branch == 'US') {
                    branch_info += '<div><label>' + Drupal.t('State') + '</label><span>' + branch.state_name + "</span></div>";
                }
                branch_info += '<div><label>' + Drupal.t('Province / Region') + '</label><span>' + fieldsMap.province_region.branch + "</span></div>";
                branch_info += '<div><label>' + Drupal.t('ZIP / Postal Code') + '</label><span>' + fieldsMap.zip.branch + "</span></div>";
                if (typeof(branch.tel) != "undefined") {
                    fieldsMap.telephone.branch = branch.tel;
                    branch_info += '<div><label>' + Drupal.t('Primary Telephone') + '</label><span>' + fieldsMap.telephone.branch + "</span></div>";
                }
                branch_info += '</div>';
                $('.branch-details .branch-info').html(branch_info);
            }
        }
    };
})(jQuery);
