#include "xml_export.h"

#include <fstream>
#include <iostream>

using namespace std;

void XML_Export::xmlexport(global &manager) {
  ofstream output("LootManager.xml");

  output << "<lootmanager>" << endl;
  output << " <global>" << endl;
  for (int i = 0; i < manager.globalHoldLen(); i++) {
    for (int c = 0; c < manager.Get_Global(i).get_count(); c++) {
      output << "   <item>" << endl;
      output << "     <itemname>" << manager.Get_Global(i).get_item(c).name
             << "</itemname>" << endl;
      output << "     <itemamount>"
             << to_string(manager.Get_Global(i).get_item(c).amount)
             << "</itemamount>" << endl;
      output << "     <itemnotes>" << manager.Get_Global(i).get_item(c).notes
             << "</itemnotes>" << endl;
      output << "     <itemvalue>"
             << to_string(manager.Get_Global(i).get_item(c).value)
             << "</itemvalue>" << endl;
      output << "     <itemtotal>"
             << to_string(manager.Get_Global(i).get_item(c).tvalue())
             << "</itemtotal>" << endl;
      output << "   </item>" << endl;
    }
  }
  output << " </global>" << endl;
  // Player Inv
  for (int i = 0; i < manager.playerHoldLen(); i++) {
    output << " <player name=\"" << manager.Get_Player_By_Pos(i).name << "\">"
           << endl;
    for (int c = 0; c < manager.Get_Player_By_Pos(i).get_count(); c++) {
      output << "   <item>" << endl;
      output << "     <itemname>"
             << manager.Get_Player_By_Pos(i).get_item(c).name << "</itemname>"
             << endl;
      output << "     <itemamount>"
             << to_string(manager.Get_Player_By_Pos(i).get_item(c).amount)
             << "</itemamount>" << endl;
      output << "     <itemnotes>"
             << manager.Get_Player_By_Pos(i).get_item(c).notes << "</itemnotes>"
             << endl;
      output << "     <itemvalue>"
             << to_string(manager.Get_Player_By_Pos(i).get_item(c).value)
             << "</itemvalue>" << endl;
      output << "     <itemtotal>"
             << to_string(manager.Get_Player_By_Pos(i).get_item(c).tvalue())
             << "</itemtotal>" << endl;
      output << "   </item>" << endl;
    }
  }
  output << " </player>" << endl;
  output << "</lootmanager>" << endl;
}
