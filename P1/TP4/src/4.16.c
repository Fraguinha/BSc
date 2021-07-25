#include<stdio.h>
#include<math.h>

int main() 
{

    int n, temp, invert=0;

    printf("Numero: ");
    scanf("%d",&n);
	
	temp = n;

	do {
		
		invert = invert * 10;
		invert = invert + temp % 10;

		temp = temp / 10;

	} while(temp != 0);

    if (n == invert) {

        printf("Capicua");

    } else {

        printf("Nao capicua");

    }
    printf("\n");

    return 0;
}
