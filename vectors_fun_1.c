#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* 
    THC
    zabawa
    ANSI-C \pl
*/

//Funkcja wczytujaca wartosci skladowych (podawanych z klawiatury) dla 1 wektora
void wczytaj(float *wsk_wektora, int n)
{
	int i;
	printf("Podaj skladowe dla pierwszego wektora:\n");
	for(i=0;i<n;i++)
	{
		printf("[W2] - SKLADOWA[%d] = ", i+1);
		scanf("%f", wsk_wektora+i);
	}
}

//Funkcja wypelniajaca wektor2
void wypelnij_w2 (float *wsk_wektora, int n)
{
	int i;
	for(i=0; i<n; i++){
		*(wsk_wektora+i)=sqrt((i+1)*n)+4/7;
	}
}

//Funkcja wypelniajaca 3 wektor liczbami pseudolosowymi
void wypelnij_w3 (float *wsk_wektora, int n)
{
//do wygenerowania liczb pseudolosowych
	int seed, i;
	seed=time(NULL);
	srand(seed);
	for(i=0; i<n; i++){
		*(wsk_wektora+i)=rand()*1.0/RAND_MAX;
	}
}

//Funkcja wypelniajaca 4 wektor liczbami pseudolosowymi w zakresie 0-100
void wypelnij_w4 (float *wsk_wektora, int n)
{
//do wygenerowania liczb pseudolosowych
	int seed, i;
	seed=time(NULL);
	srand(seed);
	for(i=0; i<n; i++){
		*(wsk_wektora+i)=rand()*100/RAND_MAX;
	}
}

//Utworzenie wektora 5 ze skladowymi jako suma skladowych wszystkich poprzednich wektorow
void wektor_suma(float *wsk_wektora1, float *wsk_wektora2, float *wsk_wektora3, float *wsk_wektora4, float *wsk_wektora5, int n)
{
	int i;
	while(i<n)
	{
		wsk_wektora5[i] = wsk_wektora1[i]+wsk_wektora2[i]+wsk_wektora3[i]+wsk_wektora4[i];
		i++;
	}
	
}

//FUNKCJA WYSWIETLA SKLADOWE WEKTOROW
void wyswietl (float *wsk_wektora, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Skladowa [%d] wektora to: %f\n", i+1, *(wsk_wektora+i));
	}
}

//FUNKCJA OBLICZAJACA SUME SKLADOWYCH WEKTORA
float suma(float *wsk_wektor, int n)
{
	int i;
	float s=0;
	for(i=0;i<n;i++)
	{
		s=s+*(wsk_wektor+i);
	}
	return s;
}

//FUNKCJA OBLICZAJACA ILOCZYN SKLADOWYCH WEKTORA

float iloczyn(float *wsk_wektora, int n)
{
	int i;
	float iloczyn;
	iloczyn=1.0;
	for(i=0;i<n;i++)
	{
		iloczyn=iloczyn*wsk_wektora[i];
	}
	return iloczyn;
}

main()
{
	int w;
	int i;
	int n=0; //przypisana wartosc 0 by dalej w kodzie zainicjowac petle while
	float wektor1[10];
	float wektor2[10];
	float wektor3[10];
	float wektor4[10];
	float wektor5[10];
	float *w1;
	float *w2;
	float *w3;
	float *w4;
	float *w5;
	w1=&wektor1[0];
	w2=&wektor2[0];
	w3=&wektor3[0];
	w4=&wektor4[0];
	w5=&wektor5[0];
	
	//PETLA W KTOREJ WPROWADZAMY N W ZAKRESIE 1-10
		do{
		printf("Wprowadz liczbe skladowych dla wektorow [1-10]: ");
		scanf("%d", &n);
	}while(n<1 || n>10);
	
	wczytaj(w1,n);
	wypelnij_w2(w2,n);
	wypelnij_w3(w3,n);
	wypelnij_w4(w4,n);
	wektor_suma(w1,w2,w3,w4,w5,n);
	printf("Wyswietlam skladowe dla 1 wektora:\n");
	wyswietl(w1,n);
	printf("Wyswietlam skladowe dla 2 wektora:\n");
	wyswietl(w2,n);
	printf("Wyswietlam skladowe dla 3 wektora:\n");
	wyswietl(w3,n);
	printf("Wyswietlam skladowe dla 4 wektora:\n");
	wyswietl(w4,n);
	printf("Wyswietlam skladowe dla 5 wektora:\n");
	wyswietl(w5,n);
	printf("Wyswietlic sume (1) czy iloczyn (2) skladowych wygenerowanych wektorow\?\n");
	printf("Wybor: ");
	scanf("%d", &w);
	switch(w)
	{
		case 1:
			printf("Suma skladowych 1 wektora = %f\n", suma(w1,n));
			printf("Suma skladowych 2 wektora = %f\n", suma(w2,n));
			printf("Suma skladowych 3 wektora = %f\n", suma(w3,n));
			printf("Suma skladowych 4 wektora = %f\n", suma(w4,n));
			printf("Suma skladowych 5 wektora = %f\n", suma(w5,n));
			break;
		case 2:
			printf("Iloczyn skladowych 1 wektora = %f\n", iloczyn(w1,n));
			printf("Iloczyn skladowych 2 wektora = %f\n", iloczyn(w2,n));
			printf("Iloczyn skladowych 3 wektora = %f\n", iloczyn(w3,n));
			printf("Iloczyn skladowych 4 wektora = %f\n", iloczyn(w4,n));
			printf("Iloczyn skladowych 5 wektora = %f\n", iloczyn(w5,n));
			break;
		default:
			printf("\nNieznana operacja!");
	}

}
