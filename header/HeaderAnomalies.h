#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CALCULSIMPSON 75

void detectionDesAnomalies(void);
int obtention(int * alphaControl, int * alphaWarning, double * moyenne, double * ecartType);
int obtentionUtilisateur(int alphaControl, int alphaWarning);
double calculIntervalle(double * lowerLimit, double moyenne, double ecartType, int alpha, int n);
FILE * lectureFichier();
double sqrt(double valeur);
double ecartTYpe(double variance);
double rechercheA(double alpha);
double calculSimpson(int valeurCalculSimpson, int zero, double a, double (*fonctionLoiNormal)(void));
double valeurAbsolue(double alphaCalcule);
void detectionDesErreurs(void);
double obtentionModele(double * UCL, double * LCL, double * UWL, double * LWL);
char contrileMoyenne(double UCL, double LCL, double UWL, double LWL, double moyenneATest);
double fonctionLoiNormal(void);