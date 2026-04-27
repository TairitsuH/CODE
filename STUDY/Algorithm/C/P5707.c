#include<stdio.h>
#include<math.h>
int main()
{
  int s,v,t;
  int h, m;
  scanf("%d%d",&s,&v);
  t = (s%v!=0?s/v+1:s/v)+10;//单位：分钟
  // scanf("%d",&t);
  if(t<480)//今天
  {
    m = 480 - t;
    h = m / 60;
    m = m - h * 60;
    printf("%02d:%02d",h,m);
  }
  else if(t>480)//昨天
  {
    t = t - 480;
    if(t/60==0)
    {
      h = 0;
    }
    else
    {
      h = 23 - t / 60;
    }
    m = 60 - (t % 60);
    if(m==60)
    {
      m=0;
      h = (h+1)%24;
    }
    printf("%02d:%02d",h,m);
  }
  else
  {
    printf("00:00");
  }
  return 0;
}