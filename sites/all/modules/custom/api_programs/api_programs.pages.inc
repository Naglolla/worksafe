<?php
/**
 * Menu callback.
 */
function api_programs_buy_page($program) {
	if ($program->type != PRODUCT_DISPLAY_CONTENT_TYPE) {
		drupal_not_found();
	}

	drupal_set_title($program->title);

	$courses = api_moodle_get_program($program->nid);

	$courses_options = array();
	$full_course = array();
	$all_modules = array();
	$exam = array();
	$recommended = array();
	foreach ($courses->products as $product) {
		switch ($product->type) {
			case MOODLE_COURSE_TYPE_FULL_COURSE:
				$full_course[$product->product_id] = $product->title . '<div class="product-price product-' . $product->product_id . '">' . $product->price['amount'] . '</div>';
				break;
			case MOODLE_COURSE_TYPE_ALL_MODULES:
				$all_modules[$product->product_id] = $product->title . '<div class="product-price product-' . $product->product_id . '">' . $product->price['amount'] . '</div>';
				break;
			case MOODLE_COURSE_TYPE_FINAL_EXAM:
				$exam[$product->product_id] = $product->title . '<div class="product-price product-' . $product->product_id . '">' . $product->price['amount'] . '</div>';
				break;
			case MOODLE_COURSE_TYPE_RECOMMENDED:
				$recommended[$product->product_id] = $product->title . '<div class="product-price product-' . $product->product_id . '">' . $product->price['amount'] . '</div>';
				break;
			default:
				$courses_options[$product->product_id] = $product->title . '<div class="product-price product-' . $product->product_id . '">' . $product->price['amount'] . '</div>';
				break;
		}
	}
	// Order options.
	if (!empty($all_modules)) {
		$courses_options = $all_modules + $courses_options;
	}
	if (!empty($full_course)) {
		$courses_options = $full_course + $courses_options;
	}

	if (!empty($exam)) {
		$courses_options += $exam;
	}
	if (!empty($recommended)) {
		$courses_options += $recommended;
	}
	// Get program description
	$description = _api_custom_field_item('node', $program, 'body') . '<br/>';
	$description .= _api_custom_field_item('node', $program, 'field_long_description');

	$apply_rules = _api_custom_field_item('node', $program, 'field_apply_rules');

	if (!$apply_rules) {
		drupal_add_js(array(
		 'api_programs' => array('courses' => $courses->modules)),
		 'setting'
		 );
		$program_form = drupal_get_form('api_programs_buy_program_form', $program->nid, $courses_options);
	} else {
		// Apply states and operator types rules.
		$states = api_programs_get_program_states($program);
		$program_form = drupal_get_form('api_programs_buy_form', $program->nid, $states, $courses_options);
	}

	$image_uri = _api_custom_get_field_image('node', $program, 'field_program_image');

	$number_of_modules = _api_custom_field_item('node', $program, 'field_number_of_modules');
	$completion_time = _api_custom_field_item('node', $program, 'field_completation_time');
	$price_range = _api_custom_field_item('node', $program, 'field_price_range');
	$handbook_uri = file_create_url(_api_custom_field_item('node', $program, 'field_handbook', 'uri'));
	$handbook_filesize = _api_custom_field_item('node', $program, 'field_handbook', 'filesize');
	$handbook_filesize = ceil($handbook_filesize/1024/1024);
	return theme('api_programs_program_description', array(
      'title'        => $program->title,
      'description'  => $description,
      'image'        => $image_uri,
	  'number_of_modules' => $number_of_modules,
	  'completion_time' => $completion_time,
	  'price_range' => $price_range,
	  'handbook_uri' => $handbook_uri,
	  'handbook_filesize' => $handbook_filesize,
      'program_form' => $program_form,
    ));
}

/**
 * Program form.
 */
function api_programs_buy_program_form($form, &$form_state, $program_nid, $courses_options) {
	$form['#attached']['js'] = array(
	  drupal_get_path('module', 'api_programs') . '/js/api_programs_buy_form.js' => array(
	  'type' => 'file',
	  ),
	);
	$form['#attached']['css'] = array(
	  drupal_get_path('module', 'api_programs') . '/css/api_programs.css' => array(
	  'type' => 'file',
	  ),
	);
	$form['program_nid'] = array(
		'#type' => 'hidden',
		'#value' => $program_nid,
	);
	// Courses list.
	$form['courses'] = array(
		'#type' => 'checkboxes',
		'#options' => $courses_options,
		'#title' => t('Choose your training materials.'),
	    '#states' => array(
	      'invisible' => array(
	        '#edit-state' => array('value' => '')
	      )
	    )
	);

	// Total amount.
	$form['total'] = array(
		'#type' => 'markup',
		'#markup' => '<div class="total">Total(USD)<div class="amount"></div></div>'
	);
	$form['add-to-cart'] = array(
		'#type' => 'submit',
		'#value' => t('Add to cart'),
	);
	$form['#submit'][] = 'api_programs_buy_form_submit';
 	return $form;
}

