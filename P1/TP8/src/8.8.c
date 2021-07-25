#include <stdio.h>
#include <stdlib.h>

#define num 5
#define stringMax 20

typedef struct {
	
	char nome[stringMax];
	char categoria[stringMax];
	char data[stringMax];

	float salario;
	
	int id;

} Funcionario;

void opcao1(Funcionario *, int);
void opcao2();
void opcao3();
void opcao4();
void opcao5();

void 

int main() 
{
	
	Funcionario list[num];
	int id=0;

	int opcao;

	while (1) {

		printf("1. Cadastrar funcionario\n2. Apresentar registos por entrada\n3. Procurar funcionario por entrada\n4. Apresentar salarios superiores a X por ordem crescente\n5. Apresentar salarios inferiores a X por ordem crescente\n6. Exit\n");
		printf("Opcao: ");

		scanf("%d", &opcao);

		switch(opcao) {

			case 1:

				opcao1(&list[id], id);
				id++;
				break;

			case 2:

				opcao2();
				break;

			case 3:

				opcao3();
				break;
			case 4:
				
				opcao4();
				break;

			case 5:

				opcao5();
				break;

			case 6:

				exit(0);

			default:

				printf("Opcao invalida!\n");
				break;
		}
	}

        return 0;
}

void opcao1(Funcionario *f, int i) {

	printf("Nome: ");
	scanf("%s", &f->nome);
	printf("Categoria: ");
	scanf("%s", &f->categoria);
	printf("Data: ");
	scanf("%s", &f->data);
	printf("Salario: ");
	scanf("%f", &f->salario);

	f->id = i;
}

void opcao2(Funcionario array[]) {
	
	for (int i=0; i<num; i++) {
		array
	
}

void opcao3() {

}

void opcao4() {

}

void opcao5() {

}
