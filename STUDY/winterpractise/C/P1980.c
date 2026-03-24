#include<stdio.h>
int main()
{
    int n,x,i,N;
    int cnt = 0;
    int M = 1;
    scanf("%d%d",&n,&x);
    for(i=0; i<n; i++)
    {
        N = M;
        while(N)
        {
            if(N%10 == x)
            {
                cnt++;
            }
            N /= 10;
        }
        M++;
    }

    printf("%d",cnt);
    return 0;
}