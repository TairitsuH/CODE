#include<iostream>
#include<vector>
using namespace std;
//暴力解法:遇到val的时候，之后的元素整体前移，重复
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int n = nums.size();
        int k = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == val)
            {
                for(int j=i; j<n-1; j++) //写成n-1是因为若为n，nums[j+1]会越界
                {
                    nums[j] = nums[j+1];
                }
                i--;
                k++;
                n--;
            }
        }
        k = nums.size() - k;
        return k;
    }
};

//快慢双指针
#include<iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int n = nums.size();
        int slow = 0;
        for(int fast=0; fast<n; fast++)
        {
            if(nums[fast] != val)
            {
                swap(nums[slow], nums[fast]);
                slow++;
                //或者直接用一行代替：swap(nums[slow++], nums[fast]);
            }
        }
        return slow;
    }
};
//和移动零一模一样的解法，只不过对象不是0