<?php

/**
 * @file
 * The class for "list" type widgets.  It allows users to define widgets that are 
 * list of posts (i.e. latest anouncements, blogs etc).
 * It's simply an interface to an existing view (as in views module)
 */

class os_boxes_list extends os_boxes_default {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['sort'] = 'newest';
    $options['style'] = 'titles';
    $options['number_of_items'] = 8; //@todo whats a good default ?
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(){
    
    $form['filter'] = array(
      '#type' => 'select', 
      '#title' => t('Display'), 
      '#options' => array(
        'all' => t('All posts') 
      ), 
      '#required' => TRUE,
      //'#default_value' => best guess about which content type belong to this feature / context
    );
    
    //@todo not all content types should be displayed -use os/vsite specific api function 
    foreach ( node_get_types('names') as $type => $name ) {
      $form['filter']['#options']['node:' . $type] = t('!type posts', array(
        '!type' => $name 
      ));
    }
    
    $form['sort'] = array(
      '#type' => 'select', 
      '#title' => t('Sorted'), 
      '#options' => array(
        'newest' => t('Newest first'), 
        'oldest' => t('Oldest first'), 
        'a-z' => t('By title') 
      ), 
      '#required' => TRUE, 
      '#default_value' => $this->option['sort'] 
    );
    
    $form['style'] = array(
      '#type' => 'select', 
      '#title' => t('As a'), 
      '#options' => array(
        'teasers' => t('List of teasers'), 
        'titles' => t('List of titles'),
        //'grid' => t('Grid of thumbnails'),
      ),
      
      '#required' => TRUE, 
      '#default_value' => $this->option['style'] 
    );
      
    $form['number_of_items'] = array(
       '#type' => 'textfield',
       '#title' => t('Number of items'),
       '#default_value' => $this->options['number_of_items'],
    );
    
    $form += parent::options_form();
    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    /*
    $view = views_get_view('some default views');
    $view->set_display('some display');
    $view->display_handler->set_option('items_per_page', $this->options['number_of_items']);
    // etc.. 

    $output = $view->execute_display();
    */
    $block = parent::render();
    $block['content'] = "some output";
    return $block;
  }

}



