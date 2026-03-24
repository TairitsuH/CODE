#include<stdio.h>
int main()
{
  int n,i;
  scanf("%d",&n);
  for(i=0; i<3; i++)
  {
    int m = n%10;
    printf("%d",m);
    n/=10;
  }
  return 0;
}