#include "item.h"

item::item(string INname, string INnotes, int INamount, float INvalue) {
  name = INname;
  notes = INnotes;
  amount = INamount;
  value = INvalue;
}

float item::tvalue() { return (amount * value); }
