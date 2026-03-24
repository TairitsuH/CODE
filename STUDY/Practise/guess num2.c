//猜数字，有限机会7次，范围200~300
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void game()
{
  int guess = 0;
  int count = 7;
  int flag = 0;
  int r = 200+rand()%101;//设置范围200~300
  while(count)
  {
    printf("请输入数字：\n");
    scanf("%d",&guess);
    count--;
    if(guess > r)
    {
      printf("猜大了，请重新猜吧\n");
    }
    else if(guess<r)
    {
      printf("猜小了，请重新猜吧\n");
    }
    else
    {
      flag += 1;
      break;
    }
  }
  if(flag==0)
  {
    printf("哎呀，机会用完了，游戏结束\n");
  }
  else
  {
    printf("恭喜你，猜对啦！\n");
  }
}



int main()
{
  srand((unsigned int)time(NULL));
  int guess = 0;
  printf("*************************\n");
  printf("*************************\n");
  printf("****1.play*****2.exit****\n");
  printf("*************************\n");
  printf("*************************\n");
  int input = 0;
  scanf("%d",&input);
  switch(input)
  {
    case 1:
    {
     printf("开始游戏\n");
      game();
      break;
    }
    case 0:
    {
     printf("游戏结束\n");
     goto end;
    }
    default:
    {
      printf("输入错误，请重新输入：\n");
      break;
    }
  }
  end:
  return 0;
}