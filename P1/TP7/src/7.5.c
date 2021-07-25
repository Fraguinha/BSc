#include <stdio.h>
#include <string.h>

#define SIZE 100

void invString(char [], char []);

int main() 
{

	char str[SIZE];
	char invstr[SIZE];

	printf("Escreva string: ");
	scanf("%s", str);

	invString(str, invstr);

	printf("%s\n", invstr);

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
