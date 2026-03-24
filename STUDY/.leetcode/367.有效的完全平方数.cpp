class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if(num == 1) return true;
        long long left = 1, right = num / 2, mid;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(mid * mid >= num) right = mid;
            else left = mid + 1;
        }
        if(right * right == num) return true;
        return false;       
    }
};
//bool类型返回值不能写字符串！！！

//二分查找，本质模板题