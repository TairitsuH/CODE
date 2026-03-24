#include<stdio.h>
#include<assert.h>

int my_strlen(const char * str)
{
    int cnt = 0;
    assert(str);
    while(*str != '\0') 
    //括号里可以直接写*str
    {
        cnt++; //计数+1
        str++; //指针右移一位
    }
    return cnt;
}

int main()
{
    int len = my_strlen("Tairitsu_Hi");
    printf("%d\n", len);
    return 0;
}