#include <stdio.h>

#define SIZE 100

void rewrite(char []);

int main() 
{

	char str[SIZE];

	printf("Escreva uma string: ");
	gets(str);	// percisamos de usar gets ("get string") para ler strings com espacos

	rewrite(str);

	printf("String: %s\n", str);

        return 0;
}

void rewrite(char s[]) {

	int cont = 0;

	// Contar tamanho string
	while (s[cont] != '\0') {
		cont++;
	}

	// Converter caracter minusculos na tabela ASCII para maiusculos
	for (int i = 0; i < cont; i++) {
		
		if ((int) s[i] >= 97 && (int) s[i] <= 122) {
			s[i] = 65 + (s[i] - 97);
		}
	}
}
