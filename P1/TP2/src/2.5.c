#include<stdio.h>

int main() 
{
    
    int numInt;
    float numReal;

    float produto;

    printf("Boa Tarde!\n");
    printf("Numero inteiro: ");
    scanf("%d",&numInt);
    printf("Numero real: ");
    scanf("%f",&numReal);

    produto = numInt * numReal; 

    printf("O produto %d x %f = %f\n",numInt,numReal,produto);

    return 0;

}
