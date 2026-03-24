#include<stdio.h>
int main()
{
  int x,money;
  char c;
  scanf("%d %c",&x,&c);
  if(x<=1000)
  {
    money = 8;
  }
  else if(x>1000)
  {
    int N;
    N = (x-1000) / 500;

    if((x-1000)%500 != 0)
    {
      N += 1;
    }
    money = 8 + 4 * N;
  }
  switch(c)
  {
    case 'y':
    {
      printf("%d",money+5);
      break;
    }
    case 'n':
    {
      printf("%d",money);
      break;
    }
  }
  return 0;
}