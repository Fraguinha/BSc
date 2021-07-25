#include <stdio.h>
#include <string.h>

#define SIZE 100

void apagar(char, char [], char []);

int main() 
{

	int ans;

	char c;
	char str1[SIZE], str2[SIZE];

	printf("Escreva um char: ");
	scanf(" %c", &c);

	printf("Escreva um string: ");
	scanf("%s", str1);

	apagar(c, str1, str2);

	printf("%s\n", str2);

        return 0;
}

void apagar(char c, char str1[], char str2[]) {

	int cont = 0;

	int len = strlen(str1);

	for (int i=0; i < len; i++) {
		
		if ((int) str1[i] == (int)c) {
			cont++;		
		} else {
			str2[i-cont] = str1[i];
		}
	}
}
