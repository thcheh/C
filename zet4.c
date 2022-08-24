#include <stdio.h>

void uzupelnij_tablice_skladowymi (int *tp, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("TAB[%d] = ", i+1);
		scanf("%d", &tp[i]);
	}
	printf("Wprowadzone dane:\n");
	for(i=0;i<n;i++)
	{
		printf("TAB[%d] = %d\n", i+1, tp[i]);
	}
	
}

int iloczyn_hadamarda(int *tp1, int *tp2, int n)
{
	int i,iloczyn;
	FILE *plik = NULL;
	plik = fopen("zadanie_2.txt","a");
	if(plik != NULL)
	{
	for(i=0;i<n;i++)
	{
		iloczyn=tp1[i]*tp2[i];
		fprintf(plik,"u[%d]*v[%d] = %d * %d = %d\n", i+1,i+1,tp1[i],tp2[i],iloczyn);
	}
	fclose( plik );
	}
	else
	{
		printf("Wystapil blad przy otwieraniu pliku %s\n","zadanie_2.txt");
	}
}

int main()
{
	int n;
	int tab1[n];
	int tab2[n];
	int *wsk_tab1;
	wsk_tab1=&tab1[0];
	int *wsk_tab2;
	wsk_tab2=&tab2[0];
	printf("Podaj ilosc skladowych wektorow: ");
	scanf("%d", &n);
	printf("Uzupelnij dane pierwszej tablicy:\n");
	uzupelnij_tablice_skladowymi(wsk_tab1,n);
	printf("Uzupelnij dane drugiej tablicy:\n");
	uzupelnij_tablice_skladowymi(wsk_tab2,n);
	printf("Wpisywanie danych do pliku zadanie_2.txt...");
	iloczyn_hadamarda(wsk_tab1, wsk_tab2, n);
}