class Solution {
public:
    bool CheckPermutation(string s1, string s2)
    {
        if(s1.size() != s2.size()) return false;
        vector<int> arr(26, 0);

        for(auto ch : s1)
        {
            arr[ch - 'a']++;
        }

        for(auto ch : s2)
        {
            arr[ch - 'a']--;
            if(arr[ch - 'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
};

//二刷：一个数组模拟哈希表，注意长度不同的情况
//一刷：暴力解法：排序后比较
// class Solution {
// public:
//     bool CheckPermutation(string s1, string s2)
//     {
//         sort(s1.begin(), s1.end());
//         sort(s2.begin(), s2.end());
//         return s1 == s2;
//     }
// };