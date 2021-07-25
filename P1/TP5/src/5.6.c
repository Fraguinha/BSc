#include<stdio.h>

void tabuada (int i) {
    
    for (int j=1; j <= 10; j++) {

        printf("%d    x    %d    =    %d\n",i,i,i*j);
        
    }
}

int main() 
{
   
    int n;

    printf("Numero: ");
    scanf("%d",&n);

    tabuada(n);

    return 0;
}
