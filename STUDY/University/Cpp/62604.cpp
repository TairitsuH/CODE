#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Matrix
{
    vector<vector<T>> v;

public:
    Matrix(const vector<vector<T>>& arr)
    :v(arr)
    {}

    void transport(int m, int n)
    {
        vector<vector<T>> tmp(n, vector<T>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                tmp[i][j] = v[j][i];
            }
        }

        *this = tmp;
    }

    void print(int m, int n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << v[i][j];
                if(j != m-1)
                {
                    cout << ' ';
                }
            }

            cout << endl;
        }
    }
};

int main()
{
    int t; cin >> t;
    while(t--)
    {
        char op; cin >> op;
        int m, n; cin >> m >> n;

        if(op == 'I')
        {
            vector<vector<int>> arr(m, vector<int>(n));
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cin >> arr[i][j];
                }
            }
            Matrix<int> m1(arr);
            m1.transport(m, n);
            m1.print(m, n);
        }
        else if(op == 'D')
        {
            vector<vector<double>> arr(m, vector<double>(n));
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cin >> arr[i][j];
                }
            }
            Matrix<double> m1(arr);
            m1.transport(m, n);
            m1.print(m, n);
        }
        else
        {
            vector<vector<char>> arr(m, vector<char>(n));
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cin >> arr[i][j];
                }
            }
            Matrix<char> m1(arr);
            m1.transport(m, n);
            m1.print(m, n);
        }
    }
    return 0;
}