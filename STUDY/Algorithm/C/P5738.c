#include<stdio.h>

void bubble(int arr[], int sz)
{
    int i,j;
    for(i=0; i<sz-1; i++)
    {
        for(j=0; j<sz-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main()
{
    int n,m,i,j,k;
    double max = 0, ave = 0;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        int arr[m];
        int sz = sizeof(arr)/sizeof(arr[0]);
        for(j=0; j<m; j++)
        {
            scanf("%d",&arr[j]);
        }
        bubble(arr, sz);
        double sum = 0;
        for(k=1; k<m-1; k++)
        {
            sum += arr[k];
        }

        ave = sum / (m-2);
        
        if(i == 0)
        {
            max = ave;
        }
        else if(ave > max)
        {
            max = ave;
        }
    }
    printf("%.2lf",max);
    return 0;
}