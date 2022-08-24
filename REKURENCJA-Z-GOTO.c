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
	poczatek:
	printf("Podaj wartosc dla n [1-20]: ");
	scanf("%d", &i);
	if (i<=0 || i>20){ //Zabezpieczenie, zeby za bardzo nie obciazac procesora, max dla n wynosi 20
		printf("Wprowadz dla n wartosc wieksza od 0 w zakresie 1-20!\n");
		goto poczatek;
	}
	else{
		printf("Koncowy wynik to: %d", rekurencja(i));
	}
	
}
