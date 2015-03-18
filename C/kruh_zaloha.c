/*
 * Obvod kruhu  ver. 2
 *
 * Program pro vypocet obvodu kruhu
 * ================================
 * 
 * O. Svec, 20. rijen 2006
 *
 */

#include <stdio.h>
#include <ctype.h>

#define PI 3.1415

double obvod_kruhu(double r){

  double obvod_kruhu, obsah_kruhu;

  obvod_kruhu = 2 * PI * (r);

  printf("Obvod kruhu je: %f", obvod_kruhu);


  obsah_kruhu = PI * (r) * (r);


  printf("\nObsah kruhu je: %f", obsah_kruhu);

}


int main(){

  double r;
  int j = 0;
  
  do {
  
  if(j != 0){printf("\n\n");}
      
  printf("Zadejte polomer kruhu: ");
  
  scanf("%lf", &r);
  
  obvod_kruhu(r);
  
  j++;
  } while( (r = getchar() )!=EOF );


}
