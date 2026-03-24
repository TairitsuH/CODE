//猜数字游戏(范围：100~200)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void game()
  {
    int guess = 0;
    int count = 5;//五次猜数字机会
    int flag = 0;
    int r = 100+rand()%101;//生成随机数100~200（%101生成1~100，加上100变成100~200）
    //猜数字
    while(count)
    {
      printf("请猜数字：");
      scanf("%d",&guess);
      count--;//猜一次，次数就减1，直到用完
      if(guess > r)
      {
        printf("猜大了\n");
      }
      else if(guess < r)
      {
        printf("猜小了\n");
      }
      else
      {
        printf("恭喜你，猜对咯~\n");
        flag = 1;//跳出循环时flag==1则猜出来了
        break;//跳出猜数字循环，回到游戏菜单
      }
    }
    if(flag == 0)
      {
        printf("哎呀...机会用完了！再试一次吧~\n");
      }
  }


int main()
{
  int input = 0;
  srand((unsigned int)time(NULL));//设置随机种子

  while(1)//游戏菜单
  {
    printf("*********************\n");
    printf("***1.play   0.exit***\n");
    printf("*********************\n");
    scanf("%d",&input);
    switch(input)
    {
      case 1:
      {
        printf("开始游戏\n");
        game();//调用game函数
        break;
      }
      case 0:
      {
        printf("退出游戏\n");
        goto end;
      }
      default:
      {
        printf("请检查输入O.o? 再试一次吧\n");
        break;
      }
    }
  }
  end:
  return 0;
}