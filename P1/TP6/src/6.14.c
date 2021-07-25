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

int nulos(float matriz[l][c]) {

	int cont = 0;

	for (int i = 0; i < l; i++) {
		if (matriz[i][i] == 0) {
			cont++;
		}	
	}

	return cont;
}

int main() 
{
	
	int ans;

	float matriz[l][c];

	lerMatriz(matriz);

	ans = nulos(matriz);

	printf("Numero de nulos: %d\n", ans);

        return 0;
}
