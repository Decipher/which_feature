<?php
/**
 * @file
 * System module integration.
 */

/**
 * Implements hook_preprocess().
 */
function which_feature_preprocess(&$vars, $hook) {
  drupal_alter('which_feature_preprocess', $vars, $hook);
  drupal_alter("which_feature_preprocess_{$hook}", $vars);
}

/**
 * Implements hook_preprocess().
 */
function which_feature_preprocess_table(&$vars) {
  drupal_alter('which_feature_preprocess_table', $vars);
}
