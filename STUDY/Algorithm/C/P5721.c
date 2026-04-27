#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j;
    int num = 1;
    scanf("%d",&n);
    for(i=0; i<n; i++) //行
    {
        for(j=0; j<n-i; j++) //列
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
    return 0;
}