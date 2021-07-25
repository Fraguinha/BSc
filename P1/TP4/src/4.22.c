#include<stdio.h>
#include<math.h>

int main () 
{
    
    int sair=0;
    int opcao;

    float p, a, imc, pmi, pma;

    do {

        printf("Selecione uma opcao\n\n1: Calcular imc e categoria\n2: Calcular peso minimo e maximo\n\n0: Sair\n\n");
        
        do {

            printf("Opcao: ");
            scanf("%d",&opcao);
            
            if((opcao !=0) && (opcao !=1) && (opcao !=2)) {
                printf("Erro: opcao invalida\n");
            }

        } while ((opcao !=0) && (opcao !=1) && (opcao !=2));

        switch (opcao) {
            case 0:
                sair=1;
                break;
            case 1:
                
                printf("\nPeso: ");
                scanf("%f",&p);
                printf("Altura: ");
                scanf("%f",&a);
                
                imc = p / pow(a, 2);
                
                printf("\nImc: %f\n",imc);

                if (imc < 19) {

                    printf("Magreza");

                } 

                if ((imc >= 19) && (imc <= 25)) {

                    printf("Normal");

                }

                if ((imc > 25) && (imc <=30)) {

                    printf("Excesso de peso");

                }

                if ((imc > 30) && (imc <= 40)) {

                    printf("Obesidade");

                }
                
                if (imc > 40) {

                    printf("Obesidade morbida");

                }
                sair=1;
                break;

            case 2:

                printf("\nAltura: ");
                scanf("%f",&a);
                
                pmi = 19 * pow(a, 2);
                pma = 25 * pow(a, 2);

                printf("\nPmi: %f",pmi);
                printf("\nPma: %f",pma);

                sair=1;
                break;
        }

    } while (sair != 1);
    printf("\n");

    return 0;
}
