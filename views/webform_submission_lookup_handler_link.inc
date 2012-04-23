<?php

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
    if (!node_access('update', $node)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Lookup Submission Email');
    return l($text, "node/$node->nid/lookup");
  }
}
