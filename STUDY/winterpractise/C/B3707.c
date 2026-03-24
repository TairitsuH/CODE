#include<stdio.h>
#include<math.h>
int main()
{
  int p,x0,y0,x1,y1;
  int flag = 0;
  scanf("%d%d%d%d%d",&p,&x0,&y0,&x1,&y1);
  switch(p)
  {
    case 1:
    {
      if(x0==x1||y0==y1)
      {
        flag++;
      }
      break;
    }
    case 2:
    {
      break;
    }
    case 3:
    {
      if((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)==5)
      {
        flag++;
      }
      break;
    }
    case 4:
    {
      if((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)==8)
      {
        flag++;
      }
      break;
    }
  }
  if(flag == 0)
  {
    printf("No");
  }
  else
  {
    printf("Yes");
  }
  return 0;
}