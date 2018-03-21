# Konzept

Unser Anwendungsfall bezieht sich auf Online Pen und Paper Rollenspiele.

Es soll ein Programm entwickelt werden, mit dessen Hilfe das Loot, also die erbeuteten Schätze, verwaltet werden sollen.

## Datenquellen

Wir gehen davon aus, dass die Rollenspiel-Bücher digital vorliegen und neben der Geschichte in PDF Form auch eine XML mit den erbeutbaren Schätzen beiliegt.

Desweiteren haben wir eine zweite Tabelle welche das Inventar der Gruppe verfolgt als CSV vorliegen.

Ziel ist es beide Quellen zusammen zu fügen um eine XML zu erzeugen in der:
* Das Party Inventar und ein globales Inventar verwaltet wird
* Neuer Loot über ein Page Attribut zum global Inventar hinzugefügt werden kann
* Loot vom globalen Inventar in das Party Inventar geschoben wird und mit einem Playername Attribut versehen wird
