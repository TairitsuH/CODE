class Solution {
public:
    vector<int> missingTwo(vector<int>& nums)
    {
        int val = 0;
        int num = 1;
        for(auto x : nums)
        {
            val ^= x;
        }
        for(num=1; num<=nums.size()+2; num++)
        {
            val ^= num;
        }
        
        int pos = val & (-val);
        int a = 0;

        for(auto x : nums)
        {
            if(x & pos)
            {
                a ^= x;
            }
        }
        for(num=1; num<=nums.size()+2; num++)
        {
            if(num & pos)
            {
                a ^= num;
            }
        }

        val ^= a;

        return {val, a};
    }
};

//一刷：思路是全部异或一遍，转化为LC260，然后再根据最后一个1的位置把两个数分到不同区间，最后输出。
//也可以用一个diff变量存储不同位的下标，然后用>>来处理