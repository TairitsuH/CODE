#include<stdio.h>
#include<math.h>
int main()
{
  int n,y;
  for(n=100; n<200; n++)
  {
    int isPrime = 1;
    int x = (int)sqrt(n);
    for(y=2; y<=x; y++)
    {
      if(n%y ==0)
      {
        isPrime = 0;
        break;
      }
    }
    if(isPrime == 1)
    {
      printf("%d ",n);
    }
  }
  return 0;
}