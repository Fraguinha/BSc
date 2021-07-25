#include<stdio.h>

int main () 
{
    
    int n; 

    printf("Numero: ");
    scanf("%d",&n);

    for (int j=1; j <= n; j++) {
        
        for (int k=j; k < n+j; k++) {

            printf("%d    ",k);

        }
        printf("\n");
    }
    printf("\n");    

    return 0;
}
