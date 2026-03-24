#include<stdio.h>
int main()
{
    int N,i;
    int X = 100, K = 0;
    scanf("%d",&N);
    int n = N/52/7;
    if(n < X)
    {
        K = 1;
        X = n-3;
    }
    else
    {
        for(i=0; i<3; i++)
        {
            if((n - X) % 3 == 0)
            {
                K = (n - X) / 3;
                break;
            }
            X--;
        }
    }
    
    printf("%d\n%d",X,K);
    return 0;
}