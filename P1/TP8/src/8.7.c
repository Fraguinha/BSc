#include <stdio.h>

#define num 5
#define stringMax 20

typedef struct {
	
	char nome[stringMax];
	int bracos;
	int pernas;

} Species;

void readSpecies(Species *);

int main() 
{
	
	Species list[num];

	for (int i=0; i<num; i++) {

		readSpecies(&list[i]);
	}

	for (int j=0; j<num; j++) {
		
		printf("%s tem %d bracos e %d pernas\n", list[j].nome, list[j].bracos, list[j].pernas);
	}

        return 0;
}

void readSpecies(Species *s) {
	
	printf("Nome: ");
	scanf("%s", &s->nome);
	printf("Numero bracos: ");
	scanf("%d", &s->bracos);
	printf("Numero pernas: ");
	scanf("%d", &s->pernas);
}
