#ifndef XML_PARSER_H
#define XML_PARSER_H

#include "LootInventory/global.h"
#include "LootUtility/utility.h"
#include "includes.h"

enum readState { direktive, erwarteAttribut, erwarteWert, readText, noise };

enum attType { none, page, name };

class xml_parser {
public:
  xml_parser(ifstream &xml, global &manager);
};

#endif // XML_PARSER_H
