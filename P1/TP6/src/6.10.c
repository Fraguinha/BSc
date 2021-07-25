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

float maximo(float matriz[l][c]) {

	float maximo = matriz[0][0];
	
	for (int i=0; i < c; i++) {
		for (int j=0; j < l; j++) {
			if (matriz[i][j] > maximo) {
				maximo = matriz[i][j];
			}
		}
	}
	
	return maximo;
}

float minimo(float matriz[l][c]) {

	float minimo = matriz[0][0];
	
	for (int i=0; i < c; i++) {
		for (int j=0; j < l; j++) {
			if (matriz[i][j] < minimo) {
				minimo = matriz[i][j];
			}
		}
	}
	
	return minimo;
}

int main () 
{
	
	float max, min;

	float matriz[l][c];

	lerMatriz(matriz);

	max = maximo(matriz);
	min = minimo(matriz);	

	printf("Max: %f\nMin: %f\n",max,min);

        return 0;
}
