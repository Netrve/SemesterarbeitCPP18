#ifndef NEXAMPLE3_H
#define NEXAMPLE3_H

#include "includes.h"
#include "ntoken3.h"

enum ezustand {
  direktive,
  element,
  attribute,
  abhaengigElement,
  abhaengigAttribute,
  noise
};

class xml_read {
public:
  ClElement *read(ifstream &xml);
};

#endif // NEXAMPLE3_H
