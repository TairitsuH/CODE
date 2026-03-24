#include<stdio.h>
int main()
{
  double r;
  double pai = 3.14;
  scanf("%lf",&r);
  double V = (4/3.0)*pai*r*r*r;
  printf("%.5f",V);
  return 0;
}