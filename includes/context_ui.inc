<?php
/**
 * @file
 * Context UI module integration.
 */

/**
 * Implements hook_which_feature_info_alter() on behalf of context_ui.module.
 */
function context_ui_which_feature_info_alter(&$items) {
  $items['admin/structure/context']['delta callback'] = 'which_feature_context_delta';
}

/**
 * Delta callback for context_ui.module.
 */
function which_feature_context_delta(&$delta, $row) {
  list($tag, $delta) = explode(':', $delta);
}
