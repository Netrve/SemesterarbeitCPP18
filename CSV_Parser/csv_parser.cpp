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
          add_player(player_name);
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
      add_item(player_name, item_name, item_notes, item_amount, item_value);
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

void csv_parser::add_player(string name) {
  player *temp;
  temp = new player;
  temp->name = name;
  if (find_player(name) == -1) {
    players.push_back(*temp);
  }
}

int csv_parser::find_player(string name) {
  for (int i = 0; i < players.size(); i++) {
    string pname = players[i].name;
    transform(pname.begin(), pname.end(), pname.begin(), ::tolower);
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (pname == name) {
      return i;
    }
  }
  return -1;
}

void csv_parser::add_item(string player_name, string name, string notes,
                          int amount, float value) {
  int position = find_player(player_name);
  if (position != -1) {
    players[position].add_item(name, notes, amount, value);
  } else {
    print_line("This player has no inventory (Player not found)");
  }
}

string csv_parser::list_players() {
  string output = "";
  for (int i = 0; i < players.size(); i++) {
    output += players[i].name + " ";
  }
  return output;
}

player csv_parser::get_player(string name) {
  int position = find_player(name);
  if (position == -1) {
    throw exception("Player not found");
  } else {
    return players[position];
  }
}
