#include "page.h"

page::page(int pnum) { pageNum = pnum; }

void page::add_item(string name, string notes, int amount, float value) {
  int pos = find_item_pos(name);
  if (pos == -1) {
    item *temp;
    temp = new item(name, notes, amount, value);
    pageInv.push_back(*temp);
  } else {
    pageInv[pos].amount++;
  }
}

void page::insert_item(item initem) {
  int pos = find_item_pos(initem.name);
  if (pos == -1) {
    pageInv.push_back(initem);
  } else {
    pageInv[pos].amount++;
  }
}

item page::get_item(int position) {
  if (position >= 0 && position <= pageInv.size()) {
    return pageInv[position];
  } else {
    print_line("Requested position is out of bounds, returning closest match");
    if (position < 0) {
      print_line("Returning first element as position < 0");
      return pageInv.front();
    } else {
      print_line("Returning last element as position > " + pageInv.size());
      return pageInv.back();
    }
  }
}

int page::find_item_pos(string name) {
  for (int i = 0; i < pageInv.size(); i++) {
    string inv = pageInv[i].name;
    transform(inv.begin(), inv.end(), inv.begin(), ::tolower);
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (inv == name) {
      return i;
    }
  }
  return -1;
}

item page::find_item(string name) {
  int pos = find_item_pos(name);
  if (pos == -1) {
    throw exception("Item not found");
  } else {
    return pageInv[pos];
  }
}

void page::display_inventory() {
  for (int i = 0; i < pageInv.size(); i++) {
    item temp = pageInv[i];
    print_line("Page " + to_string(pageNum) + " has " + to_string(temp.amount) +
               " " + temp.name + " worth " +
               sub_end(to_string(temp.tvalue()), 4) + "GP (" +
               sub_end(to_string(temp.value), 4) + "GP per item)");
  }
}
