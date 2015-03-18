#include <stdio.h>

int main(){
 
 int a;
 
 double i = 5.55;
 
 double *i_i = &i;
 
 printf("%lf\n\n", i);
 printf("%lf\n\n\n\n", *i_i);
 
 
 *i_i = 20;

 printf("%lf\n\n", i);
 printf("%lf", *i_i);
 
 a = getchar();

}
