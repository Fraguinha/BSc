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

float somaElementosMatriz(float matriz[l][c]) {
	
	float soma = 0;
	
	for (int i=0; i < c; i++) {
		for (int j=0; j < c; j++) {
			soma = soma + matriz[i][j];
		}
	}
	
	return soma;
}

int main () 
{

	float ans;

	float matriz[l][c];

	lerMatriz(matriz);
	
	ans = somaElementosMatriz(matriz);
	
	printf("Soma dos elementos da matriz: %f\n", ans);

        return 0;
}
