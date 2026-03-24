#include<stdio.h>
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    unsigned long long c = a+b;
    printf("%llu",c);
    return 0;
}