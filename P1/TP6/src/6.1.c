#include <stdio.h>

#define DIM 10
	
void lerArray(float seq[DIM]) {
	
	for (int i=0; i < DIM; i++) {
		printf("Num: ");
		scanf("%f", &seq[i]);
	}
}

void escreverArray(float seq[DIM]) {
	
	for (int i=0; i < DIM; i++) {
		printf("%f\n",seq[i]);
	}
	printf("\n");
}

int main() 
{

	float seq[DIM];

	lerArray(seq);
	escreverArray(seq);

        return 0;
}
