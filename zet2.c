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
		printf("%d ", wsk_tab[i]);
	}
}

void usun_liczbe (int *wsk_tab, int c)
{
	int i;
	for(i=0;i<8;i++)
	{
		if (wsk_tab[i] == c)
		{
			printf("");
		}
		else
		{
			printf("%d ", wsk_tab[i]);
		}
	}
}

main()
{
	int liczba[8];
	int c;
	int *wsk_tab;
	wsk_tab=&liczba[0];
	printf("Losowanie liczb do tablicy...\n");
	wylosuj_liczbe(wsk_tab);
	printf("Wylosowane liczby:\n");
	wyswietl_liczbe(wsk_tab);
	printf("\nKtora liczbe chcesz usunac? Wybor: ");
	scanf("%d", &c);
	printf("Usuwanie liczby %d z tablicy...\n",c);
	usun_liczbe(wsk_tab,c);
}