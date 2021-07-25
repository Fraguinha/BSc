#include<stdio.h>
#include<math.h>

/*
 * Binary to decimal
 * 
 * What we need to do:
 *
 * Calculate how many digits the binary number has;
 * Calculate the number in decimal;
 *
 */

int main() 
{

    int n, temp, cont=0, dec=0;

    printf("Numero: ");
    scanf("%d",&n);
	
	temp = n;

	/*
	 *	We need to know how many digits the binary number has,
	 *	so well keep on dividing it by 10 until we get to 0,
	 *	and add 1 to our counter everytime we do so.
	 *
	 *	our counter will have the amount of digits in the binary number.
	 */

    do { 
        
        temp = temp / 10;
        cont++;

    } while (temp > 0);

    /*
	 *	After we know how many digits we have (counter),
	 *
	 * 	our number written in decimal will be the sum of all digits multiplied by 2 to the corresponding power (ex: 1 * 2^0)
	 *	
	 * 	(dec = dec + (n % 10) * pow(2,i))
	 *
	 *	i will start at 0 and be incremented until i < counter.
	 *
	 *	once we have added all the digits multiplied by 2 to the corresponding power, 
	 *	our sum will have the number written in base 10.
     */
	
	for (int i = 0; i < cont; i++) {
	
		dec = dec + (n % 10) * pow(2,i);	// dec is our sum here.
		
		n = n / 10; 	// we advance the division so we can keep adding the digits times 2 to the corresponding power.
	}

    printf("Decimal: %d\n",dec);

    return 0;
}
