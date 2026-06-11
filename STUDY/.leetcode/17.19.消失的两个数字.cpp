class Solution {
public:
    vector<int> missingTwo(vector<int>& nums)
    {
        //异或nums和1~N的数
        int n = nums.size();
        int val = 0;
        for(auto x : nums)
        {
            val ^= x;
        }

        for(int i=1; i<=n+2; i++)
        {
            val ^= i;
        }

        //找不同位
        int pos = val & (-val);
        int a = 0;
        for(auto x : nums)
        {
            if((x & pos) != 0)
            {
                a ^= x;
            }
        }

        for(int i=1; i<=n+2; i++)
        {
            if((i & pos) != 0)
            {
                a ^= i;
            }
        }

        val ^= a;

        return {val, a};
    }
};

//二刷：注意和pos与运算的时候if内部是判断不为0而不是等于1
//一刷：思路是全部异或一遍，转化为LC260，然后再根据最后一个1的位置把两个数分到不同区间，最后输出。
//也可以用一个diff变量存储不同位的下标，然后用>>来处理
// class Solution {
// public:
//     vector<int> missingTwo(vector<int>& nums)
//     {
//         int val = 0;
//         int num = 1;
//         for(auto x : nums)
//         {
//             val ^= x;
//         }
//         for(num=1; num<=nums.size()+2; num++)
//         {
//             val ^= num;
//         }
        
//         int pos = val & (-val);
//         int a = 0;

//         for(auto x : nums)
//         {
//             if(x & pos)
//             {
//                 a ^= x;
//             }
//         }
//         for(num=1; num<=nums.size()+2; num++)
//         {
//             if(num & pos)
//             {
//                 a ^= num;
//             }
//         }

//         val ^= a;

//         return {val, a};
//     }
// };