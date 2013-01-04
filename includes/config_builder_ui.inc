<?php
/**
 * @file
 * Configuration builder UI module integration.
 */

/**
 * Implements hook_which_feature_preprocess_table_alter() on behalf of
 * config_builder_ui.module
 */
function config_builder_ui_which_feature_preprocess_table_alter(&$vars) {
  $menu = menu_get_item();
  if ('admin/structure/config_builder' == $menu['path']) {
    ctools_include('export');
    $component = 'config_builder';

    $operations = array_pop($vars['header']);
    $vars['header'][] = array(
      'data' => t('Module'),
      'class' => array('which-feature'),
      'style' => 'width: 16%',
    );
    array_push($vars['header'], $operations);

    foreach ($vars['rows'] as $delta => &$row) {
      $column = array(
        'data' => '',
        'class' => array('which-feature'),
      );

      $config = ctools_export_crud_load($component, $delta);
      if (isset($config->export_module)) {
        $module = features_get_info('module', $config->export_module);
        $column['data'] = $module->info['name'];
        if (isset($module->info['features'][$component]) && in_array($delta, $module->info['features'][$component])) {
          $column['data'] = l($column['data'], 'admin/structure/features/' . $module->name);
        }
      }

      $operations = array_pop($row['data']);
      $row['data'][] = $column;
      array_push($row['data'], $operations);
    }
  }
}
