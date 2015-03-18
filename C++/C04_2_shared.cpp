// Cv4_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char stext1[]="XIABDAWWFDUMZBEFDJQILCREBUIFBF";			// the first part of encrypted message
	char stext2[]="OULCREBUFYUBHFUTBGVMMBQAJOUTC";			// the second part of encrypted message
	char rtext[150];										// destination string
	char *ptr;
	char c;
	int n=0;

	printf("a) Concatenation:\n\n");
	strcpy(rtext,stext1);
	strcat(rtext,stext2);
	puts(rtext);

	printf("\nb) Replacement A=>P and W=>S:\n\n");
	ptr=strchr(rtext,'A');
	while(ptr)
	{
		*ptr='P';
		ptr=strchr(rtext,'A');
	}
	ptr=strchr(rtext,'W');
	while(ptr)
	{
		*ptr='S';
		ptr=strchr(rtext,'W');
	}
	puts(rtext);

	printf("\nc) Replacement LCR=>FSF:\n\n");
	ptr=strstr(rtext,"LCR");
	while(ptr)
	{
		strncpy(ptr,"FSF",3);
		ptr=strstr(rtext,"LCR");
	}
	puts(rtext);

	printf("\nd) Shift down in ASCII table:\n\n");
	while(rtext[n]!=NULL)
	{
		rtext[n]=rtext[n]-1;
		n++;
	}
	puts(rtext);

	printf("\ne) Replacement capital=>small:\n\n");
	for(n=1;rtext[n]!=NULL;n++)
	{
		rtext[n]=rtext[n]+32;
	}
	puts(rtext);

	printf("\nf) Replacement a=><space> and b=>. :\n\n");
	ptr=strchr(rtext,'a');
	while(ptr)
	{
		*ptr=' ';
		ptr=strchr(rtext,'a');
	}

	ptr=strchr(rtext,'b');
	while(ptr)
	{
		*ptr='.';
		ptr=strchr(rtext,'b');
	}
	puts(rtext);

	scanf("%c", &c);										// waiting for pressing key	
	return 0;
	return 0;
}

