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
      'title' => t('Title'),
      'description' => t('Description'),
      'author' => t('Author'),
      'timestamp' => t('Published date'),
      'url' => t('Item URL (link)'),
      'guid' => t('Item GUID'),
      'tags' => t('Categories'),
     );
  } 
}
