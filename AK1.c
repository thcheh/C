#include <stdio.h>
#include <math.h>
struct prostopadloscian {
	//deklaracja struktury prostopadloscian
		float a;
		float b;
		float c;
	};
	
struct prostopadloscian pobor(){
	//funkcja pobiera wartoœci boków prostopad³oœcianu które musz¹ byæ wiêksze od 0
	struct prostopadloscian p1;
	do{
		printf("Podaj dlugosc boku a: ");
		scanf("%f", &p1.a);
	}while(p1.a<=0);
	do{
		printf("Podaj dlugosc boku b: ");
		scanf("%f", &p1.b);
	}while(p1.b<=0);
	do{
		printf("Podaj dlugosc boku c: ");
		scanf("%f", &p1.c);
	}while(p1.c<=0);
	return p1;
}

float diameter(struct prostopadloscian p1){
	//funkcja zwraca d³ugoœæ przek¹tnej
	return sqrt(pow(p1.a,2)+pow(p1.b,2)+pow(p1.c,2));
}

float field(struct prostopadloscian p1){
	//funkcja zwraca pole ca³kowite prostopad³oœcianu
	return 2*(p1.a*p1.b+p1.a*p1.c+p1.b*p1.c);
}

float obj(struct prostopadloscian p1){
	//funkcja zwraca objêtoœæ prostopad³oœcianu
	return p1.a*p1.b*p1.c;
}

int main(){
	struct prostopadloscian p1;
	p1 = pobor();
	printf("Przekatna: %f\n",diameter(p1));
	printf("Pole: %f\n",field(p1));
	printf("Objetosc: %f\n",obj(p1));
	return 0;
}
