#include <stdio.h>

/*
	A: THC
	C: zabawa
	lang: PL
  ANSI-C
*/

int main()
{
	struct godzina
	{
		int G;
		int M;
		int S;
	};
	
	struct godzina czas1;
	struct godzina czas2;
	struct godzina czas3;
	

	
	printf("Wprowadz dane dla pierwszej godziny\n");
	printf("G: ");
		do{
	scanf("%d", &czas1.G);
	}while(czas1.G>24);
	printf("M: ");
			do{
	scanf("%d", &czas1.M);
	}while(czas1.M>60);
	printf("S: ");
			do{
	scanf("%d", &czas1.S);
	}while(czas1.S>60);
	
	printf("Wprowadz dane dla drugiej godziny\n");
	printf("G: ");
		do{
	scanf("%d", &czas2.G);
	}while(czas2.G>24);
	printf("M: ");
			do{
	scanf("%d", &czas2.M);
	}while(czas2.M>60);
	printf("S: ");
			do{
	scanf("%d", &czas2.S);
	}while(czas2.S>60);
	
	int G_r;
	int M_r;
	int S_r;
	
	if(czas1.G<czas2.G)
	{
		czas3.G=czas1.G;
		czas1.G=czas2.G;
		czas2.G=czas3.G;
	}
	if(czas1.M<czas2.M)
	{
		czas3.M=czas1.M;
		czas1.M=czas2.M;
		czas2.M=czas3.M;
	}
	if(czas1.S<czas2.S)
	{
		czas3.S=czas1.S;
		czas1.S=czas2.S;
		czas2.S=czas3.S;
	}
	
	G_r=czas1.G-czas2.G;
	M_r=czas1.M-czas2.M;
	S_r=czas1.S-czas2.S;
	
	printf("Roznica czasu wynosi: %dH:%dM:%dS", G_r,M_r,S_r);
}
