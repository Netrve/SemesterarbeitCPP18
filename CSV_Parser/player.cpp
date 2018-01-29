#include "player.h"

void player::add_item(string name, string notes, int amount, float value) {
  counter += 1;

  inventory[counter].name = name;
  inventory[counter].amount = amount;
  inventory[counter].notes = notes;
  inventory[counter].value = value;
}
