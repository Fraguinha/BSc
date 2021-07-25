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

int main () 
{

	float matriz[l][c];

	lerMatriz(matriz);
	escreverMatriz(matriz);

        return 0;
}
