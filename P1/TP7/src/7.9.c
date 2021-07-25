#include <stdio.h>
#include <string.h>

#define SIZE 100

void copiar(char [], char []);

int main() 
{

	char str1[SIZE], str2[SIZE];

	printf("Escreva 2 strings: ");
	scanf("%s %s", str1, str2);

	copiar(str2, str1);

	printf("%s\n", str1);

        return 0;
}

void copiar(char orig[], char dest[]) {

	int len1 = strlen(orig);
	int len2 = strlen(dest);

	for (int i=0; i < SIZE; i++) {

		dest[i] = ' ';
	}

	for (int j=0; j < len1; j++) {

		dest[j] = orig[j];
	}

	dest[len1] = '\0';
}
