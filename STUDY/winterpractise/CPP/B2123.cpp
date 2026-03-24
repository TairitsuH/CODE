#include<iostream>
using namespace std;

string str;
string out = "";

int main()
{
    cin >> str;
    int cnt = 1;

    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == str[i+1])
        {
            cnt++;
            continue;
        }
        else
        {
            out += to_string(cnt);
            out.push_back(str[i]);
            cnt = 1;
        }
    }

    cout << out;

    return 0;
}