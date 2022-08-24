
#include <stdio.h>

int main ()
{
   int i, j, n;

   printf("Podaj zakres: ");
   scanf("%d", &n);

   printf("Liczby pierwsze w zakresie od 1 do %d\n", n);

   for(i=2; i<n; i++) {
      for(j=2; j <= (i/j); j++)
         if(!(i%j)) break;       /* nie jest l. pierwsza */ 
      if(j > (i/j)) printf("%d\n", i);
   }

   return 0;
}
