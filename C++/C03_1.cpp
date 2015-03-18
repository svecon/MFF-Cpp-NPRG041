#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"

double factorial(double f)
{
    int i;

    for (i=f-1; i>=2; i--){
        f *= i;
    }
    return f;
}

int main( void)
{
	double x;					// variable for input value
	double xpow=1;				// variable for power of input value in numerator
	double fval=1;				// variable for ouput value
	double fact=1;   			// variable for factorial in denominator
	int integ,decim;			// variables for integral and decimal fractions of input value
	int n=0;					// index for computation of Taylor series in loop
	char c;

	srand(time(NULL));			// seed initialization for random generator

	// zaèátek

        /*
        integ = rand()%10;
        decim = rand()%100;
        x = (integ + (double) decim/100);
         */

        // jenom pro kontrolu => smazat
	x = 8.41;

        printf("Exponential function of %f using math library is %22.16Lf", x, exp(x));

		printf("\n\n Tailor series application:");
        printf("\n");

        for(n=1; n<=50; n++){
            if(n==1) fval = 1;
            else {
                fval += pow(x, n-1)/factorial(n-1);
            }

            printf("\n%2i terms: %22.16Lf", n, fval);
        }

	// konec

	scanf("%c", &c);						// waiting for pressing key
	return 0;								// program returns 0
}