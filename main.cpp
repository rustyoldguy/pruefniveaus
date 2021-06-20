// pruefniveaus errechnet mit Losgröße, AQL und Prüfniveaus die Stichprobengröße, die AC und RE-Zahl, ACwahrscheinlichkeit und RE-Wahrscheinlichkeit

#include <iostream>

using namespace std;

#include <math.h>
#include "binver.h"

int main()
{
 binvert bver;
 int wohin = 0;

 do
 switch(wohin)
 {
  default:
   cout << endl << "Prüfniveau-Rechner" << endl;
   cout << "Eingabe und rechnen.....1" << endl;
   cout << "Ende....................2" << endl;
   cout << "Ihre Wahl: ";
   cin >> wohin;
  break;

 case 1:
  bver.Eingabe();
  bver.CalcValues();
  bver.Ausgabe();
  wohin = 0;
 break;

 case 2:
  return 0;
 break;
}
while (wohin != 2);

 return 0;
}
