#include<iostream>
#include<vector>
using namespace std;

int n;

int main()
{
    cin >> n;
    n--;
    int ith0,m0;
    cin >> ith0 >> m0;
    vector<int> a(m0);

    for(int i=0; i<m0; i++)
    {
        cin >> a[i];
    }
    for(int j=0; j<m0; j++) cout << a[j] << " ";
    cout << endl;

    while(n--)
    {
        int ith,m;
        cin >> ith >> m;
        vector<int> end1(m);

        for(int i=0; i<m; i++) cin >> end1[i];

        if(ith >= m0+1)
        {
            cout << "error" << endl;
            continue;
        }
        else
        {
            m0 = m0 + m;
            a.resize(m0);
            a.insert(a.begin()+ith, end1.begin(), end1.end());

            for(int j=0; j<m0; j++) cout << a[j] << " ";
            cout << endl;

            end1.resize(0);
        }
    }
    return 0;
}