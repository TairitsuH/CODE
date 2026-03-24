#include<stdio.h>
int main()
{
    int arr[10];
    int i;
    int count = 0;
    for(i=0; i<10; i++)
    {
        scanf("%d",&arr[i]);
    }
    int height;
    scanf("%d",&height);
    height += 30;
    
    for(i=0; i<10; i++)
    {
        if(height>=arr[i])
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}