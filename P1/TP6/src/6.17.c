#include <stdio.h>

#define l 5
#define c 12

void lerMatriz(float matriz[l][c]) {
    
    for (int i=0; i < l; i++) {
        for (int j=0; j < c; j++) {
            printf("matriz[%d][%d]: ",i,j);
            scanf("%f", &matriz[i][j]);
        }   
    }
    printf("\n");
}

void info(float matriz[l][c]) {

	float media;
	float soma;
	float min;

	for (int i=0; i < l; i++) {

		min = matriz[i][0];

		for (int j=0; j < c; j++) {

			soma += matriz[i][j];
			if (matriz[i][j] < min) {
				min = matriz[i][j];
			}
		}

		media = (float)soma/(float)c;
		
		printf("Media %d: %f\n", i, media);
		printf("Melhor Tempo %d: %f\n", i, min);
	}
}

int main() 
{

	float matriz[l][c];

	lerMatriz(matriz);

	info(matriz);

        return 0;
}
