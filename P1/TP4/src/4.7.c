#include<stdio.h>

int main() 
{
    
    int first=1, input, max, min;
    
	do {

        printf("Num: ");
        scanf("%d",&input);

		if (first == 1) {
			
			max = input;
			min = input;
			first = 0;
		}
        
		if (input < min && input != 0) {

            min = input;

        }

        if (input > max) {

            max = input;

        }

    } while (input != 0);
    
    printf("Maximo: %d\n",max);
    printf("Minimo: %d\n",min);

    return 0;
}
