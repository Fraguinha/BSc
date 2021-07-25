#include <stdio.h>

#define DIM 10

void lerArray (int seq[DIM]) {
	
	for (int i=0; i < DIM; i++) {
		printf("Num: ");
		scanf("%d", &seq[i]);
	}
}

int somaElementosArray(int seq[DIM]) {
	
	int soma = 0;
	
	for (int i=0; i < DIM; i++) {
		soma = soma + seq[i];
	}
	
	return soma;
}

int main () 
{
	
	int soma;	

	int seq[DIM];

	lerArray(seq);

	soma = somaElementosArray(seq);

	printf("Soma: %d\n", soma);

        return 0;
}
