#include"HeaderPolynomes.h"

void decrypteCleShamir() {
	double x, y, clefSecrete;
	int i, nbPoints;
	CoordonneesPoints coordonneesPoints[NB_POINTS];
	
	system("cls");
	printf("nombre de points :");
	scanf_s("%d", &nbPoints);
	i = 0;
	while (i < nbPoints) {
		printf("%d x :", i+1);
		scanf_s("%lf", &x);
		printf("%d y :", i + 1);
		scanf_s("%lf", &y);
		coordonneesPoints[i].pointX = x;
		coordonneesPoints[i].pointY = y;
		i++;
	}
	y = fonctionPolynomes(nbPoints, coordonneesPoints, 0.0);
	clefSecrete = y;
	system("cls");
	printf("cle secrete : %f\n", clefSecrete);
	viderBuffer();
	system("pause");
	system("cls");
}

double fonctionPolynomes(int nbPoints, CoordonneesPoints coordonnees[], double iX) {
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

void calculeMaxPuissance() {
	double x, y, xMax, yMax;
	int i = 0;
	
	CoordonneesPoints coordonneesPuissanceOxygene[5];

	system("cls");
	while (i < 5) {
		printf("Entrez le x : ");
		scanf_s("%lf", &x);
		printf("Entrez le y : ");
		scanf_s("%lf", &y);

		coordonneesPuissanceOxygene[i].pointX = x;
		coordonneesPuissanceOxygene[i].pointY = y;

		i++;
	}

	xMax = gestionMaxPoints(&yMax, coordonneesPuissanceOxygene);

	printf("xMax : %lf\nyMax : %lf\n", xMax, yMax);

	system("pause");
	system("cls");
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
