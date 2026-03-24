#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            arr[i][j] = 0;
        }
    }

    //填写1
    int a,b;
    a = 0;
    b = N/2;
    arr[a][b] = 1;
    for(int i=2; i<=N*N; i++)
    {
        if(a == 0 && b != N-1)
        {
            a = N-1;
            b += 1;
            arr[a][b] = i;
        }
        else if(b == N-1 && a != 0)
        {
            b = 0;
            a -= 1;
            arr[a][b] = i;
        }
        else if(a == 0 && b == N-1)
        {
            a += 1;
            arr[a][b] = i;
        }
        else if(a != 0 && b != N-1)
        {
            if(arr[a-1][b+1] == 0)
            {
                a -= 1;
                b += 1;
                arr[a][b] = i;
            }
            else
            {
                a += 1;
                arr[a][b] = i;
            }
        }
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}