#include<stdio.h>
int main()
{
  int a,b;
  scanf("%d.%d",&a,&b);
  int reversed_a = 0;
  while(a)
  {
    reversed_a = reversed_a*10+a%10;
    a/=10;
  }
  printf("%d.%d",b,reversed_a);
  return 0;
}