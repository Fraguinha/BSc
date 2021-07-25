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

float linhaValorMaximo(float matriz[l][c]) {

	int linha, first = 1;
	float soma=0, max=0;

	for (int i=0; i < l; i++) {
		if (first == 1) {
			for (int j=0; j < l; j++) {
				max += matriz[i][j];
				linha = i;
			}
			first = 0;
		} else {
			for (int j=0; j < l; j++) {
				soma += matriz[i][j];
			}
			if (soma > max) {
				max = soma;
				linha = i;
			}
		}
	}

	return linha;
}

int main() 
{
	
	int ans;

	float matriz[l][c];

	lerMatriz(matriz);

	ans = linhaValorMaximo(matriz);

	printf("Linha: %d\n", ans);
	

        return 0;
}
