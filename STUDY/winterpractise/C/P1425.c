#include<stdio.h>
#include<math.h>
int main()
{
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  int start = a*60+b;
  int end = c*60+d;
  int time = end - start;
  int h = time / 60;
  int m = time - h * 60;
  printf("%d %d",h,m);
  return 0;
}