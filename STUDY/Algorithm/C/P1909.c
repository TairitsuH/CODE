#include<stdio.h>
int main()
{
    int n,a,A,b,B,c,C,mid;
    int sum = 0;
    scanf("%d%d%d%d%d%d%d",&n,&a,&A,&b,&B,&c,&C);
    int n1,n2,n3;
    n1 = (n%a==0?n/a:n/a+1);
    n2 = (n%b==0?n/b:n/b+1);
    n3 = (n%c==0?n/c:n/c+1);
    long long sum1 = n1*A;
    long long sum2 = n2*B;
    long long sum3 = n3*C;
    if(sum1>sum2)
    {
        mid = sum1;
        sum1 = sum2;
        sum2 = mid;
    }
    if(sum2>sum3)
    {
        mid = sum3;
        sum3 = sum2;
        sum2 = mid;
    }
    if(sum1>sum2)
    {
        mid = sum1;
        sum1 = sum2;
        sum2 = mid;
    }

    printf("%lld",sum1);
    return 0;
}