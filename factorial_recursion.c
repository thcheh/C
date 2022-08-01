#include <stdio.h>

/* THC - fun - ANSI-C
\pl comm
*/

int silnia(int n)
{
   if( n<=1 ) return 1; 
   return n * silnia(n-1);
}

int main()
{
	int ns;
	printf("Program oblicza silnie\n");
	do{
		printf("Wprowadz wartosc dla n: ");
		scanf("%d", &ns);
	}while(ns<0);
	printf("Silnia dla %d wynosi %d", ns, silnia(ns) );
	//DZIALANIA NA PLIKACH
	FILE *plik=NULL;
	plik=fopen("silnia.txt", "w");
	if(plik==NULL){
		perror("Wystapil blad pliku!");
		return 1;
	}
	fprintf(plik,"Silnia dla %d wynosi %d", ns, silnia(ns) );
	fclose(plik);

	
}
