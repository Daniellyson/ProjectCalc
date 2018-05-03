#pragma once
#include "Header.h"
#include "biblioInteg\Simpson.h"


#define CALCULSIMPSON 75
#define PI 3.14
#define FIMODELE "fiModele.csv"
#define FITEST "fiTest.csv"
#define TAILLE_MESSAGE 25


int obtention(int * alphaControl, int * alphaWarning, double * moyenne, double * ecartType);
int obtentionUtilisateur(int * alphaControl, int * alphaWarning);
double calculIntervalle(double * lowerLimit, double moyenne, double ecartType, int alpha, int n);
double rechercheA(double tauxAcceptation);
void controleMoyenne(double UCL, double LCL, double UWL, double LWL, double moyenneATest, char message[]);
double fonctionLoiNormal(double x);