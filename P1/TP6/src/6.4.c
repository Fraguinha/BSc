#include <stdio.h>

#define DIM 10

void lerArray(int seq[DIM]) {
   	
   	for (int i=0; i < DIM; i++) {
	   		printf("Num: ");
		   	scanf("%d", &seq[i]);
	}
}

int posicaoMaximo (int seq[DIM]) {
	
	int maximo = seq[0];
	int posicao = 0;		
	
	for (int i=0; i < DIM; i++) {
		if (seq[i] > maximo) {
			maximo = seq[i];
			posicao = i;
		}	
	}
	
	return posicao;
}

int posicaoMinimo (int seq[DIM]) {
	
	int minimo = seq[0];
	int posicao = 0;
	
	for (int i=0; i < DIM; i++) {
		if (seq[i] < minimo) {
			minimo = seq[i];
			posicao = i;
		}
	}
	
	return posicao;
}

int main () 
{
	
	int posMax, posMin;

	int seq[DIM];

	lerArray(seq);

	posMax = posicaoMaximo(seq);
	posMin = posicaoMinimo(seq);

	printf("Posicao max: %d\n",posMax);	
	printf("Posicao min: %d\n",posMin);

        return 0;
}
