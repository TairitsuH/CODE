#include<stdio.h>
#include<math.h>
int main()
{
    double a;
    int day = 0;
    scanf("%lf",&a);
    if(a == 1)
    {
        printf("1");
    }
    else
    {
        while(a != 1)
        {
            a /= 2;
            a = ceil(a);
            day++;
        }
    printf("%d",day);
    }
    return 0;
}