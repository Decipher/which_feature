<?php
/**
 * @file
 * Views UI module integration.
 */

/**
 * Implements hook_which_feature_preprocess_table_alter() on behalf of
 * views_ui.module
 */
function views_ui_which_feature_preprocess_table_alter(&$vars) {
  $menu = menu_get_item();
  if ('admin/structure/views' == $menu['path']) {
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

      $view = views_get_view($delta);
      if (isset($view->export_module)) {
        $module = features_get_info('module', $view->export_module);
        $column['data'] = $module->info['name'];
        if (isset($module->info['features']['views_view']) && in_array($delta, $module->info['features']['views_view'])) {
          $column['data'] = l($column['data'], 'admin/structure/features/' . $module->name);
        }
      }

      $operations = array_pop($row['data']);
      $row['data'][] = $column;
      array_push($row['data'], $operations);
    }
  }
}
