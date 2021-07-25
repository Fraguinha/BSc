#include <stdio.h>

#define l 12
#define c 35

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

	int positivas = 0;
	int melhorturma;
	int aprovados[l];
	
	float melhornota[l];

	for (int i=0; i < l; i++) {

		melhornota[i]=matriz[i][0];

		for (int j=0; j < c; j++) {
			
			if (matriz[i][j] >= 10) {
				
				aprovados[i]++;
				positivas++;

			}

			if (matriz[i][j] > melhornota[i]) {

					melhornota[i] = matriz[i][j];
			}
		}
	}

	printf("Numero positivas: %d\n", positivas);
	
	melhorturma = aprovados[0];

	for (int i=0; i < l; i++) {
		
		printf("Melhor nota turma %d: %f\n", i, melhornota[i]);
		
		if (aprovados[i] > melhorturma) {

			melhorturma = i;
		}

		printf("Melhor turma: %d\n", melhorturma);
	}
}

int main() 
{

	float matriz[l][c];

	lerMatriz(matriz);

	info(matriz);

        return 0;
}
