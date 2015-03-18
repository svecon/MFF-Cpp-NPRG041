// cv2_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int _tmain(int argc, _TCHAR* argv[])
{	int mat[3][3];																			// input random matrix
	int smat[5][3];																			// Sarrus' matrix
	int m,n;																				// indexes for loops
	
	char c;																					// char variable for pressed key						

	printf("3x3 random matrix:\n\n");														// printing "3x3 random matrix:"
   
	srand(time(NULL));																		// seed of random nuber generator initialization
	for(m=0; m<3; m++)																		// loops for generating and printing of random matrix 
	{
		for (n=0; n<3; n++)
		{	
			mat[m][n]=rand()%199-99;														// given random element of matrix generation
			printf("%3d",mat [m][n]);																	// printing given random element of matrix
		}
		printf("\n");
	}
	int Det;
	Det=mat [0][0]*mat [1][1]*mat [2][2]+mat [1][0]*mat [2][1]*mat [0][2]+mat [2][0]*mat [0][1]*mat [1][2]-mat [0][2]*mat [1][1]*mat [2][0]-mat [1][2]*mat [2][1]*mat [0][0]-mat [2][2]*mat [0][1]*mat [1][0];
	printf("Determinant matice je %d\n");
	scanf("%c", &c);	
	
	for(m=0; m<3; m++)																		// loops for generating and printing of random matrix 
	{
		for (n=0; n<3; n++)
		{	
			smat[m][n]=mat[m][n];														// given random element of matrix generation
			printf("%3d",smat [m*3][n]);																	// printing given random element of matrix
		
		}
		printf("\n");																		// waiting for pressing key
		}
		int Det1;
		for(m=0; m<2; m++)
		{	
		for(n=0; m<3; n++)
		{

		smat[m+3][n]=mat[m][n];														// given random element of matrix generation
		printf("%3d",smat [m+3][n]);
		}
	}
	int soucin1,soucin2,det2=0;
		for(m=0; m<3; m++)																		// loops for generating and printing of random matrix 
	{	soucin1=1;
		soucin2=1;
		for (n=0; n<3; n++)
		{	
			soucin1=soucin1*mat[m+n][n];											// printing given random element of matrix
			soucin2=soucin2*mat[m+n][2-n];
		}
		det2=det2+soucin1-soucin2;
		}
		scanf("%c", &c);
		
	return 0;																				// program returns 0
}