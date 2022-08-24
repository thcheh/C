
#include <stdio.h>

/* Deklaracja funkcji */
int jest_pierwsza ( int n );

int main()
{
   int n, i=1;
   printf("n = "); 
   scanf("%d", &n);
   while(i<=n) 
   {
      if(jest_pierwsza(i) == 1) printf("%d\n",i);
      i++;
   }
   return 0;
}

/* Definicja funkcji  */
int jest_pierwsza ( int n )
{
   int i =2;
   while ( i<=n/i )
   {
      if ( n % i == 0 ) return 0 ;
      i = i + 1;
   }
   return 1 ;
}
