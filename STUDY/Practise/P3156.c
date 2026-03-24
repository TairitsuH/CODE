#include<stdio.h>
int main()
{
    int m,n,i,j;
    int num;
    scanf("%d%d",&n,&m);
    int arr[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(j=0; j<m; j++)
    {
        scanf("%d",&num);
        int NUM = num - 1;
        printf("%d\n",arr[NUM]);
    }
    return 0;
}