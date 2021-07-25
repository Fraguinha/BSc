#include<stdio.h>

int main()
{
    int input;
    int segundos;
    int minutos;

    printf("segundos:");
        
    scanf("%d",&input);
    
    minutos = input / 60;
    segundos = input % 60; 

    printf("\t%d segundos sao: %d minutos e %d segundos",input,minutos,segundos);

    return 0;
}
