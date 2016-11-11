<div class="my-courses-page">
  <?php if (!empty($courses)): ?>
    <?php foreach ($courses as $course): ?>
      <div class="course">
          <div class="description" >
            <?php
            $course_description = $course->description;
            if ($course->state != 'NA') {
              $course_description .= ': ' . t($course->state_description);
            }
            if ($course->operator_type != 'NA') {
              $course_description .= ', ' . t('Class') . ' ' . $course->operator_type;
            }
            echo l($course_description, "course/$course->uid/$course->id/$course->state/$course->operator_type"); ?>
          </div>
          <div class="state <?php echo $course->status; ?>" >
            <?php echo t($course->status_description); ?>
          </div>
      </div>
    <?php endforeach; ?>
  <?php endif; ?>
</div>
