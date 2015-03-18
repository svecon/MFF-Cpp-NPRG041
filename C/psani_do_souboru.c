#include <stdio.h>	/* PSANí DO SOUBORU */
#include <stdlib.h>

int main()
{
int c, j = -1, d, i, a = 0;
FILE *fw, *fr;

if((fr = fopen("TEXT.TXT", "r")) == NULL){
  printf("Prosim restartujte aplikaci.");
  fw = fopen("TEXT.TXT", "w");

getchar();
}

printf("Soubor zatim obsahje: ");

while(j++, (c = getc(fr)) != EOF){
  putchar(c);
}

printf("\nPrejete si zmenit jeho obsah? (A/N): ");


if((d = getchar()) == 'A'){
  printf("\n\nNyni muzete zapisovat do souboru: \n");

  fw = fopen("TEXT.TXT", "w");

while(a < 1){
 
i = getchar();

putc(i, fw);

}

}

}
