<?php
/**
 * Simple latex widiget
 */
class boxes_mathjax extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    return array(
      'body' => '',
      'format' => FILTER_FORMAT_DEFAULT,
    );
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form() {
    if (filter_access($this->options['format'])) {
      $form = array();
      $form['body'] = array(
        '#type' => 'textarea',
        '#title' => t('Box body'),
        '#default_value' => $this->options['body'],
        '#rows' => 6,
        '#description' => t('The latex content to be '),
      );
      $form['format'] = filter_form($this->options['format']);
      return $form;
    }
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function render() {
    $content = '';
    if (!empty($this->options['body']) && isset($this->options['format'])) {
      $content = check_markup($this->options['body'], $this->options['format'], FALSE);
    }
    $title = isset($this->title) ? check_plain($this->title) : NULL;
    return array(
      'delta' => $this->delta, // Crucial.
      'title' => $title,
      'subject' => $title,
      'content' => $content,
    );
  }
}