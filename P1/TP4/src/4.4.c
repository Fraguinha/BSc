#include<stdio.h>

int main() 
{
    
    int num=0, input=0, soma=0;

    do {

        printf("Numero >= 2: ");
        scanf("%d",&num);

    } while (num < 2);

	for (int i=0; i < num; i++) {
		scanf("%d",&input);
		soma += input; 
	}

    printf("Sn: %d\n",soma);

    return 0;
}
