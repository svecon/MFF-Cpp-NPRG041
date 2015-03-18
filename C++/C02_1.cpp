// C02_1 source code solution
#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main( void)
{
	int mat[3][3];																			// input random matrix
	int smat[5][3];																			// Sarrus' matrix
	int m,n;																				// indexes for loops
	...
	char c;																					// char variable for pressed key						

	printf("3x3 random matrix:\n\n");														// printing "3x3 random matrix:"
   
	srand(time(NULL));																		// seed of random nuber generator initialization
	for(m=0; m<3; m++)																		// loops for generating and printing of random matrix 
	{
		for (n=0; n<3; n++)
		{	
			mat[m][n]=rand()%199-99;														// given random element of matrix generation
			printf(...);																	// printing given random element of matrix
		}
		printf("\n");
	}

	...

	scanf("%c", &c);																		// waiting for pressing key

	return 0;																				// program returns 0
}