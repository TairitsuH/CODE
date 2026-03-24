#include<stdio.h>
int main()
{
  long long m = 0,n;
  int a = 3;
  while(a)
  {
    scanf("%lld",&n);
    if(a==3)
    {
      m = n;
    }
    if(n>m)
    {
      m = n;
    }
    a--;
  }
  printf("%lld",m);
  return 0;
}