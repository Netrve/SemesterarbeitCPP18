#include "lootcart.h"

void lootcart::add_item(string name, string notes, int amount, float value) {
  int pos = find_item_pos(name);
  if (pos == -1) {
    item *temp;
    temp = new item;
    temp->name = name;
    temp->amount = amount;
    temp->notes = notes;
    temp->value = value;
    inventory.push_back(*temp);
  } else {
    inventory[pos].amount++;
  }
}

size_t lootcart::get_count() { return inventory.size(); }

item lootcart::get_item(int position) {
  if (position >= 0 && position <= inventory.size()) {
    return inventory[position];
  } else {
    print_line("Requested position is out of bounds, returning closest match");
    if (position < 0) {
      print_line("Returning first element as position < 0");
      return inventory.front();
    } else {
      print_line("Returning last element as position > " + inventory.size());
      return inventory.back();
    }
  }
}

int lootcart::find_item_pos(string name) {
  for (int i = 0; i < inventory.size(); i++) {
    string inv = inventory[i].name;
    transform(inv.begin(), inv.end(), inv.begin(), ::tolower);
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (inv == name) {
      return i;
    }
  }
  return -1;
}

item lootcart::find_item(string name) {
  for (int i = 0; i < inventory.size(); i++) {
    string inv = inventory[i].name;
    transform(inv.begin(), inv.end(), inv.begin(), ::tolower);
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (inv == name) {
      return inventory[i];
    }
  }
  throw exception("Item not found");
}

void lootcart::display_inventory() {
  for (int i = 0; i < inventory.size(); i++) {
    item temp = inventory[i];
    print_line("Cart " + page_id + " has " + to_string(temp.amount) + " " +
               temp.name + " worth " + sub_end(to_string(temp.tvalue()), 4) +
               "GP (" + sub_end(to_string(temp.value), 4) + "GP per item)");
  }
}
