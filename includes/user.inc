<?php
/**
 * @file
 * User module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of user.module.
 */
function user_which_feature_info() {
  $items = array();

  $items['admin/people/permissions'] = array(
    'component' => 'user_permission',
    'delta callback' => 'which_feature_user_permissions_delta',
    'offset' => array(0, 0),
  );

  $items['admin/people/permissions/roles'] = array(
    'component' => 'user_role',
    'delta callback' => 'which_feature_user_roles_delta',
  );


  return $items;
}

/**
 * Delta callback for User Permissions.
 */
function which_feature_user_permissions_delta(&$delta, $row) {
  if (preg_match('/1\[(.*?)\]/', $row[1]['data'], $matches)) {
    $delta = $matches[1];
  }
}

/**
 * Delta callback for User Roles.
 */
function which_feature_user_roles_delta(&$delta, $row) {
  $delta = str_replace('<em>(locked)</em>', '', $row[0]);
}
