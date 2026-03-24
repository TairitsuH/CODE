#include<iostream>
#include<cstring>
using namespace std;

const int N = 10;

int n = 5;
int a[N], t[N];

int calc(int x)
{
    int cnt = 0;
    while(x)
    {
        cnt++;
        x &= x - 1;
    }
    return cnt;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        memset(a, 0, sizeof(a)); //清空上一组数据

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                char ch; cin >> ch;
                if(ch == '0') a[i] |= 1 << j; 
                //把a[i]的二进制第j位改为1
            }
        }

        int ret = 0x3f3f3f3f; //设置一个无穷大数
        for(int st=0; st<(1<<n); st++) //子集
        {
            memcpy(t, a, sizeof(a));
            
            int push = st;
            int cnt = 0;

            for(int i=0; i<n; i++)
            {
                cnt += calc(push);
                t[i] = t[i] ^ push ^ (push<<1) ^ (push>>1);
                t[i] &= (1<<n) - 1;
                t[i+1] ^= push;
                push = t[i]; 
            }
            
            if(t[n-1] == 0) ret = min(ret, cnt); 
        }

        if(ret > 6) cout << -1 << endl;
        else cout << ret << endl;
    }

    return 0;
}