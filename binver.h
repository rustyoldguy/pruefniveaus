#ifndef BINVER_H_INCLUDED
#define BINVER_H_INCLUDED
#include <iostream>

using namespace std;

#include <math.h>


class binvert
{
public:
binvert();
~binvert();

double Binko(double n, double x);
double Gross_gx(double n, double x, double p);
double Klein_gx(double n, double x, double p);

long   losumfang;
long   losgroesse[15][2];
int    lgr;
string prniv;
long   pniv;
string pruefniveaus[7];
string kennbuchstabe[7];
float  aqlist;
float  AQL[16];
float istaql;
int    aqlspalte;
int    Stichprobenumfang[2][16];
double p;
int    spu;
int    kennbustnr;
int    ac;
int    re;
int    panweisung[16][16][2];
double acwahrsch;
double rewahrsch;


void Eingabe(void);
void GetLosgroesse(void);
void GetPruefniveau(void);
void GetAQL(void);
void CalcValues(void);
void Ausgabe(void);

};


#endif // BINVER_H_INCLUDED
