#ifndef PAGE_H
#define PAGE_H

#include "LootInventory/item.h"
#include "LootUtility/utility.h"
#include "includes.h"

using namespace std;

class page {
public:
  page(int pnum);
  int pageNum;
  vector<item> returnInv() { return pageInv; }
  item find_item(string name);
  item get_item(int position);
  size_t get_count() { return pageInv.size(); }
  int find_item_pos(string name);
  void display_inventory();
  vector<item> returnPageInv() { return pageInv; }
  void add_item(string name, string notes = "", int amount = 1,
                float value = 0);
  void insert_item(item initem);

private:
  vector<item> pageInv;
};

#endif // PAGE_H
