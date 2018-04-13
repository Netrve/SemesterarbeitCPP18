#include "main.h"

using namespace std;

global manager;

int DebugCSV();
int DebugXML();

int MainMenu();
int PageMenu();
int GlobalMenu();
int PlayerMenu();

int main() {
  string xml_filename = "Loottable.xml";
  string csv_filename = "Players.csv";
  ifstream input;

  input.open(xml_filename);

  if (input.is_open()) {
    xml_parser xml(input, manager);
  } else {
    print_line("Couldn't open file Loottable.xml", f_error);
    return -1;
  }

  input.close();

  input.open(csv_filename);

  if (input.is_open()) {
    csv_parser csv(input, manager);
  } else {
    print_line("Couldn't open file Players.csv", f_error);
    return -1;
  }

  input.close();

  MainMenu();

  return 0;
}

int MainMenu() {
  char c;

selection:
  system("cls");
  print_line("Please select an option (type in the number): ");
  print_line("  1. Check Pages");
  print_line("  2. Check Global");
  print_line("  3. Check Players");
  print_line("  4. Write XML");
  print_line("  5. Exit Program");

  cin >> c;
  system("cls");

  switch (c) {
  case '1':
    PageMenu();
    break;
  case '2':
    GlobalMenu();
    break;
  case '3':
    PlayerMenu();
    break;
  case '4':
    XML_Export xml_out;
    xml_out.xmlexport(manager);
    break;
  case '5':
    return 0;
    break;
  }
  goto selection;

  return 0;
}

int PageMenu() {
  char c;
  char d[5];

selection:
  system("cls");
  print_line("Please select an option (type in the number): ");
  print_line("  1. Check Page Loot");
  print_line("  2. Go Back");

  cin >> c;

  system("cls");
  switch (c) {
  case '1':
    print_line("Following Pages are available: " + manager.List_Pages());
    print_line("Please enter the Page you want to check:");
    cin >> d;
    manager.Get_Page(stoi(d)).display_inventory();
    system("pause");
    goto selection;
    break;
  case '2':
    return 0;
    break;
  default:
    goto selection;
    break;
  }

  return 0;
}

int GlobalMenu() {
  char c;
  char d[5];

selection:
  system("cls");
  print_line("Please select an option (type in the number): ");
  print_line("  1. Check Global Loot");
  print_line("  2. Add Page to Global");
  print_line("  3. Go Back");

  cin >> c;

  system("cls");
  switch (c) {
  case '1':
    for (int i = 0; i < manager.globalHoldLen(); i++) {
      manager.Get_Global(i).display_inventory();
    }
    system("pause");
    goto selection;
    break;
  case '2':
    print_line("Following Pages are available: " + manager.List_Pages());
    print_line("Please enter the Page to be added to the Global inventory:");
    cin >> d;
    manager.Add_Loot_To_Global(stoi(d));
    break;
  case '3':
    return 0;
    break;
  default:
    goto selection;
    break;
  }

  return 0;
}

int PlayerMenu() {
  char c;
  char d[64], e[512];
  string name, notes, select;
  int value, amount;

  print_line("Following Players are available: " + manager.List_Players());
  print_line("Please enter the Player you want to check:");
  cin >> d;

  if (strlen(d) != 0) {
    try {
      player phandler = manager.Get_Player(d);

    selection:
      system("cls");
      print_line("Please select an option (type in the number): ");
      print_line("  1. Add Item To Player");
      print_line("  2. Remove Item From Player");
      print_line("  3. Check Inventory Of Player");
      print_line("  4. Search Inventory Of Player");
      print_line("  5. Go Back");

      cin >> c;

      system("cls");
      switch (c) {
      case '1':
        print_line("Itemname: ");
        cin >> e;
        name = e;
        print_line("Itemnotes: ");
        cin >> e;
        notes = e;
        print_line("Itemamount: ");
        cin >> e;
        amount = stoi(e);
        print_line("Itemvalue: ");
        cin >> e;
        value = stoi(e);
        manager.Add_Item_To_Player(phandler.name, name, notes, amount, value);
        print_line("Added Item");
        goto selection;
        break;
      case '2':
        try {
          print_line("What item do you want to delete:");
          cin >> select;
          phandler.remove_item(select);
          print_line("Deleted item");
          break;
          system("pause");
        } catch (exception &e) {
          print_line(e.what());
          system("pause");
        }
        goto selection;
        break;
      case '3':
        try {
          phandler.display_inventory();
          system("pause");
        } catch (exception &e) {
          print_line(e.what());
          system("pause");
        }
        goto selection;
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
        goto selection;
        break;
      case '5':
        return 0;
        break;
      default:
        goto selection;
        break;
      }
    } catch (exception &e) {
      print_line(e.what());
      system("pause");
    }

    return 0;
  }
}

int DebugXML() {
  string xml_filename = "Loottable.xml";
  ifstream input;
  string select;

  input.open(xml_filename);

  if (input.is_open()) {
    xml_parser xml(input, manager);
    cout << manager.List_Pages() << endl;
    manager.Get_Page(2).display_inventory();
  } else {
    print_line("Couldn't open file Loottable.xml", f_error);
    return -1;
  }

  return 0;
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

  return 0;
}
