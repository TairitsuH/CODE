#include<iostream>
#include<stack>
using namespace std;



int main()
{
    stack<int> st;

    for(int i=0; i<=10; i++)
    {
        st.push(i);
    }

    while(st.size()) //!sz.empty()
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}