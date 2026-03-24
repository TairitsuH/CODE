#include<stdio.h>

void bubble_sort(int sz, int arr[])
{
    for(int i=0; i<sz-1; i++)
    {
        for(int j=0; j<sz-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int mid = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = mid;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int arr1[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int sz = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(sz, arr);

    for(int i=0; i<n; i++)
    {
        arr1[i] = 1;
    }

    int count = 0;
    for(int i=2; i<n; i++)
    {
        for(int j=0; j<i-1; j++)
        {
            for(int k=j+1; k<i; k++)
            {
                if(arr[i] == arr[j] + arr[k])
                {
                    if(arr1[i] == 1)
                    {
                        count++;
                        arr1[i] = 0;
                    }
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}