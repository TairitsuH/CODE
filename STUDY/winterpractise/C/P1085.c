#include<stdio.h>
int main()
{
    int i,school,mom;
    int arr[7];
    int flag = 0;
    for(i=0; i<7; i++)
    {
        scanf("%d%d",&school,&mom);
        arr[i] = school + mom;
        if(arr[i]<=8)
        {
            flag += 1;
        }
    }



    if(flag == 7) //不会不高兴
    {
        printf("0");
    }
    else
    {
        int hour = arr[0];
        int day = 1;
        for(i=0; i<6; i++)
        {
            if(hour < arr[i+1])
            {
                hour = arr[i+1];
                day = i+1+1;
            }
        }
        printf("%d",day);
    }
    
    return 0;
}