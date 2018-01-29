#ifndef PLAYER_H
#define PLAYER_H

#include <includes.h>
#include <item.h>

using namespace std;

class player {
public:
  string name;
  void add_item(string name, string notes = "", int amount = 1,
                float value = 0);
  item get_item(int position) { return inventory[position]; }
  int get_count() { return counter; }

private:
  int counter = -1;
  item inventory[1000];
};

#endif // PLAYER_H
