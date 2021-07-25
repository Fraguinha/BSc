#include<stdio.h>

int main() 
{
    
    int n, first=1, input, max, min;
    
    printf("N: ");
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
		
		printf("Num: ");
		scanf("%d",&input);

		if (first == 1) {

			max = input;
			min = input;
			first = 0;

		} else {

			if (input > max) {
				max = input;	
			}

			if (input < min) {
				min = input;
			}
		}
    }

    printf("Maximo: %d\n",max);
    printf("Minimo: %d\n",min);
    

    return 0;
}
