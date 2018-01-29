#include <iostream>
using namespace std;
#include "att.h"
#include <fstream>
#include <string.h>

int ClattToken::getAttList(char *eingabe) {
  char puffer[100];
  int zaehler;

  for (zaehler = 0, anzahlAtt = 0; *eingabe != '\0'; eingabe = eingabe + 1) {
    switch (*eingabe) {
    case ' ':
      puffer[zaehler] = '\0';
      attName[anzahlAtt] = new char[zaehler + 1];
      strcpy(attName[anzahlAtt], puffer);
      anzahlAtt++;
      zaehler = 0;
      break;

    case '\n':
      attName[anzahlAtt] = new char[zaehler + 1];
      strcpy(attName[anzahlAtt], puffer);
      anzahlAtt++;
      zaehler = 0;
      break;

    default:
      puffer[zaehler] = *eingabe;
      zaehler++;
      break;
    }
  }

  return 1;
}
