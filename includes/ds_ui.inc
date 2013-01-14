<?php
/**
 * @file
 * Display Suite UI module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of ds_ui.module.
 */
function ds_ui_which_feature_info() {
  $items = array();

  $items['admin/structure/ds/fields'] = array(
    'component' => 'ds_fields',
    'delta callback' => 'which_feature_ds_fields_delta',
  );

  $items['admin/structure/ds/view_modes'] = array(
    'component' => 'ds_view_modes',
    'delta callback' => 'which_feature_ds_view_modes_delta',
  );

  return $items;
}

/**
 * Delta callback for Display Suite fields.
 */
function which_feature_ds_fields_delta(&$delta, $row) {
  $delta = $row[2];
}

/**
 * Delta callback for Display Suite view modes.
 */
function which_feature_ds_view_modes_delta(&$delta, $row) {
  $delta = $row[1];
}
