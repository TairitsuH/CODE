#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int cute;
    for(i=0; i<n; i++)
    {
        cute = 0;
        if(i == 0)
        {
            printf("%d ",cute);
        }
        else
        {
            for(int j=0; j<i; j++)
            {
                if(arr[j] < arr[i])
                {
                    cute++;
                }
            }
            printf("%d ",cute);
        }

    }
    return 0;
}