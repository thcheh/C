
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
/*  Funnkcja wyszukuje najczesciej wystepujacą liczbę w ciągu n liczb. 
 *  Argumenty:
 *    t[] - tablica zawirajaca liczby calkowite,
 *    n   - ilosc elementow,
 *    x   - adres zmiennej do ktorej zostanie postawiona ilosc wystapien znalezionego elementu.
 *    Wartoscia zwracana jest liczba najczesciej wystepujaca.
 *    Jezeli ciag zawiera wiecej niz jedna wartosc dominujaca to zwracana jest pierwsza napotkana. */
int dominanta2(const int *t, int n, int *c)
{
   int i, j, k, x;
  
   *c=0;
   x=t[0]-1;
   i=0;
   while( i<n-*c )
   {
      if( t[i]!=x )
      {
         k=1;
         j=i+1;
         while( j<n )
         {
            if ( t[i]==t[j] ) k = k + 1;
            j = j + 1;   
         }
         if( k > *c ) 
         {
            *c = k;
            x = t[i];
         }
      }
      i = i + 1;
   }
   return x;
}

int *wczytaj(int *t, int n)
{
   int i=0;

   printf("Podaj %d liczb calkowitych\n",n);
   while(i<n)
   {
      scanf("%d",t+i);
      i = i + 1;
   }
   return t;
}

int main()
{
   int n, x, i;
   int t[MAX];

   printf("Ile liczb (nie wiecej niz %d) ? ", MAX); 
   scanf("%d",&n);

   if(n<1 || n>MAX) 
   {
      printf("Niepoprawna wartosc\n");
      exit(1);
   }
   
   wczytaj(t,n); 
   x = dominanta2(t, n, &i);
   printf("Liczba %d wsytepuje %d razy\n", x, i);
   
   return 0;
}
