#include "utility.h"
#include "main.h"

bool debugmode = true;

void print_line(string inS, format inF) {
  switch (inF) {
  case f_info:
    cout << "[INFO]  " << inS << endl;
    break;
  case f_error:
    cout << "[ERROR] " << inS << endl;
    break;
  case f_debug:
    if (debugmode) {
      cout << "[DEBUG] " << inS << endl;
    }
    break;
  default:
    print_line("Invalid print_line() Format", f_error);
    break;
  }
}

string sub_end(string in, int count) {
  if (in.size() <= count) {
    return in;
  }
  return in.erase(in.size() - count);
}
