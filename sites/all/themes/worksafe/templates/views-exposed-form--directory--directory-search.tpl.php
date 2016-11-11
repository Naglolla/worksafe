<div class="views-exposed-form">
  <div class="views-exposed-widgets clearfix">
    <div class="column-1">
      <h2><?php print t('State & Work Type'); ?></h2>
      <div id="edit-field-address-country-wrapper" class="views-exposed-widget views-widget-filter-field_address_country">
        <label for="edit-field-address-country"><?php print t('Country'); ?></label>
        <?php print render($form['field_address_country']); ?>
      </div>
      <div id="edit-field-address-administrative-area-wrapper" class="views-exposed-widget views-widget-filter-field_address_administrative_area">
        <label for="edit-field-address-administrative-area"><?php print t('States'); ?></label>
        <?php print render($form['field_address_administrative_area']); ?>
      </div>
      <div id="edit-field-address-data-wrapper" class="views-exposed-widget views-widget-filter-field_address_data">
        <label for="edit-field-address-data"><?php print t('Province / Region'); ?></label>
        <?php print render($form['field_address_data']); ?>
      </div>
      <div id="edit-field-types-of-work-value-wrapper" class="views-exposed-widget views-widget-filter-field_types_of_work_value">
        <label for="edit-field-types-of-work-value"><?php print t('Work Types'); ?></label>
        <?php print render($form['field_types_of_work_value']); ?>
      </div>
      <div class="views-exposed-widget views-submit-button submit-state">
        <?php print render($form['submit']); ?>
      </div>
    </div>
    <div class="column-2">
      <h2><?php print t('Company'); ?></h2>
      <div id="edit-title-wrapper" class="views-exposed-widget views-widget-filter-title">
        <label for="edit-title"><?php print t('Company Name'); ?></label>
        <?php print render($form['title']); ?>
      </div>
      <div class="views-exposed-widget views-submit-button submit-company">
        <?php print render($form['submit']); ?>
      </div>
    </div>
  </div>
</div>
