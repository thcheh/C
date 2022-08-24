#include <stdio.h>
int rekurencja(int n){
	//funkcja zwraca 1 gdy n jest równe 1, 2 gdy n jest równe 2 i 3*F(n-1)*F(n-2) dla n>2
	if(n==1) return 1;
	if(n==2) return 2;
	return 3*rekurencja(n-1)*rekurencja(n-2);
}
int main(){
	int n;
	//pêtla pozwalaj¹ca na podanie elementu ci¹gu który ma zostaæ wyœwietlony
	do{
		printf("Podaj numer elementu ktory chcesz sprawdzic: ");
		scanf("%i", &n);
	}while(n<1);
	printf("Wyraz %i to: %i", n, rekurencja(n));
	return 0;
}
