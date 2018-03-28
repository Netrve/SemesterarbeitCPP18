#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include "LootInventory/global.h"
#include "LootInventory/player.h"
#include "LootUtility/utility.h"
#include "includes.h"

using namespace std;

class csv_parser {
public:
	csv_parser(ifstream &file, global &manager);
  int read_csv(ifstream &file, global &manager);

private:
  bool sanity_check(ifstream &file);
};

enum state { normal, escaped };

#endif // CSV_PARSER_H
