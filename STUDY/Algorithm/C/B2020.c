#include<stdio.h>
int main()
{
    int i;
    int sum = 0;
    int arr[5];
    for(i=0; i<5; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0; i<5; i++)
    {
        sum += arr[i] % 3;
        if(i == 0)
        {
            arr[i] /= 3;
            arr[4] += arr[i];
            arr[i+1] += arr[i];
        }
        else if(i == 4)
        {
            arr[i] /= 3;
            arr[0] += arr[i];
            arr[i-1] += arr[i];
        }
        else
        {
            arr[i] /= 3;
            arr[i+1] += arr[i];
            arr[i-1] += arr[i];
        }
    }

    for(i=0; i<5; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n%d",sum);

    return 0;
}