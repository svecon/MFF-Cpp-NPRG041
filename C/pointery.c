/*
 * Pøehození promìnných
 *
 * Program, který pøehodí hodnoty 2 promìnných pomocí pointerù
 * ================================
 * 
 * O. Svec, 1. listopad 2006
 *
 */
 
 
#include <stdio.h>

int prehod(int *x, int *y){
    
  int pom;
  
  pom = *x;
  *x = *y;
  *y = pom;
  
}

int main(){

 int i = 2, j = 1;
  
  printf("Pred:\ni = %d\nj = %d\n\n", i, j);
  
  prehod(&i, &j);
  
  printf("Po:\ni = %d\nj = %d\n\n", i, j);
  
  j = getchar();
}
