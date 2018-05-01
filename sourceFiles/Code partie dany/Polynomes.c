#include"HeaderPolynomes.h"

void decrypterCleShamir() {
	double x, y, clefSecrete;
	int i, nbPoints;
	CoordonneesPoints coordonneesPoints[NB_POINTS];

	scanf_s("%d", &nbPoints);
	i = 0;
	while (i < nbPoints) {
		scanf_s("%f", &x);
		scanf_s("%f", &y);
		coordonneesPoints[i].pointX = x;
		coordonneesPoints[i].pointY = y;
		i++;
	}
	y = fonctionPolynomes(nbPoints, coordonneesPoints, 0);
	clefSecrete = y;
	printf("cle secrete : %f", clefSecrete);
}

double fonctionPolynomes(int nbPoints, CoordonneesPoints coordonnees[], int iX) {
	double y, numerateur, denominateur;
	int i, j;

	y = 0;
	i = 0; 
	while (i < nbPoints) {
		numerateur = 1;
		denominateur = 1;
		j = 0;
		while (j < nbPoints) {
			if (i != j) {
				numerateur *= (iX - coordonnees[j].pointX);
				denominateur *= (coordonnees[i].pointX - coordonnees[j].pointX);
			}
			j++;
		}
		if (denominateur != 0) {
			y += (numerateur / denominateur) * coordonnees[i].pointY;
		}
		i++;
	}
	return y;
}

void maxPolynome() {
	double x, y;
	int i = 0;

	CoordonneesPoints coordonneesPuissanceOxygene[5];

	while (i < 5) {
		printf("Entrez le x : ");
		scanf_s("%lf", &x);
		printf("Entrez le y : ");
		scanf_s("%lf", &y);
		system("cls");

		coordonneesPuissanceOxygene[i].pointX = x;
		coordonneesPuissanceOxygene[i].pointY = y;

		i++;
	}

	double xMax, yMax;

	xMax = gestionMaxPoints(&yMax, coordonneesPuissanceOxygene);

	printf("xMax : %lf\nyMax : %lf", xMax, yMax);

	system("pause");
}

double gestionMaxPoints(double* pYMax, CoordonneesPoints coordonneesPuissanceOxygene[]) {
	int nbPoints = 5;
	double yMax = 0;
	double xMax;
	double iX = coordonneesPuissanceOxygene[0].pointX;
	double iFin = coordonneesPuissanceOxygene[4].pointX;
	double y;

	while (iX <= iFin) {
		y = fonctionPolynomes(nbPoints, coordonneesPuissanceOxygene, iX);

		if (y >= *pYMax) {
			*pYMax = y;
			xMax = iX;
		}
		iX += 0.01;
	}

	return xMax;
}
