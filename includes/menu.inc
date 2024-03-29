<?php
/**
 * @file
 * Menu module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of menu.module.
 */
function menu_which_feature_info() {
  $items = array();

  $items['admin/structure/menu'] = array(
    'component' => 'menu_custom',
    'delta callback' => 'which_feature_menu_delta',
  );

  return $items;
}

/**
 * Delta callback for menu.module.
 */
function which_feature_menu_delta(&$delta, $row) {
  if (preg_match('/manage\/(.*?)\"/', $row[1]['data'], $matches)) {
    $delta = $matches[1];
  }
}
