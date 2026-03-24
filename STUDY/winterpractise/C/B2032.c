#include<stdio.h>
int main()
{
  int a1,a2,n;
  scanf("%d%d%d",&a1,&a2,&n);
  int d = a2 - a1;
  int an = a1+(n-1)*d;
  printf("%d",an);
  return 0;
}