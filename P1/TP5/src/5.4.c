#include<stdio.h>

float maximo (float i, float j) {
    if (i > j) {

        return i;

    } else { 

        return j;

    }
}

float minimo (float i, float j) {
    if (i < j) {

        return i;

    } else {

        return j;

    }
}

int main() 
{
    
    float a, b, max, min;

    printf("Numero 1: ");
    scanf("%f",&a);
    printf("Numero 2: ");
    scanf("%f",&b);

    max = maximo(a, b);
    min = minimo(a, b);

    printf("Maximo: %f\n",max);
    printf("Minimo: %f\n",min);

    return 0;
}
