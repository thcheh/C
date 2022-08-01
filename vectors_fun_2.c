#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
THC - zabawa - ANSI-C - PL
prev. comm.
*/

//Funkcja wczytujaca skladowe dla 1 wektora, nalezy je wprowadzic z klawiatury
void wczytaj(float *wsk_wektora)
{
	int i;
	printf("Podaj skladowe dla pierwszego wektora:\n");
	for(i=0;i<10;i++)
	{
		printf("[W1] - SKLADOWA[%d] = ", i+1);
		scanf("%f", wsk_wektora+i);
	}
}

//Funkcja wypelniajaca 2 wektor liczbami pseudolosowymi
void wypelnij (float *wsk_wektora)
{
//do wygenerowania liczb pseudolosowych
	int seed, i;
	seed=time(NULL);
	srand(seed);
	for(i=0; i<10; i++){
		*(wsk_wektora+i)=rand()*1.0/RAND_MAX;
	}
}

//Funkcja wyswietla skladowe wektorow
void wyswietl (float *wsk_wektora)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("Skladowa [%d] wektora to: %f\n", i+1, *(wsk_wektora+i));
	}
}

//Utworzenie wektora 3 ze skladowymi jako suma skladowych dwoch wczesniejszych wektorow
void wektor_suma(float *wsk_wektora1, float *wsk_wektora2, float *wsk_wektora3)
{
	int i;
	while(i<10)
	{
		wsk_wektora3[i] = wsk_wektora1[i]+wsk_wektora2[i];
		i++;
	}
	
}

main()
{
	//Deklaracje wektorow
	float wektor1[10];
	float wektor2[10];
	float wektor3[10];
	//Wskazniki dla wektorow
	float *w1;
	float *w2;
	float *w3;
	w1=&wektor1[0];
	w2=&wektor2[0];
	w3=&wektor3[0];
	wczytaj(w1); //Funkcja wczytujaca dane 1 wektora
	wypelnij(w2); //Funkcja wypelniajaca 2 wektor liczbami pseudolosowymi w zakresie <0,1>
	wektor_suma(w1,w2,w3); //Funkcja tworzaca wektor 3
	printf("Skladowe pierwszego wektora to:\n");
	wyswietl(w1); //Funkcja wyswietla skladowe wektora
	printf("Skladowe drugiego wektora to:\n");
	wyswietl(w2);
	printf("Skladowe trzeciego wektora to:\n");
	wyswietl(w3);


}
