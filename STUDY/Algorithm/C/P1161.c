#include<stdio.h>
#include<math.h>
int arr[2000001] = {0};
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        double a;
        int t;
        scanf("%lf%d",&a,&t);
        for(int i=1; i<=t; i++)
        {
            int num = floor(a*i);
            arr[num]++;
        }
    }

    for(int j=1; j<2000001; j++)
    {
        if(arr[j] % 2 != 0)
        {
            printf("%d",j);
            break;
        }
    }
    return 0;
}