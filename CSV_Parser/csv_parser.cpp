#include "csv_parser.h"

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

int csv_parser::read_csv(ifstream &file) {
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
          manipulate_player(player_name);
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
      manipulate_item(player_name, item_name, item_notes, item_amount,
                      item_value);
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

void csv_parser::manipulate_player(string name) {
  if (counter == -1) {
    counter++;
    players[counter].name = name;
  } else {
    if (find_player(name) == -1) {
      counter++;
      players[counter].name = name;
    }
  }
}

int csv_parser::find_player(string name) {
  for (int i = 0; i <= counter; i++) {
    if (players[i].name == name) {
      return i;
    }
  }
  return -1;
}

void csv_parser::manipulate_item(string player_name, string name, string notes,
                                 int amount, float value) {
  int position = find_player(player_name);
  players[position].add_item(name, notes, amount, value);
}

void csv_parser::get_player_inventory(string name) {
  int position = find_player(name);
  if (position == -1) {
    print_line("This player has no inventory (This search is case sensitive, "
               "please check the spelling)");
  } else {
    for (int i = 0; i <= players[position].get_count(); i++) {
      print_line("Player " + name + " has " +
                 to_string(players[position].get_item(i).amount) + " " +
                 players[position].get_item(i).name + " worth " +
                 to_string(players[position].get_item(i).tvalue()) + "GP (" +
                 to_string(players[position].get_item(i).value) +
                 "GP per item)");
    }
  }
}

string csv_parser::get_players() {
  string output = "";
  for (int i = 0; i <= counter; i++) {
    output += players[i].name + " ";
  }
  return output;
}
