#include "natt3.h"
#include <includes.h>

using namespace std;

class ClToken {
public:
  ClToken();
  char *name() { return tokenName; }
  ClToken *child() { return tokenChild; }
  char *inhalt() { return tokenInhalt; }
  void druckeToken(int ebene);
  int getToken(ifstream &datei, ClElement *element, ClElement *wurzel);
  ClattToken att;

private:
  void cleanToken();
  void druckeTokenEbene(int ebene);
  int fillToken(int mode);
  char tokenName[64];
  ClToken *tokenChild;
  ClToken *tokenSibling;
  char *tokenInhalt;
};

enum zustand { istStartTag, istEndTag };
