<?php
/**
 * @file gogolenews-views-xml-style.tpl.php
 * Default template for the Views XML style plugin
 *
 * @ingroup views_templates
 */

if (!defined('DATE_W3C')) {
  define('DATE_W3C', 'Y-m-d\TH:i:s+00:00');
}

global $base_url;

  $xml = '<?xml version="1.0" encoding="UTF-8"?>';
  $xml .= '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9"';
  $xml .= '  xmlns:n="http://www.google.com/schemas/sitemap-news/0.9">';

foreach($entries as $entry) {
	//_views_xml_debug_stop($entry);
    $xml .= "  <url>\n";
    $xml .= '<loc>' . $entry['googlenews_url'] . '</loc>';
    $xml .= '<n:news>';
      $xml .= '<n:publication>';
        $xml .= '<n:name>' . variable_get('site_name', 'Drupal') . '</n:name>';
        $xml .= '<n:language>en</n:language>';
      $xml .= '</n:publication>';
      $xml .= !empty($entry['googlenews_genres']) ? '<n:genres>' . $entry['googlenews_genres'] . '</n:genres>' : '';
      $xml .= '<n:title>' . $entry['googlenews_title'] . '</n:title>';
      $xml .= '<n:publication_date>' . gmdate(DATE_W3C, $entry['googlenews_postdate']) . '</n:publication_date>';
      $xml .= !empty($entry['googlenews_tag']) ? '<n:keywords>' . $entry['googlenews_tag'] . '</n:keywords>' : '';
    $xml .= '</n:news>';
    $xml .= "  </url>\n";
}
  $xml .= "</urlset>\n";
  
  if ($view->override_path) {       // inside live preview
    print htmlspecialchars($xml);
  }
  else {
  	drupal_set_header('Content-Type: text/xml');
    print $xml;
    exit;
  }
