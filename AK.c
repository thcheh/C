#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void wypiszI(int W[], int iS) {
	//wypisuje sk³adowe tablicy liczb ca³kowitych
	int i;
	printf("[");
	for (i = 0; i < iS; i++) {
		if (i != iS - 1) {
			printf("%i, ", W[i]);
		}
		else {
			printf("%i]", W[i]);
		}

	}
}

void wypiszF(float W[], int iS) {
	//wypisuje sk³adowe tablicy liczb rzeczywistych
	int i;
	printf("[");
	for (i = 0; i < iS; i++) {
		if (i != iS - 1) {
			printf("%f, ", W[i]);
		}
		else {
			printf("%f]", W[i]);
		}

	}
}

void PodpunktA(float W1[], int W2[], int iS) {
	//wypisuje sk³adowe wektora powstaj¹cego z sumy wektorów W1 i W2
	int i;
	float skladowa;
	printf("\nWektor powstajacy z sumy wektorow W1 i W2 ma postac:\n[");
	for (i = 0; i < iS; i++) {
		skladowa = W1[i] + W2[i];
		if (i != iS - 1) {
			printf("%f, ", skladowa);
		}
		else {
			printf("%f]", skladowa);
		}

	}
}

void PodpunktB(float W1[], int W2[], int iS) {
	//wypisuje sk³adowe wektora powstaj¹cego z iloczynu wektorów W1 i W2
	int i;
	float skladowa;
	printf("\nWektor powstajacy z iloczynu wektorow W1 i W2 ma postac:\n[");
	for (i = 0; i < iS; i++) {
		skladowa = W1[i] * W2[i];
		if (i != iS - 1) {
			printf("%f, ", skladowa);
		}
		else {
			printf("%f]", skladowa);
		}

	}
}

void PodpunktC(float W1[], int W2[], int iS) {
	//wypisuje sk³adowe wektora powstaj¹cego z ró¿nicy wektorów W1 i W2
	int i;
	float skladowa;
	printf("\nWektor powstajacy z roznicy wektorow W1 i W2 ma postac:\n[");
	for (i = 0; i < iS; i++) {
		skladowa = W1[i] - W2[i];
		if (i != iS - 1) {
			printf("%f, ", skladowa);
		}
		else {
			printf("%f]", skladowa);
		}

	}
}

float PodpunktD(float W1[], int W2[], int iS) {
	//Oblicza iloczyn skalarny który jest sum¹ iloczynów odpowiadaj¹cych sobie
	int i;
	float suma = 0;
	for (i = 0; i < iS; i++) {
		suma = suma + (W1[i] * W2[i]);
	}
	return suma;
}



int main() {
	int W2[10];
	float W1[10];
	int iloscSkladowych, i;
	int seed;
	seed = time(NULL);
	srand(seed);

	do {
		printf("Podaj ilosc skladowych wektora W1 od 3 do 10 skladowych: ");
		scanf_s("%i", &iloscSkladowych);
	} while (iloscSkladowych < 3 || iloscSkladowych>10);

	for (i = 0; i < iloscSkladowych; i++) {
		printf("Podaj wartosc %i skladowej wektora W1: ", i);
		scanf_s("%f", &W1[i]);
		W2[i] = rand() % 11;
	}
	printf("Wektor W1 ma postac: ");
	wypiszF(W1, iloscSkladowych);

	printf("\nWektor W2 ma postac: ");
	wypiszI(W2, iloscSkladowych);

	printf("\n\nPodpunkt A)\n");

	PodpunktA(W1, W2, iloscSkladowych);

	printf("\n\nPodpunkt B)\n");

	PodpunktB(W1, W2, iloscSkladowych);

	printf("\n\nPodpunkt C)\n");

	PodpunktC(W1, W2, iloscSkladowych);

	printf("\n\nPodpunkt D)\n");

	printf("\nIloczyn skalarny tych wektorow wynosi: %f\n\n\n", PodpunktD(W1, W2, iloscSkladowych));
}
