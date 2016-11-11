<?php

defined('MOODLE_INTERNAL') || die;

if ($ADMIN->fulltree) {

    // Invert Navbar to dark background.
    $name = 'theme_worksafe/invert';
    $title = get_string('invert', 'theme_worksafe');
    $description = get_string('invertdesc', 'theme_worksafe');
    $setting = new admin_setting_configcheckbox($name, $title, $description, 0);
    $setting->set_updatedcallback('theme_reset_all_caches');
    $settings->add($setting);

    // Logo file setting.
    $name = 'theme_worksafe/logo';
    $title = get_string('logo','theme_worksafe');
    $description = get_string('logodesc', 'theme_worksafe');
    $setting = new admin_setting_configstoredfile($name, $title, $description, 'logo');
    $setting->set_updatedcallback('theme_reset_all_caches');
    $settings->add($setting);

    // Custom CSS file.
    $name = 'theme_worksafe/customcss';
    $title = get_string('customcss', 'theme_worksafe');
    $description = get_string('customcssdesc', 'theme_worksafe');
    $default = '';
    $setting = new admin_setting_configtextarea($name, $title, $description, $default);
    $setting->set_updatedcallback('theme_reset_all_caches');
    $settings->add($setting);

    // Footnote setting.
    $name = 'theme_worksafe/footnote';
    $title = get_string('footnote', 'theme_worksafe');
    $description = get_string('footnotedesc', 'theme_worksafe');
    $default = '';
    $setting = new admin_setting_confightmleditor($name, $title, $description, $default);
    $setting->set_updatedcallback('theme_reset_all_caches');
    $settings->add($setting);
}
