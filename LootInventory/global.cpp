#include "global.h"

bool global::Add_Item_To_Player(string playername, string name, string notes, int amount, float value) {
  int pos = Find_Player_By_Name(playername);
  if (pos >= 0) {
    playerHold[pos].add_item(name, notes, amount, value);
    return true;
  }
  return false;
}

bool global::Add_Player_To_Hold(string name) {
  int pos = Find_Player_By_Name(name);
  if (pos == -1) {
    player *temp;
    temp = new player(name);
	playerHold.push_back(*temp);
    return true;
  } else if (pos >= 0) {
    return true;
  }
  return false;
}

int global::Find_Player_By_Name(string name) {
  for (int i = 0; i < playerHold.size(); i++) {
    string pname = playerHold[i].name;
    transform(pname.begin(), pname.end(), pname.begin(), ::tolower);
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (pname == name) {
      return i;
    }
  }
  return -1;
}

player global::Get_Player(string name)
{
	int pos = Find_Player_By_Name(name); 
	return playerHold[pos];
}

string global::List_Players()
{
	string output = "";
	for (int i = 0; i < playerHold.size(); i++) {
		output += playerHold[i].name + " ";
	}
	return output;
}
