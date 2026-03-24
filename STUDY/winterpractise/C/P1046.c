#include<stdio.h>
int main()
{
    int arr[10];
    int height,i;
    int sum = 0;
    for(i=0; i<10; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&height);

    for(i=0; i<10; i++)
    {
        if(arr[i]<=height+30)
        {
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}