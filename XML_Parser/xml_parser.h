#ifndef XML_PARSER_H
#define XML_PARSER_H

#include "includes.h"
#include "ntoken3.h"

enum ezustand {
  direktive,
  element,
  attribute,
  abhaengigElement,
  abhaengigAttribute,
  noise,
  text
};

class xml_parser {
public:
  xml_parser(ifstream &xml);
  ClElement *reader(ifstream &xml);
};

#endif // XML_PARSER_H
