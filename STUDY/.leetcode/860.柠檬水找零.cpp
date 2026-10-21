/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0, ten = 0, twe = 0;
        for(int i=0; i<bills.size(); ++i)
        {
            cout << i << ' ';
            cout << five << ' ' << ten << ' ' << twe << endl;
            if(bills[i] == 5) ++five;
            else if(bills[i] == 10)
            {
                ++ten;
                if(five > 0) --five;
                else return false;
            }
            else if(bills[i] == 20)
            {
                ++twe;
                if(ten > 0 && five > 0)
                {
                    --ten;
                    --five;
                }
                else if(five > 2)
                {
                    five -= 3;
                }
                else return false;
            }
        }    

        return true;
    }
};
// @lc code=end
//一刷：贪心算法，注意分类讨论时需要先更新变量，最好在判断的时候用>=
