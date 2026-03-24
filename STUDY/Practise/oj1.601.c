#include<stdio.h>
int main()
{
    int N,i,n;
    int count = 0;
    scanf("%d",&N);
    int arr[N];
    for(i=0; i<N; i++)
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&n);
    for(i=0; i<N; i++)
    {
        if(n == arr[i])
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}