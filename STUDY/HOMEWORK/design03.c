#include<stdio.h>
#include<string.h>
int main()
{
    unsigned long long a, sum = 0;
    
    for(int j = 0; j<2; j++)//四进制转化为十进制
    {
        scanf("%llu",&a);
        unsigned long long A = a;
        unsigned long long p = 1;
        while(A)
        {
            unsigned long long m = A%10;
            m *= p;
            sum += m;
            p *= 4;
            A /= 10;
        }
    }
    
    char str[50] = {0};//十进制转化为四进制
    if(sum == 0)
    {
        strcpy(str, "0");
    }
    else
    {
        int index = 0;
        int devide = 0;
        while(sum > 0)
        {
            devide = sum % 4;
            char ch = devide + '0';
            str[index] = ch;
            index++;
            sum /= 4;
        }
        str[index] = '\0';
        int len = strlen(str);
        for(int i = 0; i<len/2; i++)
        {
            char mid = str[i];
            str[i] = str[len-1-i];
            str[len-1-i] = mid;
        }
    }

    printf("%s",str);
    return 0;
}