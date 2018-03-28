#ifndef GLOBAL_H
#define GLOBAL_H

#include "LootInventory/item.h"
#include "LootInventory/player.h"
#include "includes.h"

using namespace std;

class global {
public:
  bool Add_Item_To_Player(string playername, string name, string notes = "", int amount = 1, float value = 0);
  bool Add_Player_To_Hold(string name);
  int Find_Player_By_Name(string name);
	player Get_Player(string name);
	string List_Players();

private:
  vector<item> globalHold;
  vector<player> playerHold;
};

#endif // GLOBAL_H
