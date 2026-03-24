#include<iostream>
using namespace std;

int n,m;
int arr1[101][101],b;

int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> b;
            arr1[i][j] += b;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}