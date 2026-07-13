#include<iostream>
#include<vector>
using namespace std;

class MyMatrix
{
public:
    vector<vector<int>> data;
    static int n;

    MyMatrix(vector<vector<int>>& d)
    :data(d)
    {}


    MyMatrix operator*(const MyMatrix& d)
    {
        vector<vector<int>> r(n, vector<int>(n, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    r[i][j] += data[i][k] * d.data[k][j];
                }       
            }
        }

        MyMatrix ret(r);
        return ret;
    }
};

int MyMatrix::n = 0;

int main()
{
    int t; cin >> t;
    cin >> MyMatrix::n;
    int N = MyMatrix::n;

    vector<vector<int>> vv(MyMatrix::n, vector<int>(MyMatrix::n, 0));
    int j = 0;
    for(int i=0; i<N; i++)
    {
        vv[i][j++] = 1;
    }
    MyMatrix ret(vv);

    while(t--)
    {
        vector<vector<int>> vv0(N, vector<int>(N, 0));

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin >> vv0[i][j];
            }
        }

        MyMatrix vv1(vv0);

        ret = ret * vv1;
    }

        for(int i=0; i<MyMatrix::n; i++)
        {
            for(int j=0; j<MyMatrix::n; j++)
            {
                cout << ret.data[i][j];

                if(j != N - 1) cout << " ";
            }
            
            cout << endl;
        }
    return 0;
}