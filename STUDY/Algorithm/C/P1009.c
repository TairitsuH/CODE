#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j;
    double S;
    double sum = 0, S1 = 1;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        S1 = 1;
        for(j=1; j<=i; j++)
        {
            S1 *= j;
        }
        sum += S1;
    }
    printf("%.0lf",sum);
    return 0;
}