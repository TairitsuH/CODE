#include<stdio.h>
int main()
{
    int k;
    int n = 1;
    double sum = 0;
    scanf("%d",&k);
    while(1)
    {
        sum += 1.0/n;
        if(sum <= k)
        {
            n++;
        }
        else
        {
            break;
        }
    }
    printf("%d",n);
    return 0;
}