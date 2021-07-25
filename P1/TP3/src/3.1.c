#include<stdio.h>

int main() 
{

    int input, segundos, minutos, horas;

    printf("Segundos: ");
    scanf("%d",&input);

    horas = input / 3600;
    minutos = (input - horas * 3600) / 60;
    segundos = (input - horas * 3600 - minutos * 60);

    printf("Horas: %d:%d:%d\n",horas,minutos,segundos);

    return 0;
}
