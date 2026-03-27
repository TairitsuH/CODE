#include<stdio.h>
#include "game.c"
#include "game.h"



void menu()
{
    printf("********扫雷游戏*********\n"
           "*********1.PLAY**********\n"
           "*********0.EXIT**********\n"
           "*************************\n");
}

void game()
{
    char mine[ROWS][COLS];
    char show[ROWS][COLS];

    InitBoard(show, ROWS, COLS, '*');
    InitBoard(mine, ROWS, COLS, '0');

    SetMine(mine, ROW, COL); //只布置在有效位置！

    FindMine(mine, show, ROW, COL);

    printf("\n按任意键继续...");
    getchar(); //吸收最后一次输入的回车
    getchar(); //按任意键继续

}

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择：\n>");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
            {
                game();
                break;
            }
            case 0:
            {
                printf("退出游戏中……\n");
                break;
            }
            default:
            {
                printf("输入错误，请重新输入\n>");
                break;
            }
        }
    }while(input);
    return 0;
}