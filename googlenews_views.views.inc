<?php
/**
 * @file
 * Views style plugins to render nodes in the XML data format.
 *
 * @see googlenews_views_plugin_style_xml.inc
 * @ingroup views_plugins
 */


/**
 * Implementation of hook_views_plugin().
 */
function googlenews_views_views_plugins() {
  $path = drupal_get_path('module', 'googlenews_views'); 
	return array(
	   'module' => 'googlenews_views',
      'style'   => array(
        'googlenews_views_xml_style' => array(
          'title'           => ('Google News data document'),
	        'path'            => $path,
          'help'            => ('Display a view as an Google news document.'),
          'handler'         => 'googlenews_views_plugin_style_xml',
	        'theme'           => 'googlenews_views_xml_style',
	        'theme file'      => 'googlenews_views_xml_style.theme.inc',
	        'theme path'      => $path.'/theme',
          'uses row plugin' => FALSE,
          'uses fields'     => TRUE,
          'uses options'    => TRUE,
	        'type'            => 'normal',
	        'help_topic'      => 'style-xml',
	        'even empty'      => TRUE
       ),
     ),
    );
}
