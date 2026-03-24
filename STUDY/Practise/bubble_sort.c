//对数组进行输入并冒泡排序
#include<stdio.h>
void bubble_size(int arr[], int sz);

int main()
{
    int i;
    int arr[] = {2,4,6,3,5,8,9,7,10,1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    bubble_size(arr, sz);
    for(i=0; i<sz; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void bubble_size(int arr[], int sz)
{
    int i,j,mid;
    int flag =1;
    for(i=0; i<sz-1; i++)
    {
        for(j=0; j<sz-1-i; j++)
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
}