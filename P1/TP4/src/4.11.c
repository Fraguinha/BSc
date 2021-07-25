#include<stdio.h>

int main() 
{

    int n, factorial=1;

    printf("Numero: ");
    scanf("%d",&n);
    
    for (int i=n; i > 0; i--) {

    factorial = factorial * i;

    }

    printf("Factorial: %d\n",factorial);

    return 0;
}
