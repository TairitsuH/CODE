#include<iostream>
#include<vector>
using namespace std;

const int N = 1e6;
vector<int> a(N);
int n;

int main()
{
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<a.size()-1; i++)
    {
        for(int j=i+1; j<a.size(); j++)
        {
            if(a[i] == a[j])
            {
                a.erase(a.begin()+j);
                j--;
            }
        }
    }

    for(int i=0; i<a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

