#include<stdio.h>
#include<math.h>
int main()
{
  double a,b,c;
  scanf("%lf%lf%lf",&a,&b,&c);
  double p = 1/2.0*(a+b+c);
  double s = sqrt(p*(p-a)*(p-b)*(p-c));
  printf("%.1f",s);
  return 0;
}