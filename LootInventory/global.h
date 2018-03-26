#ifndef GLOBAL_H
#define GLOBAL_H

#include <LootInventory/item.h>
#include <LootInventory/player.h>
#include <includes.h>

using namespace std;

class global {
public:
  global();

private:
  vector<item> globalHold;
  vector<player> playerHold;
};

#endif // GLOBAL_H
