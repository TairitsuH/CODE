#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N,i,j;
    scanf("%d",&N);
    int arr[N][3];
    for(i=0; i<N; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int count = 0;
    for(i=0; i<N; i++)
    {
        for(j=i+1; j<=N-1; j++)
        {
            int s1 = abs(arr[i][0]-arr[j][0]);
            int s2 = abs(arr[i][1]-arr[j][1]);
            int s3 = abs(arr[i][2]-arr[j][2]);
            int sum = abs(arr[i][0]-arr[j][0]+arr[i][1]-arr[j][1]+arr[i][2]-arr[j][2]);
            if((s1<=5)&&(s2<=5)&&(s3<=5)&&(sum<=10))
            {
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}