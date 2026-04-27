#include<iostream>
using namespace std;

int arr[6][6];
int m,n;

int main()
{
    for(int i=1; i<=5; i++)
    {
        for(int j=1;j<=5; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> m >> n;
    for(int i=1; i<=5; i++)
    {
        swap(arr[n][i],arr[m][i]); //不要忘记swap可以直接交换，不需要创建中间变量存储数据！
    }

    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}