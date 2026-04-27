#include<stdio.h>
int main()
{
    int i;
    int flag = 1;
    int now = 0, cost = 0,sum = 0;
    double bank = 0;
    for(i=1; i<=12; i++)
    {
        now += 300;
        scanf("%d",&cost);
        if(cost > now)
        {
            flag = 0;
            printf("-%d\n",i);
            break;
        }
        now -= cost;
        if(now >= 100)
        {
            bank += now/100*100;
            now %= 100; 
        }
    }
    if(flag == 1)
    {
        sum = bank*1.2 + now;
        printf("%d\n",sum);
    }
    return 0;
}