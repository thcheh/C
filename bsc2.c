#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define epsilon 0.000001


double wynik (double x)
{
	return pow(x-1,3);
}

void bisekcja (double x1, double x2)
{
	if(wynik(x1)*wynik(x2) >= 0)
	{
		printf("Wprowadz inne wartosci dla x1 i x2 lub zmien funkcje");
		return;
	}
	double y = x1;
	while((x2-x1) >= epsilon)
	{
		y = (x1+x2)/2; // - znajduje punkt srodkowy
		if(wynik(y) == 0.0) // - sprawdza czy punkt srodkowy jest pierwiastkiem funkcji - x0
			break;
		else if (wynik(y)*wynik(x1) < 0) // sprawdza z ktorej strony powtorzyc kroki
			x2 = y;
		else
			x1 = y;
	}
	printf("Wartosc dla x0 wynosi: %f", y);
}

main()
{
	double x1 = -10;
	double x2 = 10;
	bisekcja(x1,x2);	
}