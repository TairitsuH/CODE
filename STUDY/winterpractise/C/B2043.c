#include<stdio.h>
int main()
{
  int x;
  int flag =0;
  int a=0,b=0,c=0;
  scanf("%d",&x);

  //能被3整除
  if(x % 3 == 0)
  {
    flag++;
    a = 1;
  }

  //能被5整除
  if(x % 5 == 0)
  {
    flag++;
    b = 1;
  }

  //能被7整除
  if(x % 7 == 0)
  {
    flag++;
    c = 1;
  }

  if(flag == 3)
  {
    printf("3 5 7");
  }
  else if(flag == 2)
    {
      if(a==1 && b==1 && c==0)
      {
        printf("3 5");
      }
      else if(a==1 && c==1 && b==0 )
      {
        printf("3 7");
      }
      else
      {
        printf("5 7");
      }
    }
  else
  {
    printf("n");
  }
  return 0;
}