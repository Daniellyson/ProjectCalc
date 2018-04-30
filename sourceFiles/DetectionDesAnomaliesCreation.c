#include "HeaderAnomalies.h"

void detectionDesAnomalies(void) {
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

	system("pause");
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

	while (!feof(fiModele)) {
		fscanf_s(fiModele, "%lf", &valeur);

		sommeX += valeur;

		sommeXCarre += valeur * valeur;

		nbValeur++;

		//fiModele = lectureFichier();
	}

	*moyenne = sommeX / nbValeur;

	variance = (sommeXCarre / nbValeur) - (*moyenne) * (*moyenne); 

	*ecartType = sqrt(variance);

	fclose(fiModele);

	return n;
}

int obtentionUtilisateur(int * alphaControl, int * alphaWarning) {

	int n;

	prinft("Tapez la valeur pour n :");
	scanf_s("%d", &n);

	prinft("Tapez la valeur pour alphaControl :");
	scanf_s("%lf", *alphaControl);

	prinft("Tapez la valeur pour alphaWarning :");
	scanf_s("%lf", *alphaWarning);

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