#include<iostream>
#include<vector>
using namespace std;

class borrow
{
public:
    long long no;
    long long book;
    long long day;

    borrow(long long n, long long b, long long d)
    :no(n)
    ,book(b)
    ,day(d)
    {}
};

int main()
{
    int t; cin >> t;
    vector<borrow> arr;
    while(t--)
    {
        long long n, b, d; cin >> n >> b >> d;
        borrow b1{n, b, d};
        arr.push_back(b1);
    }
    int q; cin >> q;
    while(q--)
    {
        long long pos; cin >> pos;
        long long i; cin >> i;

        if(i == 1)
        {
            cout << arr[pos - 1].no <<endl;
        }
        else if(i == 2)
        {
            cout << arr[pos - 1].book << endl;
        }
        else
        {
            cout << arr[pos - 1].day << endl;
        }
    }
    return 0;
}