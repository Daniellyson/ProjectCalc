#include"HeaderAx.h"

void calculeExpBaseA() {
	double base, exposant, resultat, argMod, reste, arg, resultatPartiel, resultatDuReste;
	int nbDecimales, nbIterations, nbDecimalNecessaires, nombreDeFois05, i;
	bool negatif = false, multipleDe05;

	system("cls");
	printf("Base :");
	scanf_s("%lf", &base);
	printf("Exposant :");
	scanf_s("%lf", &exposant);
	printf("Nombre de decimales :");
	scanf_s("%d", &nbDecimales);
	system("cls");

	exposant *= log(base);

	if (exposant == 0) {
		resultat = 1;
	}
	else {
		if (exposant < 0) {
			negatif = true;
			exposant *= -1;
		}
		if (exposant < 0.5) {
			nbIterations = calculNombreIteration(nbDecimales);
			resultat = calcul(exposant, nbIterations);
		}
		else {
			multipleDe05 = estMultipleDe05(exposant);
			if (multipleDe05) {
				argMod = exposant;
			}
			else {
				argMod = ((int)((exposant * 2) + 1)) / 2;
			}
			nbDecimalNecessaires = calculNombreDecimalesNecessairePourChaqueTerme(argMod, nbDecimales);
			nbIterations = calculNombreIteration(nbDecimalNecessaires);
			nombreDeFois05 = (int)(exposant * 2);
			reste = exposant - (0.5 * (double)nombreDeFois05);
			arg = 0.5;
			resultatPartiel = calcul(arg, nbIterations);
			resultat = 1;
			i = nombreDeFois05;
			while (i > 0) {
				resultat *= resultatPartiel;
				i--;
			}
			if (reste > 0) {
				arg = reste;
				resultatDuReste = calcul(arg, nbIterations);
				resultat *= resultatDuReste;
			}
		}
		if (negatif) {
			resultat = 1 / resultat;
		}
	}
	printf("Resultat : %.10lf\n", resultat);
	system("pause");
	system("cls");
}

int calculNombreIteration(int nbDecimales) {
	int nbIterations = 1;
	double erreurRelativeMax;
	double essai;

	erreurRelativeMax = calculErreurRelativeMax(nbDecimales);

	essai = ((exp(1)) * pow(0.5, (nbIterations + 1))) / (factorielle(nbIterations + 1));

	while (essai > erreurRelativeMax) {
		nbIterations++;
		essai = ((exp(1)) * pow(0.5, (nbIterations + 1))) / (factorielle(nbIterations + 1));
	}

	return nbIterations;
}

double calculErreurRelativeMax(int nbDecimalesNecessaire) {
	double erreur = 0.5;
	int nombre = 10;

	while (nbDecimalesNecessaire > 0) {
		nombre *= 10;
		nbDecimalesNecessaire--;
	}

	return erreur *= (1 / (double)nombre);
}

int calculNombreDecimalesNecessairePourChaqueTerme(double argMod, int nbDecimales) {
	int p;
	p = ((int)(nbDecimales + (argMod - 0.5) * 0.5 + (argMod / 5) + 0.31) + 1);

	return p;
}

double calcul(double arg, int nbIterations) {
	double resultat = 1;
	int degre = 1;
	double resultatDegreI;

	while (degre <= nbIterations) {
		resultatDegreI = degreN(arg, degre);
		resultat += resultatDegreI;
		degre++;
	}
	return resultat;
}

bool estMultipleDe05(double exposant) {
	bool multipleDe05;

	while (exposant > 0) {
		exposant -= 0.5;
	}

	multipleDe05 = (exposant == 0) ? true : false;

	return multipleDe05;
}

double degreN(double arg, int degre) {
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