#include <stdio.h>      /* KOP�ROV�N� OBSAHU TEXTOV�HO SOUBORU */

int main()
{
FILE *fr, *fw;
int c;
fr = fopen("orig.txt", "r");    /* MUS� EXISTOVAT */
fw = fopen("kopie.txt", "w");

while ((c = getc(fr)) != EOF)
  putc(c, fw);

fclose(fw);
fclose(fr);
return 0;
}
