#include<stdio.h>

int main() 
{

    int n, input, soma=0;
    
    float media;
        
    printf("N: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {

        printf("Num: ");
        scanf("%d",&input);
    
        soma = soma + input;
    }
    
    media = ((float) soma / (float) n);

    printf("Media: %f\n",media);

    return 0;
}
