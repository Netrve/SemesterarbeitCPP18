#ifndef LOOTCART_H
#define LOOTCART_H

#include <CSV_Parser/item.h>
#include <CSV_Parser/utility.h>
#include <includes.h>

using namespace std;

class lootcart {
public:
  int page_id;
  int find_item_pos(string name);
  void display_inventory();
  void add_item(string name, string notes = "", int amount = 1,
                float value = 0);
  item find_item(string name);
  item get_item(int position);
  size_t get_count();

private:
  vector<item> inventory;
};

#endif // LOOTCART_H
