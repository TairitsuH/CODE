#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int T; cin >> T;

    while(T--)
    {
        string ret;
        string str; cin >> str;
        for(auto c : str)
        {
            if(c == '#')
            {
                if(ret.size() != 0) ret.pop_back();
            }
            else if(c == '$')
            {
                ret = "";
            }
            else ret += c;
        }

        if(ret.size() == 0) cout << "empty" << endl;
        else cout << ret << endl;
    }
    return 0;
}