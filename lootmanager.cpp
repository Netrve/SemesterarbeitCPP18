#include "lootmanager.h"

int LootManager::InitializeObjects() {
  string dtd_filename = "Input/Loottable.dtd";
  string xml_filename = "Input/Loottable.xml";
  string csv_filename = "Input/Players.csv";
  ifstream input;

  csv = new csv_parser;
  xml = new ClToken;
  xml_read xmlreader;

  // Read the DTD
  input.open(dtd_filename);

  if (input.is_open()) {
    root = xmlreader.read(input);
  } else {
    print_line("Couldn't open file Loottable.dtd");
    return -1;
  }

  input.close();

  // Read the XML
  input.open(xml_filename);

  if (input.is_open()) {
    if (xml->getToken(input, NULL, root) != 0)
      print_line("Loaded XML Loottable");
  } else {
    print_line("Couldn't open file Loottable.xml");
    return -1;
  }

  input.close();

  // Read the CSV
  input.open(csv_filename);

  if (input.is_open()) {
    csv->read_csv(input);
    print_line("Loaded Player Inventories");
  } else {
    print_line("Couldn't open file Player.csv");
    return -1;
  }

  input.close();

  return 0;
}
