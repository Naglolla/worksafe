<?php

$THEME->name = 'worksafe';
$THEME->doctype = 'html5';
$THEME->parents = array('bootstrapbase');
$THEME->sheets = array('custom','iframe');
$THEME->supportscssoptimisation = false;
$THEME->yuicssmodules = array();
$THEME->enable_dock = true;
$THEME->editor_sheets = array();

$THEME->rendererfactory = 'theme_overridden_renderer_factory';
$THEME->csspostprocess = 'theme_worksafe_process_css';

$THEME->blockrtlmanipulations = array(
    'side-pre' => 'side-post',
    'side-post' => 'side-pre'
);

$THEME->layouts = array(
    'incourse' => array(
        'file' => 'selector.php',
        'regions' => array('side-pre', 'side-post'),
        'defaultregion' => 'side-pre'
    )
);

$THEME->javascripts[] = 'iframedetector';