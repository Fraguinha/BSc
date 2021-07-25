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

void transposta(float matriz[l][c]) {

	float tmp[l][c];

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			tmp[i][j] = matriz[i][j];
		}
	}
	for (int a = 0; a < l; a++) {
		for (int b = 0; b < c; b++) {
			matriz [a][b] = tmp[b][a];
		}
	}
}

int main() 
{
	
	float matriz[l][c];

	lerMatriz(matriz);

	transposta(matriz);

	escreverMatriz(matriz);

        return 0;
}
