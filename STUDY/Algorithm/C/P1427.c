#include<stdio.h>
int main()
{
    int arr[100] = {0};
    int i;
    for(i=0; i<100; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i] == 0)
        {
            break;
        }
    }
    for(i=99; i>=0; i--)
    {
        if(arr[i] != 0)
        {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}