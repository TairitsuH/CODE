/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n)
    {
        long long slow = n;
        long long fast = n;

        do
        {
            long long sum1 = 0;
            long long sum2 = 0;
            int time = 2;

            while(slow != 0)
            {
                sum1 += pow(slow % 10, 2);
                slow /= 10;
            }
            
            while(time--)
            {
                while(fast != 0)
                {
                    sum2 += pow(fast % 10, 2);
                    fast /= 10;
                }

                fast = sum2;
                sum2 = 0;
            }

            slow = sum1;
        }while(slow != fast);

        if(slow == 1)
        {
            return true;
        }

        return false;
    }
};
// @lc code=end

//二刷：do-while循环yyds！最后总会进入循环，因此设置快慢指针，fast走两步，看相遇点是否为1
//一刷：用了比较作弊的方法，个位数只有1和7能过 > v < 
// class Solution {
// public:
//     bool isHappy(int n)
//     {
//         while(n >= 10)
//         {
//             int num = n;
//             long long sum = 0;

//             while(num)
//             {
//                 sum += (num % 10) * (num % 10);
//                 num /= 10;
//             }

//             n = sum;
//         }

//         if(n == 1 || n == 7)
//         {
//             return true;
//         }

//         return false;
//     }
// };
