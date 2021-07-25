#include<stdio.h>

int main() 
{

    int num1, num2, produto=1;

    do {

        printf("Numero1: ");
        scanf("%d",&num1);
        printf("Numero2: ");
        scanf("%d",&num2);

    } while (num2 <= num1);

    for (int i = num1; i <= num2; i++) {

        produto = produto * i;

    }

    printf("Produto: %d\n",produto);

    return 0;
}
