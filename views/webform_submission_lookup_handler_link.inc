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
 * Views handler to display a link to the email submission lookup form
 */

/**
 * Field handler to present a link to the email submission lookup form
 */
class webform_submission_lookup_handler_link extends views_handler_field_node_link {
  function construct() {
    parent::construct();
  }

  function render($values) {
    // ensure user has access to edit this node.
    $node = new stdClass();
    $node->nid = $values->{$this->aliases['nid']};
		//EDIT FOR proper permissions
    if (!user_access('webform submission lookup')) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Lookup Submission Email');
    return l($text, "node/$node->nid/lookup");
  }
}
