#include<stdio.h>
#include<math.h>
int main()
{
  double Xa,Xb,Ya,Yb;
  scanf("%lf%lf%lf%lf",&Xa,&Ya,&Xb,&Yb);
  double L = sqrt((Xa-Xb)*(Xa-Xb)+(Ya-Yb)*(Ya-Yb));
  printf("%.3f",L);
  return 0;
}