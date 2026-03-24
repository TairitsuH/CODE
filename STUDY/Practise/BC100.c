#include<stdio.h>

void bubble(int a[], int sz)
{
    for(int i=0; i<sz-1; i++)
    {
        for(int j=0; j<sz-1-i; j++)
        {
            if(a[j+1] < a[j])
            {
                int mid = a[j+1];
                a[j+1] = a[j];
                a[j] = mid;
            }
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    n = n+m;
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    int sz = sizeof(a) / sizeof(a[0]);
    bubble(a, sz);

    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}