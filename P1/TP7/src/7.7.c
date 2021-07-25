#include <stdio.h>
#include <string.h>

#define SIZE 100

void cat(char [], char [], char []);

int main() 
{

	char str1[SIZE], str2[SIZE], strcat[SIZE];

	printf("Escreva 2 strings: ");
	scanf("%s %s", str1, str2);

	cat(str1, str2, strcat);

	printf("%s\n", strcat);

        return 0;
}

void cat(char str1[], char str2[], char strcat[]) {

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (int i=0; i < len1; i++) {

		strcat[i] = str1[i];
	}

	for (int j=0; j < len2; j++) {

		strcat[len1+j] = str2[j];
	}

	strcat[len1+len2] = '\0';
}
