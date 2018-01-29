#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <includes.h>
#include <player.h>

using namespace std;

class csv_parser {
public:
  int read_csv(ifstream &file);
  int get_count() { return counter; }
  void get_player_inventory(string name);
  string get_players();

private:
  player players[30];
  int counter = -1;
  int find_player(string name);
  bool sanity_check(ifstream &file);
  void manipulate_player(string name);
  void manipulate_item(string player_name, string name, string notes = "",
                       int amount = 1, float value = 0);
};

enum state { normal, escaped };

#endif // CSV_PARSER_H
