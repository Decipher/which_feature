<?php
/**
 * @file
 * Strongarm module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of strongarm.module.
 */
function strongarm_which_feature_info() {
  $items = array();

  $items['admin/config/development/strongarm'] = array(
    'component' => 'variable',
    'delta callback' => 'which_feature_strongarm_delta',
  );

  return $items;
}

/**
 * Delta callback for strongarm.module.
 */
function which_feature_strongarm_delta(&$delta, $row) {
  $delta = $row[1];
}
