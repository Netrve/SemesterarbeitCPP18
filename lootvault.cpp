#include "lootvault.h"

Lootvault::VaultStore(string name, string notes, int amount, float value) {
  item *temp;
  temp = new item;
  temp->name = name;
  temp->notes = notes;
  temp->name = name;
  temp->amount = amount;
  temp->value = value;

  VaultCart.push_back(*temp);
}
