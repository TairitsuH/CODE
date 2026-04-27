#include<stdio.h>
int main()
{
  int a,b;
  char ch;
  scanf("%d %d %c",&a,&b,&ch);
  switch(ch)
  {
    case '+':
    {
      printf("%d",a+b);
      break;
    }
    case '-':
    {
      printf("%d",a-b);
      break;
    }
    case '*':
    {
      printf("%d",a*b);
      break;
    }
    case '/':
    {
      if(b==0)
      {
        printf("Divided by zero!");
      }
      else
      {
        printf("%d",a/b);
      }
      break;
    }
    default:
    {
      printf("Invalid operator!");
      break;
    }
  }
  return 0;
}