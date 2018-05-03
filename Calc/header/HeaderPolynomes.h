#pragma once
#include "Header.h"

#define NB_POINTS 25


typedef struct coordonnees CoordonneesPoints;
struct coordonnees {
	double pointX;
	double pointY;
};

double fonctionPolynomes(int nbPoints, CoordonneesPoints coordonnees[], double iX);
double gestionMaxPoints(double* pYMax, CoordonneesPoints coordonneesPuissanceOxygene[]);