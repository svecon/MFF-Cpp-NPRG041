#include <stdio.h>      /* MALÁ PÍSMENA NA VELKÁ */

int main()
{
int c, d, j = 0, l = 0;

printf("Chcete konvertovat z malych pismen na velke (1) nebo z velkych na male(2)???");

if((d = getchar()) == '1'){

int male_velke(){

j = 1;

  printf("Text: \n");

while((c = getchar()) != '\n'){
  if (c <= 'z' && c >= 'a') {c = c + 'A' - 'a';}

  if(j == 1)
    printf("\nVelke: \n");
  printf("%c", c);
  j++;
  }
if (c == '\n')
  if (j != 1)
    printf("\n\n\n");

male_velke();

} /* KONEC FCE MALE NA VELKE */

male_velke();

} /* KONECPODMÍNKY MALE NA VELKE */




else{

int velke_male(){

j = 1;

  printf("Text: \n");


while((c = getchar()) != '\n'){
  if (c <= 'Z' && c >= 'A') {c = c + 'a' - 'A';}

  if(j == 1)
    printf("\nMale: \n");
  printf("%c", c);
  j++;
  }
if (c == '\n')
  if (j != 1)
    printf("\n\n\n");

velke_male();

} /* KONEC FCE MALE NA VELKE */

velke_male();

} /* KONECPODMÍNKY MALE NA VELKE */
  

} /* KONEC MAIN() */
