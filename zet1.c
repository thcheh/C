#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void wylosuj_liczbe (int *wsk_tab)
{
	int seed,i;
	seed=time(NULL);
	srand(seed);
	for(i=0;i<8;i++)
	{
	*(wsk_tab+i)=rand()*10.0/RAND_MAX;	
	}
}

void wyswietl_liczbe (int *wsk_tab)
{
	int i;
	for(i=0;i<8;i++)
	{
		printf("%d", wsk_tab[i]);
	}
}

int zsumuj_liczbe (int *wsk_tab)
{
	int i,suma;
	for(i=0,suma=0;i<8;i++)
	{
		suma=wsk_tab[i]+suma;
	}
	
	printf("\nSuma: %d", suma);
}
main()
{
	int suma;
	int liczba[8];
	int *wsk_tab;
	wsk_tab=&liczba[0];
	wylosuj_liczbe(wsk_tab);
	wyswietl_liczbe(wsk_tab);
	zsumuj_liczbe(wsk_tab);
}