#include <stdio.h>
#include <string.h>

#define SIZE 100

int num(char, char []);

int main() 
{

	int ans;

	char c;
	char str[SIZE];

	printf("Escreva um char: ");
	scanf(" %c", &c);

	printf("Escreva um string: ");
	scanf("%s", str);

	ans = num(c, str);

	printf("%d\n", ans);


        return 0;
}

int num(char c, char str[]) {

	int cont = 0;

	int len = strlen(str);

	for (int i=0; i < len; i++) {
		
		if ((int) str[i] == (int)c) {
			cont++;		
		}
	}

	return cont;
}
