#include<iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s, str, rep; cin >> s >> str >> rep;
        size_t pos = s.find(str);

        cout << s << endl;
        if(pos != string::npos)
        {
            s.replace(pos, str.size(), rep);
        }
        
        cout << s << endl;
    }
    return 0;
}