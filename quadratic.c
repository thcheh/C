#include <stdio.h>
#include <math.h>

/* THC - fun - ANSI-C
PL' comments
*/

struct kwadratowa
{
	float a;
	float b;
	float c;
};

struct kwadratowa dane()
{
	struct kwadratowa f;
	
	do{
		printf("Podaj wartosc dla a: ");
		scanf("%f", &f.a);
	}while(f.a==0);
		printf("Podaj wartosc dla b: ");
		scanf("%f", &f.b);
		printf("Podaj wartosc dla c: ");
		scanf("%f", &f.c);
	
	return f;
}

float delta(struct kwadratowa f)
{
	return pow(f.b,2) - (4*f.a*f.c);
}

int main()
{
	struct kwadratowa f;
	printf("Podaj wspolczynniki dla funkcji ax^2+bx+c aby obliczyc delte:\n");
	f=dane();
	printf("Delta wynosi: %f", delta(f));
	
}
