#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct {

	char nome[MAX];
	char apelido[MAX];
	char residencia[MAX];
	int telefone;

} Estudante;

void read(Estudante*);

int equalEntry(Estudante*, Estudante*);
int comesFirst(Estudante*, Estudante*);

int main()
{

	Estudante a, b;

	read(&a);
	read(&b);

	if (equalEntry(&a, &b)) {
		printf("Sao identicos\n");
	} else {
		printf("Sao diferentes\n");
	}

	if(comesFirst(&a, &b)) {
		printf("%s %s vem primeiro\n", a.nome, a.apelido);
	} else {
		printf("%s %s vem primeiro\n", b.nome, b.apelido);
	}

        return 0;
}

void read(Estudante* i) {

	printf("Nome: ");
	scanf("%s",&(i->nome));
	printf("Apelido: ");
	scanf("%s",&(i->apelido));
	printf("Residencia: ");
	scanf("%s",&(i->residencia));
	printf("Telefone: ");
	scanf("%d",&(i->telefone));
	printf("\n");
}

int equalEntry(Estudante* a, Estudante* b) {

	if (strcmp(a->nome, b->nome) == 0 && strcmp(a->apelido, b->apelido) == 0 && strcmp(a->residencia, b->residencia) == 0 && a->telefone == b->telefone) {
		return 1;
	} else {
		return 0;
	}
}

int comesFirst(Estudante* a, Estudante* b) {

	if (strcmp(a->nome, b->nome) == 0) {

		if(strcmp(a->apelido, b->apelido) > strcmp(b->apelido, a->apelido)) {
			return 0;
		} else {
			return 1;
		}

	} else {

		if(strcmp(a->nome, b->nome) > strcmp(b->nome, a->nome)) {
			return 0;
		} else {
			return 1;
		}
	}
}
