<?php
/**
 * @file
 * Search API module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of search_api.module.
 */
function search_api_which_feature_info() {
  $items = array();

  $items['admin/config/search/search_api'] = array(
    'components callback' => 'which_feature_search_api_index_components',
    'delta callback' => 'which_feature_search_api_index_delta',
    'row callback' => 'which_feature_search_api_index_row',
  );

  $items['admin/config/search/search_api/index/%/autocomplete'] = array(
    'component' => 'search_api_autocomplete_search',
    'delta callback' => 'which_feature_search_api_autocomplete_delta',
  );

  $items['admin/config/search/search_api/index/%/facets'] = array(
    'component' => 'facetapi',
    'delta callback' => 'which_feature_search_api_facets_delta',
  );

  return $items;
}

function which_feature_search_api_index_components($item) {
  $components = array();

  // Servers.
  $item['component'] = 'search_api_server';
  $components['server'] = which_feature_components_callback($item);

  // Indexes.
  $item['component'] = 'search_api_index';
  $components['index'] = which_feature_components_callback($item);

  return $components;
}

/**
 * Delta callback for Search API Index.
 */
function which_feature_search_api_index_delta(&$delta, $row) {
  if (preg_match('/search_api\/.*?\/(.*?)\//', $row[5], $matches)) {
    $delta = $matches[1];
  }
}

/**
 * Row callback for Search API Index.
 */
function which_feature_search_api_index_row($item, $components, &$delta, &$row) {
  $modules = &drupal_static('which_feature_modules');

  $return = ' ';
  $types = array('server', 'index');
  foreach ($types as $type) {
    if (isset($components[$type][$delta])) {
      if (!isset($modules[$components[$type][$delta]])) {
        $modules[$components[$delta]] = features_get_info('module', $components[$type][$delta]);
      }
      $module = $modules[$components[$type][$delta]];

      $return = $module->info['name'];
      if (isset($module->info['features']["search_api_{$type}"]) && (in_array($delta, $module->info['features']["search_api_{$type}"]) || in_array($delta, array_keys($module->info['features']["search_api_{$type}"])))) {
        $return = l($return, 'admin/structure/features/' . $module->name);
      }
      return $return;
    }
  }

  return $return;
}


/**
 * Delta callback for Search API Autocomplete search.
 */
function which_feature_search_api_autocomplete_delta(&$delta, $row) {
  if (preg_match('/autocomplete\/(.*?)\/edit/', $row[3], $matches)) {
    $delta = $matches[1];
  }
}

/**
 * Delta callback for Search API Facet.
 */
function which_feature_search_api_facets_delta(&$delta, $row) {
  $delta = 'search_api@' . arg(5) . '::' . $delta;
}
