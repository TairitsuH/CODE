#include<stdio.h>
int main()
{
    int  m,n;
    scanf("%d%d",&n,&m);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int min =100*m;
    for(int j=0; j<=n-m; j++)
    {
        int sum = 0;
        for(int k=j; k<j+m; k++)
        {
            sum += arr[k];
        }
        if(sum < min)
        {
            min = sum;
        }
    }

    printf("%d",min);

    return 0;
}