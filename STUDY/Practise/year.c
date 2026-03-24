#include<stdio.h>

int Leap_year(int a)
{
    if((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
    return 1;
    return 0;
}

int main()
{
    int year;
    scanf("%d",&year);
    if(Leap_year(year))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}