#include "att.h"

class ClToken {
public:
  ClToken();
  char *name() { return tokenName; }
  ClToken *child() { return tokenChild; }
  char *inhalt() { return tokenInhalt; }
  void druckeToken(void);
  void setTokenEbene(int ebene);
  int getToken(ifstream &datei);
  ClattToken att;

private:
  void cleanToken();
  void druckeTokenEbene(int ebene);
  int fillToken(int mode);
  char tokenName[64];
  ClToken *tokenChild;
  char *tokenInhalt;
  int tokenEbene = 0;
};

enum zustand { istStartTag, istName, istEndTag };
