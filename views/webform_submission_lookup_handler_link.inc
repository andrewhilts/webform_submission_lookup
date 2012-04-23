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
    $this->additional_fields['uid'] = 'uid';
    $this->additional_fields['type'] = 'type';
    $this->additional_fields['format'] = array('table' => 'node_revisions', 'field' => 'format');
  }

  function render($values) {
    // ensure user has access to edit this node.
    $node = new stdClass();
    $node->nid = $values->{$this->aliases['nid']};
    $node->uid = $values->{$this->aliases['uid']};
    $node->type = $values->{$this->aliases['type']};
    $node->format = $values->{$this->aliases['format']};
    $node->status = 1; // unpublished nodes ignore access control
		//EDIT FOR proper permissions
    if (!node_access('update', $node)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Lookup Submission Email');
    return l($text, "node/$node->nid/lookup");
  }
}
