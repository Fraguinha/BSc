#include<stdio.h>

int main() 
{

    float quilogramas, gramas;

    printf("Quilogramas: ");
    scanf("%f",&quilogramas);
    
    gramas = quilogramas * 1000;

    printf("%f quilogramas sao %f gramas.\n",quilogramas,gramas);

    return 0;
}
