#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 100

typedef struct {
	
	float x;
	float y;
	float z;

} Point3D;

void ler(Point3D *);
void opcao1();
void opcao2();
void opcao3();

int main() 
{

	int opcao;

	while (1) {

		printf("1. Distancia entre dois pontos em R3.\n2. Ponto medio entre dois pontos em R3.\n3. Baricentro de N pontos em R3.\n4. Exit\n");
		printf("Opcao: ");

		scanf("%d", &opcao);

		switch(opcao) {

			case 1:

				opcao1();
				break;

			case 2:

				opcao2();
				break;

			case 3:

				opcao3();
				break;

			case 4:

				exit(0);

			default:

				printf("Opcao invalida!\n");
				break;
		}
	}

        return 0;
}

void ler(Point3D *p) {
	
	printf("x: ");	
	scanf("%f",&(p->x));
	printf("y: ");	
	scanf("%f",&(p->y));
	printf("z: ");	
	scanf("%f",&(p->z));
}

void opcao1() {

	Point3D a, b;

	float distancia;

	ler(&a);
	ler(&b);

	distancia = sqrt((pow((b.x-a.x),2)) + (pow((b.y-a.y),2)) + (pow((b.z-a.z),2)));

	printf("Distancia: %f\n", distancia);
}

void opcao2() {

	Point3D a, b, pm;

	ler(&a);
	ler(&b);

	pm.x = (a.x + b.x)/2;
	pm.y = (a.y + b.y)/2;
	pm.z = (a.z + b.z)/2;

	printf("Ponto medio: (%f, %f, %f)\n", pm.x, pm.y, pm.z);
}

void opcao3() {
	
	Point3D points[max];
	Point3D bc;
	
	int n;

	printf("N: ");
	scanf("%d", &n);

	for (int i=0; i < n; i++) {
		
		ler(&points[i]);
	}

	int somax=0, somay=0, somaz=0;
	
	for (int j=0; j < n; j++) {
		
		somax += points[j].x;
		somay += points[j].y;
		somaz += points[j].z;
	}
	
	bc.x = somax / n;
	bc.y = somay / n;
	bc.z = somaz / n;
	
	printf("Baricentro: (%f, %f, %f)\n", bc.x, bc.y, bc.z);
}
