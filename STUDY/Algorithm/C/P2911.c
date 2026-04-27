#include<stdio.h>
int main()
{
    int s1,s2,s3;
    scanf("%d%d%d",&s1,&s2,&s3);
    int arr[81] = {0};
    for(int i=1; i<=s1; i++)
    {
        for(int j=1; j<=s2; j++)
        {
            for(int k=1; k<=s3; k++)
            {
                int sum = i + j + k;
                arr[sum]++;
            }
        }
    }

    int max = 0,p = 0;
    for(int i=0; i<81; i++)
    {
        if(arr[i] > max)
        {
            p = i;
            max = arr[i];
        }
    }

    printf("%d",p);
    return 0;
}