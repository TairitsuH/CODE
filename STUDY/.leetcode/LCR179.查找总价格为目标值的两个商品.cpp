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

//一刷：单调性+双指针，由于是升序数组，因此左右指针两端出发，偏大动右偏小动左