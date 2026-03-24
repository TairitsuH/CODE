class Solution {
public:
    int mySqrt(int x)
    {
        if(x == 0) return 0;
        else if(x == 1) return 1;
        long long left = 1, right = x/2;
        long long mid;
        while(left < right)
        {
            mid = left + (right - left + 1) / 2;
            if(mid * mid <= x) left = mid;
            else right = mid - 1; //有-1时mid补+1
        }
        return left;
    }
};

//二分查找，本质模板题