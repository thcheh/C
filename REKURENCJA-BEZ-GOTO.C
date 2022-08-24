#include <stdio.h>

int rekurencja (int n)
{
	if (n==1) return 1;
	if (n==2) return 2;
	else
	{
		return (3*(rekurencja(n-1)))-(2*(rekurencja(n-2)));
	}
}

main()
{
	int i;
	i=0; //dla i przypisana wartosc 0, zeby nizej zainicjowac petle
	
	while (i<=0 || i>20) //ograniczone od 1 (dla 0 i liczb ujemnych wyrzuca z programu) do max 20, (dla wiekszych wartosci wyrzuca z programu)
	{
		printf("Podaj wartosc dla n [1-20]: ");
		scanf("%d", &i);
		if (i<=0 || i>20) printf("Wprowadz dla n wartosc wieksza od 0 w zakresie 1-20!\n");
	}
	
	printf("Koncowy wynik to: %d", rekurencja(i));
	
}
