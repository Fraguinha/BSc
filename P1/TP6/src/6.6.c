#include <stdio.h>

#define DIM 10

void lerArray(int seq[DIM]) {
    
    for (int i=0; i < DIM; i++) {
        printf("Num: ");
        scanf("%d", &seq[i]);
    }
}

void copia(int seqOrig[DIM], int seqCopy[DIM]) {
	
	for (int i=0; i < DIM; i++) {
		seqCopy[i] = seqOrig[i];
	}	
}

int main() 
{

	int seqOrig[DIM];
	int seqCopy[DIM];

	lerArray(seqOrig);

	copia(seqOrig, seqCopy);
	
	printf("Original: ");
	for (int i=0; i < DIM; i++) {
		printf("%d ",seqOrig[i]);
	}

	printf("\nCopy: ");
	for (int j=0; j < DIM; j++) {
		printf("%d ",seqCopy[j]);
	}
	printf("\n");

        return 0;
}
