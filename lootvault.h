#ifndef LOOTVAULT_H
#define LOOTVAULT_H

#include <CSV_Parser/item.h>
#include <includes.h>

using namespace std;

class Lootvault {
public:
  VaultStore(string name, string notes = "", int amount = 1, float value = 0);

private:
  vector<VaultShelf> VaultCart;
  vector<VaultCart> VaultShelf;
};

#endif // LOOTVAULT_H