/**
 * Program form.
 */
function api_programs_buy_form($form, &$form_state, $program_nid, $states, $courses_options) {
	$form['#attached']['js'] = array(
	  drupal_get_path('module', 'api_programs') . '/js/api_programs.js' => array(
	  'type' => 'file',
	  ),
	);
	$form['#attached']['css'] = array(
	  drupal_get_path('module', 'api_programs') . '/css/api_programs.css' => array(
	  'type' => 'file',
	  ),
	);
	$form['program_nid'] = array(
		'#type' => 'hidden',
		'#value' => $program_nid,
	);

	$state_options = array('' => t('--Choose State--'));
	$state_options = array_merge($state_options, $states);

	$form['state'] = array(
		'#type' => 'select',
		'#title' => t('Choose your state.'),
		'#options' => $state_options,
	);
	$form['operator_type'] = array(
		'#type' => 'select',
		'#title' => t('Choose your class.'),
		'#validated' => TRUE,
		'#options' => array('' => '-Select-'),
	    '#states' => array(
	      'invisible' => array(
	        '#edit-state' => array('value' => '')
	      )
	    )
	);

	// Regulatory questions
	$regulatory_questions_options = array(
		'Yes' => 'Yes',
		'No' => 'No',
		'Don\'t Know' => 'Don\'t Know',
	);

	$form['regulatory_questions'] = array(
		'#type' => 'fieldset'
	);
	$form['regulatory_questions']['question_1'] = array(
		'#type' => 'select',
		'#title' => t('Are you a single-site owner or operator?'),
		'#options' => $regulatory_questions_options,
	);
	$form['regulatory_questions']['question_2'] = array(
		'#type' => 'select',
		'#title' => t('Do you use inventory reconciliation or SIR as a method of release detection?'),
		'#options' => $regulatory_questions_options,
	);
	$form['regulatory_questions']['question_3'] = array(
		'#type' => 'select',
		'#title' => t('Is your facility equipped with an automatic tank gauge?'),
		'#options' => $regulatory_questions_options,
	);
	$form['regulatory_questions']['question_4'] = array(
		'#type' => 'select',
		'#title' => t('Does your leak detection system have sensors?'),
		'#options' => $regulatory_questions_options,
	);
	$form['regulatory_questions']['question_5'] = array(
		'#type' => 'select',
		'#title' => t('Do you have secondary containment on your sumps and beneath your dispensers?'),
		'#options' => $regulatory_questions_options,
	);
	$form['regulatory_questions']['question_6'] = array(
		'#type' => 'select',
		'#title' => t('Do you have hazardous substance storage tanks?'),
		'#options' => $regulatory_questions_options,
	);
	$form['regulatory_questions']['question_7'] = array(
		'#type' => 'select',
		'#title' => t('Does your facilty have steel components, including tanks or piping?'),
		'#options' => $regulatory_questions_options,
	);

	// Courses list.
	$form['courses'] = array(
		'#type' => 'checkboxes',
		'#options' => $courses_options,
		'#title' => t('Choose your training materials.'),
	    '#states' => array(
	      'invisible' => array(
	        '#edit-state' => array('value' => '')
	      )
	    )
	);

	// Total amount.
	$form['total'] = array(
		'#type' => 'markup',
		'#markup' => '<div class="total">Total(USD)<div class="amount"></div></div>'
	);
	$form['add-to-cart'] = array(
		'#type' => 'submit',
		'#value' => t('Add to cart'),
	);

	return $form;

}

/**
 * Submit callback.
 */
