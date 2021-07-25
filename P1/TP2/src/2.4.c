#include<stdio.h>

int main() 
{

    int numero, anos, peso;

    printf("Numero de aluno: ");
    scanf("%d",&numero);
    printf("Anos: ");
    scanf("%d",&anos);
    printf("Peso: ");
    scanf("%d",&peso);

    printf("Ola! Tu es o aluno %d, tens %d anos e pesas %d.\n",numero,anos,peso);

    return 0;

}
