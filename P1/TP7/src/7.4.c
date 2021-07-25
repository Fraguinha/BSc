#include <stdio.h>
#include <string.h>

#define SIZE 100

int subString(char [], char []);

int main() 
{

	char str[SIZE];
	char substr[SIZE];

	printf("Escreva 2 string: ");
	scanf("%s %s", str, substr);

	int ans = subString(str, substr);

	if (ans) {
		printf("%s\n", "E substring");
	} else {
		printf("%s\n", "Nao e substring");
	}


        return 0;
}

int subString(char str[], char substr[]) {

	int len = strlen(str);
	int sublen = strlen(substr);

	int k=0;

	for (int i = 0; i < len; i++) {
		
		if (str[i] == substr[k]) {
			k++;
		} else {
			k=0;
		}
		if (k == sublen) {
			return 1;
		}

	}
	return 0;
}
