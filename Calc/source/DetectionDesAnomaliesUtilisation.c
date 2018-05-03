#include "HeaderAnomalies.h"

void detecteAnomalies(void) {
	int numeroEchantillon = 0;
	int i = 0;
	double sommeValeurs = 0;
	double moyenne;

	int n;
	double ucl, lcl, uwl, lwl, valeur;

	char message[TAILLE_MESSAGE];

	FILE * fiTest = NULL;

	system("cls");

	printf("Encodez la valeur pour le UCL :");
	scanf_s("%lf", &ucl);

	printf("Encodez la valeur pour le LCL :");
	scanf_s("%lf", &lcl);

	printf("Encodez la valeur pour le UWL :");
	scanf_s("%lf", &uwl);

	printf("Encodez la valeur pour le LWL :");
	scanf_s("%lf", &lwl);

	printf("Encodez la valeur pour le n :");
	scanf_s("%d", &n);

	system("cls");

	fopen_s(&fiTest, FITEST, "r");

	fscanf_s(fiTest, "%lf,", &valeur);

	while (!feof(fiTest)) {
		i++;
		sommeValeurs += valeur;

		if (i == n) {
			numeroEchantillon++;

			moyenne = sommeValeurs / n;
			controleMoyenne(ucl, lcl, uwl, lwl, moyenne, message);

			printf("Echantillon %d : %s (%lf)\n", numeroEchantillon, message, moyenne);

			i = 0;
			sommeValeurs = 0;
		}

		fscanf_s(fiTest, "%lf,", &valeur);
	}

	fclose(fiTest);
	viderBuffer();
	system("pause");
	system("cls");
}

void controleMoyenne(double UCL, double LCL, double UWL, double LWL, double moyenneATest, char message[]) {
	

	if (LWL < moyenneATest && moyenneATest < UWL) {
		strcpy_s(message, sizeof(char)*TAILLE_MESSAGE, "moyenne dans les limites");
	}
	else if (moyenneATest < LCL || moyenneATest > UCL) {
		strcpy_s(message, sizeof(char)*TAILLE_MESSAGE, "alerte controle");
	}
	else {
		strcpy_s(message, sizeof(char)*TAILLE_MESSAGE, "alerte warning");
	}
}
