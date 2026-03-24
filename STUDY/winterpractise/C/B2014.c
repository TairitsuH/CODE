#include<stdio.h>
int main()
{
  double r;
  double pai = 3.14159;
  scanf("%lf",&r);
  double d = 2*r;
  double C = 2*pai*r;
  double S = pai*r*r;
  printf("%.4f %.4f %.4f",d,C,S);
  return 0;
}