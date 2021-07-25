#include<stdio.h>

int main() 
{

    int numero, temp, dig1, dig2, dig3;

    printf("Numero de 3 digitos: ");
    scanf("%d",&numero);
    
    temp = numero;
    
    dig1 = temp % 10;
    temp = temp / 10;
    dig2 = temp % 10;
    temp = temp / 10;
    dig3 = temp % 10;
    
    printf("%d = %d x 1 + %d x 10 + %d x 100.\n",numero,dig1,dig2,dig3);

    return 0;
}   
