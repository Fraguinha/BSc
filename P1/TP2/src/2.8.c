#include<stdio.h>

int main() 
{

    int nota1, nota2;
    
    float media;
        
    printf("Nota1 :");
    scanf("%d",&nota1);
    printf("Nota2 :");
    scanf("%d",&nota2);

    media = (nota1 + nota2) / 2;

    printf("Media: %f\n",media);

    return 0;
}
