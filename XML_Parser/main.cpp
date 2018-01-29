#include <iostream>
using namespace std;
#include <fstream>

#include "token6.h"

int main() {
  ifstream eingabe;
  ClToken *token;

  eingabe.open("daten2.xml");
  token = new ClToken;

  if (token->getToken(eingabe) != 0) {
    token->druckeToken();
  }
  eingabe.close();
  {
    /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
    int x;
    cin >> x;
  }
}
