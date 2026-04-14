#include<stdio.h>
#include<string.h>

const int N = 1e5 + 10;
char a[N];
char acpy[N];

int main()
{
    scanf("%s", a);
    int len = strlen(a);

    int j = 0;
    for(int i=0; i<len; i++)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            acpy[j++] = 'n';
            acpy[j++] = 'u';
            acpy[j++] = 'm';
            acpy[j++] = 'b';
            acpy[j++] = 'e';
            acpy[j++] = 'r';
        }
        else
        {
            acpy[j++] = a[i];
        }
    }

    printf("%s\n", acpy);
    return 0;
}

//一刷：直接暴力做了，另开了一个数组。看了题解发现大致思路是扩容，明天打算再细致琢磨琢磨。