#include<stdio.h>
int main()
{
    int M,N;
    scanf("%d%d",&M,&N);
    int num[10] = {0};
    for(int i=M; i<=N; i++)
    {
        int n = i;
        while(n)
        {
            int p = n%10;
            num[p]++;
            n /= 10;
        }
    }

    for(int j=0; j<10; j++)
    {
        printf("%d ",num[j]);
    }
    return 0;
}