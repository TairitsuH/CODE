#include<stdio.h>
int main()
{
    int l,zone,i,j;
    scanf("%d%d",&l,&zone);
    int L = l+1;
    int arr[L];
    for(i=0; i<L; i++)
    {
        arr[i] = 1;
    }

    for(i=0; i<zone; i++)
    {
        int begin = 0, end = 0;
        scanf("%d%d",&begin,&end);
        for(j=begin; j<=end; j++)
        {
            arr[j] = 0;
        }
    }

    int count = 0;
    for(i=0; i<L; i++)
    {
        if(arr[i] == 1)
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}