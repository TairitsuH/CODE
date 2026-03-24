#include<iostream>
#include<cstring>
using namespace std;

string x;
int sz,flag;

int main()
{
    cin >> x;
    sz = x.size();
    for(int i=0; i<sz; i++)
    {
        flag = 0;
        for(int j=0; j<sz; j++)
        {
            if(x[i] == x[j] && i!=j) 
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout << x[i];
            break;
        }
    }

    if(flag != 0) cout << "no";

    return 0;
}