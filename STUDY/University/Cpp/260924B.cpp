#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        string str; cin >> str;
        stack<char> st;
        int flag = 1;

        for(auto c : str)
        {
            if(c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else if(c == ']')
            {
                if(st.empty() || st.top() != '[')
                {
                    flag = 0;
                    break;
                }
                st.pop();
            }
            else if(c == ')')
            {
                if(st.empty() || st.top() != '(') //注意判断不要反了
                {
                    flag = 0;
                    break;
                }
                st.pop();
            }
            else if(c == '}')
            {
                if(st.empty() || st.top() != '{')
                {
                    flag = 0;
                    break;
                }
                st.pop();
            }
        }

        if(!st.empty() || flag == 0) cout << "error" << endl;
        else cout << "ok" << endl;
 
        
    }

    return 0;
}