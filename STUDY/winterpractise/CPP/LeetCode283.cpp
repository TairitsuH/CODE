//核心代码模式
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        for(int i=0, p=-1; i<nums.size(); i++)
        {
            if(nums[i])
            {
                swap(nums[++p], nums[i]);
            }
        }
        
    }
};