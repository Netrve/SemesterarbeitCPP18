#ifndef PLAYER_H
#define PLAYER_H

#include <CSV_Parser/item.h>
#include <CSV_Parser/utility.h>
#include <includes.h>

using namespace std;

class player {
public:
  item find_item(string name);
  item get_item(int position);
  size_t get_count();
  string name;
  int find_item_pos(string name);
  void display_inventory();
  void add_item(string name, string notes = "", int amount = 1,
                float value = 0);

private:
  vector<item> inventory;
};

#endif // PLAYER_H
