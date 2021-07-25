#include <stdio.h>

float media (int n) {

	int input, soma = 0;

	float media;

	for (int i = 0; i < n; i++) {

		printf("Num[%d]: ",i+1);
		scanf("%d",&input);

		soma = soma + input;
	}

	media = soma / n;

	return media;

}

int main() 
{

	int n;

	printf("Numero: ");
	scanf("%d",&n);

	printf("Media: %f\n", media(n));

        return 0;
}
