<?php

/**
 * @file
 * Implementation of views_plugin_style for googlenews_views
 */


/**
 * Implementation of views_plugin_style
 */
class googlenews_views_plugin_style_xml extends views_plugin_style {

  /** 
   * Implementation of views_plugin_style::option_definition 
   */ 
	function option_definition() {
		global $user;
    $options = parent::option_definition();
    
    $options['googlenews_title'] = array('default' => NULL, 'translatable' => FALSE);
    $options['googlenews_postdate'] = array('default' => NULL, 'translatable' => FALSE);
    $options['googlenews_url'] = array('default' => NULL, 'translatable' => FALSE);
    $options['googlenews_tag'] = array('default' => NULL, 'translatable' => FALSE);
    $options['googlenews_genres'] = array('default' => NULL, 'translatable' => FALSE);
    
    
    return $options;
  }
  
  /**
   * Provide a form for setting options.
   *
   * @param $form
   * @param $form_state
   */
  function options_form(&$form, &$form_state) {
    
    
    $handlers = $this->display->handler->get_handlers('field');
    if (empty($handlers)) {
      drupal_set_message(t('You need at least one field before you can configure your field settings.'), 'error');
    }
    else {
    $field_names = array('' => '--');
      foreach ($handlers as $field => $handler) {
        if ($label = $handler->label()) {
          $field_names[$field] = $label;
        }
        else {
          $field_names[$field] = $handler->ui_name();
        }
      }
    }  
    
    
  	$form['googlenews_title'] = array(
      '#type' => 'select',
      '#title' => t('GoogleNews title'),
      '#options' => $field_names,
      '#default_value' => $this->options['googlenews_title'],
    );
           
   $form['googlenews_postdate']  = array(
      '#type' => 'select',
      '#title' => t('GoogleNews Postdate'),  
      '#options' => $field_names,
      '#default_value' => $this->options['googlenews_postdate'],
    );
    
    $form['googlenews_url'] = array(
      '#type'           => 'select',
      '#title'          => ('GoogleNews url'),
      '#options' => $field_names,
      '#default_value'  => $this->options['googlenews_url'],
      '#description'    => ('For each row in the view, strip all markup from the field output.'),
    );
    
    $form['googlenews_tag'] = array(
      '#type' => 'select',
      '#title' => t('GoogleNews Keywords'),
      '#options' => $field_names,
      '#default_value' => $this->options['googlenews_tag'],
    );
    
    $form['googlenews_genres'] = array(
      '#type' => 'select',
      '#title' => t('GoogleNews Genres'),
      '#options' => $field_names,
      '#default_value' => $this->options['googlenews_genres'],
    );
   
  } 
 	
  /**
   * Implementation of views_style_plugin::theme_functions(). Returns an array of theme functions to use.
   * for the current style plugin
   * @return array 
   */
  function theme_functions() {
    $hook = 'googlenews_views_xml_style'; 
  	return views_theme_functions($hook, $this->view, $this->display);
  }

/**
 * Implementation of views_style_plugin::additional_theme_functions(). Returns empty array.
 * @return array
 */  
  function additional_theme_functions() {
  	return array();
  }
  
  /**
   * Implementation of view_style_plugin::render()
   */
  function render() {
  	$view = $this->view;
  	$options = $this->options;
  	$field = $view->field;
  	
 	  $rows = array();
    
 	  foreach ($view->result as $row) {
      $rows[] = _googlenews_views_render_fields($view, $row);        
    }
    
    return theme($this->theme_functions(), $this->view, $this->options, $rows);    	  
 	}
 
}
