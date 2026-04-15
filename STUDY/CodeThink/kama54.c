#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct SeqList
{
    char* a;
    int size;
    int capacity;
}SL;

int main()
{
    SL s;
    s.a = (char*)malloc(sizeof(char)*(1e5 + 10));
    s.capacity = 1e5 + 10;

    scanf("%s", s.a);
    int len = strlen(s.a);

    int cnt = 0;
    for(int i=0; i<len; i++)
    {
        if(s.a[i] >= '0' && s.a[i] <= '9')
        {
            cnt++;
        }
    }

    int newcapacity = len + cnt * 5 + 1;
    if(newcapacity > s.capacity)
    {
        s.a = (char*)realloc(s.a, sizeof(char)*newcapacity);
        s.capacity = newcapacity;
    }

    int left = len, right = newcapacity - 1;

    while(left >= 0)
    {
        if(s.a[left] >= '0' && s.a[left] <= '9')
        {
            s.a[right--] = 'r';
            s.a[right--] = 'e';
            s.a[right--] = 'b';
            s.a[right--] = 'm';
            s.a[right--] = 'u';
            s.a[right--] = 'n';
            left--;
        }
        else
        {
            s.a[right--] = s.a[left--];
        }
    }

    printf("%s\n", s.a);

    return 0;
}
//二刷：利用动态顺序表，成功过关~需要注意的是数字变number后改变的容量为5不是6，不要忘记放入'\0'。
//一刷：直接暴力做了，另开了一个数组。看了题解发现大致思路是在原数组基础上扩容，明天打算再细致琢磨琢磨。
// const int N = 1e5 + 10;
// char a[N];
// char acpy[N];

// int main()
// {
//     scanf("%s", a);
//     int len = strlen(a);

//     int j = 0;
//     for(int i=0; i<len; i++)
//     {
//         if(a[i] >= '0' && a[i] <= '9')
//         {
//             acpy[j++] = 'n';
//             acpy[j++] = 'u';
//             acpy[j++] = 'm';
//             acpy[j++] = 'b';
//             acpy[j++] = 'e';
//             acpy[j++] = 'r';
//         }
//         else
//         {
//             acpy[j++] = a[i];
//         }
//     }

//     printf("%s\n", acpy);
//     return 0;
// }
