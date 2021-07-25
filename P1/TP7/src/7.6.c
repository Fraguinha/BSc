#include <stdio.h>
#include <string.h>

#define SIZE 100

int num(char []);

int main() 
{

	int ans;

	char str[SIZE];

	printf("Escreva string: ");
	scanf("%s", str);

	ans = num(str);

	printf("%d\n", ans);

        return 0;
}

int num(char str[]) {

	int cont = 0;

	int len = strlen(str);

	for (int i=0; i < len; i++) {
		
		if ((int) str[i] >= 48 && (int) str[i] <= 57) {
			cont++;		
		}
	}

	return cont;
}
