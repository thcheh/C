#include <stdio.h>
#include <math.h>
#include <stdio.h>

/* THC - zabawa - ANSI-C \PL */

void szukaj_czy_pierwsza (int liczba)
{
   int i = 2;
   
   while ( pow(i,2) < liczba )
   {
      if ( liczba % i == 0 ) break;
      i = ++i;
   }

   if(pow(i,2) > liczba || liczba == 1) printf("Liczba %d jest liczba pierwsza\n",liczba);
   else printf("Liczba %d nie jest liczba pierwsza\n",liczba);
}

int main()
{
   int liczba = 0;

   printf("Wprowadz liczbe: "); 
   do{
		scanf("%d", &liczba);
   }while(liczba<=0);
   
   szukaj_czy_pierwsza(liczba);
   
   return 0;
}
