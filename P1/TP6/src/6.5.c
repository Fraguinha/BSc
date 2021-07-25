#include <stdio.h>

#define DIM 10

void lerArray(float seq[DIM]) {
	
	for (int i=0; i < DIM; i++) {
		printf("Num: ");
		scanf("%f", &seq[i]);
	}
}

void somaElementosArray(float seq1[DIM], float seq2[DIM], float seq3[DIM]) {
    
    float soma = 0;
    
    for (int i=0; i < DIM; i++) {
        soma = seq2[i] + seq1[i];
        seq3[i] = soma;
    }
}

int main() 
{

	float seq1[DIM];
	float seq2[DIM];
	float seq3[DIM];
	
	lerArray(seq1);
	lerArray(seq2);

	somaElementosArray(seq1, seq2, seq3);

	printf("Sequencia soma: ");

	for (int i = 0; i < DIM; i++) {
		
		printf("%f ", seq3[i]);
	}
	printf("\n");

        return 0;
}
