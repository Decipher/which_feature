<?php
/**
 * @file
 * Chaos tool suite (ctools) module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of ctools.module.
 */
function ctools_which_feature_info() {
  $items = array();

  if (function_exists('ctools_get_export_uis')) {
    foreach (ctools_get_export_uis() as $plugin) {
      if (is_array($plugin['menu']) && !empty($plugin['menu'])) {
        $items["{$plugin['menu']['menu prefix']}/{$plugin['menu']['menu item']}"] = array(
          'component' => $plugin['schema'],
          'components callback' => 'which_feature_ctools_components',
        );
      }
    }
  }

  return $items;
}

/**
 * Components callback for ctools.module.
 */
function which_feature_ctools_components($item) {
  $components = array();

  $items = ctools_export_crud_load_all($item['component']);
  foreach ($items as $item) {
    if (isset($item->export_module)) {
      $components[$item->name] = $item->export_module;
    }
  }

  return $components;
}
