#include<iostream>
using namespace std;

const int N = 25;
int arr[N][N];

int main()
{
    int n; cin >> n;

    int x = 1, y = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(j == 1 || j == i)
            {
                arr[x][y] = 1;
            }
            else
            {
                arr[x][y] = arr[x-1][y] + arr[x-1][y-1];
            }
            y++;
        }
        x++;
        y = 1;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
