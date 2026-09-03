#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        vector<vector<int>> vv(2, vector<int>(3));
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<3; j++)
            {
                cin >> vv[i][j];
            }
        }

        for(int i=2; i>=0; i--)
        {
            for(int j=0; j<2; j++)
            {
                cout << vv[j][i] << " ";
            }

            cout << endl;
        }
    }
    return 0;
}