<div style="width:660px; height:195px; border: 1px dashed #000;font-family: Verdana, Helvetica, sans-serif;
    <?php print $certificate_info['background_image_style']; ?>" class="safety-key">

    <!-- FRONT SIDE -->
    <div style="width: 310px; height:195px; float:left; border-right: 1px dashed #000; box-sizing: border-box; padding:10px 10px 0px 10px;">
        <div style="font-size: 11px; font-weight: 700;color: #cc0000; text-align: center;
            display:inline-block; margin-left: 10px;width: 300px; height: 24px">
            <span><?php print t('Certificate ID: %number', array('%number' => $key->number)); ?></span>
        </div>
        <div style="font-size: 12px; font-weight: 700; height: 125px; text-align: center; margin-top: 15px; padding: 0 30px;">
            <div>
                <?php print t($certificate_info['front_text_1']); ?>
            </div>
            <div style="font-weight: 100; margin-top: 5px">
                <?php print $first_name . ' ' . $last_name; ?>
            </div>
            <div style="border-bottom: 1px solid #000"></div>
            <div style="margin-top: 5px">
                <?php print t($certificate_info['front_text_2']); ?>
            </div>
            <div style="font-weight: 100; margin-top: 5px">
                <?php print $program_name; ?>
            </div>
            <div style="font-weight: 100; margin-top: 5px"><?php print $issue_date; ?></div>
            <div style="border-bottom: 1px solid #000"></div>
            <div><?php print t('Date of Training'); ?></div>
        </div>
    </div>

    <!-- BACK SIDE -->
    <div style="width: 315px; float:left;">
        <div style="padding: 10px;">
            <div style="font-size: 12px; font-weight: 700; text-align: center;">
                <?php print t($certificate_info['back_title']); ?>
            </div>
            <p style="font-size: 8px; margin: 3px 0 5px 0;">
                <?php print t($certificate_info['certificate_text']); ?></p>
            <div style="font-size: 9px; height: 75px; padding-top: 5px;">
                <div style="width: 45%; float: left; padding-right: 10px; box-sizing: border-box;">
                    <div style="height:45px">
                    <?php if(!empty($certificate_info['printed_name_text'])) : ?>
                        <div style="margin-top: 15px;overflow: hidden;text-overflow: ellipsis;white-space: nowrap;"></div>
                        <div style="border-bottom: 1px solid #000"></div>
                        <div><?php print t($certificate_info['printed_name_text']); ?></div>
                    <?php endif; ?>
                    </div>
                    <?php if(!empty($certificate_info['signature_text'])) : ?>
                        <div style="margin-bottom: 20px;overflow: hidden;text-overflow: ellipsis;white-space: nowrap;"></div>
                        <div style="border-bottom: 1px solid #000"></div>
                        <div><?php print t($certificate_info['signature_text']); ?></div>
                    <?php endif; ?>
                </div>
                <div style="width: 45%; float: right; padding-left: 10px; box-sizing: border-box;">
                    <div style="margin-top: 15px;overflow: hidden;text-overflow: ellipsis;white-space: nowrap;"></div>
                    <div style="border-bottom: 1px solid #000"></div>
                    <div><?php print t('Date'); ?></div>
                    <div style="margin-top: 18px;border-bottom: 1px solid #000"></div>
                    <div style="margin-top: 18px;border-bottom: 1px solid #000"></div>
                    <div><?php print t('Print facility Name/Address'); ?></div>
                </div>
            </div>
        </div>
    </div>
</div>
