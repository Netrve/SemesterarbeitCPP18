#include "csv_parser.h"

csv_parser::csv_parser(ifstream &file, global &manager) {
	file.clear();
	file.seekg(0, ios::beg);
	read_csv(file, manager);
}

bool csv_parser::sanity_check(ifstream &file) {
  int counter;
  char character;
  char buffer[200];
  int fix = 0;
  string hold;

  for (counter = 0;;) {
    file.get(character);

    if (file.eof()) {
      break;
    }

    switch (character) {
    case '\n':
      buffer[counter] = '\0';
      hold = string(buffer);
      transform(hold.begin(), hold.end(), hold.begin(), ::tolower);
      if (hold == "player;item;notes;amount;value") {
        print_line("Passed Sanity Check");
        return true;
      } else {
        print_line("Failed Sanity Check");
        print_line("First line did not match expected form: "
                   "player;item;notes;amount;value");
        print_line("Incoming first line from file: " + hold);
        return false;
      }

    default:
      if (fix <= 2) {
        fix++;
      } else {
        buffer[counter] = character;
        counter++;
      }
      break;
    }
  }
  return false;
}

int csv_parser::read_csv(ifstream &file, global &manager) {
  int counter;
  enum state state = normal;
  char character;
  char buffer[200];
  int step = 0;

  string player_name;
  string item_name;
  string item_notes;
  int item_amount;
  float item_value;

  if (!sanity_check(file)) {
    return -1;
  }

  for (counter = 0;;) {
    file.get(character);

    if (file.eof()) {
      break;
    }

    switch (character) {
    case '"':
      if (state == normal) {
        state = escaped;
      } else {
        state = normal;
      }
      break;

    case ';':
      if (state == normal) {
        buffer[counter] = '\0';
        counter = 0;
        switch (step) {
        case 0:
          player_name = buffer;
          manager.Add_Player_To_Hold(player_name);
          break;
        case 1:
          item_name = buffer;
          break;
        case 2:
          item_notes = buffer;
          break;
        case 3:
          item_amount = atoi(buffer);
          break;
        }
        step++;
      } else {
        buffer[counter] = character;
        counter++;
      }
      break;

    case '\n':
      buffer[counter] = '\0';
      counter = 0;
      item_value = atof(buffer);
			manager.Add_Item_To_Player(player_name, item_name, item_notes, item_amount, item_value);
      step = 0;
      break;

    default:
      buffer[counter] = character;
      counter++;
      break;
    }
  }
  return 0;
}