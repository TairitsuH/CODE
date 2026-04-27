#include<stdio.h>
int main()
{
    int set;
    int max, min;
    scanf("%d",&set);
    for(int i=0; i<set; i++)
    {
        int round;
        scanf("%d",&round);
        max = round - 1;
        min = round / 2;
        printf("%d %d\n",max,min);
    }
    return 0;
}