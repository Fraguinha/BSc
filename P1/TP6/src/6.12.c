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

void somaMatrizes(float matriz1[l][c], float matriz2[l][c], float soma[l][c]) {

	for (int i=0; i < l; i++) {
		for (int j=0; j < c; j++) {
			soma[i][j] = matriz1[i][j] + matriz2[i][j];
		}
	}
}

int main () 
{
	
	float matriz1[l][c];
	float matriz2[l][c];
	float soma[l][c];

	lerMatriz(matriz1);
	lerMatriz(matriz2);

	somaMatrizes(matriz1, matriz2, soma);

	escreverMatriz(soma);

        return 0;
}
