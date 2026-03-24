#include<stdio.h>
#include<string.h>
#include<stdlib.h>

__int128 four_to_ten(const char *s)//四到十
{
    __int128 result = 0;
    int sign = 1;
    int start = 0;

    if(s[0] == '-')
    {
        sign = -1;
        start = 1;
    }
    else if(s[0] == '+')
    {
        start = 1;
    }

    int i;
    for(i=start; s[i]!='\0'; i++)
    {
        result *= 4;
        result += (s[i]-'0');
    }

    return result*sign;
}

void ten_to_four(__int128 num, char *out)//十到四
{
    if(num == 0)
    {
        strcpy(out, "0");
        return;
    }

    char yushu[50] = {0};//余数

    int fushu = 0;
    if(num < 0)
    {
        fushu = 1;
        num = -num;
    }
    int j = 0;

    while(num>0)
    {
        int yushu1 = num % 4;
        yushu[j++] = yushu1 + '0';
        num /= 4;
    }

    int index = 0;
    if(fushu)
    {
        out[index++] = '-';
    }

    int i;
    for(i=j-1; i>=0; i--)
    {
        out[index++] = yushu[i];
    }
    out[index] = '\0';

}

int main()
{
    char num1[100], num2[100];
    char num_out[100] = {0};
    __int128 sum = 0;

    scanf("%s%s",num1,num2);

    sum += four_to_ten(num1) + four_to_ten(num2);
    ten_to_four(sum,num_out);
    
    printf("%s",num_out);
    return 0;
}