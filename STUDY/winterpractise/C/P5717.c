#include<stdio.h>
int main()
{
    long long a,b,c,mid;
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
    if(a+b>c)
    {
        if(a*a+b*b==c*c)
        {
            printf("Right triangle\n");
        }
        else if(a*a+b*b>c*c)
        {
            printf("Acute triangle\n");
        }
        else
        {
            printf("Obtuse triangle\n");
        }

        if(a == b)
        {
            printf("Isosceles triangle\n");
        }
        if(a == b && b == c)
        {
            printf("Equilateral triangle\n");
        }
    }
    else
    {
        printf("Not triangle\n");
    }

    return 0;
}