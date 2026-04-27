#include<iostream>
#include<string> //用到字符串函数都要加string头文件
using namespace std;

string a,b;
int n, cnt = 1, flag = 0;

int main()
{
    cin >> b;
    n = b.size();

    //字符串可以直接相加
    while(cin >> a)
    {
        b += a;
        if(b.size() == n*n) break; //读取到规定长度则退出
    }

    //或者：
    // while(cin >> a)
    // {
    //     b += a;
    // }当输入结束时按ctrl+z，再按回车即可退出循环

    cout << n << " ";
    //处理首位不为0的情况
    if(b[0] != '0') cout << "0 ";

    //开始循环输出
    for(int i=0; i<n*n; i++)
    {
        if(b[i] == b[i+1])
        {
            cnt++;
            flag = 0;
        }
        else
        {
            cout << cnt << " ";
            cnt = 1;
            flag = 1;
        }
    }

    //循环结束后别忘记输出cnt
    if(flag == 0) cout << cnt;
    return 0;
}