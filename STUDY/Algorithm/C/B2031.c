#include<stdio.h>
#include<math.h>
int main()
{
  double x1,x2,x3,y1,y2,y3;
  scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
  double a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  double b = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
  double c = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
  double p = 1/2.0*(a+b+c);
  double s = sqrt(p*(p-a)*(p-b)*(p-c));
  printf("%.2f",s);
  return 0;
}