#include "HeaderAnomalies.h"


void determineModeleAnomalies(void) {
	int n;
	int alphaControl; 
	int alphaWarning;
	double moyenne;
	double ecartType;

	double upperControlLimit;
	double lowerControlLimit;

	double upperWarningLimit;
	double lowerWarningLimit;

	system("cls");

	n = obtention(&alphaControl, &alphaWarning, &moyenne, &ecartType);

	upperControlLimit = calculIntervalle(&lowerControlLimit, moyenne, ecartType, alphaControl, n);

	upperWarningLimit = calculIntervalle(&lowerWarningLimit, moyenne, ecartType, alphaWarning, n);

	system("cls");

	printf("Moyenne : %.2lf \n", moyenne);
	printf("Ecart type : %.2lf \n", ecartType);
	printf("Lower control limit : %.2lf \n", lowerControlLimit);
	printf("Upper control limit : %.2lf \n", upperControlLimit);
	printf("Lower warning limit : %.2lf \n", lowerWarningLimit);
	printf("Upper warning limit : %.2lf \n", upperWarningLimit);

	viderBuffer();
	system("pause");
	system("cls");
}


int obtention(int * alphaControl, int * alphaWarning, double * moyenne, double * ecartType) {
	FILE * fiModele = NULL;
	double valeur;
	int n;
	int nbValeur = 0;
	double sommeX = 0;
	double sommeXCarre = 0;
	double variance;

	n = obtentionUtilisateur(alphaControl, alphaWarning);

	fopen_s(&fiModele, FIMODELE, "r");

	fscanf_s(fiModele, "%lf,", &valeur);

	while (!feof(fiModele)) {
	
		sommeX += valeur;

		sommeXCarre += valeur * valeur;

		nbValeur++;

		fscanf_s(fiModele, "%lf,", &valeur);
	}

	*moyenne = sommeX / nbValeur;

	variance = (sommeXCarre / nbValeur) - (*moyenne) * (*moyenne); 

	*ecartType = sqrt(variance);

	fclose(fiModele);

	return n;
}

int obtentionUtilisateur(int * alphaControl, int * alphaWarning) {

	int n;

	printf("Tapez la valeur pour n :");
	scanf_s("%d", &n);

	printf("Tapez la valeur pour alphaControl :");
	scanf_s("%d", alphaControl);

	printf("Tapez la valeur pour alphaWarning :");
	scanf_s("%d", alphaWarning);

	return n;
}

double fonctionLoiNormal(double x) {
	double racineQuotient;
	double xCarre;
	double exponentiel;

	racineQuotient = sqrt(2 * PI);

	xCarre = x * x;

	exponentiel = exp((-xCarre) / 2);

	return (1 / racineQuotient) * exponentiel;
}

double rechercheA(double tauxAcceptation) {
	double aMax = 3.99;
	double aMin = 0;
	double aMid;
	double diffTauxAcceptationEtProbaTable;
	double probabiliteTable;
	Fonction f = fonctionLoiNormal;

	do
	{
		aMid = (aMax + aMin) / 2;

		probabiliteTable = calculSimpson(75, 0, aMid, f);

		probabiliteTable += 0.5;

		if (probabiliteTable < tauxAcceptation) {
			aMin = aMid;
		}
		else {
			aMax = aMid;
		}

		diffTauxAcceptationEtProbaTable = fabs(tauxAcceptation - probabiliteTable);

	} while (diffTauxAcceptationEtProbaTable > 0.000005);

	return aMid;
}

double calculIntervalle(double * lowerLimit, double moyenne, double ecartType, int alpha, int n) {
	double a = rechercheA(1 - ((double) alpha / 200));

	double racineN = sqrt(n);

	double demiLongueurInterval = a * (ecartType / racineN);
	double UpperLimit = moyenne + demiLongueurInterval;
	*lowerLimit = moyenne - demiLongueurInterval;

	return UpperLimit;
}
