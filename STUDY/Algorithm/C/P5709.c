#include<stdio.h>
int main()
{
    int m,t,s;
    float S;
    scanf("%d%d%d",&m,&t,&s);
    if(t==0||m*t<=s)
    {
        printf("0");
    }
    else
    {
        S = s;
        if(s/t==S/t)
        {
            printf("%d",m-s/t);
        }
        else
        {
            printf("%d",m-1-s/t);

        }
    }
    return 0;
}