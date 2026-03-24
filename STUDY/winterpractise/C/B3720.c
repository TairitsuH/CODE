#include<stdio.h>
int main()
{
  char n;
  int B = 0, C = 0;
  long long x;
  scanf("%lld",&x);
  getchar();
  while(1)
  {
    n = getchar();
    
    if(n == '\n')
    {
      break;
    }

    switch(n)
    {
      case 'B':
      {
        B++;
        break;
      }
      case 'C':
      {
        C++;
        break;
      }
    }
  }
  if(B == 0 && C == 0)
  {
    printf("%lld",x);
  }
  else if(B == 0 && C != 0)
  {
    printf("%lld",7*x/10);
  }
  else if(B != 0 && C != 0)
  {
    printf("%lld",6*x/10);
  }
  else
  {
    printf("%lld",8*x/10);
  }
  return 0;
}