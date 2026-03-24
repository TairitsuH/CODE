#include<stdio.h>
int main()
{
    int a = 1, b = 1;
    for(int i=1; i<=9; i++) //行
    {
        for(int j=1; j<=i; j++)
        {
            printf("%d * %d = %d ",i,j,i*j);
        }
        printf("\n");
    }
    return 0;
}