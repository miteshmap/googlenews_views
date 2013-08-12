<?php
/**
 * @file
 * View template to render view fields as XML.
 *
 * - $view: The view in use.
 * - $rows: Array of row objects as rendered by _views_json_render_fields 
 * - $attachment: not used currently
 * - $options: The options for the style passed in from the UI.
 *
 * @ingroup views_templates
 * @see googlenews_views.views.inc
 */


function template_preprocess_googlenews_views_xml_style($vars) {
 
	global $user;
	global $base_url; 
  $view = $vars["view"];
  $rows = $vars["rows"];
  $options = $vars["options"];
  $link = $view->display_handler->get_path();
  $url_options = array('absolute' => TRUE);
  if (!empty($view->exposed_raw_input)) {
    $url_options['query'] = $view->exposed_raw_input;
  }
	$base = $view->base_table;
  
	$entries = array();
  foreach($rows as $row) {
  	$entry = array();
    
    
    //watchdog('entries','<pre>'.print_r($row,true));
    
    if (array_key_exists($options['googlenews_title'], $row)) {
      if($row[$options['googlenews_title']]->raw){
        $entry["googlenews_title"] =check_plain($row[$options['googlenews_title']]->raw);  
      }else{
        $entry["googlenews_title"] =check_plain($row[$options['googlenews_title']]->content);
      }
  	}
    
    if (array_key_exists($options['googlenews_url'], $row)) {
      if($row[$options['googlenews_url']]->raw){
	  	  $entry["googlenews_url"] = check_plain($row[$options['googlenews_url']]->raw);
      }else{
        $entry["googlenews_url"] = check_plain($row[$options['googlenews_url']]->content);
      }
  	}
    
    if (array_key_exists($options['googlenews_postdate'], $row)) {
      if($row[$options['googlenews_postdate']]->raw){
	  	  $entry["googlenews_postdate"] = $row[$options['googlenews_postdate']]->raw;
      }else{
        $entry["googlenews_postdate"] = $row[$options['googlenews_postdate']]->content;
      }
  	}
    
    if (array_key_exists($options['googlenews_tag'], $row)) {
      if($row[$options['googlenews_tag']]->content){
        if(is_array($row[$options['googlenews_tag']]->content)){
          $tags = join(',',$row[$options['googlenews_tag']]->content);
        }
        else{
          $tags = $row[$options['googlenews_genres']]->content;
        }
        $entry["googlenews_tag"] = $tags;  
      }
  	}
    //watchdog('options','<pre>'.print_r($row,true));
    if (array_key_exists($options['googlenews_genres'], $row)) {
      if($row[$options['googlenews_genres']]->content){
        if(is_array($row[$options['googlenews_genres']]->content)){
          $tags = join(',',$row[$options['googlenews_genres']]->content);
        }else{
          $tags = $row[$options['googlenews_genres']]->content;
        }
        $entry["googlenews_genres"] = $tags;  
      }
  	}
    
    
	  $entries[] = $entry;
    
  }
 
  $vars["entries"] = $entries;  
}