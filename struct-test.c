#include <stdio.h>
#include <math.h>

struct prostopadloscian
{
	float a;
	float b;
	float c;		
};


float przekatna (struct prostopadloscian p)
{
	float D;
	D=sqrt(pow(p.a,2)+pow(p.b,2)+pow(p.c,2));
	return D;
}

float pole (struct prostopadloscian p)
{
	float S;
	S=2*( (p.a*p.b) + (p.b*p.c) + (p.c*p.a) );
	return S;
}

float objetosc (struct prostopadloscian p)
{
	float V;
	V=p.a*p.b*p.c;
	return V;
}

int main()
{
	struct prostopadloscian p;
	p.a=0;
	p.b=0;
	p.c=0;
	printf("Podaj dlugosci krawedzi prostopadloscianu\n");

	while (p.a <= 0)
	{
		printf("a: ");
		scanf("%f", &p.a);
		if(p.a<=0) printf("Wprowadz dla A wartosc wieksza od 0!\n");
	}
	
	while (p.b <= 0)
	{
		printf("b: ");
		scanf("%f", &p.b);
		if(p.b<=0) printf("Wprowadz dla B wartosc wieksza od 0!\n");
	}
	
	
	while (p.c <= 0)
	{
		printf("c: ");
		scanf("%f", &p.c);
		if(p.c<=0) printf("Wprowadz dla C wartosc wieksza od 0!\n");
	}

	printf("\nWprowadzone wartosci to: a = %f | b = %f | c = %f \n", p.a, p.b, p.c);
	printf("Wyniki obliczen:\n");
	printf("Przekatna: %f\n", przekatna(p));
	printf("Pole: %f\n", pole(p));
	printf("Objetosc: %f\n", objetosc(p));
	
	return 0;
}

