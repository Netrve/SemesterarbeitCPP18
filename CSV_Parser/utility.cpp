#include "utility.h"

void print_line(string in) { cout << in << endl; }

string sub_end(string in, int count) {
  if (in.size() <= count) {
    return in;
  }
  return in.erase(in.size() - count);
}
