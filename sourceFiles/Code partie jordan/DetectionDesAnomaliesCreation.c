#include "HeaderAnomalies.h"
#include "Header.h"

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


	n = obtention(&alphaControl, &alphaWarning, &moyenne, &ecartType);

	upperControlLimit = calculIntervalle(&lowerControlLimit, moyenne, ecartType, alphaControl, n);

	upperWarningLimit = calculIntervalle(&lowerWarningLimit, moyenne, ecartType, alphaWarning, n);

	printf("Moyenne : %.2lf \n", moyenne);
	printf("Ecart type : %.2lf \n", ecartType);
	printf("Lower control limit : %.2lf \n", lowerControlLimit);
	printf("Upper control limit : %.2lf \n", upperControlLimit);
	printf("Lower warning limit : %.2lf \n", lowerWarningLimit);
	printf("Upper warning limit : %.2lf \n", upperWarningLimit);

	getchar();
}


int obtention(int * alphaControl, int * alphaWarning, double * moyenne, double * ecartType) {
	FILE * fiModele;
	double valeur;
	int n;
	int nbValeur = 0;
	double sommeX = 0;
	double sommeXCarre = 0;
	double variance;

	n = obtentionUtilisateur(alphaControl, alphaWarning);

	fiModele = lectureFichier();
	fscanf_s(fiModele, "%lf", &valeur);

	while (!feof(fiModele)) {
	

		sommeX += valeur;

		sommeXCarre += valeur * valeur;

		nbValeur++;

		fscanf_s(fiModele, "%lf", &valeur);
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

FILE * lectureFichier() {
	FILE * pFicher; 

	fopen_s(&pFicher, FIMODELE, "r");

	return pFicher;
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