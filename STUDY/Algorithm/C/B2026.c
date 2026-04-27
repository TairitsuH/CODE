#include<stdio.h>
#include<stdbool.h>
int main()
{
  double a,b;
  scanf("%lf%lf",&a,&b);
  int k = (int)a/b;
  double r = a-k*b;
  printf("%.4f",r);
  return 0;
}