// Cv5_1.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "string.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
float temp[16][12]={-1.1,-0.3,7.6,12.7,19.2,27.6,29.3,29.1,22.4,14.2,8.1,0.5,
						-2.1,-1.1,5.4,11.0,18.4,23.9,32.5,26.0,19.4,11.8,6.2,-0.5,
						-0.3,-1.3,9.9,13.7,20.3,22.0,28.4,28.1,20.2,14.6,7.3,0.4,
						 1.1,-0.7,10.6,14.0,17.5,25.0,27.3,30.2,23.2,10.9,5.2,0.0,
						-8.6,-2.5,5.1,12.2,15.2,25.0,25.3,28.3,24.9, 9.2,1.5,0.2,
						-3.1,-0.3,4.6,12.3,14.0,28.6,29.0,32.5,22.0,12.3,9.1,4.3,
						-2.5,0.8,7.7,11.4,17.2,21.9,29.0,26.9,17.1,13.3,3.1,0.6,
						-1.0,-1.1,7.3,16.6,18.0,22.9,27.1,28.5,19.4,14.3,8.0,0.9,
						 0.0,2.6,7.8,10.9,19.1,28.8,28.1,28.1,18.5,13.8,6.0,1.5,
						 0.2,1.4,8.6,10.0,18.1,25.5,32.5,27.0,20.4,12.0,2.0,2.5,
						-0.7,-0.1,6.1,13.0,18.4,24.1,31.9,29.0,21.6,11.0,5.3,3.0,
						-5.4,3.3,11.6,12.8,16.9,23.8,28.7,29.0,23.4,13.7,3.8,4.1,
						-3.8,0.8,13.1,12.6,13.7,23.7,26.3,25.8,20.8,14.9,6.7,1.3,
						-1.2,0.0,8.6,15.9,15.6,26.6,29.2,26.6,20.8,15.1,4.1,-7.4,
						-2.5,2.5,8.8,11.7,19.8,27.3,33.3,25.4,22.9,14.1,4.1,2.9,
						-6.4,-6.3,2.5,13.8,19.1,27.6,28.1,23.2,20.1,12.0,5.1,0.8};						// temp. table

	

	char	mon[]="JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";									// abbreaviations of months	
	int		m,n,i,krok=0;
	int		pom1=1,pom2=1;
	unsigned int k=0;
	int		rok[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int		coldest[12]={0,0,0,0,0,0,0,0,0,0,0,0};																																					
	int		hottest[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	float	prumerT[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	float	prumerM[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	float	odchylka[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	float	pomf,prumer,skok=0;
	int		pomi;
	int		mesic1[2]={0,0};
	int		mesic2[2]={0,0};
	char	c;

// tisk hlavicky

	printf("Temperature table:\n\n\t");

	while((k<(strlen(mon))))
	{	
		if (mon[k]==',') printf("   ");		
		else printf("%c",mon[k]);
		k++;
	}	

	printf("\n");

// tisk roku a teplot
	k=0;
	do		
	{
		printf("%d:  ",1995+k);
		for(m=0;m<12;m++)
		{
			if ((temp[k][m]>=0) && (temp[k][m])<10) printf(" %.1f  ",temp[k][m]);
			else printf("%.1f  ",temp[k][m]);
		}
		printf("\n");
		k++;
	}
	while(k<16);

	printf("\n");

// prumerna mesicni teplota
	
	
	
	//hlavicka

	printf("Average temperature in month (in period 1996-2000, 2001-2005, 2006-2010):\n\n\t      ");
	for(n=0;n<strlen(mon);n++)
	{	
		if (mon[n]==',')
		{
			printf("   ");
			continue;
		}
			
		printf("%c",mon[n]);
	}	
	printf("\n");
		
	//tisk prumernych teplot

	for(i=1;i<4;i++)
	{
		pom1+=5;
		
		switch (i)
		{
			case 1: printf("%d-%d:   ",1996,2000);	break;
			case 2: printf("%d-%d:   ",2001,2005);	break;
			case 3: printf("%d-%d:   ",2006,2010);	break;
			default:;
		}

		for(m=0;m<12;m++)
		{	
			prumer=0;
 			for(n=pom2;n<pom1;n++)
			{
				prumer+=temp[n][m];		
			}

			if (((prumer/5)>=0) && ((prumer/5)<10)) printf(" %.1f  ", prumer/5);
			else printf("%.1f  ", prumer/5);				
		}				
		pom2+=5;		
		printf("\n");
	}

//nejchladnejsi mesic

	//hlavicka
	printf("\n");
	printf("The coldest month in period (1996-2010):\n");
	printf("\n\t        ");
	for(n=0;n<strlen(mon);n++)
	{	
		if (mon[n]==',')
		{
			printf("   ");
			continue;
		}
			
		printf("%c",mon[n]);
	}	

	//tisk let
	
	printf("\n");
	printf("Year       :   ");
	
	for(m=0;m<12;m++)
	{
		for(n=0;n<16;n++)
		{
			if (temp[n][m]<=temp[coldest[m]][m]) coldest[m]=n;
		}	
		printf("%d  ", 1995+coldest[m]);
	}
	
	//tisk teplot

	printf("\n");
	printf("Temperature:   ");	
	for(m=0;m<12;m++)
	{	
		if ((temp[coldest[m]][m]>=0) && (temp[coldest[m]][m])<10) printf(" %.1f  ",temp[coldest[m]][m]);
			else printf("%.1f  ",temp[coldest[m]][m]);	
	}
	printf("\n");

//nejteplejsi mesic

	//hlavicka
	printf("\n");
	printf("The hottest month in period (1996-2010):\n");
	printf("\n\t        ");
	for(n=0;n<strlen(mon);n++)
	{	
		if (mon[n]==',')
		{
			printf("   ");
			continue;
		}
			
		printf("%c",mon[n]);
	}	

	//tisk let
	
	printf("\n");
	printf("Year       :   ");
	
	for(m=0;m<12;m++)
	{
		for(n=0;n<16;n++)
		{
			if (temp[n][m]>=temp[hottest[m]][m]) hottest[m]=n;
		}	
		printf("%d  ", 1995+hottest[m]);
	}
	
	//tisk teplot

	printf("\n");
	printf("Temperature:   ");	
	for(m=0;m<12;m++)
	{	
		if ((temp[hottest[m]][m]>=0) && (temp[hottest[m]][m])<10) printf(" %.1f  ",temp[hottest[m]][m]);
			else printf("%.1f  ",temp[hottest[m]][m]);	
	}
	printf("\n");

//Vypocet prumeru a smerodatnych odchylek

	//hlavicka
	printf("\n");
	printf("Mean and standart deviation of temperature in month:\n");
	printf("\n\t\t       ");
	for(n=0;n<strlen(mon);n++)
	{	
		if (mon[n]==',')
		{
			printf("   ");
			continue;
		}
			
		printf("%c",mon[n]);
	}
	printf("\n");

	//prumer
	
	for(m=0;m<12;m++)
	{
		prumer=0;
		for (n=0;n<16;n++)
		{
		prumer+=temp[n][m];
		}
		prumerT[m]=prumer/16;
	}

	//prumer mocnin

	for(m=0;m<12;m++)
	{
		prumer=0;
		for (n=0;n<16;n++)
		{
		prumer=prumer + temp[n][m]*temp[n][m];
		}
		prumerM[m]=prumer/16;
	}
	
	//smerodatna odchylka
	
	for(m=0;m<12;m++)
	{
		odchylka[m]=sqrt(prumerM[m]-prumerT[m]*prumerT[m]);	
	}
	
	//tisk prumeru
	printf("Mean val. [deg. C]:   ");
	for(m=0;m<12;m++)
	{
		if ((prumerT[m]>=0) && (prumerT[m])<10) printf(" %.1f  ",prumerT[m]);
			else printf("%.1f  ",prumerT[m]);
	}
	printf("\n");
	
	//tisk odchylky
	printf("St. dev. [deg. C]:    ");
	for(m=0;m<12;m++)
	{
		printf("%.2f  ",odchylka[m]);
	}
	printf("\n\n");

//maximalni teplotni skok
	
	for(n=0;n<16;n++)
	{
		for(m=0;m<11;m++)
		{
			if ((fabs(temp[n][m+1]-temp[n][m]))>fabs(skok))
			{
				skok=temp[n][m+1]-temp[n][m];
				mesic1[0]=n;
				mesic1[1]=m;
				mesic2[0]=n;
				mesic2[1]=m+1;
			}
		}
		if (n<15)
		{
			if ((fabs(temp[n][11]-temp[n+1][0]))>fabs(skok))
			{
			skok=temp[n][11]-temp[n+1][0];
			mesic1[0]=n;
			mesic1[1]=11;
			mesic2[0]=n+1;
			mesic2[1]=0;
			}
		}
	}

	printf("The maximum change of temperature happened between %d/%d and %d/%d.\n", mesic1[1]+1, mesic1[0]+1995, mesic2[1]+1,mesic2[0]+1995);
	printf("The difference of temperature was %.1f deg. C.\n\n", skok);

//setrizeni bubble sortem mesic cervenec
	
	//trizeni
	for(m=0;m<15;m++)
	{	
		//i=0;
		for(n=0;n<15;n++)
		{
			krok++;	
			if(temp[n][6]>temp[n+1][6])
			{
				pomf=temp[n+1][6];
				temp[n+1][6]=temp[n][6];
				temp[n][6]=pomf;
				
				pomi=rok[n+1];
				rok[n+1]=rok[n];
				rok[n]=pomi;
				//i++;
				
			}
		}
		//if (i==0) break;
	}
	
	//tisk

	for(n=0;n<16;n++)
	{
		printf("%d => %.1f\n",rok[n]+1995,temp[n][6]);
	}
	printf("\n");
	printf("%d steps was performed during sorting.", krok);

	scanf("%c", &c);
	
	return 0;
}

