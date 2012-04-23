<?php
/**
 * @file
 * Views hooks implemented for the Webform submission lookup module.
 */

function webform_submission_lookup_views_data_alter(&$data) {
//Link to lookup form
$data['node']['webform_submission_lookup_handler_link'] = array(
    'field' => array(
      'title' => t('Webform submission email lookup'),
      'help' => t('A link to the submission email lookup form.'),
      'handler' => 'webform_submission_lookup_handler_link',
    ),
  );
}

/**
 * Implements hook_views_handlers().
 */
function webform_submission_lookup_views_handlers() {
	return array(
    'info' => array(
      'path' => drupal_get_path('module', 'webform_submission_lookup') . '/views',
    ),
    'handlers' => array(
      'webform_submission_lookup_handler_link' => array(
        'parent' => 'views_handler_field_node_link',
        'file' => 'webform_submission_lookup_handler_link.inc',
    ),
		),
  );	
}