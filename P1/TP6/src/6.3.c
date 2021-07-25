#include <stdio.h>

#define DIM 10

void lerArray(int seq[DIM]) {
	
	for (int i=0; i < DIM; i++) {
		printf("Num: ");
		scanf("%d", &seq[i]);
	}
}

int minimo(int seq[DIM]) {
	
	int minimo = seq[0];
	
	for (int i=0; i < DIM; i++) {
		if (seq[i] < minimo) {
			minimo = seq[i];
		}
	}
	
	return minimo;
}

int maximo(int seq[DIM]) {
	
	int maximo = seq[0];
	
	for (int i=0; i < DIM; i++) {
		if (seq[i] > maximo) {
			maximo = seq[i];
		}
	}
	
	return maximo;
}

int main () 
{
	
	int max, min;	

	int seq[DIM];
	
	lerArray(seq);

	max = maximo(seq);
	min = minimo(seq);
		
	printf("Maximo: %d\n",max);
	printf("Minimo: %d\n",min);

        return 0;
}
