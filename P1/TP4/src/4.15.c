#include<stdio.h>

int main() 
{

    int n;
    int ans = 0;

    do {
        
        printf("Numero: ");
        scanf("%d",&n);
    
    } while (n < 0);

    for (int i=2; i < n; i++) {

        if ((n % i) == 0) {

            ans=1;
            
        }
    }

    if (ans == 0) {

        printf("Numero primo\n");

    } else { 

        printf("Numero nao primo\n");

    }

    return 0;
}
