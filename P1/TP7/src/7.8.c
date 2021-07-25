#include <stdio.h>
#include <string.h>

#define SIZE 100

void invString(char [], char []);

int capicua(char []);

int main() 
{

	char str[SIZE];

	printf("Escreva uma string: ");
	scanf("%s", str);

	capicua(str);

        return 0;
}

void invString(char str[], char invstr[]) {

	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		
		int index = len - 1 - i;

		invstr[index] = str[i];

	}
	
	invstr[len] = '\0';
}

int capicua (char str[]) {

	char invstr[SIZE];

	int len = strlen(str);
	int capicua = 1;

	invString(str, invstr);

	for (int i=0; i < len; i++) {

		if (str[i] != invstr[i]) {
			capicua = 0;
		}
	}

	if (capicua) {
		printf("E capicua\n");
	} else {
		printf("Nao e capicua\n");
	}
}
