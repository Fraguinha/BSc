#include <stdio.h>

#define l 3
#define c 3

void lerMatriz(float matriz[l][c]) {
	
	for (int i=0; i < l; i++) {
		for (int j=0; j < c; j++) {
			printf("matriz[%d][%d]: ",i,j);
			scanf("%f", &matriz[i][j]);
		}
	}
	printf("\n");
}

void escreverMatriz(float matriz[l][c]) {
	
	for (int i=0; i < c; i++) {
		for (int j=0; j < l; j++) {
			printf("%f    ",matriz[i][j]);
		}
		printf("\n");
	}
}

void matrizProducto(float matriz1[l][c], float matriz2[l][c], float producto[l][c]) {

	float soma = 0;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < l; k++) {
				soma += matriz1[i][k] * matriz2[k][j];
			}
			producto[i][j] = soma;
			soma = 0;
		}
	}
}

int main () 
{

	float matriz1[l][c];
	float matriz2[l][c];
	float producto[l][c];

	lerMatriz(matriz1);
	lerMatriz(matriz2);

	matrizProducto(matriz1, matriz2, producto);

	escreverMatriz(producto);

        return 0;
}
