class Solution {
public:
    bool isUnique(string astr)
    {
        if(astr.size() > 26)
        {
            return false;
        }

        int hash = 0;

        for(auto ch : astr)
        {
            int pos = ch - 'a';
            if(((hash >> pos) & 1) == 0) //注意优先级！
            {
                hash |= (1 << pos);
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

//一刷：位运算的思想，用一个整数的二进制位来表示，注意判断条件的优先级！
//尽可能加括号