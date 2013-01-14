<?php
/**
 * @file
 * Custom Breadcrumbs module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of custom_breadcrumbs.module.
 */
function custom_breadcrumbs_which_feature_info() {
  $items = array();

  $items['admin/structure/custom_breadcrumbs'] = array(
    'component' => 'custom_breadcrumb',
    'delta callback' => 'which_feature_custom_breadcrumbs_delta',
    'offset' => array(2, 2),
  );

  return $items;
}

/**
 * Delta callback for custom_breadcrumbs.module.
 */
function which_feature_custom_breadcrumbs_delta(&$delta, $row) {
  foreach ($row as $item) {
    if (is_string($item) && preg_match('/custom_breadcrumbs\/edit\/(.*?)\W/', $item, $matches)) {
      $delta = $matches[1];
    }
  }
}
