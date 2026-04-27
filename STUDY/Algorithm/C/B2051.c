#include<stdio.h>
int main()
{
  int x,y;
  scanf("%d%d",&x,&y);
  if((-1<=x&&x<=1)&&(-1<=y&&y<=1))
  {
    printf("yes");
  }
  else
  {
    printf("no");
  }
  return 0;
}