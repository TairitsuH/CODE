//字符串遍历
#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    scanf("%s",s);
    int len = strlen(s);

    for(int i=0; i<len; i++)
    {
        printf("%c ", s[i]);
    }
    return 0;
}

//暴力枚举
for(int i=0; i<100; i++)
{
    for(int j=0; j<100; j++)
    {

    }
}

//判断一个数n是否为素数
int isprime(int n)
{
    if(n < 2) return 0;
    for(int i=2; i*i<=n; i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

//输入一个字符串，输出它的长度
#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    scanf("%s", s);
    int sz = strlen(s);
    printf("%d", sz);
    return 0;
}
//test
