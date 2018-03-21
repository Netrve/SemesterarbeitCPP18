#include "nexample3.h"

using namespace std;

ClElement *verarbeite(ifstream &datei);

ClElement *xml_read::read(ifstream &dtd) {
  ClElement *wurzel;
  wurzel = verarbeite(dtd);
  return wurzel;
}

ClElement *verarbeite(ifstream &datei) {
  char zeichen, letztes;
  char puffer[100];
  int zaehler;
  enum ezustand zustand = noise;
  ClElement *jetzt = NULL, *wurzel = NULL, *neu;

  for (datei.get(zeichen); !datei.eof(); datei.get(zeichen)) {
    switch (zeichen) {
    case '<':
      zustand = direktive;
      zaehler = 0;
      break;
    case '>':
      if (letztes != ' ') {
        puffer[zaehler] = '\0';
        switch (zustand) {
        case abhaengigElement:
          jetzt->addTag(puffer);
          break;
        case abhaengigAttribute:
          jetzt->addAttribute(puffer);
          break;
        case element:
          neu = new ClElement(puffer);
          if (jetzt != NULL)
            jetzt->setNext(neu);
          else
            wurzel = neu;
          jetzt = neu;
          zustand = abhaengigElement;
          break;
        }
      }
      zustand = noise;
      break;
    case ' ':
      if (letztes == ' ')
        continue;
      puffer[zaehler] = '\0';
      zaehler = 0;
      switch (zustand) {
      case direktive:
        if (!strcmp(puffer, "!ELEMENT"))
          zustand = element;
        else if (!strcmp(puffer, "!ATTLIST"))
          zustand = attribute;
        else {
          cout << endl << "Diese Direktive verstehe ich nicht: " << puffer;
          zustand = noise;
        }
        break;
      case element:
        neu = new ClElement(puffer);
        if (jetzt != NULL)
          jetzt->setNext(neu);
        else
          wurzel = neu;
        jetzt = neu;
        zustand = abhaengigElement;
        break;
      case attribute:
        if (wurzel == NULL)
          neu = NULL;
        else
          neu = wurzel->sucheElement(puffer, wurzel);
        if (neu == NULL) {
          cout << endl
               << "Es gibt kein Element mit dem Namen: " << puffer << endl;
          zustand = noise;
        } else {
          zustand = abhaengigAttribute;
          jetzt = neu;
        }
        break;
      case abhaengigElement:
        jetzt->addTag(puffer);
        break;
      case abhaengigAttribute:
        jetzt->addAttribute(puffer);
        break;
      }
      break;
    default:
      if (zustand != noise)
        puffer[zaehler] = zeichen;
      zaehler++;
      break;
    }
    letztes = zeichen;
  }

  return wurzel;
}
