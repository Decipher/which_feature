<?php
/**
 * @file
 * Meta tags module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of metatag.module.
 */
function metatag_which_feature_info() {
  $items = array();

  $items['admin/config/search/metatags'] = array(
    'component' => 'metatag',
  );

  return $items;
}
