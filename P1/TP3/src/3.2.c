#include<stdio.h>

int main() 
{

    float input, inteira, fractionaria;

    printf("Numero real: ");
    scanf("%f",&input);

    inteira = (int) input;
    
    fractionaria = input - inteira;
    
    printf("Inteira: %f Fractionaria: %f\n",inteira,fractionaria);

    return 0;
}
