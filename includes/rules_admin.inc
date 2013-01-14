<?php
/**
 * @file
 * Rules UI module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of rules_admin.module.
 */
function rules_admin_which_feature_info() {
  $items = array();

  $items['admin/config/workflow/rules'] = array(
    'component' => 'rules_config',
    'components callback' => 'which_feature_rules_components',
    'delta callback' => 'which_feature_rules_delta',
  );

  return $items;
}

/**
 * Components callback for rules_admin.module.
 */
function which_feature_rules_components($item) {
  $components = array();

  $rules = entity_load('rules_config');
  foreach ($rules as $rule) {
    $components[$rule->name] = $rule->module;
  }

  return $components;
}

/**
 * Delta callback for rules_admin.module.
 */
function which_feature_rules_delta(&$delta, $row) {
  // @TODO - Deal with translation string.
  if (preg_match('/Machine name: (.*)/', $row[0]['data']['description']['settings']['machine_name']['#markup'], $matches)) {
    $delta = $matches[1];
  }
}
