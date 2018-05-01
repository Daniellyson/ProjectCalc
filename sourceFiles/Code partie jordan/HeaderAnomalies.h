#pragma once
#include "Header.h"

#define CALCULSIMPSON 75
#define PI 3.14
#define FIMODELE "fiModele.csv"
#define FITEST "fiTest.csv"


int obtention(int * alphaControl, int * alphaWarning, double * moyenne, double * ecartType);
int obtentionUtilisateur(int * alphaControl, int * alphaWarning);
double calculIntervalle(double * lowerLimit, double moyenne, double ecartType, int alpha, int n);
FILE * lectureFichier();
double sqrt(double valeur);
double ecartType(double variance);
double rechercheA(double alpha);
double valeurAbsolue(double alphaCalcule);
void detectionDesErreurs(void);
double obtentionModele(double * UCL, double * LCL, double * UWL, double * LWL);
char controleMoyenne(double UCL, double LCL, double UWL, double LWL, double moyenneATest);
double fonctionLoiNormal(double x);