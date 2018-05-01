#pragma once
#include <stdio.h>
#include <stdlib.h>

#define NB_POINTS 25

void decrypterCleShamir();
double fonctionPolynomes(int nbPoints, CoordonneesPoints coordonnees[], int iX);
void maxPolynome();
double gestionMaxPoints(double* pYMax, CoordonneesPoints coordonneesPuissanceOxygene);

typedef struct coordonnees CoordonneesPoints;
struct coordonnees {
	double pointX;
	double pointY;
};