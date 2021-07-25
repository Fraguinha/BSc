#include <stdio.h>

#define DIM 10

void lerArray(float seq[DIM]) {
    
    for (int i=0; i < DIM; i++) {
        printf("Num: ");
        scanf("%f", &seq[i]);
    }
}

float media (float seq[DIM]) {
	
	float soma = 0;	
	
	for (int i=0; i < DIM; i++) {
		soma = soma + seq[i];
	}
	float media = soma / DIM;
	
	return media;
}

int main () 
{
	
	float med;

	float seq[DIM];

	lerArray(seq);
			
	med = media(seq);

	printf("Media: %f\n", med);

        return 0;
}
