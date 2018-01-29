#include <iostream>
using namespace std;
#include "token6.h"
#include <fstream>
#include <string.h>

ClToken::ClToken() {
  *tokenName = '\0';
  tokenChild = NULL;
  tokenInhalt = new char[1];
  *tokenInhalt = '\0';
}

int ClToken::getToken(ifstream &datei) {
  int zaehler;
  enum zustand zustand;
  char zeichen;
  char puffer[200];

  cleanToken();

  for (zaehler = 0;;) {
    datei.get(zeichen);
    if (datei.eof()) {
      if (*tokenName == '\0' && tokenChild == NULL && tokenInhalt == NULL)
        return fillToken(0);
      return fillToken(1);
    }
    switch (zeichen) {
    case '<':
      datei.get(zeichen);
      switch (zeichen) {
      case '/':
        zustand = istEndTag;
        if (zaehler != 0) {
          puffer[zaehler] = '\0';
          tokenInhalt = new char[zaehler + 1];
          strcpy(tokenInhalt, puffer);
        }
        break;
      case '!':
        datei.putback(zeichen);
        if (*tokenName != '\0') {
          datei.putback('!');
          tokenChild = new ClToken;
          tokenChild->getToken(datei);
        } else {
          zustand = istName;
        }
        break;
      default:
        break;
      }
      zaehler = 0;
      break;
    case '>':
      puffer[zaehler] = '\0';
      if (zustand == istStartTag) {
        puffer[zaehler] = '\n';
        att.getAttList(puffer);
        // strcpy(tokenName, puffer);
      }
      zaehler = 0;
      break;
    case ' ':
      if (zustand == istName) {
        strcpy(tokenName, puffer);
        puffer[zaehler] = '\0';
        zaehler = 0;
        zustand = istStartTag;
      } else {
        puffer[zaehler] = zeichen;
        zaehler++;
      }
      break;
    case '\n':
      break;
    default:
      puffer[zaehler] = zeichen;
      zaehler++;
      break;
    }
  }
}

int ClToken::fillToken(int mode) {
  if (*tokenName == '\0')
    strcpy(tokenName, "Unbekanntes Element");
  if (tokenInhalt == NULL) {
    tokenInhalt = new char[1];
    *tokenInhalt = '\0';
  }

  return mode;
}

void ClToken::cleanToken(void) {
  *tokenName = '\0';
  if (tokenChild != NULL) {
    delete tokenChild;
    tokenChild = NULL;
  }
  if (tokenInhalt != NULL) {
    delete tokenInhalt;
    tokenInhalt = NULL;
  }
}

void ClToken::druckeToken(void) {
  int ebene = tokenEbene;
  druckeTokenEbene(ebene);
  cout << "Token: " << name() << endl;
  if (att.zahlAtt() > 0) {
    druckeTokenEbene(ebene);
    for (int i = 0; i < att.zahlAtt(); i++)
      cout << "Attribut: " << att.zeigeAttName(i) << endl;
  }
  if (tokenChild != NULL) {
    tokenEbene += 1;
    tokenChild->druckeToken();
  }
}

void ClToken::setTokenEbene(int ebene) { tokenEbene = ebene; }

void ClToken::druckeTokenEbene(int ebene) {
  while (ebene > 0) {
    cout << "| ";
    ebene = ebene - 1;
  }
}
