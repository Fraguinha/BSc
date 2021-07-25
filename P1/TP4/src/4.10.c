#include<stdio.h>

int main () 
{

    int n, soma=0;

    printf("Numero: ");
    scanf("%d",&n);

    while (n > 0) {

        soma = soma + n;
        n--;
    }

    printf("Soma: %d\n",soma);

    return 0;
}
