#include<stdio.h>
int main()
{
    int a,b,c;
    int mid;
    scanf("%d%d%d",&a,&b,&c);
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
    printf("%d %d %d",a,b,c);
    return 0;
}