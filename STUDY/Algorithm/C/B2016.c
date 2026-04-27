#include<stdio.h>
#include<math.h>
int main()
{
  long double x;
  long long X = 0;
  scanf("%Lf",&x);
  if(x>0)
  {
    X = floor(x);
  }
  else if(x==0)
  {
    X = 0;
  }
  else
  {
    X = ceil(x);
  }
  printf("%ld",X);
  return 0;
}