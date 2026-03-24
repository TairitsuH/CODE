#include<stdio.h>
int main()
{
    int n,i,j;
    int flag = 1;
    scanf("%d",&n);
    int arr[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int mid;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag = 0;
                mid = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = mid;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }

    printf("%d",arr[0]);
    return 0;
}