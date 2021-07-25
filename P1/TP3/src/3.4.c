#include<stdio.h>

int main() 
{

    float input, celsius;
    
    printf("Fahreneit: ");
    scanf("%f",&input);

    celsius = (input - 32) / (9/5);

    printf("Celsius: %f\n",celsius);

    return 0;
}
