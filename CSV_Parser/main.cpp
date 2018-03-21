#include <fstream>
#include <iostream>
#include <string>

#include <main.h>

using namespace std;

void check_inventory(csv_parser *csv);

int main() {
  string filename;
  ifstream input;

  csv_parser *csv;
  csv = new csv_parser;

  print_line("Please enter the filename (default: 'Player.csv'):");
  getline(cin, filename);
  if (filename.empty()) {
    filename = "Players.csv";
  }
  input.open(filename);

  if (input.is_open()) {
    csv->read_csv(input);
  } else {
    print_line("Couldn't open file Player.csv");
    return -1;
  }

  input.close();

in:
  check_inventory(csv);

  goto in;
}

void check_inventory(csv_parser *csv) {
  string userinput;
  print_line();
  print_line("Whose inventory do you want to see?");
  print_line("Available inventories: " + csv->get_players());

  getline(cin, userinput);
  csv->get_player_inventory(userinput);
}
