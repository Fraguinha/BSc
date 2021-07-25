#include<stdio.h>

int main () 
{

    int n;

    printf("Numero: ");
    scanf("%d",&n);
    
    for (int i=1; i <= 10; i++) {

        printf("%d    x    %d    =    %d\n",n,n,n*i);

    }

    return 0;
}
