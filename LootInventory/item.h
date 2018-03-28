#ifndef ITEM_H
#define ITEM_H

#include "includes.h"

using namespace std;

class item {
public:
  item(string INname, string INnotes, int INamount, float INvalue);
  string name;
  string notes;
  int amount;
  float value;
  float tvalue();
};

#endif // ITEM_H
