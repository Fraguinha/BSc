#include<stdio.h>

void escreveCaracter(char a, int i) {

	for (int j=0; j < i; j++) {

		printf("%c", a);
	}
}

int main() 
{

	int b, l, a;
	char c;

	do {

		printf("B: Numero impar >= 3: ");
		scanf("%d",&b);

	} while (b % 2 == 0 || b < 3 || b <= 0);

	do {

		printf("L: Numero impar >= 1 e < (B/2): ");
		scanf("%d",&l);

	} while (l % 2 == 0 || l > (b/2) || l <= 0);

	do {

		printf("A: Numero > 1: ");
		scanf("%d",&a);

	} while (a <= 0);

	printf("Character para desenho: ");
	scanf(" %c",&c);

	int spaces = b / 2;
	int stars = 1;

	do {

		for (int i=0; i < spaces; i++) {

			escreveCaracter(' ',1);

		}

		for (int j=0; j< stars; j++){

			escreveCaracter(c,1);

		} 

		printf("\n");

		spaces = spaces -1;
		stars = stars + 2;

	} while (spaces >= 0);

	int spaces2 = (b - l) / 2;

	for (int m=0; m < a; m++) {

		for (int n=0; n < spaces2; n++) {

			escreveCaracter(' ',1);

		}

		for (int o=0; o < l; o++) {

			escreveCaracter(c,1);

		}

		printf("\n");
	}
        return 0;
}
