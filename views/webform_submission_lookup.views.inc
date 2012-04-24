<?php
/*
Copyright 2012 Andrew Hilts

This file is part of the webform email lookup module (a Drupal module).

Webform Email Lookup is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Webform Email Lookup is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To review a copy of the GNU General Public License, see http://www.gnu.org/licenses/.
*/

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