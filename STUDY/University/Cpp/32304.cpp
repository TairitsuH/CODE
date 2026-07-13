#include<iostream>
using namespace std;

struct age
{
    int y;
    int m;
    int d;
};

bool oldercmp(const age& a, const age &b)
{
    if(a.y != b.y) return a.y < b.y;
    if(a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

int main()
{
    int t; cin >> t;
    age* dates = new age[t];
    for(int i=0; i<t; i++)
    {
        cin >> dates[i].y >> dates[i].m >> dates[i].d;
    }

    int oldest = 0;
    int second = -1;

    for(int i=1; i<t; i++)
    {
        if(oldercmp(dates[i], dates[oldest]))
        {
            second = oldest;
            oldest = i;
        }
        else if(second == -1 || oldercmp(dates[i], dates[second]))
        {
            second = i;
        }
    }

    cout << dates[second].y << "-" << dates[second].m << "-" << dates[second].d << endl;
    return 0;
}