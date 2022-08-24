#include <stdio.h>


int fib_it(int n)
{
	int f=1, fp=0, k;
	if(n==0) return 0;
	while(n>1)
	{
		k=f+fp;
		fp=f;
		f=k;
		n--;
	}
	return f;
}

int fib_rek(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	return fib_rek(n-1)+fib_rek(n-2);	
}

main()
{
	int n,i;
	printf("program liczy nty element ci¹gu Fibonacciego.\n Podaj n: ");
	scanf("%d", &n);
	printf("Ciag fibonacciego wyznacany iteracyjnie:\n");
	for(i=0; i<=n; i++)
	{
		printf("wartosc wyrazu: %d ciagu Fib: %d\n", i, fib_it(i)); 
	}
	
	printf("Ciag fibonacciego wyznacany rkurencyjnie:\n");
	for(i=0; i<=n; i++)
	{
		printf("wartosc wyrazu: %d ciagu Fib: %d\n", i, fib_rek(i)); 
	}
	
}
