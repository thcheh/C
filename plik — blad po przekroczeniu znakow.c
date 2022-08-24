#include <stdio.h>
#include <stdlib.h>

int arraySize(char array[])
{
	int i;
	int cont = 0;
	for(i=0;array[i] != 0; i++)
	{
		cont++;
	}
	return cont;
}

int main()
{
	char in[20] = { 0 };
	printf("Wprowadz swoje imie: ");
	scanf("%s", in);
	if(arraySize(in)>20)
	{
		printf("Przekroczyles limit znakow! MAX: 20!\n");
		return 0;
	}
	else
	{
	printf("Twoje imie to: %s, zapisuje je do pliku...", in);
	}
	FILE *plik = NULL;
	plik = fopen("plik.txt","a");
	if(plik != NULL)
	{
      fprintf(plik,"%s\n", in);
      fclose( plik );
	}
	else
	{
		printf("Wystapil blad przy otwieraniu pliku %s\n","plik.txt");
	}
	return 0;
}