
#include<stdio.h>

int main()
{
   unsigned char klucz = 13;
   char znak;
   
   while( (znak=getchar()) != EOF )
      putchar( znak ^ klucz );

   return 0;
}


