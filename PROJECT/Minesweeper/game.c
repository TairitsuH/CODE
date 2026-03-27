#include "game.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char set) //初始化棋盘
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) //打印棋盘
{
    printf("-------MineSweeper--------\n");
    printf("  ");
    for(int i=1; i<=col; i++)
    {
        printf("%d ", i); //打印坐标（从0开始）
    }
    printf("\n");

    for(int i=1; i<=row; i++) //打印棋盘（不打印外圈）
    {
        printf("%d ", i);
        for(int j=1; j<=col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void SetMine(char mine[ROWS][COLS], int row, int col) //布置雷
{
    int count = MINE;
    while(count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if(mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count--;
        }
    }
}

int AroundMine(char mine[ROWS][COLS], int x, int y) //计算周围雷的数量
{
    int a = mine[x-1][y] + mine[x+1][y] + mine[x][y-1]
     + mine[x][y+1] + mine[x-1][y-1] + mine[x+1][y+1]
      + mine[x-1][y+1] + mine[x+1][y-1] - 8 * '0';
      return a;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) //排查雷
{
    int x = 0;
    int y = 0;
    int win = 0;
    int time = 3;
    while(win < row * col - MINE)
    {
        DisplayBoard(show, ROW, COL);
        printf("请输入要排查的坐标：\n>");
        scanf("%d%d", &x, &y); //检查合理性！！
        if(x > 0 && x <= row && y > 0 && y <= col)
        {
            if(mine[x][y] == '1')
            {
                time--;
                if(time > 0)
                {
                    printf("踩到雷了！你还有%d次机会TvT\n", time);
                    
                }
                else
                {
                    printf("排雷次数已用尽，很遗憾，你被炸死了TAT\n");
                    DisplayBoard(mine, ROW, COL);
                    break;
                }
            }
            else if(show[x][y] == '*')
            {
                win++;
                int a = AroundMine(mine, x, y);
                show[x][y] = a + '0';
                if(win == row * col - MINE) printf("恭喜！已你成功排查所有雷！[]~(￣▽￣)~*\n");
                else printf("排查成功！请继续......\n");
            }
            else
            {
                printf("该坐标已经排查！\n");
            }
        }
        else
        {
            printf("请输入有效坐标！\n");
        }
    }
} 