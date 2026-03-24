//错漏百出，等待修改
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s; cin >> s;
    int n; cin >> n;

    int cnt = 0;
    int sum = 0;
    string x = "";
    x += s[0];

    for(int i=1; i<s.size(); i++)
    {
        int num = 0;
        if(s[i] != '0')
        {
            cnt++;
        }
        else
        {
            if(!x.empty())
            {
                num = stoi(x);
                sum += num;
                x = "";
            }
        }

        if(n == sum)
        {
            cout << cnt-1;
            return 0;
        }
    }

    if(!x.empty())
    {
        int num = stoi(x);
        sum += num;
    }
    if(n != sum)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << cnt;
    }

    return 0;
}