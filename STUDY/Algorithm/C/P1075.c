#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j;
    int max1 = 1;
    scanf("%d",&n);
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            int p = n / i;
            int flag = 1;
            for(j=2; j<=sqrt(p); j++)
            {
                if(p % j == 0)
                {
                    flag = 0;
                }
            }
            if(flag == 1)
            {
                printf("%d",p);
                break;
            }
        }
    }
    return 0;
}