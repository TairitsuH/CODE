#include<stdio.h>
int main()
{
  int i = 0;
  int score = 0;
  int flag = 0;
  for(i = 0; i < 3; i++)
  {
    scanf("%d",&score);
    if(score < 60)
    {
      flag++;
    }
  }
  if(flag == 1)
  {
    printf("1");
  }
  else
  {
    printf("0");
  }
  return 0;
}