#include<stdio.h>

int main() 
{

    int n;

    printf("Numero: ");
    scanf("%d",&n);

    int i=1;    
    int space = n;

    for (int j=0; j<n; j++) {
        
        for (int k=0; k < space; k++) {
            
            printf("     ");
        }

        for (int l=1; l < i; l++) {
            
            printf("%d    ",l); 
        }

        for (int m=i; m > 0 ; m--) {

            printf("%d    ",m);
        }
        printf("\n");
        i++;
        space--; 
    }

    printf("\n");

    return 0;
}
