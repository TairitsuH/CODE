#include<stdio.h>
int main()
{
    double sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; i++)
    {
        if(i%k == 0)
        {
            sum1 += i;
            cnt1 ++;
        }
        else
        {
            sum2 += i;
            cnt2 ++;
        }
    }
    double ave1 = sum1/cnt1;
    double ave2 = sum2/cnt2;
    printf("%.1lf %.1lf",ave1,ave2);

    return 0;
}