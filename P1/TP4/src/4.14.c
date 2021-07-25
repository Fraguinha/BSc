#include<stdio.h>
#include<math.h>

/*
 * Decimal to binary
 *
 * What we need to do:
 *
 * Calculate the number of digits we will need to use to write the number in binary;
 * Calculate the number in binary;
 * 
 */

int main() 
{

    int n, temp, cont=0, bin=0;

    printf("Numero: ");
    scanf("%d",&n);

	temp = n;

	/*
	 *	We need to know how many digits the binary number will need to have,
	 *	so well keep on dividing it by 2 until we get to 0,
	 *	and add 1 to our counter everytime we do so.
	 *
	 *	our counter will have the amount of digits we will need to write.
	 */
    
    do {
		
		temp = temp / 2;
		cont++;

    } while (temp > 0);

    /*
	 *	After we know how many digits we will need (counter),
	 *
	 *	our number written in binary will be the sum of all the remainders of the decimal number divided by 2 (n % 2)
	 *	times 10 to the power of counter that was calculated before,
	 *
	 * 	(sum = sum + (n % 2) * pow(10,counter)
	 *
	 *	multiplying by 10 to the power of counter ensures that the remainders calculated will stay in the correct position within the binary number.
	 *	
	 * 	we need to repeat this cycle, counter number of times in order to write the full number, and decrease the counter by 1 each time.
	 *
	 *	also dont forget to divide the number by 2 after you've calculated the remainded and before the cycle ends.
	 *
	 *	in the end, our sum will have the number written in base 2.
     */
	
	for (int i = cont; i > 0; i--) {
	
		bin = bin + (n % 2) * pow(10,i);	// bin is the sum of remainders here.
		
		n = n / 2;	// we advance the division so we can keep on calculating and adding the remainders.

	}

	printf("Binario: %d\n",bin);

        return 0;
}