function api_programs_buy_form_submit($form, &$form_state) {
	global $user;

	$values = &$form_state['values'];

	$operator_type = $values['operator_type'];
	// We do this beacuse an issue with javascript.
	if ($operator_type == 'AB') {
		$operator_type = 'A+B';
	}

	$exam = NULL;
	$full_course = NULL;
	$all_modules = NULL;
	$recommended = NULL;
	$products = array();
	foreach ($values['courses'] as $key => $product_id) {
		if (!empty($product_id)) {
			$product = commerce_product_load($product_id);
			$course_type = _api_custom_field_item('commerce_product', $product, 'field_course_type');
			switch ($course_type) {
				case MOODLE_COURSE_TYPE_FINAL_EXAM:
					$exam = $product;
					break;
				case MOODLE_COURSE_TYPE_FULL_COURSE:
					$full_course = $product;
					break;
				case MOODLE_COURSE_TYPE_ALL_MODULES:
					$all_modules = $product;
					break;
				case MOODLE_COURSE_TYPE_RECOMMENDED:
					$recommended = $product;
					break;
				case MOODLE_COURSE_TYPE_TRAINING:
					$products[$product_id] = $product;
					break;
			}
		}
	}

	// Do we have something to add to shopping cart?
	if (!empty($exam) ||
		!empty($full_course) ||
		!empty($all_modules) ||
		!empty($recommended) ||
		!empty($products)) {

		// Create the new order in checkout; we might also check first to
		// see if our user already has an order to use instead of a new one.
		$order = commerce_cart_order_load($user->uid);
		if (empty($order)) {
			$order = commerce_order_new($user->uid, 'checkout_checkout');

			// Save the order to get its ID.
			commerce_order_save($order);
			// Link anonymous user session to the cart
			if (!$user->uid) {
			    commerce_cart_order_session_save($order->order_id);
			}
		}

		// Save regulatory questions?
		$state = $values['state'];
		$program_rules = api_program_rules_definition();
		if (!empty($program_rules[$state]['types'][$operator_type]['regulatory_questions']) && $program_rules[$state]['types'][$operator_type]['regulatory_questions']) {

		    $regulatory_questions = entity_create(REGULATORY_QUESTIONS_ENTITY, array('type' => REGULATORY_QUESTIONS_ENTITY));
		    $regulatory_questions->created = time();
		    $regulatory_questions->uid = $user->uid;

		    // Operator type
		    $regulatory_questions->field_operator_type = array(LANGUAGE_NONE => array(0 => array('value' => $operator_type)));
		    // US state
		    $regulatory_questions->field_state = array(LANGUAGE_NONE => array(0 => array('value' => $state)));
		    // Program reference field
		    $regulatory_questions->field_program = array(LANGUAGE_NONE => array(0 => array('target_id' => $values['program_nid'])));
		    // Order reference field
		    $regulatory_questions->field_order = array(LANGUAGE_NONE => array(0 => array('target_id' => $order->order_id)));

			$regulatory_questions->field_question_1 = array(LANGUAGE_NONE => array(0 => array('value' => $values['question_1'])));
			$regulatory_questions->field_question_2 = array(LANGUAGE_NONE => array(0 => array('value' => $values['question_2'])));
			$regulatory_questions->field_question_3 = array(LANGUAGE_NONE => array(0 => array('value' => $values['question_3'])));
			$regulatory_questions->field_question_4 = array(LANGUAGE_NONE => array(0 => array('value' => $values['question_4'])));
			$regulatory_questions->field_question_5 = array(LANGUAGE_NONE => array(0 => array('value' => $values['question_5'])));
			$regulatory_questions->field_question_6 = array(LANGUAGE_NONE => array(0 => array('value' => $values['question_6'])));
			$regulatory_questions->field_question_7 = array(LANGUAGE_NONE => array(0 => array('value' => $values['question_7'])));

		    entity_save(REGULATORY_QUESTIONS_ENTITY, $regulatory_questions);
		}


		// Data to add in the line item.
		$data = array(
			'field_order_product_state' => $values['state'],
			'field_order_product_type' => $operator_type,
			'program_nid' => $values['program_nid'],
			'context' => array(
				'entity' => array(
					'entity_type' => 'node',
					'entity_id' => $values['program_nid'],
					'product_reference_field_name' => 'field_product',
				),
			),
		);

		if (!empty($full_course)) {
			// only add this product to shopping cart.
			api_programs_add_product_line_item_to_cart($full_course, 1, $order, $data);
		}
		if (!empty($all_modules) && empty($full_course)) {
			// only add this product to shopping cart.
			api_programs_add_product_line_item_to_cart($all_modules, 1, $order, $data);
		}
		if (!empty($recommended)) {
			api_programs_add_product_line_item_to_cart($recommended, 1, $order, $data);
		}
		if (empty($full_course) && !empty($exam)) {
			api_programs_add_product_line_item_to_cart($exam, 1, $order, $data);
		}
		if (empty($all_modules) && empty($full_course) && !empty($products)) {
			foreach ($products as $product_id => $product) {
				api_programs_add_product_line_item_to_cart($product, 1, $order, $data);
			}
		}

		$form_state['redirect'] = 'cart';
	}

}

/**
 * Add a product line item to an order.
 */
function api_programs_add_product_line_item_to_cart($product, $quantity = 1, $order, $data) {
	// Create a line item.
	$line_item = commerce_product_line_item_new($product, $quantity, $order->order_id, $data);

	$line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);
    $line_item_wrapper->field_order_product_state = $data['field_order_product_state'];
    $line_item_wrapper->field_order_product_type = $data['field_order_product_type'];

	// Save the line item to get its ID.
	commerce_line_item_save($line_item);

	// Add the line item to the order.
	$order_wrapper = entity_metadata_wrapper('commerce_order', $order);
	$order_wrapper->commerce_line_items[] = $line_item;

	// Save the order again to update its line item reference field.
	commerce_order_save($order);
}
