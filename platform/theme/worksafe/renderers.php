<?php

// Include all PHP files in the pdf_renderers directory.
foreach(glob(__DIR__ . '/renderers/*.php') as $renderer) {
    include_once($renderer);
}
