<div class="my-courses-block">
  <?php if (!empty($purchases)): ?>
    <?php foreach ($purchases as $purchase): ?>
      <?php
            if ($purchase->type == 'course' && $purchase->status == COURSE_STATUS_SAFETY_KEY_RECEIVED){
              continue;
            } else if ($purchase->type == 'token' && $purchase->amount <= 0){
              continue;
            }
      ?>
      <div class="course">
          <div class="description" >
            <?php
              if ($purchase->type == 'course'){
                $course_description = $purchase->program_name;
                if ($purchase->state != 'NA') {
                  $course_description .= ': ' . t($purchase->program_state_description);
                }
                if ($purchase->operator_type != 'NA') {
                  $course_description .= ', ' . t('Class') . ' ' . $purchase->operator_type;
                }
                print l($course_description, "course/$purchase->uid/$purchase->id/$purchase->state/$purchase->operator_type");
              } else if ($purchase->type == 'token'){
                $token_description = t('Token @token_code', array('@token_code' => $purchase->code));
                print l($token_description, "token_entity/token_entity_bundle/$purchase->token_id");
              }
            ?>
          </div>
          <div class="state <?php echo $purchase->status; ?>" >
            <?php
              if ($purchase->type == 'course'){
                print t($purchase->status_description);
              } else if ($purchase->type == 'token'){
                print t('Balance') . ': ' . commerce_currency_format($purchase->amount,commerce_default_currency(),NULL,FALSE);
              }
            ?>
          </div>
      </div>
    <?php endforeach; ?>
    <div class="view-all-link">
      <?php echo l(t('View all'), $view_all_link, array('fragment' => 'edit-purchases')); ?>
    </div>
  <?php else: ?>
    <span class="message"><?php echo t('No courses available.'); ?></span>
  <?php endif; ?>
</div>
