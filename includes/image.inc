<?php
/**
 * @file
 * Image module integration.
 */

/**
 * Implements hook_which_feature_info() on behalf of image.module.
 */
function image_which_feature_info() {
  $items = array();

  $items['admin/config/media/image-styles'] = array(
    'component' => 'image',
    'delta callback' => 'which_feature_image_delta',
    'offset' => array(1, 2),
  );

  return $items;
}

/**
 * Delta callback for image.module.
 */
function which_feature_image_delta(&$delta, $row) {
  if (preg_match('/\"\>(.*?)\</', $row[0], $matches)) {
    $delta = $matches[1];
  }
}
