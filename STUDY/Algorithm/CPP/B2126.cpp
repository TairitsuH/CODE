#include<iostream>
using namespace std;

string x;

int main()
{
    int k; cin >> k >> x;
    int cnt = 1;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i] == x[i+1])
        {
            cnt++;
            continue;
        }
        else
        {
            if(cnt >= k) 
            {
                cout << x[i];
                return 0;
            }
            else
            {
                cnt = 1;
            }
        }
    }

    cout << "No";

    return 0;
}