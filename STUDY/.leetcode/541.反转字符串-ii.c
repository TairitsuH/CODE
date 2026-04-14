/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 */

// @lc code=start
char* reverseStr(char* s, int k)
{
    int length = strlen(s);
    for(int i=0; i<length; i+=2*k)
    {
        k = i + k > length ? length - i : k;
        
        int left = i, right = i + k - 1;
        while(left < right)
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;

            left++;
            right--;
        }
    }

    return s;
}
// @lc code=end

