<?php
/**
 * @file
 * Delta module integration.
 */

/**
 * Implements hook_which_feature_preprocess_table_alter() on behalf of
 * delta_ui.module
 */
function delta_ui_which_feature_preprocess_table_alter(&$vars) {
  $menu = menu_get_item();
  if ('admin/appearance/delta' == $menu['path']) {
    ctools_include('export');
    $component = 'delta';

    $operations = array_pop($vars['header']);
    $vars['header'][] = array(
      'data' => t('Module'),
      'class' => array('which-feature'),
      'style' => 'width: 16%',
    );
    array_push($vars['header'], $operations);

    foreach ($vars['rows'] as $id => &$row) {
      $column = array(
        'data' => '',
        'class' => array('which-feature'),
      );

      $delta = ctools_export_crud_load($component, $id);
      if (isset($delta->export_module)) {
        $module = features_get_info('module', $delta->export_module);
        $column['data'] = $module->info['name'];
        if (isset($module->info['features'][$component]) && in_array($id, $module->info['features'][$component])) {
          $column['data'] = l($column['data'], 'admin/structure/features/' . $module->name);
        }
      }

      $operations = array_pop($row['data']);
      $row['data'][] = $column;
      array_push($row['data'], $operations);
    }
  }
}
