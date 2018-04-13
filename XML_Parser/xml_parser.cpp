#include "xml_parser.h"

using namespace std;

xml_parser::xml_parser(ifstream &datei, global &manager) {
  bool isLoottable = false;
  char zeichen, letztes;
  char puffer[512], puffer2[512];
  enum readState zustand = noise;
  enum attType attrtyp = none;
  int attRead = 0;
  int zaehler, lastPID;

  string player_name;
  string item_name;
  string item_notes;
  int item_amount;
  float item_value;

  for (datei.get(zeichen); !datei.eof(); datei.get(zeichen)) {
    // print_line("Current State: " + to_string(zustand) + " | Symbol: " +
    // zeichen, f_debug);
    switch (zeichen) {
    case '<':
      if (zustand != readText) {
        zustand = direktive;
      } else {
        zustand = direktive;
        puffer2[zaehler] = '\0';
      }
      zaehler = 0;
      break;
    case '>':
      if (letztes != ' ') {
        puffer[zaehler] = '\0';
      }
      if (strcmp(puffer, "loottable") == 0) {
        isLoottable = true;
        zustand = noise;
      } else if (strcmp(puffer, "itemname") == 0 ||
                 strcmp(puffer, "itemamount") == 0 ||
                 strcmp(puffer, "itemdescription") == 0 ||
                 strcmp(puffer, "itemvalue") == 0) {
        puffer[zaehler] = '\0';
        zaehler = 0;
        zustand = readText;
      } else if (strcmp(puffer, "/itemname") == 0) {
        print_line(puffer2, f_debug);
        puffer[zaehler] = '\0';
        zaehler = 0;
        item_name = puffer2;
        zustand = noise;
      } else if (strcmp(puffer, "/itemamount") == 0) {
        print_line(puffer2, f_debug);
        puffer[zaehler] = '\0';
        zaehler = 0;
        item_amount = stoi(puffer2);
        zustand = noise;
      } else if (strcmp(puffer, "/itemdescription") == 0) {
        print_line(puffer2, f_debug);
        puffer[zaehler] = '\0';
        zaehler = 0;
        item_notes = puffer2;
        zustand = noise;
      } else if (strcmp(puffer, "/itemvalue") == 0) {
        print_line(puffer2, f_debug);
        puffer[zaehler] = '\0';
        zaehler = 0;
        item_value = stoi(puffer2);
        zustand = noise;
      } else if (strcmp(puffer, "/item") == 0) {
        puffer[zaehler] = '\0';
        zaehler = 0;
        manager.Add_Item_To_Page(lastPID, item_name, item_notes, item_amount,
                                 item_value);
        zustand = noise;
      } else {
        zustand = noise;
      }
      break;
    case ' ':
      if (letztes == ' ')
        continue;
      if (zustand == readText) {
        puffer2[zaehler] = zeichen;
        zaehler++;
      } else if (zustand == direktive) {
        puffer[zaehler] = '\0';
        zaehler = 0;
        zustand = erwarteAttribut;
      }
      break;
    case '=':
      if (zustand == erwarteAttribut) {
        zustand = erwarteWert;
        if (strcmp(puffer, "page") == 0) {
          attrtyp = page;
        } else if (strcmp(puffer, "name") == 0) {
          attrtyp = name;
        } else {
          print_line("Unknown Attribute " + string(puffer), f_error);
        }
        puffer[zaehler] = '\0';
        zaehler = 0;
      } else {
        puffer[zaehler] = zeichen;
        zaehler++;
      }
      break;
    case '"':
      if (zustand == erwarteWert) {
        attRead++;
        if (attRead == 1) {
          puffer[zaehler] = '\0';
          zaehler = 0;
        } else if (attRead == 2) {
          puffer[zaehler] = '\0';
          zaehler = 0;
          if (attrtyp == page) {
            lastPID = stoi(puffer);
            manager.Add_Page_To_Hold(lastPID);
          }
          zustand = direktive;
          attrtyp = none;
          attRead = 0;
        }
      }
      break;
    default:
      if (zustand != noise)
        puffer[zaehler] = zeichen;
      if (zustand == readText)
        puffer2[zaehler] = zeichen;
      zaehler++;
      break;
    }
    letztes = zeichen;
  }
}
