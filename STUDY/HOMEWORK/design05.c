#include <stdio.h>
#include <string.h>

void rev(char s[]) 
{
    int l = 0;
    int r = strlen(s)-1;
    // 左右指针交换字符
    while(l < r) {
        char t = s[l];
        s[l] = s[r];
        s[r] = t;
        l++;
        r--;
    }
}

int main() 
{
    char a[200], b[200];
    scanf("%s%s", a, b);
    // 拆分每个数的整数和小数
    char ai[200] = "0", ad[200] = "";
    char bi[200] = "0", bd[200] = "";

    //数a
    char *p = strchr(a, '.');
    if(p) 
    {
        *p = '\0';
        strcpy(ai, a);
        strcpy(ad, p+1);
        
    } 
    else
    {
        strcpy(ai, a);
    }

    //数b
    p = strchr(b, '.');
    if(p) {
        *p = '\0';
        strcpy(bi, b);
        strcpy(bd, p+1);
    } else {
        strcpy(bi, b);
    }

    // 对齐小数部分
    int len1 = strlen(ad);
    int len2 = strlen(bd);
    int maxd = len1 > len2 ? len1 : len2;
    // 给短的小数部分补零
    while(strlen(ad) < maxd) 
    {
        strcat(ad, "0");
    }
    while(strlen(bd) < maxd) 
    {
        strcat(bd, "0");
    }

    // 计算小数部分的和
    char dr[200] = {0};
    int c = 0;
    rev(ad); 
    rev(bd);
    for(int i=0; i<maxd; i++) 
    {
        int sum = (ad[i]-'0') + (bd[i]-'0') + c;
        dr[i] = (sum % 10) + '0';
        c = sum / 10;
    }
    rev(dr); //反转回来

    // 计算整数部分的和
    char ir[200] = {0};
    rev(ai); rev(bi); //反转整数部分
    int maxi = strlen(ai) > strlen(bi) ? strlen(ai) : strlen(bi);
    for(int i=0; i<maxi || c; i++) 
    {
        int da = i < strlen(ai) ? (ai[i]-'0') : 0;
        int db = i < strlen(bi) ? (bi[i]-'0') : 0;
        int sum = da + db + c;
        ir[i] = (sum % 10) + '0';
        c = sum / 10;
    }
    rev(ir);// 反转回来


    int st = 0;
    while(ir[st] == '0' && ir[st+1] != '\0')
    {
        st++;
    }
    printf("%s", ir + st);

    if(maxd > 0)
    {
        printf(".%s", dr);
    }
    
    return 0;
}