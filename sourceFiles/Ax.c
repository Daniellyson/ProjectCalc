#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int calculNombreIteration(int nbDecimales, int exponsant) {
	int nbIterations = 1;
	int erreurRelativeMax;
	double essai;

	erreurRelativeMax = calculErreurRelativeMax(nbDecimales);

	essai = ((exponsant / 2) * pow(0.5, (factorielle(factorielle(nbIterations + 1))))) / (factorielle(nbIterations + 1));

	while (essai > erreurRelativeMax) {
		nbIterations++;
		nbIterations = factorielle(nbIterations);
		essai = ((exponsant / 2) * pow(0.5, (factorielle(nbIterations + 1)))) / (factorielle(nbIterations + 1));
	}

	return nbIterations;
}

int calculErreurRelativeMax(int nbDecimalesNecessaire) {
	int erreurRelativeMax = 0.5;
	int nombre = 10;
	int nbDeci;

	while (nbDecimalesNecessaire > 0) {
		nombre *= 10;
		nbDecimalesNecessaire--;
	}

	return erreurRelativeMax *= (1 / nombre);
}

int calculNombreDecimalesNecessairePourChaqueTerme(int argMod, int nbDecimales) {
	int p;
	p = ((nbDecimales + (argMod - 0.5) * 0.5 + (argMod / 5) + 0.31) + 1);

	return p;
}

int calcul(double arg, int nbIterations) {
	int resultat = 1;
	int degre = 1;
	int resultatDegreI;

	while (degre <= nbIterations) {
		resultatDegreI = DegreN(arg, degre);
		resultat += resultatDegreI;
		degre++;
	}
	return resultat;
}

bool multipleDe05(double exposant) {
	bool multipleDe05;

	while (exposant > 0) {
		exposant -= 0.5;
	}

	multipleDe05 = (exposant == 0) ? true : false;

	return multipleDe05;
}

int degreN(int arg, int degre) {
	return pow(arg, degre) / (factorielle(degre));
}

int factorielle(int nombre) {
	int i = 0;
	int factorielle = 1;
	while (i < nombre) {
		factorielle *= nombre;
		nombre--;
	}
	return factorielle;
}