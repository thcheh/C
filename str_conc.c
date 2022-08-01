#include <stdio.h>

/*
    A: THC
    C: zabawa
    lang: PL
    ANSI-C
*/

int main()
{
    char aa[100], bb[100];

    printf("\nEnter the first string: ");
    scanf("%s",aa);

    printf("\nEnter the second string to be concatenated: ");
    scanf("%s",bb);

    char *a = aa;
    char *b = bb;

    while(*a)
    {
        a++; 
    }
    while(*b)
    {
        *a = *b;
        b++;
    }
    *a = '\0';
    printf("\nThe string after concatenation is: %s%s \n\n", aa,bb);
    return 0;
}
