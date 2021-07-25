#include<stdio.h>

int main() 
{

    int comprimento, largura;
    int area;

    printf("Comprimento: ");
    scanf("%d",&comprimento);
    printf("Largura: ");
    scanf("%d",&largura);

    area = comprimento * largura;

    printf("Area: %d\n",area);

    return 0;
}
