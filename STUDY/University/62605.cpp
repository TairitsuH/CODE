#include<iostream>
#include<vector>
using namespace std;

template<class T>
class List
{
    vector<T> v;
    int len;

public:
    List(const vector<T>& arr, int n)
    :v(arr)
    ,len(n)
    {}

    void Insert(int pos, T x)
    {
        v.insert(v.begin() + pos, x);
        len++;
    }

    void Erase(int pos)
    {
        v.erase(v.begin() + pos);
        len--;
    }

    void print_int()
    {
        for(int i=0; i<len; i++)
        {
            cout << v[i];
            if(i != len - 1)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }

    void print_float()
    {
        for(int i=0; i<len; i++)
        {
            printf("%.1lf", v[i]);
            if(i != len - 1)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }

};

int main()
{
    int n; cin >> n;
    vector<int> v1(100);

    for(int i=0; i<n; i++)
    {
        cin >> v1[i];
    }
    List<int> l1(v1, n);
    int pos;
    int x;
    cin >> pos >> x;
    l1.Insert(pos, x);
    cin >> pos;
    l1.Erase(pos);
    l1.print_int();

    
    cin >> n;
    vector<double> v2(100);

    for(int i=0; i<n; i++)
    {
        cin >> v2[i];
    }
    List<double> l2(v2, n);
    double X;
    cin >> pos >> X;
    l2.Insert(pos, X);
    cin >> pos;
    l2.Erase(pos);
    l2.print_float();
    return 0;
}