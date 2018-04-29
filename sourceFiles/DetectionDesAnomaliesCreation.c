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


//DOING
int obtention(int * alphaControl, int * alphaWarning, double * moyenne, double * ecartType) {
	
}