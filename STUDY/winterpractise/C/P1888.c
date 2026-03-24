#include<stdio.h>
int main()
{
    long long a,b,c,mid,temp;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(a>b)
    {
        mid = a;
        a = b;
        b = mid;
    }
    if(b>c)
    {
        mid = c;
        c = b;
        b = mid;
    }
    if(a>b)
    {
        mid = a;
        a = b;
        b = mid;
    }

    long long A = a, C = c;
    while(A)
    {
        temp = C%A;
        C = A;
        A = temp;
    }
    a/=C;
    c/=C;
    printf("%lld/%lld",a,c);
    return 0;
}