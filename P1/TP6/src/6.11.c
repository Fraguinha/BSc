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

void posicaoMaximo(float matriz[l][c]) {
	
	int a=0, b=0;
	float maximo = matriz[0][0];
	
	for (int i=0; i < c; i++) {
		for (int j=0; j < l; j++) {
			if (matriz[i][j] > maximo) {
				maximo = matriz[i][j];
				a = i;
				b = j;
			}
		}
	}
	printf("Posicao maximo: [%d][%d]\n",a,b);
}

void posicaoMinimo(float matriz[l][c]) {
	
	int a=0, b=0;
	float minimo = matriz[0][0];
	
	for (int i=0; i < c; i++) {
		for (int j=0; j < l; j++) {
			if (matriz[i][j] < minimo) {
				minimo = matriz[i][j];
				a = i;
				b = j;
			}
		}
	}
	printf("Posicao minimo: [%d][%d]\n",a,b);
}

int main () 
{
	
	float matriz[l][c];

	lerMatriz(matriz);

	posicaoMaximo(matriz);
	posicaoMinimo(matriz);

        return 0;
}
