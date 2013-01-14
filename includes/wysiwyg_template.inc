<?php
/**
 * @file
 * Wysiwyg Template Plugin module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of wysiwyg_template.module.
 */
function wysiwyg_template_which_feature_info() {
  $items = array();

  $items['admin/config/content/wysiwyg-templates'] = array(
    'component' => 'wysiwyg_template',
    'delta callback' => 'which_feature_wysiwyg_template_delta',
  );

  return $items;
}

/**
 * Delta callback for wysiwyg_template.module.
 */
function which_feature_wysiwyg_template_delta(&$delta, $row) {
  if (preg_match('/edit\/(.*?)\"/', $row[2], $matches)) {
    $delta = $matches[1];
  }
}
