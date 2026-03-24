#include<stdio.h>
int main()
{
  double x,y;
  scanf("%lf",&x);
  if(x>=0&&x<5)
  {
    y = -x+2.5;
    printf("%.3f",y);
  }
  else if(x>=5&&x<10)
  {
    y = 2-1.5*(x-3)*(x-3);
    printf("%.3f",y);
  }
  else
  {
    y = x/2-1.5;
    printf("%.3f",y);
  }
  return 0;
}