#include<iostream>
using namespace std;

string s;
string S = "";

int main()
{
    cin >> s;
    for(int i=0; i<s.size(); i++)
    {
        if(i == s.size()-1)
        {
            int x = (int)s[i] + (int)s[0];
            S += (char)x;
        }
        else
        {
            int x = (int)s[i] + (int)s[i+1];
            S += (char)x;
        }
    }

    cout << S;

    return 0;
}