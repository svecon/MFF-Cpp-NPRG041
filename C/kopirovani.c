#include <stdio.h>      /* KOPÍROVÁNÍ OBSAHU TEXTOVÉHO SOUBORU */

int main()
{
FILE *fr, *fw;
int c;
fr = fopen("orig.txt", "r");    /* MUSÍ EXISTOVAT */
fw = fopen("kopie.txt", "w");

while ((c = getc(fr)) != EOF)
  putc(c, fw);

fclose(fw);
fclose(fr);
return 0;
}
