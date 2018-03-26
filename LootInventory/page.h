#ifndef PAGE_H
#define PAGE_H

#include <LootInventory/item.h>
#include <includes.h>

using namespace std;

class page {
public:
  int pageNum;
  vector<item> returnInv() { return pageInv; }

private:
  vector<item> pageInv;
};

#endif // PAGE_H
