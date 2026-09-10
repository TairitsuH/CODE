#include<iostream>
#include<vector>
using namespace std;

int op1(vector<int>& a)
{
    int n = a.size();
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        for (int k = 1; k <= n; k++)
            if (k <= a[i] && a[j] % 2 == a[k - 1] % 2)
            {
                ++cnt;
            }

    return cnt;
    
}

int op2(vector<int>& a)
{
    int n = a.size();

    int cnt = 0;
    for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
        if (a[j] <= a[i])
        {
            ++cnt;
        }

    return cnt;

}

int op3(vector<int>& a)
{
    int n = a.size();

    int cnt = 0;
    for (int i = 0; i < n; i++)
    for (int t = 1; t < a[i]; t *= 2)
        ++cnt;
    
    return cnt;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a;
        while(n--)
        {
            int x; cin >> x;
            a.push_back(x);
        }

        cout << op1(a) << " " << op2(a) << " "<< op3(a) << endl;
    }
    return 0;
}