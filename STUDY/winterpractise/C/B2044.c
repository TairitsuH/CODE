#include<stdio.h>
int main()
{
  int n;
  int x = 3;
  int flag = 0;
  while(x)
  {
    scanf("%d",&n);
    if(n<60)
    {
      flag++;
    }
    x--;
  }
  if(flag==1)
  {
    printf("1");
  }
  else
  {
    printf("0");
  }
  return 0;
}