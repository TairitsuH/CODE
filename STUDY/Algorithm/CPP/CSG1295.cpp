#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,s,e; cin >> n >> s >> e;
    vector<int> a(2*n);

    for(int i = 0; i < n; i ++) 
    {
        a[i] = i * 100 + (int)(sin(n + i) * 100);
        a[n+i] = i * 100 + (int)(cos(n + i) * 100);
    }


    //部分排序
    int k = e;
    nth_element(a.begin(), a.begin()+k, a.end());
    nth_element(a.begin(), a.begin()+s, a.begin()+k);
    sort(a.begin()+s, a.begin()+k);


    for(int j=s; j<e; j++)
    {
        cout << a[j] << " ";
    }

    return 0;
}