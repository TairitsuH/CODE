#include<stdio.h>
int main()
{
    int n,i,j;
    int num = 1;
    scanf("%d",&n);

    for(i=0; i<n; i++)//矩形
    {
        for(j=0; j<n; j++)
        {
            if(num < 10)
            {
                printf("0");
            }
            printf("%d",num);
            num++;
        }
        printf("\n");
    }

    printf("\n");

    int k,l;
    num = 1;
    for(k=1; k<=n; k++)
    {
        for(i=0; i<2*(n-k); i++)
        {
            printf(" ");
        }
        for(j=0; j<k; j++)
        {
            if(num < 10)
            {
                printf("0");
            }
            printf("%d",num);
            num++;
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}