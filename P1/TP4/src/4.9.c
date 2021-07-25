#include<stdio.h>

int main() 
{

    int n=0, input, soma=0; 

    float media;

    do {
		
		printf("N: ");
    	scanf("%d",&input);

		soma = soma + input;
		
		if (input != 0) {
			n++;
		}

	} while (input != 0);
    
    media = ((float) soma / (float) n);
    
    printf("Media: %f\n",media);

    return 0;
}
