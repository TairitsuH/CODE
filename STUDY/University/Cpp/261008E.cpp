#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        int n = s.size();

        vector<int> next(n + 1);        // 改动①：多开一格
        next[0] = -1;
        int i = 0, j = -1;
        while(i < n)                    // 改动②：n-1 改成 n，多迭代一次
        {
            if(j == -1 || s[i] == s[j])
            {
                ++i; ++j;
                next[i] = j;            // 最后一轮写出 next[n]
            }
            else
                j = next[j];
        }

        int p = n - next[n];            // 改动③：整串的 border 在 next[n]
        if(p != n && n % p == 0)
            cout << 0 << endl;
        else
            cout << p - n % p << endl;
    }
    return 0;
}
