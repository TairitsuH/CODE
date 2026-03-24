#include<stdio.h>
int main()
{
    int arr[10];
    int i;
    double sum = 0;
    for(i=0; i<10; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0; i<10; i++)
    {
        double money = 0;
        switch(i)
        {
            case 0:
            {
                money = arr[i]*28.9;
                sum += money;
                break;
            }
            case 1:
            {
                money = arr[i]*32.7;
                sum += money;
                break;
            }
            case 2:
            {
                money = arr[i]*45.6;
                sum += money;
                break;
            }
            case 3:
            {
                money = arr[i]*78;
                sum += money;
                break;
            }
            case 4:
            {
                money = arr[i]*35;
                sum += money;
                break;
            }
            case 5:
            {
                money = arr[i]*86.2;
                sum += money;
                break;
            }
            case 6:
            {
                money = arr[i]*27.8;
                sum += money;
                break;
            }
            case 7:
            {
                money = arr[i]*43;
                sum += money;
                break;
            }
            case 8:
            {
                money = arr[i]*56;
                sum += money;
                break;
            }
            case 9:
            {
                money = arr[i]*65;
                sum += money;
                break;
            }
        }
    }
    printf("%.1lf",sum);
    return 0;
}