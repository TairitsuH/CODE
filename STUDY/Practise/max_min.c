#include<stdio.h>
int main()
{
    int n,i,score;
    int a=0, b=100;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&score);
        if(score > a)
        {
            a = score;
        }
        if(score < b)
        {
            b = score;
        }
    }
    printf("%d",a-b);
    return 0;
}