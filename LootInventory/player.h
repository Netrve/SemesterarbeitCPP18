#ifndef PLAYER_H
#define PLAYER_H

#include "LootInventory/item.h"
#include "LootUtility/utility.h"
#include "includes.h"

using namespace std;

class player {
public:
  player(string pname);
  string name;
  item find_item(string name);
  item get_item(int position);
  size_t get_count() { return playerInv.size(); }
  int find_item_pos(string name);
  void display_inventory();
  vector<item> returnPlayerInv() { return playerInv; }
  void add_item(string name, string notes = "", int amount = 1,
                float value = 0);
  void insert_item(item initem);
  void remove_item(string itemname);

private:
  vector<item> playerInv;
};

#endif // PLAYER_H
