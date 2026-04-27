#include<stdio.h>
int main()
{
    int flag = 0;
    int x;
    scanf("%d",&x);
    if(x % 2==0)
    {
        flag++;
    }
    if(4<x && x<=12)
    {
        flag++;
    }
    switch(flag)
    {
        case 2:
        {
            printf("1 1 0 0");
            break;
        }
        case 1:
        {
            printf("0 1 1 0");
            break;
        }
        case 0:
        {
            printf("0 0 0 1");
            break;
        }
    }
    return 0;
}