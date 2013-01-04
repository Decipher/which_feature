<?php
/**
 * @file
 * Custom Formatters module integration.
 */

/**
 * Implements hook_which_feature_preprocess_table_alter() on behalf of
 * custom_formatters.module
 */
function custom_formatters_which_feature_preprocess_table_alter(&$vars) {
  $menu = menu_get_item();
  if ('admin/structure/formatters' == $menu['path']) {
    ctools_include('export');
    $component = 'formatters';

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

      $formatter = ctools_export_crud_load($component, $delta);
      if (isset($formatter->export_module)) {
        $module = features_get_info('module', $formatter->export_module);
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
