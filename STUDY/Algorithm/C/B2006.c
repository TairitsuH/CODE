#include<stdio.h>
#include<math.h>
int main()
{
  double x,a,y,b;
  scanf("%lf%lf%lf%lf",&x,&a,&y,&b);
  double plus = (a*x-b*y)/(a-b);
  double begin = a*(x-plus);
  printf("%.2f",plus);
  return 0;
}