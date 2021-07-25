#include<stdio.h>

void quadrado (int i) {
    
    int j=1;

    for (int k=0; k < i; k++) {
        
        for (int l=j; l < i+j; l++) {
            printf("%d    ",l);
        }
        printf("\n");
        j++;   
    }
}

int main() 
{
    
    int n;

    printf("Numero: ");
    scanf("%d",&n);

    quadrado(n);

    return 0;
}
