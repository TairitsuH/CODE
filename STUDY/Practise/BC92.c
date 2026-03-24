#include<stdio.h>
int main()
{
    long long a[10];
    for(int i=0; i<10; i++)
    {
        scanf("%lld",&a[i]);
    }

    for(int i=9; i>=0; i--)
    {
        printf("%lld ",a[i]);
    }

    return 0;
}