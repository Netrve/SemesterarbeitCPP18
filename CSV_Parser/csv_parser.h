#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <LootInventory/player.h>
#include <LootUtility/utility.h>
#include <includes.h>

using namespace std;

class csv_parser {
public:
  int read_csv(ifstream &file);
  size_t get_count() { return players.size(); }
  player get_player(string name);
  string list_players();

private:
  vector<player> players;
  int find_player(string name);
  bool sanity_check(ifstream &file);
  void add_player(string name);
  void add_item(string player_name, string name, string notes = "",
                int amount = 1, float value = 0);
};

enum state { normal, escaped };

#endif // CSV_PARSER_H
