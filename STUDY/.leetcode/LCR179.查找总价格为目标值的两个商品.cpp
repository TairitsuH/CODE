class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target)
    {
        vector<int> ret;
        int left = 0;
        int right = price.size() - 1;

        while(left < right)
        {
            if(price[left] + price[right] < target)
            {
                left++;
            }
            else if(price[left] + price[right] > target)
            {
                right--;
            }
            else
            {
                ret.push_back(price[left]);
                ret.push_back(price[right]);
                break;
            }
        }

        return ret;
        //或者：return {price[left], price[right]};
    }
};

//二刷：验证了一下思路的正确性，利用排除法：指针的每次移动都是排除了不可能出现的情况：（仅生效于升序数组）
//例如和太大了，说明当前右边的数太大了，向右移动左指针只会使结果变得更大，说明右指针的数是可以排除的了，因此可以直接向左移动右指针
//一刷：单调性+双指针，由于是升序数组，因此左右指针两端出发，偏大动右偏小动左