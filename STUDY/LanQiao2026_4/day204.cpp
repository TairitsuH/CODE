// //子集 力扣78
// //2026.3.13
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) 
//     {
//         vector<vector<int>> ret;
//         int n = nums.size();
//         for(int st=0; st<(1<<n); st++)
//         {
//             vector<int> tmp;
//             for(int i=0; i<n; i++)
//             {
//                 if((st >> i) & 1) tmp.push_back(nums[i]);
//             }
//             ret.push_back(tmp);
//         }
//         return ret;
//     }
// };

//2026.3.14 复盘
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> ret;
        for(int st=0; st<(1<<n); st++)
        {
            vector<int> tmp;
            for(int i=0; i<n; i++)
            {
                if((st>>i) & 1) //二进制运算符还是不太熟练
                {
                    tmp.push_back(nums[i]);
                }
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};