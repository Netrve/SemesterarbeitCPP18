#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>

using namespace std;

enum format { f_info = 0, f_error = 1, f_debug = 2 };

void print_line(string inS = "", format inF = f_info);
string sub_end(string in, int count);

#endif // UTILITY_H
