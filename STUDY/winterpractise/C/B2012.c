#include<stdio.h>
int main()
{
  double a,b;
  scanf("%lf%lf",&a,&b);
  printf("%.3f%%",b/a*100);
}