#include<stdio.h>
#include<math.h>
int main()
{
  double a,b,c,x1,x2;
  double del;
  scanf("%lf%lf%lf",&a,&b,&c);
  del = b*b - 4*a*c;
  if(del == 0)
  {
    x1 = (-b-sqrt(b*b-4*a*c))/(2*a);
    printf("x1=x2=%.5lf",x1);
  }
  else if(del > 0)
  {
    x1 = (-b-sqrt(b*b-4*a*c))/(2*a);
    x2 = (-b+sqrt(b*b-4*a*c))/(2*a);
    if(x1>x2)
    {
      double mid;
      mid = x2;
      x2 = x1;
      x1 = mid;
    }
    printf("x1=%.5lf;x2=%.5lf",x1,x2);
  }
  else
  {
    printf("No answer!");
  }
  return 0;
}