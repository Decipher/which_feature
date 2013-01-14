<?php
/**
 * @file
 * Delta UI module integration.
 */

/**
 * Implements hook_which_feature_info_alter() on behalf of delta_ui.module.
 */
function delta_ui_which_feature_info_alter(&$items) {
  $items['admin/appearance/delta']['components callback'] = 'which_feature_delta_components';
}

/**
 * Components callback for delta_ui.module.
 */
function which_feature_delta_components($item) {
  $components = array();

  $items = ctools_export_crud_load_all($item['component']);
  foreach ($items as $item) {
    if (isset($item->export_module)) {
      $components[$item->machine_name] = $item->export_module;
    }
  }

  return $components;
}
