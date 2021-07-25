#include<stdio.h>

int main() 
{

    float preco, final;
    int iva;

    printf("Preco: ");
    scanf("%f",&preco);
    printf("Iva: ");
    scanf("%d",&iva);

    final = preco * iva;

    printf("Preco final: %f\n",final);

    return 0;
}
