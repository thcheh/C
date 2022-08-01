#include <stdio.h>

/*
	A: THC
	C: zabawa
	lang: PL
  ANSI-C
*/

int tab_wyswietl (int *tp)
{
	FILE *plik = NULL;
	plik = fopen("zadanie_1.txt","w");
	if(plik != NULL)
	{
	int i;
	fprintf(plik,"Wartosci w tablicy:\n");
	for(i=0;i<10;i++)
	{
		fprintf(plik,"TAB [%d] = %d\n", i+1, tp[i]);
	}	
	fprintf(plik,"Adresy elementow tablicy:\n");
	for(i=0;i<10;i++)
	{
		fprintf(plik,"TAB [%d] = %d\n", i+1, &tp[i]);
	}
      fclose( plik );
	}
	else
	{
		printf("Wystapil blad przy otwieraniu pliku %s\n","zadanie_1.txt");
	}
}

int main()
{
	int tablica[10] = {11,12,13,14,15,16,17,18,19,20};
	int *wsk_tablica;
	wsk_tablica=&tablica[0];
	tab_wyswietl(wsk_tablica);
	printf("Dane zapisano w pliku zadanie_1.txt");
}
