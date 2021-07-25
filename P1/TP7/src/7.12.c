#include <stdio.h>
#include <string.h>

#define SIZE 100

int strcounta(char []);
char[] strlower(char []);
char[] strset(char [], char ch, int n); // huh ?
int strwords(char []);
int strpack(char []);
int strwords(char []); 

int main() 
{

	printf("%s\n", "Don't worry, be happy :)");

        return 0;
}

int strcounta(char str[]) {

	int cont = 0;

	int len = strlen(str);

	for (int i=0; i < len; i++) {
		
		if (((int) str[i] >= 65 && (int) str[i] <= 90) || ((int) str[i] >= 97 && (int) str[i] <= 122)) {
			cont++;		
		}
	}

	return cont;
}

char[] strlower(char str[]) {

	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		
		if ((int) s[i] >= 65 && (int) s[i] <= 90) {
			s[i] = 97 + (s[i] - 65);
		}
	}
}
