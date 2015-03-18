/*
 * Vzoreèky do matiky
 *
 * Program pro vypocet obvodu kruhu
 * ================================
 * 
 * O. Svec, 20. rijen 2006
 *
 */

#include <stdio.h>
#include <math.h>

#define PI 3.1415

int j;


int kruh(){

  double o, s, r;
  int i;
  
  printf("\nCo chcete pocitat:\n");
  printf("Obvod a obsah z polomeru.....1\n");
  printf("Polomer a obsah z obvodu.....2\n");
  printf("Polomer a obvod z obsahu.....3\n\n");

  printf("Vybrana moznost u kruhu: ");
  scanf("%d", &i);


  
  if(i == 1){    
    printf("Zadejte polomer kruhu: ");
    if((scanf("%lf", &r))){
  
      printf("Obvod kruhu je: %f", 2 * PI * r);      //obvod z polomeru
      printf("\nObsah kruhu je: %f", PI * r * r);      //obsah z polomeru

      }
    else {printf("\nVami vlozena hodnota neni cislo!!!\n\n");}
  }


  
  if(i == 2){
    printf("Zadejte obvod kruhu: ");
    if((scanf("%lf", &o))){
  
      printf("Polomer kruhu je: %f", o/(2 * PI));      //polomer z obvodu
      printf("\nObsah kruhu je: %f", PI * pow(o / (2 * PI), 2));      //obsah z obvodu

      }
    else {printf("\nVami vlozena hodnota neni cislo!!!\n\n");}
  }



  if(i == 3){
    printf("Zadejte obsah kruhu: ");
    if((scanf("%lf", &s))){
  
      r = sqrt(s/PI);
      printf("Polomer kruhu je: %f", r);      //polomer z obsahu
      printf("\nObvod kruhu je: %f", 2 * PI * r);      //obvod z obsahu

      }
    else {printf("\nVami vlozena hodnota neni cislo!!!\n\n");}
  }

}


int ctverec(){

  double o, s, a, u;
  int i;
  
  if(j != 0){printf("\n\n");}

  printf("\nCo chcete pocitat:\n");
  printf("Obvod, obsah a uhlopricku ze strany.....1\n");
  printf("Stranu, obsah a uhlopricku z obvodu.....2\n");
  printf("Stranu, obvod a uhlopricku z obsahu.....3\n");
  printf("Stranu, obvod a obsah z uhlopricky......4\n\n");

  printf("Vybrana moznost u ctverce: ");
  scanf("%d", &i);

  if(i == 1){    
    printf("Zadejte delku strany: ");
    if((scanf("%lf", &a))){
  
      printf("Obvod ctverce je: %f", 4 * a);      //obvod ze strany
      printf("\nObsah ctverce je: %f", a * a);      //obsah ze strany
      printf("\nUhlopricka ctverce je: %f", sqrt(a * a + a * a));      //uhlopricka ze strany
  
      }
    else {printf("\nVami vlozena hodnota neni cislo!!!\n\n");}
  }

  if(i == 2){    
    printf("Zadejte obvod ctverce: ");
    if((scanf("%lf", &o))){
  
      a = o / 4;
      printf("Strana ctverce je: %f", a);                     //strana z obvodu
      printf("\nObsah ctverce je: %f", a * a);                //obsah z obvodu
      printf("\nUhlopricka ctverce je: %f", sqrt(a * a + a * a));      //uhlopricka z obvodu
 
  
      }
    else {printf("\nVami vlozena hodnota neni cislo!!!\n\n");}
  }


  if(i == 3){    
    printf("Zadejte obsah ctverce: ");
    if((scanf("%lf", &s))){
  
      a = sqrt(s);
      printf("Strana ctverce je: %f", a);                      //strana z obsahu
      printf("\nObvod ctverce je: %f", a * 4);                 //obvod z obsahu
      printf("\nUhlopricka ctverce je: %f", sqrt(a * a + a * a));      //uhlopricka z obsahu
  
      }
    else {printf("\nVami vlozena hodnota neni cislo!!!\n\n");}
  }


  if(i == 4){    
    printf("Zadejte uhlopricku ctverce: ");
    if((scanf("%lf", &u))){
  
      a = sqrt(u * u / 2);
      printf("Strana ctverce je: %f", a);           //strana z uhlopricky
      printf("\nObsah ctverce je: %f", a * a);      //obsah  z uhlopricky
      printf("\nObvod ctverce je: %f", a * 4);      //obvod z uhlopricky
  
      }
    else {printf("\nVami vlozena hodnota neni cislo!!!\n\n");}
  }

}

int main(){

  int r, i, j = 0;

  do {
    
    if(j != 0){printf("\n\n\n");}
    
    printf("Kruh.........................1\n");
    printf("Ctverec......................2\n");
    
    printf("\nVybrana moznost: ");
    scanf("%d", &i);
    
    if(i == 1){kruh();}
    if(i == 2){ctverec();}
    
    j++;
  } while( (r = getchar() )!=EOF );


}
