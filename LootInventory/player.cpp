#include "player.h"

player::player(string pname)
{
	name = pname;
}

void player::add_item(string name, string notes, int amount, float value) {
  int pos = find_item_pos(name);
  if (pos == -1) {
    item *temp;
    temp = new item(name, notes, amount, value);
    playerInv.push_back(*temp);
  } else {
    playerInv[pos].amount++;
  }
}

item player::get_item(int position) {
  if (position >= 0 && position <= playerInv.size()) {
    return playerInv[position];
  } else {
    print_line("Requested position is out of bounds, returning closest match");
    if (position < 0) {
      print_line("Returning first element as position < 0");
      return playerInv.front();
    } else {
      print_line("Returning last element as position > " + playerInv.size());
      return playerInv.back();
    }
  }
}

int player::find_item_pos(string name) {
  for (int i = 0; i < playerInv.size(); i++) {
    string inv = playerInv[i].name;
    transform(inv.begin(), inv.end(), inv.begin(), ::tolower);
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (inv == name) {
      return i;
    }
  }
  return -1;
}

item player::find_item(string name) {
  int pos = find_item_pos(name);
  if (pos == -1) {
    throw exception("Item not found");
  } else {
    return playerInv[pos];
  }
}

void player::display_inventory() {
  for (int i = 0; i < playerInv.size(); i++) {
    item temp = playerInv[i];
    print_line("Player " + name + " has " + to_string(temp.amount) + " " +
               temp.name + " worth " + sub_end(to_string(temp.tvalue()), 4) +
               "GP (" + sub_end(to_string(temp.value), 4) + "GP per item)");
  }
}
