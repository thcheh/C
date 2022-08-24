#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generateWektor1(float ww1, int n){
	//generuje wektor1 na zasadzie liczb pseudolosowych
	int seed, i;
	//seed zmienna która okreœla czas od rozpoczêcia epoki linuxa w sekundach
	seed = time(NULL);
	//rozpoczêcie generowania liczb pseudolosowych
	srand(seed);
	//pêtla w której wstawiane s¹ wartoœci do obszaru pamiêci wektora
	for(i=0; i<n; i++){
		*(wektor1+i)=rand()*5.0/RAND_MAX;
	}
}

void generateWektor2(float *wektor2, int n){
	//funkcja generuj¹ca wektor2 poprzez wpisywanie z klawiatury
	int i;
	//pêtla w której œrodku wype³niany zostaje wektor2
	for(i=0; i<n; i++){
		printf("Podaj %i skladowa wektora2: ", i+1);
		scanf("%f", &wektor2[i]);
	}
}

void wyswietlenie(float *wektor, int n){
	//funkcja pozwalaj¹ca na wyœwietlenie sk³adowych wektorów
	int i;
	//pêtla przechodz¹ca przez wszystkie wype³nione wartoœci sk³adowych wektorów i wypisuj¹ca ich wartoœæ
	for(i=0; i<n; i++){
		printf("%i skladowa wektora: %f\n", i+1 , *(wektor + i));
	}
}
float suma(float *wektor, int n){
	//funkcja wyliczaj¹ca sumê sk³adowych danego wektora
	int i;
	float suma=0;
	//pêtla w której wnêtrzu zliczana jest suma sk³adowych wektora
	for(i=0; i<n; i++){
		suma = suma + *(wektor + i);
	}
	return suma;
}

float iloczynSkalarny(float *wektor1, float *wektor2, int n){
	//funkcja obliczaj¹ca iloczyn skalarny
	int i;
	float suma=0;
	//pêtla która sumuje poszczególne wyrazy bo iloczyn skalarny liczy siê is=w1[0]*w2[0]+w1[1]*w2[1]... itd.
	for(i=0; i<n; i++){
		suma = suma + *(wektor1 + i)* *(wektor2 + i);
	}
	return suma;
}
int main(){
	int n, i;
	float wektor1[10];
	float wektor2[10];
	//deklaracja pliku wyjœciowego
	FILE *plik=NULL;
	plik=fopen("wektor.txt", "w");
	//sprawdzanie czy plik powsta³
	if(plik==NULL){
		perror("blad pliku");
		return 1;
	}
	//pêtla pozwalaj¹ca okreœliæ n które bêdzie ogranicza³o d³ugoœæ wektorów
	do{
		printf("wybierz jak duzo skladowych maja posiadac oba wektory(1-10): ");
		scanf("%i", &n);
	}while(n<1 || n>10);
	//wywo³ywanie funkcji oraz zapisywanie do pliku
	generateWektor1(wektor1, n);
	generateWektor2(wektor2, n);
	printf("\n\nWektor1:\n");
	wyswietlenie(wektor1, n);
	fprintf(plik,"\nSuma skladowych Wektora1: %f\n", suma(wektor1, n));
	printf("\n\nWektor2:\n");
	wyswietlenie(wektor2, n);
	fprintf(plik, "\nSuma skladowych Wektora2: %f\n", suma(wektor2, n));
	fprintf(plik, "\nIloczyn skalarny tych wektorow rowna sie: %f", iloczynSkalarny(wektor1, wektor2, n));
	//zamkniêcie pliku
	fclose(plik);
	
	return 0;
}
