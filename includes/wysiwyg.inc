<?php
/**
 * @file
 * Wysiwyg module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of wysiwyg.module.
 */
function wysiwyg_which_feature_info() {
  $items = array();

  $items['admin/config/content/wysiwyg'] = array(
    'component' => 'wysiwyg',
    'delta callback' => 'which_feature_wysiwyg_delta',
  );

  return $items;
}

/**
 * Delta callback for wysiwyg.module.
 */
function which_feature_wysiwyg_delta(&$delta, $row) {
  if (preg_match('/profile\/(.*?)\/edit/', $row[2], $matches)) {
    $delta = $matches[1];
  }
}
