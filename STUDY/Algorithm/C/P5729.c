#include<stdio.h>
int main()
{
    int q,a,b,c;
    scanf("%d%d%d%d",&a,&b,&c,&q);
    int arr[a+1][b+1][c+1];//方块数
    int i,j,k;
    for(i=1; i<=a; i++)
    {
        for(j=1; j<=b; j++)
        {
            for(k=1; k<=c; k++)
            {
                arr[i][j][k] = 1;
            }
        }
    }

    for(int l=0; l<q; l++)
    {
        int x1,y1,z1,x2,y2,z2;
        scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2); 
        for(i=x1; i<=x2; i++)
        {
            for(j=y1; j<=y2; j++)
            {
                for(k=z1; k<=z2; k++)
                {
                    arr[i][j][k] = 0;
                }
            }
        }
    }

    int  count = 0;
    for(i=1; i<=a; i++)
    {
        for(j=1; j<=b; j++)
        {
            for(k=1; k<=c; k++)
            {
                if(arr[i][j][k] == 1)
                {
                    count++;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}