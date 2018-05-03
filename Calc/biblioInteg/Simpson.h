#include <stdio.h>
# include <stdbool.h>
#include <math.h>

typedef double(*Fonction)(double); 
double calculSimpson(int, double, double, Fonction);

