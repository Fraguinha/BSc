#include<stdio.h>
#include<stdlib.h>

int main() 
{
    
    int plano;
    float custo;
    
    int minutosRede;
    int minutosMovel;
    int minutosFixa;

    printf("Tarifarios disponiveis\n\n1:Cartao Recarregavel\n2:Plano Personalizado\n\nOpcao: ");
    scanf("%d",&plano);

    if ((plano != 1) && (plano != 2)) {

        printf("Opcao invalida\n");
    
    } else {
    
        if (plano == 1) {
        
            printf("\nPlanos recarregaveis\n\n1:Mynet\n2:MyFriends\n3:MyJob\n\nOpcao: ");
            scanf("%d",&plano);
    
            if ((plano != 1) && (plano != 2) && (plano !=3)) {

                printf("Opcao invalida\n");
            
            } else {
                
                printf("\nMinutos mesma rede: ");
                scanf("%d",&minutosRede);
                printf("Minutos redes moveis: ");
                scanf("%d",&minutosMovel);
                printf("Minutos redes fixas: ");
                scanf("%d",&minutosFixa);

                if (plano == 1) {

                    custo = (0.05 * minutosRede) + (0.5 * minutosMovel) + (0.5 * minutosFixa);

                }

                if (plano == 2) {

                    custo = (0.1 * minutosRede) + (0.1 * minutosMovel) + (0.5 * minutosFixa);

                }

                if (plano == 3) {

                    custo = (0.1 * minutosRede) + (0.5 * minutosMovel) + (0.1 * minutosFixa);

                }
                
                printf("\nCusto: %f\n",custo);
            }
    
        } else {

            printf("\nPlanos personalizados\n\n1:Base\n2:Super\n3:Executive\n\nOpcao: ");
            scanf("%d",&plano);

            if ((plano != 1) && (plano != 2) && (plano !=3)) {

                printf("Opcao invalida\n");

            } else {

                printf("\nMinutos mesma rede: ");
                scanf("%d",&minutosRede);
                printf("Minutos redes moveis: ");
                scanf("%d",&minutosMovel);
                printf("Minutos redes fixas: ");
                scanf("%d",&minutosFixa);
                
                if (plano == 1) {

                    custo = 10 + (0.1 * minutosRede) + (0.3 * minutosMovel) + (0.3 * minutosFixa);

                }

                if (plano == 2) {

                    custo = 15 + (0.05 * minutosRede) + (0.2 * minutosMovel) + (0.2 * minutosFixa);

                }

                if (plano == 3) {

                    custo = 25 + (0.05 * minutosRede) + (0.05 * minutosMovel) + (0.05 * minutosFixa);

                }

                printf("\nCusto: %f\n",custo);
            }
        }        
    }

    return 0;
}
