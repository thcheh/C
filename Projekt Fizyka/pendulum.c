#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	double A, l, g, omega, phi, T, t, x, v, a;
	FILE *plik = NULL;
	fopen_s(&plik, "dane.txt", "w+");
	if (plik==NULL) {
		perror("Error pliku");
		return 1;
	}
	do{
		printf("Podaj wartosc wychylenia wahadla w stopniach: ");
		scanf_s("%lf", &phi);
	} while(phi<0 || phi>90);
	do {
		printf("\nPodaj dlugosc wahadla: ");
		scanf_s("%lf", &l);
	} while (l <= 0);
	
	do {
		printf("\nPodaj wartosc przyspieszenia grawitacyjnego: ");
		scanf_s("%lf", &g);
	} while (g == 0);
	

	l = 0.01 * l;
	omega = sqrt(g / l);
	phi = M_PI * phi / 180;
	A = sin(phi)*l;
	T = 2 * M_PI / omega;

	fputs("t[s]\tx(t)[m]\tv(t)[m/s]\ta(t)[m/s^2]", plik);

	for (t = 0; t <= 2*T; t = t + 0.02*T) {
		x = A * cos(omega * t + phi);
		v = -A * omega * sin(omega * t + phi);
		a = -A * pow(omega, 2) * cos(omega * t + phi);
		fprintf(plik, "\n%.6lf\t%.6lf\t%.6lf\t%.6lf", t, x, v, a);
	}

	fclose(plik);
	system("python wykres_x.py");
	system("python wykres_v.py");
	system("python wykres_a.py");
	
	return 0;
}