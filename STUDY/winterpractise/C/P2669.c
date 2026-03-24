#include<stdio.h>
int main()
{
    int k,i;
    int n = 1, coin = 0, sum = 0,a = 2;
    scanf("%d",&k);
    if(k!=1)
    {
        while(sum<=k)
        {
            sum = (1+(n+1))*(n+1)/2;
            n++;
        }
        n--;
        coin = 1;
        for(i=0; i<n-1; i++)
        {
            coin += a*a;
            a++;
        }
        coin += (k-(1+n)*n/2)*(n+1);
    }
    else
    {
        coin = 1;
    }
    printf("%d",coin);
    return 0;
}