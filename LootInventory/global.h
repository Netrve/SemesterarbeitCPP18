#ifndef GLOBAL_H
#define GLOBAL_H

#include "LootInventory/item.h"
#include "LootInventory/page.h"
#include "LootInventory/player.h"
#include "includes.h"

using namespace std;

class global {
public:
  // Player Hold Functions
  bool Add_Item_To_Player(string playername, string name, string notes = "",
                          int amount = 1, float value = 0);
  bool Insert_Item_To_Player(string playername, item initem);
  bool Add_Player_To_Hold(string name);
  int Find_Player_By_Name(string name);
  int playerHoldLen() { return playerHold.size(); }
  player Get_Player(string name);
  player Get_Player_By_Pos(int pos);
  string List_Players();

  // Page Hold Functions
  bool Add_Item_To_Page(int pageid, string name, string notes = "",
                        int amount = 1, float value = 0);
  bool Insert_Item_To_Page(int pageid, item initem);
  bool Add_Page_To_Hold(int pageid);
  int Find_Page_By_ID(int pageid);
  int pageHoldLen() { return pageHold.size(); }
  page Get_Page(int pageid);
  string List_Pages();

  // Global Hold Functions
  bool Add_Loot_To_Global(int pageid);
  page Get_Global(int pos) { return globalHold[pos]; }
  int globalHoldLen() { return globalHold.size(); }

private:
  vector<page> pageHold;
  vector<page> globalHold;
  vector<player> playerHold;
};

#endif // GLOBAL_H
