#ifndef LOOTMANAGER_H
#define LOOTMANAGER_H

#include <CSV_Parser/csv_parser.h>
#include <XML_Parser/nexample3.h>
#include <includes.h>

using namespace std;

class LootManager {
public:
  int InitializeObjects();
  csv_parser *csv;
  ClToken *xml;
  ClElement *root;

private:
  vector<player> player_inventories;
};

#endif // LOOTMANAGER_H
