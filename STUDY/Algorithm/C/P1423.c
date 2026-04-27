#include<stdio.h>
int main()
{
    double step = 2, sum = 0;
    int count = 0;
    double s;
    scanf("%lf",&s);
    while(sum < s)
    {
        sum += step;
        step *= 0.98;
        count++;
    }
    printf("%d",count);
    return 0;
}