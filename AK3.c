#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generateWektor1(float ww1, int n){
	//generuje wektor1 na zasadzie liczb pseudolosowych
	int seed, i;
	//seed zmienna kt�ra okre�la czas od rozpocz�cia epoki linuxa w sekundach
	seed = time(NULL);
	//rozpocz�cie generowania liczb pseudolosowych
	srand(seed);
	//p�tla w kt�rej wstawiane s� warto�ci do obszaru pami�ci wektora
	for(i=0; i<n; i++){
		*(wektor1+i)=rand()*5.0/RAND_MAX;
	}
}

void generateWektor2(float *wektor2, int n){
	//funkcja generuj�ca wektor2 poprzez wpisywanie z klawiatury
	int i;
	//p�tla w kt�rej �rodku wype�niany zostaje wektor2
	for(i=0; i<n; i++){
		printf("Podaj %i skladowa wektora2: ", i+1);
		scanf("%f", &wektor2[i]);
	}
}

void wyswietlenie(float *wektor, int n){
	//funkcja pozwalaj�ca na wy�wietlenie sk�adowych wektor�w
	int i;
	//p�tla przechodz�ca przez wszystkie wype�nione warto�ci sk�adowych wektor�w i wypisuj�ca ich warto��
	for(i=0; i<n; i++){
		printf("%i skladowa wektora: %f\n", i+1 , *(wektor + i));
	}
}
float suma(float *wektor, int n){
	//funkcja wyliczaj�ca sum� sk�adowych danego wektora
	int i;
	float suma=0;
	//p�tla w kt�rej wn�trzu zliczana jest suma sk�adowych wektora
	for(i=0; i<n; i++){
		suma = suma + *(wektor + i);
	}
	return suma;
}

float iloczynSkalarny(float *wektor1, float *wektor2, int n){
	//funkcja obliczaj�ca iloczyn skalarny
	int i;
	float suma=0;
	//p�tla kt�ra sumuje poszczeg�lne wyrazy bo iloczyn skalarny liczy si� is=w1[0]*w2[0]+w1[1]*w2[1]... itd.
	for(i=0; i<n; i++){
		suma = suma + *(wektor1 + i)* *(wektor2 + i);
	}
	return suma;
}
int main(){
	int n, i;
	float wektor1[10];
	float wektor2[10];
	//deklaracja pliku wyj�ciowego
	FILE *plik=NULL;
	plik=fopen("wektor.txt", "w");
	//sprawdzanie czy plik powsta�
	if(plik==NULL){
		perror("blad pliku");
		return 1;
	}
	//p�tla pozwalaj�ca okre�li� n kt�re b�dzie ogranicza�o d�ugo�� wektor�w
	do{
		printf("wybierz jak duzo skladowych maja posiadac oba wektory(1-10): ");
		scanf("%i", &n);
	}while(n<1 || n>10);
	//wywo�ywanie funkcji oraz zapisywanie do pliku
	generateWektor1(wektor1, n);
	generateWektor2(wektor2, n);
	printf("\n\nWektor1:\n");
	wyswietlenie(wektor1, n);
	fprintf(plik,"\nSuma skladowych Wektora1: %f\n", suma(wektor1, n));
	printf("\n\nWektor2:\n");
	wyswietlenie(wektor2, n);
	fprintf(plik, "\nSuma skladowych Wektora2: %f\n", suma(wektor2, n));
	fprintf(plik, "\nIloczyn skalarny tych wektorow rowna sie: %f", iloczynSkalarny(wektor1, wektor2, n));
	//zamkni�cie pliku
	fclose(plik);
	
	return 0;
}
