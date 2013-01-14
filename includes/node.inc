<?php
/**
 * @file
 * Node module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of node.module.
 */
function node_which_feature_info() {
  $items = array();

  $items['admin/structure/types'] = array(
    'component' => 'node',
    'delta callback' => 'which_feature_node_delta',
  );

  return $items;
}

/**
 * Delta callback for node.module.
 */
function which_feature_node_delta(&$delta, $row) {
  // @TODO - Deal with translation string.
  if (preg_match('/\(Machine name: (.*?)\)/', $row[0], $matches)) {
    $delta = $matches[1];
  }
}
