#include <stdio.h>

int main()
{
double x, y, z, max;
printf("Zadej tri realna cisla: \n");
scanf("%lf %lf %lf", &x, &y, &z);

if (x > y) {
  if (x >z)
    max = x;
  else
    max = z;
}
else {
  if (y < z)
    max = z;
  else
    max = y;
}

printf("Nejvetsi cislo je %f\n\n", max);

main();


}
