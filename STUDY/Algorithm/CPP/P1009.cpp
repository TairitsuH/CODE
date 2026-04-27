#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n; cin >> n;
    getchar();
    while(n--)
    {
        string x; getline(cin, x);
        int sum = 0;
        int num = 0;

        for(int i=0; i<x.size(); i++)
        {
            if(isdigit(x[i]))
            {
                num = num * 10 + (x[i] - '0');
            }
            else
            {
                sum += num;
                num = 0;
            }
        }
        sum += num;
        cout << sum << endl;
    }
    return 0;
}