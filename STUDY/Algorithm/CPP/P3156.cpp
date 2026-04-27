#include<iostream>
#include<vector>
using namespace std;

const int N = 2e6 + 10;
vector<int> a(N);

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    
    while(m--)
    {
        int x;
        cin >> x;
        cout << a[x] << endl;
    }

    return 0;
}