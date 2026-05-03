// https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

    bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
    {
        stack<int> st;
        if(pushV.size() != popV.size())
        {
            return false;
        }

        size_t pu = 0, po = 0;
        while(po < popV.size())
        {
            st.push(pushV[pu]);

            while(!st.empty() && st.top() == popV[po])
            {
                st.pop();
                ++po;
            }

            ++pu;
        }

        return st.empty();
    }

int main()
{
    vector<int> push1 = {1, 2, 3, 4, 5};
    vector<int> pop1 = {4, 5, 3, 2, 1};

    cout << (IsPopOrder(push1, pop1)) << endl;
    return 0;
}