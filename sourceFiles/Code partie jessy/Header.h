#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void calculExpBaseA();
int calculNombreIteration(int nbDecimales);
int calcul(double exposant, int nbIterations);
bool estMultipleDe05(double exposant);
int calculNombreDecimalesNecessairePourChaqueTerme(int argMod, int nbDecimales);
int calculNombreIteration(int nbDecimalesNeessaires);
double calculErreurRelativeMax(int nbDecimales);
double degreN(int arg, int degre);
int factorielle(int nombre);