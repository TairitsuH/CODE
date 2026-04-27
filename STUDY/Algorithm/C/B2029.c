// 大象喝水：AC
#include<stdio.h>
#include<math.h>
int main()
{
  int r = 0;
  int h = 0;
  scanf("%d%d",&h,&r);
  float pai = 3.14;
  double S = pai*pow(r,2);
  double V = S * h;
  double T =fmod(20000,V); //fmod函数的功能是计算浮点数除法的余数
  int i = 20000/V;
  if(20000 > i * V)
  {
    printf("%d",i + 1);
  }
  else
  {
    printf("%d",i);
  }
  return 0;
}