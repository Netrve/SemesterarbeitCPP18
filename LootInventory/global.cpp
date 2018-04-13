#include "global.h"

///////////////////////////
// Player Hold Functions //
///////////////////////////
bool global::Add_Item_To_Player(string playername, string name, string notes,
                                int amount, float value) {
  int pos = Find_Player_By_Name(playername);
  if (pos >= 0) {
    playerHold[pos].add_item(name, notes, amount, value);
    return true;
  }
  return false;
}

bool global::Insert_Item_To_Player(string playername, item initem) {
  int pos = Find_Player_By_Name(playername);
  if (pos >= 0) {
    playerHold[pos].insert_item(initem);
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

player global::Get_Player(string name) {
  int pos = Find_Player_By_Name(name);
  return playerHold[pos];
}

player global::Get_Player_By_Pos(int pos) { return playerHold[pos]; }

string global::List_Players() {
  string output = "";
  for (int i = 0; i < playerHold.size(); i++) {
    if (i == playerHold.size() - 1) {
      output += playerHold[i].name;
    } else {
      output += playerHold[i].name + ", ";
    }
  }
  return output;
}

/////////////////////////
// Page Hold Functions //
/////////////////////////
bool global::Add_Item_To_Page(int pageid, string name, string notes, int amount,
                              float value) {
  int pos = Find_Page_By_ID(pageid);
  if (pos >= 0) {
    pageHold[pos].add_item(name, notes, amount, value);
    return true;
  }
  return false;
}

bool global::Insert_Item_To_Page(int pageid, item initem) {
  int pos = Find_Page_By_ID(pageid);
  if (pos >= 0) {
    pageHold[pos].insert_item(initem);
    return true;
  }
  return false;
}

bool global::Add_Page_To_Hold(int pageid) {
  int pos = Find_Page_By_ID(pageid);
  if (pos == -1) {
    page *temp;
    temp = new page(pageid);
    pageHold.push_back(*temp);
    return true;
  } else if (pos >= 0) {
    return true;
  }
  return false;
}

int global::Find_Page_By_ID(int pageid) {
  for (int i = 0; i < pageHold.size(); i++) {
    int pid = pageHold[i].pageNum;
    if (pid == pageid) {
      return i;
    }
  }
  return -1;
}

page global::Get_Page(int pageid) {
  int pos = Find_Page_By_ID(pageid);
  if (pos == -1) {
    print_line("Requested page doesn't exist", f_error);
    return pageHold[0];
  } else {
    return pageHold[pos];
  }
}

string global::List_Pages() {
  string output = "";
  for (int i = 0; i < pageHold.size(); i++) {
    if (i == pageHold.size() - 1) {
      output += to_string(pageHold[i].pageNum);
    } else {
      output += to_string(pageHold[i].pageNum) + ", ";
    }
  }
  return output;
}

///////////////////////////
// Global Hold Functions //
///////////////////////////
bool global::Add_Loot_To_Global(int pageid) {
  page temp = Get_Page(pageid);
  globalHold.push_back(temp);
  return true;
}
