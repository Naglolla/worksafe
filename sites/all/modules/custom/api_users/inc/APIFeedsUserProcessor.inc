<?php

/**
 * @file
 * Contains FeedsUserProcessor.
 */

/**
 * Option to block users not found in the feed.
 *
 * @var string
 */
define('FEEDS_BLOCK_NON_EXISTENT', 'block');

/**
 * Feeds processor plugin. Create users from feed items.
 */
class APIFeedsUserProcessor extends FeedsProcessor {

  private $users_in_use = array();
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'user';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Users');
    return $info;
  }

  /**
   * Creates a new user account in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $account = new stdClass();
    $account->uid = 0;
    $account->roles = array_filter($this->config['roles']);
    $account->status = $this->config['status'];
    return $account;
  }

  /**
   * Loads an existing user.
   */
  protected function entityLoad(FeedsSource $source, $uid) {
    $user = parent::entityLoad($source, $uid);

    // Copy the password so that we can compare it again at save.
    $user->feeds_original_pass = $user->pass;
    return $user;
  }

  /**
   * Validates a user account.
   */
  protected function entityAPIValidate(&$account, $item) {
    if (empty($account->mail) || !valid_email_address($account->mail)) {
      throw new FeedsValidationException(t('User email not valid.'));
    }
    // Set user name
    $first_name = trim($item['first name']);
    $last_name = trim($item['last name']);
    $user_name = $last_name;
    $user_name .= !empty($first_name[0]) ? $first_name[0] : '';
    $user_exists = user_load_by_name($user_name);
    if ($user_exists) {
      $this->users_in_use[] = array('user_name' => $user_name, 'mail' => $account->mail);
      //throw new FeedsValidationException(t('Username already in use.'));
      throw new FeedsValidationException();
    }

    $account->name = $user_name;

    // Validate password policies.
    $password = $item['password'];
    global $user;
    password_policy_user_load(array($user->uid => $user));
    $policies = PasswordPolicy::matched_policies($user);

    $errors = array();
    foreach ($policies as $policy) {
      $errors = $errors + $policy->check($password, $user);
    }
    if (!empty($errors)) {
      throw new FeedsValidationException(t('Password does not meet required strength.'));
    }
  }

  /**
   * Save a user account.
   */
  protected function entitySave($account) {
    if ($this->config['defuse_mail']) {
      $account->mail = $account->mail . '_test';
    }

    $edit = (array) $account;

    // Remove pass from $edit if the password is unchanged.
    if (isset($account->feeds_original_pass) && $account->pass == $account->feeds_original_pass) {
      unset($edit['pass']);
    }

    user_save($account, $edit);
    //_user_mail_notify('register_admin_created', $account);
    if ($account->uid && !empty($account->openid)) {
      $authmap = array(
        'uid' => $account->uid,
        'module' => 'openid',
        'authname' => $account->openid,
      );
      if (SAVED_UPDATED != drupal_write_record('authmap', $authmap, array('uid', 'module'))) {
        drupal_write_record('authmap', $authmap);
      }
    }
  }

  /**
   * Delete multiple user accounts.
   */
  protected function entityDeleteMultiple($uids) {
    user_delete_multiple($uids);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'roles' => array(),
      'status' => 1,
      'defuse_mail' => FALSE,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    $form['status'] = array(
      '#type' => 'radios',
      '#title' => t('Status'),
      '#description' => t('Select whether users should be imported active or blocked.'),
      '#options' => array(0 => t('Blocked'), 1 => t('Active')),
      '#default_value' => $this->config['status'],
    );

    $roles = user_roles(TRUE);
    unset($roles[2]);
    if (count($roles)) {
      $form['roles'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Additional roles'),
        '#description' => t('Every user is assigned the "authenticated user" role. Select additional roles here.'),
        '#default_value' => $this->config['roles'],
        '#options' => $roles,
      );
    }
    $form['defuse_mail'] = array(
      '#type' => 'checkbox',
      '#title' => t('Defuse e-mail addresses'),
      '#description' => t('This appends _test to all imported e-mail addresses to ensure they cannot be used as recipients.'),
      '#default_value' => $this->config['defuse_mail'],
    );
    $form['update_non_existent']['#options'][FEEDS_BLOCK_NON_EXISTENT] = t('Block non-existent users');
    return $form;
  }

  /**
   * Override setTargetElement to operate on a target item that is a node.
   */
  public function setTargetElement(FeedsSource $source, $target_user, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_user->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      case 'language':
        $target_user->language = strtolower($value);
        break;
      default:
        parent::setTargetElement($source, $target_user, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $targets += array(
      'name' => array(
        'name' => t('User name'),
        'description' => t('Name of the user.'),
        'optional_unique' => TRUE,
       ),
      'mail' => array(
        'name' => t('Email address'),
        'description' => t('Email address of the user.'),
        'optional_unique' => TRUE,
       ),
      'created' => array(
        'name' => t('Created date'),
        'description' => t('The created (e. g. joined) data of the user.'),
       ),
      'pass' => array(
        'name' => t('Unencrypted Password'),
        'description' => t('The unencrypted user password.'),
      ),
      'status' => array(
        'name' => t('Account status'),
        'description' => t('Whether a user is active or not. 1 stands for active, 0 for blocked.'),
      ),
      'language' => array(
        'name' => t('User language'),
        'description' => t('Default language for the user.'),
      ),
    );
    if (module_exists('openid')) {
      $targets['openid'] = array(
        'name' => t('OpenID identifier'),
        'description' => t('The OpenID identifier of the user. <strong>CAUTION:</strong> Use only for migration purposes, misconfiguration of the OpenID identifier can lead to severe security breaches like users gaining access to accounts other than their own.'),
        'optional_unique' => TRUE,
       );
    }

    $this->getHookTargets($targets);

    return $targets;
  }

  /**
   * Get id of an existing feed item term if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($uid = parent::existingEntityId($source, $result)) {
      return $uid;
    }

    // Iterate through all unique targets and try to find a user for the
    // target's value.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'name':
          $uid = db_query("SELECT uid FROM {users} WHERE name = :name", array(':name' => $value))->fetchField();
          break;
        case 'mail':
          $uid = db_query("SELECT uid FROM {users} WHERE mail = :mail", array(':mail' => $value))->fetchField();
          break;
        case 'openid':
          $uid = db_query("SELECT uid FROM {authmap} WHERE authname = :authname AND module = 'openid'", array(':authname' => $value))->fetchField();
          break;
      }
      if ($uid) {
        // Return with the first nid found.
        return $uid;
      }
    }
    return 0;
  }

  /**
   * Overrides FeedsProcessor::clean().
   *
   * Block users instead of deleting them.
   *
   * @param FeedsState $state
   *   The FeedsState object for the given stage.
   */
  protected function clean(FeedsState $state) {
    // Delegate to parent if not blocking or option not set.
    if (!isset($this->config['update_non_existent']) || $this->config['update_non_existent'] !== FEEDS_BLOCK_NON_EXISTENT) {
      return parent::clean($state);
    }

    if (!empty($state->removeList)) {
      // @see user_user_operations_block().
      // The following foreach is copied from above function but with an added
      // counter to count blocked users.
      foreach (user_load_multiple($state->removeList) as $account) {
        $this->loadItemInfo($account);
        $account->feeds_item->hash = $this->config['update_non_existent'];
        // For efficiency manually save the original account before applying any
        // changes.
        $account->original = clone $account;
        user_save($account, array('status' => 0));
        $state->blocked++;
      }
    }
  }

  /**
   * Process the result of the parsing stage.
   *
   * @param FeedsSource $source
   *   Source information about this import.
   * @param FeedsParserResult $parser_result
   *   The result of the parsing stage.
   */
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
    $state = $source->state(FEEDS_PROCESS);
    $skiped_items['count'] = 0;
    if (!isset($state->removeList) && $parser_result->items) {
      $this->initEntitiesToBeRemoved($source, $state);
    }

    while ($item = $parser_result->shiftItem()) {

      // Check if this item already exists.
      $entity_id = $this->existingEntityId($source, $parser_result);
      // If it's included in the feed, it must not be removed on clean.
      if ($entity_id) {
        unset($state->removeList[$entity_id]);
      }
      $skip_existing = $this->config['update_existing'] == FEEDS_SKIP_EXISTING;

      module_invoke_all('feeds_before_update', $source, $item, $entity_id);

      // If it exists, and we are not updating, pass onto the next item.
      if ($entity_id && $skip_existing) {
        $skiped_items['items'][$entity_id] = $entity_id;
        $skiped_items['count']++;
        continue;
      }

      try {

        $hash = $this->hash($item);
        $changed = ($hash !== $this->getHash($entity_id));
        $force_update = $this->config['skip_hash_check'];

        // Do not proceed if the item exists, has not changed, and we're not
        // forcing the update.
        if ($entity_id && !$changed && !$force_update) {
          continue;
        }

        // Load an existing entity.
        if ($entity_id) {
          $entity = $this->entityLoad($source, $entity_id);

          // The feeds_item table is always updated with the info for the most
          // recently processed entity. The only carryover is the entity_id.
          $this->newItemInfo($entity, $source->feed_nid, $hash);
          $entity->feeds_item->entity_id = $entity_id;
          $entity->feeds_item->is_new = FALSE;
        }

        // Build a new entity.
        else {
          $entity = $this->newEntity($source);
          $this->newItemInfo($entity, $source->feed_nid, $hash);
        }

        // Set property and field values.
        $this->map($source, $parser_result, $entity);
        $this->entityAPIValidate($entity, $item);

        // Allow modules to alter the entity before saving.
        module_invoke_all('feeds_presave', $source, $entity, $item, $entity_id);

        if (module_exists('rules')) {
          rules_invoke_event('feeds_import_'. $source->importer()->id, $entity);
        }

        // Enable modules to skip saving at all.
        if (!empty($entity->feeds_item->skip)) {
          continue;
        }

        // This will throw an exception on failure.
        $this->entitySaveAccess($entity);
        $this->entitySave($entity);

        // Allow modules to perform operations using the saved entity data.
        // $entity contains the updated entity after saving.
        module_invoke_all('feeds_after_save', $source, $entity, $item, $entity_id);

        // Track progress.
        if (empty($entity_id)) {
          $state->created++;
        }
        else {
          $state->updated++;
        }
      }

      // Something bad happened, log it.
      catch (Exception $e) {
        $state->failed++;
        drupal_set_message($e->getMessage(), 'warning');
        list($message, $arguments) = $this->createLogEntry($e, $entity, $item);
        $source->log('import', $message, $arguments, WATCHDOG_ERROR);
      }
    }

    // Set messages if we're done.
    if ($source->progressImporting() != FEEDS_BATCH_COMPLETE) {
      return;
    }
    // Remove not included items if needed.
    // It depends on the implementation of the clean() method what will happen
    // to items that were no longer in the source.
    $this->clean($state);
    $info = $this->entityInfo();
    $tokens = array(
      '@entity' => strtolower($info['label']),
      '@entities' => strtolower($info['label plural']),
    );
    $messages = array();
    if ($state->created) {
      $messages[] = array(
       'message' => format_plural(
          $state->created,
          'Pre-registration email was sent to @number @entity.',
          'Pre-registration emails were sent to @number @entities.',
          array('@number' => $state->created) + $tokens
        ),
      );
    }
    if ($state->updated) {
      $messages[] = array(
       'message' => format_plural(
          $state->updated,
          'Updated @number @entity.',
          'Updated @number @entities.',
          array('@number' => $state->updated) + $tokens
        ),
      );
    }
    if ($state->unpublished) {
      $messages[] = array(
        'message' => format_plural(
            $state->unpublished,
            'Unpublished @number @entity.',
            'Unpublished @number @entities.',
            array('@number' => $state->unpublished) + $tokens
        ),
      );
    }
    if ($state->blocked) {
      $messages[] = array(
        'message' => format_plural(
          $state->blocked,
          'Blocked @number @entity.',
          'Blocked @number @entities.',
          array('@number' => $state->blocked) + $tokens
        ),
      );
    }
    if ($state->deleted) {
      $messages[] = array(
       'message' => format_plural(
          $state->deleted,
          'Removed @number @entity.',
          'Removed @number @entities.',
          array('@number' => $state->deleted) + $tokens
        ),
      );
    }
    /*
    if ($state->failed) {
      $messages[] = array(
       'message' => format_plural(
          $state->failed,
          'Failed importing @number @entity.',
          'Failed importing @number @entities.',
          array('@number' => $state->failed) + $tokens
        ),
        'level' => WATCHDOG_ERROR,
        'type' => 'warning'
      );
    }
    */
    if ($skiped_items['count'] > 0) {
      $title = t('Users already registered');
      $type = 'ul';
      $attributes = array(
        'id' => 'my-custom-listing',
        'class' => 'custom-class another-custom-class',
      );

      $accounts = array();
      foreach ($skiped_items['items'] as $uid) {
        $accounts[] = user_load($uid);
      }

      $items = array();
      foreach ($accounts as $account) {
        $items[] = array(
          'data' =>  $account->mail . ' - ' . $account->name,
          'id' => $account->uid,
          'class' => array_keys($account->roles),
        );
      }

      $items_list = theme_item_list(array('items' => $items, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));

      $messages[] = array(
       'message' => format_plural(
          $skiped_items['count'],
          '@number @entity was already registered.<br/>',
          '@number @entities were already registered.<br/>',
          array('@number' => $skiped_items['count']) + $tokens
        ) . $items_list,
       'type' => 'warning'
      );
    }

    if (count($this->users_in_use)) {
      $title = t('Usernames already in use');
      $type = 'ul';
      $attributes = array(
        'id' => 'my-custom-listing',
        'class' => 'custom-class another-custom-class',
      );

      $items = array();
      foreach ($this->users_in_use as $user_in_use) {
        $items[] = array(
          'data' =>  $user_in_use['mail'] . ' - ' . $user_in_use['user_name'],
          'id' => $user_in_use['user_name'],
          'class' => array_keys($user_in_use['user_name']),
        );
      }

      $items_list = theme_item_list(array('items' => $items, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));

      $messages[] = array(
       'message' => format_plural(
          count($this->users_in_use),
          '@number username was already registered.<br/>',
          '@number usernames were already registered.<br/>',
          array('@number' => count($this->users_in_use)) + $tokens
        ) . $items_list,
       'type' => 'warning'
      );
    }
    if (empty($messages)) {
      $messages[] = array(
        'message' => t('There are no new @entities.', array('@entities' => strtolower($info['label plural']))),
      );
    }
    foreach ($messages as $message) {
      $message_type = !empty($message['type']) ? $message['type'] : 'status';
      drupal_set_message($message['message'], $message_type);
      $source->log('import', $message['message'], array(), isset($message['level']) ? $message['level'] : WATCHDOG_INFO);
    }
  }
}
