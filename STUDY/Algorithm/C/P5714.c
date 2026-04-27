#include<stdio.h>
int main()
{
    double m,h;
    scanf("%lf%lf",&m,&h);
    double bmi = m/h/h;
    if(bmi<18.5)
    {
        printf("Underweight");
    }
    else if(bmi>=18.5 && bmi<24)
    {
        printf("Normal");
    }
    else
    {
        printf("%.6g\nOverweight",bmi);
    }
    return 0;
}