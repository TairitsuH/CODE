#include<stdio.h>
int main()
{
    int n,i;
    int num;
    scanf("%d",&n);
    int arr[1000] = {0};
    arr[0] = n;
    if(n == 1)
    {
        printf("1");
    }
    else
    {
        for(i=1; i<1000; i++)
        {
            if(n % 2 == 0)
            {
                num = n/2;
            }
            else
            {
                num = n*3+1;
            }
            n = num;
            arr[i] = num;
            if(num == 1)
            {
                break;
            }
        }
        for(i=999; i>=0; i--)
        {
            if(arr[i] != 0)
            {
                printf("%d ",arr[i]);
            }
        }
    }
    return 0;
}