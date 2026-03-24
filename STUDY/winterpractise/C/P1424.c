#include<stdio.h>
int main()
{
    int x,n,i;
    int sum = 0;
    scanf("%d%d",&x,&n);
    for(i=0; i<n; i++)
    {
        if(x!=6 && x!=7)
        {
            sum += 250;
        }
        x++;
        if(x > 7)
        {
            x = 1;
        }
    }
    printf("%d",sum);
    return 0;
}