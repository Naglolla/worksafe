 <?php

/**
 * @file
 * API Mail template.
 *
 * Variables available:
 * - $arguments: Array.
 *
 */
 ?>

<!DOCTYPE html>
<html>
  <body>
    <table width="90%" style="max-width: 600px; margin: auto;">
      <tr>
        <td width="70%">
          <a href="<?php print $base_url; ?>">
            <img src="<?php print $logo_icon_path; ?>" alt="API WorkSafe">
          </a>
        </td>
        <?php if($show_cart): ?>
          <td width="30%" style="text-align:right">
            <img src="<?php print $cart_icon_path; ?>" alt="Cart">
          </td>
        <?php endif; ?>
      </tr>
      <tr>
        <td colspan="2" style="text-align:center">
          <h1 style="font-family:'Segoe UI Light',Helvetica,Arial,sans-serif; color:#f60; font-size:90px; text-transform:uppercase; letter-spacing:1px;">
            <?php print $header_title; ?>
          </h1>
        </td>
      </tr>
      <tr>
        <td colspan="2" style="font-family:'Segoe UI Light',Helvetica, sans-serif; color: #666; font-size:18px">
          <?php print $content; ?>
        </td>
      </tr>
    </table>
  </body>
</html>
