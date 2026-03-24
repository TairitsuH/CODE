#include<stdio.h>
int main()
{
    int L,i;
    int count = 0, sum = 0, n = 2,flag = 0;
    scanf("%d",&L);
    if(L < 2)
    {
        printf("0\n");
    }
    else
    {
        while(sum<L)
        {
            flag = 0;
            if(n == 2)
            {
                flag = 0;
            }
            else
            {
                for(i=2; i<n; i++)
                {
                    if(n%i == 0)
                    {
                        flag++;
                    }
                }   
            }
            if(flag == 0)
            {
                sum += n;
                if(sum>L)
                {
                    break;
                }
                else
                {
                    count++;
                    printf("%d\n",n); 
                }
            }
            n++;
        }
        printf("%d\n",count);
    }

    return 0;
}