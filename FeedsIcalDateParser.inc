<?php
// $Id$

/**
 * Class definition for iCal date module Parser.
 *
 * Parses iCal feeds using the iCal parser included with the date module.
 */
class FeedsIcalDateParser extends FeedsParser {

  /**
   * Parse content fetched by fetcher.
   */
  public function parse(FeedsImportBatch $batch, FeedsSource $source) {
    module_load_include('inc', 'parser_ical', 'parser_ical.dateapi');
    $result = _parser_ical_parse($batch->getRaw());
    $batch->setTitle($result['title']);
    $batch->setItems($result['items']);
    // also available description, calscale, timezone
  }

  /**
   * Return mapping sources.
   *
   * At a future point, we could expose data type information here,
   * storage systems like Data module could use this information to store
   * parsed data automatically in fields with a correct field type.
   */
  public function getMappingSources() {
    return array(
      'title' => array(
        'name' => t('Title'),
        'description' => t('Title of the feed item.'),
      ),
      'description' => array(
        'name' => t('Description'),
        'description' => t('Description of the feed item.'),
      ),
      // 'author' => t('Author'), // not implemented
      'timestamp' => array(
        'name' => t('Published date'),
        'description' => t('Published date as UNIX time UTC of the feed item.'),
      ),
      'url' => array(
        'name' => t('Item URL (link)'),
        'description' => t('URL of the feed item.'), // @todo check description
      ),
      'guid' => array(
        'name' => t('Item GUID'),
        'description' => t('Global Unique Identifier of the feed item.'),
      ),
      'tags' => array(
        'name' => t('Categories'),
        'description' => t('An array of categories that have been assigned to the feed item.'),
      ),
      'ical_date' => array(
         'name' => t('iCal Date'),
         'description' => t('iCal date associated with item as an array.'),
      ),
    );
  }
}
