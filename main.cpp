#include "main.h"

using namespace std;

global manager;

int DebugCSV();
int DebugXML();

int main() {
  DebugXML();

  return 1;
}

int DebugXML() {
  string xml_filename = "Loottable.xml";
  ifstream input;
  string select;

  input.open(xml_filename);

  if (input.is_open()) {
    xml_parser xml(input);
  } else {
    print_line("Couldn't open file Loottable.xml", f_error);
    return -1;
  }

  return 1;
}

int DebugCSV() {
  string csv_filename = "Players.csv";
  ifstream input;
  string select;
  char c;

  // Read the CSV
  input.open(csv_filename);

  if (input.is_open()) {
    csv_parser csv(input, manager);
    print_line("Loaded Player Inventories");
    print_line("Players: " + manager.List_Players());
  } else {
    print_line("Couldn't open file Players.csv", f_error);
    return -1;
  }

  input.close();

  print_line("Whose inventory do you want to check?");
  cin >> select;

  system("cls");

playerinput:
  if (!select.empty()) {
    try {
      player phandler = manager.Get_Player(select);

      while (c != 'Q') {
        system("cls");
        print_line("What do you want to do: ");
        print_line("  1. Add Item");
        print_line("  2. Remove Item");
        print_line("  3. Check Inventory");
        print_line("  4. Search Inventory");

        cin >> c;
        switch (c) {
        case '1':
          phandler.add_item("Test", "Test", 1, 10);
          break;
        case '2':
          break;
        case '3':
          system("cls");
          phandler.display_inventory();
          system("pause");
          break;
        case '4':
          try {
            system("cls");
            string itname;
            print_line("What are you searching for:");
            cin >> itname;
            item ihandler = phandler.find_item(itname);
            print_line("Found item: " + ihandler.name);
            break;
            system("pause");
          } catch (exception &e) {
            print_line(e.what());
            system("pause");
          }
          break;
        }
      }
    } catch (exception &e) {
      print_line(e.what());
    }
  } else {
    goto playerinput;
  }
  return 0;
}
