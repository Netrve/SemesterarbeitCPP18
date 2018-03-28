#ifndef NEXAMPLE3_H
#define NEXAMPLE3_H

#include "ntoken3.h"
#include "includes.h"

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
  ClElement *read(ifstream &dtd);
};

#endif // NEXAMPLE3_H
