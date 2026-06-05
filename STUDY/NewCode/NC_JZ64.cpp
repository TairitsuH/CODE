// https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    class Sum
    {
    public:
        static int _ret;
        static int _i;

        Sum()
        {
            _ret += _i;
            _i++;
        }

    };

    int Sum_Solution(int n)
    {
        Sum a[n];
        return Sum::_ret;
    }
};

int Solution::Sum::_ret = 0;
int Solution::Sum::_i = 1;