//关机小程序
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  char input[20];
  system("shutdown -s -t 60");
again:
  printf("请注意，电脑将在一分钟内关机，输入“我是猪”以取消程序：\n");
  scanf("%s",input);
  if(strcmp(input,"我是猪")==0)
  {
    system("shutdown -a");
    printf("关机已取消");
  }
  else
  {
    printf("内容不符，请重新输入：\n");
    goto again;
  }
  return 0;
}