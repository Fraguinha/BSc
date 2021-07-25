#include <stdio.h>

int main() 
{

	float a, b, c;

	printf("A: ");
	scanf("%f",&a);

	printf("B: ");
	scanf("%f",&b);

	printf("C: ");
	scanf("%f",&c);

	if ((a == (float)0.1) && (b == (float)0.5) && (c == (float)0.6)) {
		printf("Producto 1");
	} else if ((a == (float)0.1) && (b == (float)0.3) && (c == (float)0.7)) {
		printf("Producto 2");
	} else if ((a == (float)0.2) && (b == (float)0.5) && (c == (float)0.7)) {
		printf("Producto 3");
	} else if ((a == (float)0.2) && (b == (float)0.3) && (c == (float)0.1)) {
		printf("Producto 4");
	} else if ((a == (float)0.2) && (b == (float)0.5) && (c == (float)0.6)) {
		printf("Producto 5");
	} else {
		printf("Producto desconhecido");
	}
	printf("\n");

        return 0;
}
