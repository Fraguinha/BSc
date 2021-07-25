#include<stdio.h>

int main() 
{

    int n, fib, last1=1, last2=1;

    printf("Numero: ");
    scanf("%d",&n);

    printf("Fibonacci: ");

	if (n == 1) {
		printf("1 ");
	} else if (n >= 2) {
		printf("1 1 ");
	} 
	
	for (int i = 2; i < n; i++) {
		fib = last1 + last2;
		printf("%d ",fib);
		last2 = last1;
		last1 = fib;
    }
    printf("\n");

    return 0;
}
