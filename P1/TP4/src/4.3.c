#include<stdio.h>
#include<math.h>

int main() 
{

    float peso, altura, imc, pmi, pma;
    
    printf("Peso: ");
    scanf("%f",&peso);
    printf("Altura: ");
    scanf("%f",&altura);

    imc = peso / pow(altura,2);
    
    printf("%f\n",imc);

    if (imc < 19) {

        printf("Magreza\n");
    
    } else if (imc >= 19 && imc <= 25) {

        printf("Normal\n");

    } else if (imc > 25 && imc <= 30) {

        printf("Excesso de peso\n");

    } else if (imc > 30 && imc <= 40) {

        printf("Obesidade\n");

    } else if (imc > 40) {

        printf("Obesidade morbida\n");

    }

    pmi = 19 * pow(altura,2);

    printf("%f\n",pmi);

    pma = 25 * pow(altura,2);

    printf("%f\n",pma);

    return 0;
}
