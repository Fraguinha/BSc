#include <stdio.h>

typedef struct {
	
	float real;
	float img;

} Complexo;

void ler(Complexo*);
void soma(Complexo*, Complexo*, Complexo*);
void escrever(Complexo*);

int main()
{
	
	Complexo a, b, s;
	
	ler(&a);
	ler(&b);

	soma(&a, &b, &s);

	escrever(&s);

        return 0;
}

void ler(Complexo* i) {

	printf("Real: ");
	scanf("%f",&(i->real));
	printf("Imaginario: ");
	scanf("%f",&(i->img));
}

void soma(Complexo* a, Complexo* b, Complexo* c) {

	c->real = a->real + b->real;
	c->img = a->img + b->img;
}

void escrever(Complexo* i) {

	printf("Soma: %f + %fi\n",i->real, i->img);
}
