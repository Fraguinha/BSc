#include <stdio.h>

#define SIZE 20

int comprimento(char []);

int main() 
{

	char str[SIZE];
	int len;

	printf("Escreva uma string: ");
	scanf("%s", str);

	len = comprimento(str);

	printf("Tamanho da string: %d\n", len);

        return 0;
}

int comprimento(char s[] ) {

	int cont = 0;

	while(s[cont] != '\0') {
		cont++;
	}

	return cont;
}
