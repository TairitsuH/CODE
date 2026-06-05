// https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
    {
        stack<int> st;
        int j = 0;
        for(auto num : pushV)
        {
            if(st.empty() || st.top() != popV[j])
            {
                st.push(num);
            }

            while(!st.empty() && st.top() == popV[j])
            {
                st.pop();
                j++;
            }
        }

        if(st.empty()) return true;

        return false;
    }
};


//三刷：有一些格式上的编译错误，注意一下就好
//二刷：注意条件判断用if和while的区别！
// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 
//      * @param pushV int整型vector 
//      * @param popV int整型vector 
//      * @return bool布尔型
//      */
//     bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
//     {
//         stack<int> st;
//         int j = 0;
//         for(int i=0; i<pushV.size(); i++)
//         {
//             if(st.empty() || st.top() != popV[j])
//             {
//                 st.push(pushV[i]);
//             }

//             while(!st.empty() && st.top() == popV[j])
//             {
//                 st.pop();
//                 j++;
//             }
//         }

//         if(!st.empty())
//         {
//             return false;
//         }

//         return true;
//     }
// };

// int main()
// {
//     vector<int> v1 = {1, 2, 3, 4, 5};
//     vector<int> v2 = {4, 5, 3, 2, 1};

//     cout << Solution().IsPopOrder(v1, v2) << endl;
//     return 0;
// }


//一刷
// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std;

//     bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
//     {
//         stack<int> st;
//         if(pushV.size() != popV.size())
//         {
//             return false;
//         }

//         size_t pu = 0, po = 0;
//         while(po < popV.size())
//         {
//             st.push(pushV[pu]);

//             while(!st.empty() && st.top() == popV[po])
//             {
//                 st.pop();
//                 ++po;
//             }

//             ++pu;
//         }

//         return st.empty();
//     }

// int main()
// {
//     vector<int> push1 = {1, 2, 3, 4, 5};
//     vector<int> pop1 = {4, 5, 3, 2, 1};

//     cout << (IsPopOrder(push1, pop1)) << endl;
//     return 0;
// }