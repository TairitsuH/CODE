#include<iostream>
using namespace std;

int m,n,x;
const int N = 100;
int arr[N][N];

int find(int x)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j] == x) return i;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> x;

    cout << find(x) << endl;

    return 0;
}