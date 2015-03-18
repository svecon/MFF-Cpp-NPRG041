#include <stdio.h>

int j = 0;

int deset2dva(int i, int nasobek) {

  if (j == 0){ printf("Vysledne cislo ve dvojkove soustave:\n"); j++; }

  if(i >= (nasobek * 2)){
  
  nasobek *= 2;
  
  deset2dva(i, nasobek);
  
  }
  
  else if(i == 0 && nasobek != 1){
  
  printf("0");
  
  nasobek /= 2;
  
  deset2dva(i, nasobek);
  }
  
  else if(i == 0 || nasobek == 1){
  
  if (i == 0){ printf("0"); }
  else { printf("1"); }

  printf("\n\n");

  main();
  }
 
  else if(i < nasobek){
  
  nasobek /= 2;
  
  printf("0");
  
  deset2dva(i, nasobek);
  
  }
  
  else if (i >= nasobek){
  
  i -= nasobek;
  
  nasobek /= 2;
  
  printf("1");
  
  deset2dva(i, nasobek);
  
  }
}

int main(){
  
  int i;

  printf("Zadejte cele cislo v desitkove soustave:\n");

  if(scanf("%d", &i)){

    deset2dva(i, 2);
  }
  
  main();
  
}
