#include "binver.h"

binvert::binvert()
{
int  slei, sleib, sleic;
losumfang = 0;
lgr = 0;
pniv = 0;
aqlspalte = 0;
p = 0;
spu = 0;
kennbustnr = 0;

long losgr[15][2] = { {2,8}, {9,15}, {16, 25}, {26, 50}, {51,90}, {91, 150}, {151,280},{281, 500},{501, 1200},
                    {1201, 3200},{3201, 10000}, {10001,35000},{ 35001,150000}, {150001,500000},{500001, 9000000000} };
float _aql[16] = {0, 0.04,	0.065, 0.1,	0.15, 0.25,	0.4, 0.65, 1, 1.5, 2.5,	4, 6.5,	10,	15,	25};
int Spumfang[2][16] = {{2,3,5,8,13,20,32,50,80,125,200,315,500,800,1250,2000},
                      {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R'}};
int pweis[16][16][2] = {
                          // A       B      C      D     E      F        G       H       J       K      L        M       N       O      P        R
                          {{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},      // 0
                          {{0, 1},{0, 1},{0, 1},{0, 1},{0, 1},{0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {1, 2}, {1, 2}, {2, 3}},      // 0.04
                          {{0, 1},{0, 1},{0, 1},{0, 1},{0, 1},{0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {1, 2}, {1, 2}, {2, 3}, {3, 4}},      // 0.065
                          {{0, 1},{0, 1},{0, 1},{0, 1},{0, 1},{0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {1, 2}, {1, 2}, {2, 3}, {3, 4}, {5, 6}},      // 0.1
                          {{0, 1},{0, 1},{0, 1},{0, 1},{0, 1},{0, 1}, {0, 1}, {0, 1}, {0, 1}, {0, 1}, {1, 2}, {1, 2}, {2, 3}, {3, 4}, {5, 6}, {7, 8}},      // 0.15
                          {{0, 1},{0, 1},{0, 1},{0, 1},{0, 1},{0, 1}, {0, 1}, {0, 1}, {0, 1}, {1, 2}, {1, 2}, {2, 3}, {3, 4}, {5, 6}, {7, 8}, {10,11}},     // 0.25
                          {{0, 1},{0, 1},{0, 1},{0, 1},{0, 1},{0, 1}, {0, 1}, {0, 1}, {1, 2}, {1, 2}, {2, 3}, {3, 4}, {5, 6}, {7, 8}, {10,11},{14,15}},     // 0.4
                          {{0, 1},{0, 1},{0, 1},{0, 1},{0, 1},{0, 1}, {0, 1}, {1, 2}, {1, 2}, {2, 3}, {3, 4}, {5, 6}, {7, 8}, {10,11},{14,15},{21,22}},     // 0.65
                          {{0, 1},{0, 1},{0, 1},{0, 1},{0, 1},{0, 1}, {1, 2}, {1, 2}, {2, 3}, {3, 4}, {5, 6}, {7, 8}, {10,11},{14,15},{21,22},{21,22}},     // 1
                          {{0, 1},{0, 1},{0, 1},{0, 1},{0, 1},{1, 2}, {1, 2}, {2, 3}, {3, 4}, {5, 6}, {7, 8}, {10,11},{14,15},{21,22},{21,22},{21,22}},     // 1.5
                          {{0, 1},{0, 1},{0, 1},{0, 1},{1, 2},{1, 2}, {2, 3}, {3, 4}, {5, 6}, {7, 8}, {10,11},{14,15},{21,22},{21,22},{21,22},{21,22}},     // 2.5
                          {{0, 1},{0, 1},{0, 1},{1, 2},{1, 2},{2, 3}, {3, 4}, {5, 6}, {7, 8}, {10,11},{14,15},{21,22},{21,22},{21,22},{21,22},{21,22}},     // 4
                          {{0, 1},{0, 1},{1, 2},{1, 2},{2, 3},{3, 4}, {5, 6}, {7, 8}, {10,11},{14,15},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22}},     // 6.5
                          {{1, 2},{1, 2},{1, 2},{2, 3},{3, 4},{5, 6}, {7, 8}, {10,11},{14,15},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22}},     // 10
                          {{1, 2},{1, 2},{2, 3},{3, 4},{5, 6},{7, 8}, {10,11},{14,15},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22}},     // 15
                          {{1, 2},{2, 3},{3, 4},{5, 6},{7, 8},{10,11},{14,15},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22},{21,22}}};    // 25

for (slei = 0; slei < 15; slei++)
 for (sleib = 0; sleib < 2; sleib++)
  losgroesse[slei][sleib] = losgr[slei][sleib];

pruefniveaus[0] = "S-1";
pruefniveaus[1] = "S-2";
pruefniveaus[2] = "S-3";
pruefniveaus[3] = "S-4";
pruefniveaus[4] = "I";
pruefniveaus[5] = "II";
pruefniveaus[6] = "III";
kennbuchstabe[0] =  "AAAABBBBCCCCDDD";
kennbuchstabe[1] =  "AAABBBCCCDDDEEE";
kennbuchstabe[2] =  "AABBCCDDEEFFGGH";
kennbuchstabe[3] =  "AABCCDEEFGGHJJK";
kennbuchstabe[4] =  "AABCCDEFGHJKLMN";
kennbuchstabe[5] =  "ABCDEFGHJKLMNPQ";
kennbuchstabe[6] =  "BCDEFGHJKLMNPQR";
for (slei = 0; slei < 16; slei++)
 AQL[slei] = _aql[slei];

for (slei = 0; slei < 2; slei++)
 for (sleib = 0; sleib < 16; sleib++)
  Stichprobenumfang[slei][sleib] = Spumfang[slei][sleib];

for (slei = 0; slei < 16; slei++)
 for (sleib = 0; sleib < 16; sleib++)
  for (sleic = 0; sleic < 2; sleic++)
   panweisung[slei][sleib][sleic] = pweis[slei][sleib][sleic];
};

binvert::~binvert(){};


///** Alte Version von Binko
double binvert::Binko(double n, double x)
{
double x2, n2, n3 = 1, x3 = 1, erge;

for (n2 = n - x + 1; n2 <= n; n2++)
  n3 *= n2;

for (x2 = 1; x2 <= x; x2++)
  x3 *= x2;

erge = n3 / x3;
return erge;
}
/*
double binvert::Binko(double n, double k)
{
 double i, erg, zaehler, nenner;
   erg = 1;
   zaehler = n -k + 1;
   nenner = 1;

 for(i=1; i<= k; i++)
  erg *=zaehler++/nenner++;

return erg;
}
*/

// n ist der Stichprobenumfang (Anzahl der Versuche in Excel Parameter 2)
// x ist die Anzahl fehlerhafter Einheiten in der Stichprobe (Zahl der Erfolge in Excel Parameter 1)
// p ist der Anteil Fehlerhafter Einheiten der Grundgesamtheit (Erfolgswahrscheinlichkeit in Excel Parameter 3)
double binvert::Gross_gx(double n, double x, double p)
{
double bk, i, Phi, eminp, nmini, f4, f5, gx = 0;

for (i = 0; i <= x; i++)
 {
  bk = Binko(n, i);
  Phi = pow(p, i);
  eminp = 1 - p;
  nmini = n - i;
  f4 = pow(eminp, nmini);
  f5 = bk * Phi * f4;
  gx += f5;
 }
return gx;
}

double binvert::Klein_gx(double n, double x, double p)
{
double bk, px, f1, minp, nminx, f2, erge;

bk = Binko(n, x);
px = pow(p, x);
f1 = bk * px;
minp = 1 - p;
nminx = n - x;
f2 = pow(minp, nminx);
erge = f2 * f1;
return erge;
}

void binvert::Eingabe(void)
{
  cout << "Pruefniveaus" << endl;
  cout << "Bitte Losumfang eingeben..........: ";
  cin >> losumfang;
  if (losumfang < 2)
   {
    cout << "Ein Losumfang  kleiner als 2 wurde eingegeben, wird auf 3 festgesetzt" << endl;
    losumfang = 3;
   }

  // Losgröße eingeben
  cout << "Moegliche Pruefniveaus: S-1  S-2  S-3  S-4  I  II  III" << endl;
  cout << endl << "Bitte Pruefniveau eingeben: ";
  cin >> prniv;
  cout << "Mögliche AQL: 0.04, 0.065, 0.1,	0.15, 0.25,	0.4, 0.65, 1" << endl;
  cout << "              1.5,  2.5, 4,    6.5,	10,	15,	  25" << endl;
  cout << "Bitte AQL eingeben................: ";
  cin >> aqlist;
}

void binvert::GetLosgroesse(void)
{
 int slei;
 // Losgröße ermittlen
  for (slei = 0; slei < 15; slei++)
   {
   //cout << "min= " << losgroesse[slei][0] << "   max= " <<  losgroesse[slei][1] << endl;
   if ((losumfang >= losgroesse[slei][0]) && (losumfang <= losgroesse[slei][1]))
    {
     lgr = slei;
     break;
    }
   }
}
void binvert::GetPruefniveau(void)
{
 int slei;
  // Pruefniveau ermittlen
 for (slei = 0; slei < 7; slei++)
  {
    //cout << "slei: " << slei <<  " *prniv=" << prniv << "  pruefniveaus=" << pruefniveaus[slei] << endl;
   if(prniv == pruefniveaus[slei])
    {
     //cout << "prniv=" << prniv << "  pruefniveaus=" << pruefniveaus[slei] << endl;
     pniv = slei;
     break;
    }
  }
}

void binvert::GetAQL(void)
{
 int slei;

   // ermittle AQL
 for (slei = 0; slei < 16; slei++)
   if ((aqlist >= AQL[slei]) && (aqlist <= AQL[slei + 1]))
    //{
    //cout << "*aqlist= "<< aqlist << "" "AQL-liste: " << AQL[slei] << endl;
    {
     aqlspalte = slei + 1;
     istaql = AQL[slei +1];

     break;
    }
    //}
}

void binvert::CalcValues(void)
{
 int slei;

 GetLosgroesse();  //lgr
 GetPruefniveau(); //pniv
 GetAQL();         //AQL-Spalte

/** Faustregel:
 * Bei einer AQL von 1 Prozent sollte der mittlere Fehleranteil p-Dach der
 * Grundgesamtheit bei etwa < 0.5 AQl sein */
p = (aqlist / 100) / 2;

for (slei = 0; slei < 16; slei++)
 {
  if (Stichprobenumfang[1][slei] == kennbuchstabe[pniv][lgr])
   {
    spu = Stichprobenumfang[0][slei];
    kennbustnr = slei;
    break;
   }
 }
/*-----------------------------------------------------------------------*/
//kennbustnr = (int)(kennbuchstabe[pniv][lgr] - 65);

ac = panweisung[aqlspalte][kennbustnr][0];
re = panweisung[aqlspalte][kennbustnr][1];
/**-----------------------------------------------------------------------
 * n ist der Stichprobenumfang (Anzahl der Versuche in Excel Parameter 2)
 * x ist die Anzahl fehlerhafter Einheiten in der Stichprobe (Zahl der Erfolge in Excel Parameter 1)
 * p ist der Anteil Fehlerhafter Einheiten der Grundgesamtheit (Erfolgswahrscheinlichkeit in Excel Parameter 3)
 * Hier ist p die Annahmezahl einer Stichprobe */
 acwahrsch = Gross_gx((double)spu, (double) ac, p) * 100;
 //acwahrsch = Gross_gx(spu, ac, p) * 100;
 rewahrsch = 100 - acwahrsch;
}


void binvert::Ausgabe(void)
{
 //cout << endl << "Pr-Niveau: " << prniv << endl;
 cout << endl << "Pruefniveau.........: " << pruefniveaus[pniv] << endl;
 cout << "Kennbuchstabe.......: " << (char)kennbuchstabe[pniv][lgr] << endl; //<< "= " << (int)(kennbuchstabe[pniv][lgr] - 65)<< endl;
 cout << "Empfohlene maximale Anzahl der Fehlerhaften Einheiten der Grundgesamtheit: " << (p * 100) << " %" << endl;
 cout << "Gewählte AQL........: " << istaql << endl;
 cout << "Stichprobenumfang...: " << spu << endl;
 cout << "Kennbuchstabennummer: " << kennbustnr << endl;
 cout << "Anweisung...........: " << spu << " - "  << ac << " / " << re << endl;
 cout << "Erlaubter Fehleranteil pro Stichprobe: " << (double)((double)ac * 100 / (double)spu) << " %" << endl;
 cout << "Annahmewahrscheinlichkeit...: " << acwahrsch << "%" << endl;
 cout << "Rueckweisewahrscheinlichkeit: " << rewahrsch << "%" << endl;
}
