#include<iostream>
using namespace std;

void find(int *a, int t, int &minx, int &maxx)
{
    int mina = 1e9;
    int maxa = -1e9;
    for(int i=0; i<t; i++)
    {
        if(a[i] < mina)
        {
            mina = a[i];
            minx = i;
        }
        if(a[i] > maxa)
        {
            maxa = a[i];
            maxx = i;
        }
    }
}

int main()
{
    int n; cin >> n;
    while(n--)
    {
        int t; cin >> t;
        int * a = new int[t];
        for(int i=0; i<t; i++)
        {
            cin >> a[i];
        }
        int minx = 0, maxx = 0 ;
        find(a, t, minx, maxx);
        cout << "min=" << a[minx] << " " << "minindex=" << minx << endl;
        cout << "max=" << a[maxx] << " " << "maxindex=" << maxx << endl;
        cout << endl;
        delete []a;
    }
    return 0;
}